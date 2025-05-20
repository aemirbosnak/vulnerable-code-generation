#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_BUFFER_SIZE 16

typedef struct {
    char name[32];
    void (*execute)();
} Plugin;

void execute_plugin(Plugin *plugin) {
    printf("Executing plugin: %s\n", plugin->name);
    plugin->execute();
}

int main() {
    Plugin plugins[10];
    int num_plugins = 0;
    char buffer[PLUGIN_BUFFER_SIZE];

    while (num_plugins < 10) {
        printf("Enter plugin name (or 'exit' to finish): ");
        fgets(buffer, sizeof(buffer), stdin);

        if (buffer[0] == 'e' && buffer[1] == 'x' && buffer[2] == 'i' && buffer[3] == 't') {
            break;
        }

        if (num_plugins >= 10) {
            printf("Too many plugins!\n");
            continue;
        }

        plugins[num_plugins].name[0] = '\0';
        strncpy(plugins[num_plugins].name, buffer, sizeof(plugins[num_plugins].name) - 1);
        plugins[num_plugins].name[sizeof(plugins[num_plugins].name) - 1] = '\0';

        printf("Enter plugin function address: ");
        scanf("%p", &plugins[num_plugins].execute);
        getchar(); // Consume newline character left by scanf

        num_plugins++;
    }

    for (int i = 0; i < num_plugins; i++) {
        execute_plugin(&plugins[i]);
    }

    return 0;
}
