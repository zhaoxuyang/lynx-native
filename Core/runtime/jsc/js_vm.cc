// Copyright 2017 The Lynx Authors. All rights reserved.

#include <JavaScriptCore/JavaScript.h>
#include "runtime/js/js_vm.h"
#include "base/lazy_instance.h"

namespace jscore {
    namespace {
        base::LazyInstance<JSVM> g_vm;
    }
    
    JSVM* JSVM::Instance() {
        return g_vm.Get();
    }
    
    void JSVM::Initialize() {
        JSContextGroupRef context_group = JSContextGroupCreate();
        vm_ = static_cast<void*>(const_cast<OpaqueJSContextGroup*>(context_group));
    }
    
    JSVM::~JSVM() {
        if(vm_) {
            JSContextGroupRef context_group = static_cast<JSContextGroupRef>(vm_);
            JSContextGroupRelease(context_group);
        }
    }
}
