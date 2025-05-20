#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* Plugin;

Plugin load_plugin(const char* path) {
    FILE* fp = fopen(path, "rb");
    Plugin plugin = malloc(sizeof(char) * (1 + strlen(path)));
    fread(plugin, 1, strlen(path) + 1, fp);
    fclose(fp);
    return plugin;
}

void unload_plugin(Plugin plugin) {
    free(plugin);
}

void execute_plugin(Plugin plugin) {
    void (*func)(void) = (void(*)(void))plugin;
    func();
}

int main() {
    Plugin plugin = load_plugin("evil_plugin.so");
    execute_plugin(plugin);
    unload_plugin(plugin);
    return 0;
}

// evil_plugin.so
#include <stdio.h>

void execute() {
    char* secret_flag = getenv("SECRET_FLAG");
    printf("The secret flag is: %s\n", secret_flag);
}
