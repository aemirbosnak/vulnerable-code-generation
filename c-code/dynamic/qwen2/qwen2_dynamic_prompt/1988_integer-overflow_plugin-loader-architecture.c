#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGINS 10

typedef struct {
    int id;
    char name[256];
} Plugin;

Plugin plugins[MAX_PLUGINS];

int load_plugins(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return -1;

    int count = 0;
    while (count < MAX_PLUGINS && fscanf(file, "%d %s", &plugins[count].id, plugins[count].name) == 2) {
        count++;
    }

    fclose(file);
    return count;
}

void execute_plugins(int num_plugins) {
    for (int i = 0; i < num_plugins; i++) {
        printf("Executing plugin: %s\n", plugins[i].name);
        // Simulate plugin execution
        int result = plugins[i].id * 1000; // Integer overflow vulnerability here
        printf("Result: %d\n", result);
    }
}

int main() {
    const char* plugin_file = "plugins.txt";
    int num_plugins = load_plugins(plugin_file);

    if (num_plugins == -1) {
        fprintf(stderr, "Failed to load plugins.\n");
        return 1;
    }

    execute_plugins(num_plugins);

    return 0;
}
