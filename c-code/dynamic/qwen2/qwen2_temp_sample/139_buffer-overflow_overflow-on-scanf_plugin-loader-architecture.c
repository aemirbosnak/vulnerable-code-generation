#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_BUFFER_SIZE 10

typedef struct {
    char buffer[PLUGIN_BUFFER_SIZE];
} Plugin;

void load_plugin(Plugin *plugin) {
    printf("Enter plugin data: ");
    scanf("%s", plugin->buffer);
}

int main() {
    Plugin plugins[2];
    int choice;

    while (1) {
        printf("\n1. Load Plugin\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            break;
        } else if (choice == 1) {
            load_plugin(&plugins[0]);
            printf("Plugin loaded successfully.\n");
        }
    }

    return 0;
}
