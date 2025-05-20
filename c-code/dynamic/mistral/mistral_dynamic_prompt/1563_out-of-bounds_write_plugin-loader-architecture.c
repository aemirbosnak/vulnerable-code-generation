#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*load)(void);
    void (*unload)(void);
} Plugin;

void* load_plugin(const char* filename) {
    FILE* file = fopen(filename, "rb");
    Plugin* plugin = (Plugin*) malloc(sizeof(Plugin));
    fread(plugin, 1, sizeof(Plugin), file);
    fclose(file);
    return plugin;
}

void run_plugin(Plugin* plugin) {
    (*plugin->load)();
}

int main() {
    Plugin* plugin = load_plugin("bad_plugin.bin");
    run_plugin(plugin);
    free(plugin);
    return 0;
}

// bad_plugin.bin content:
// Plugin {
//     name: "\0" // zero length string
//     load: system // arbitrary function pointer (system())
//     unload: free // arbitrary function pointer (free())
// }
