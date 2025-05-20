//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define OPT_NONE             0
#define OPT_PRELOAD          1
#define OPT_FREEABLE         2
#define OPT_NOW              4
#define OPT_LAZY             8
#define OPT_INTERPOSE        16
#define OPT_DELIBS           32

int main(int argc, char *argv[]) {
    char *libpath = "/usr/lib64";
    char *libname = "libstdc++.so.6";
    void *handle;
    int opt = OPT_NONE;

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-p") == 0) {
                opt |= OPT_PRELOAD;
            } else if (strcmp(argv[i], "-f") == 0) {
                opt |= OPT_FREEABLE;
            } else if (strcmp(argv[i], "-n") == 0) {
                opt |= OPT_NOW;
            } else if (strcmp(argv[i], "-l") == 0) {
                opt |= OPT_LAZY;
            } else if (strcmp(argv[i], "-i") == 0) {
                opt |= OPT_INTERPOSE;
            } else if (strcmp(argv[i], "-d") == 0) {
                opt |= OPT_DELIBS;
            }
        }
    }

    if (opt & OPT_PRELOAD) {
        handle = dlopen(libname, RTLD_NOW | RTLD_GLOBAL);
    } else {
        handle = dlopen(libname, RTLD_LAZY);
    }

    if (handle == NULL) {
        fprintf(stderr, "dlopen() failed: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    if (opt & OPT_FREEABLE) {
        if (dlclose(handle) != 0) {
            fprintf(stderr, "dlclose() failed: %s\n", dlerror());
            exit(EXIT_FAILURE);
        }
    }

    if (opt & OPT_DELIBS) {
        char *deps[10];
        int numdeps = dladdr1(handle, deps, 10);
        for (int i = 0; i < numdeps; i++) {
            printf("%s\n", deps[i]);
        }
    }

    exit(EXIT_SUCCESS);
}