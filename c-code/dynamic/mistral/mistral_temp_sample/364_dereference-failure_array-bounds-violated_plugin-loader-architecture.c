#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[20];
    void (*func)();
} Plugin;

Plugin* load_plugin(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    Plugin plugin;
    fread(&plugin, sizeof(Plugin), 1, fp);
    fclose(fp);
    return &plugin;
}

void run_plugin(Plugin* plugin) {
    (*(plugin->func))();
}

void crash_plugin() {
    int arr[5];
    int i = 10;
    arr[i] = 42;
}

void plugin1_func() {
    printf("Loading Plugin 1...\n");
    crash_plugin();
}

void plugin2_func() {
    printf("Loading Plugin 2...\n");
    // Add another plugin function here
}

int main() {
    Plugin* plugins[2] = {load_plugin("plugin1.bin"), load_plugin("plugin2.bin")};

    for (int i = 0; i < 2; i++) {
        run_plugin(plugins[i]);
    }

    return 0;
}
