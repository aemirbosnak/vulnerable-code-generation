#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*func)();
} Plugin;

Plugin* load_plugin(char* path) {
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    FILE* file = fopen(path, "rb");
    fread(plugin, 1, sizeof(Plugin), file);
    fclose(file);
    return plugin;
}

void run_plugin(Plugin* plugin) {
    (*(plugin->func))();
}

void plugin1_func() {
    printf("Plugin 1: Executing malicious code...\n");
    char buffer[10];
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "Attacker's payload");
    system(buffer);
}

void plugin2_func() {
    printf("Plugin 2: Doing useful work...\n");
}

int main() {
    Plugin plugins[2] = {
        {
            .name = "evil_plugin",
            .func = plugin1_func
        },
        {
            .name = "useful_plugin",
            .func = plugin2_func
        }
    };

    for (int i = 0; i < 2; ++i) {
        run_plugin(&plugins[i]);
    }

    Plugin* malicious_plugin = load_plugin("./evil_plugin.bin");
    run_plugin(malicious_plugin);

    return 0;
}
