#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGINS 10

typedef struct {
    int id;
    char name[20];
} Plugin;

Plugin plugins[MAX_PLUGINS];

void load_plugins() {
    FILE *file = fopen("plugins.txt", "r");
    if (!file) {
        perror("Failed to open plugins file");
        return;
    }

    int i = 0;
    while (i < MAX_PLUGINS && fscanf(file, "%d %s", &plugins[i].id, plugins[i].name) == 2) {
        i++;
    }
    fclose(file);
}

void execute_plugin(int index) {
    if (index >= 0 && index < MAX_PLUGINS) {
        printf("Executing plugin: %s\n", plugins[index].name);
        // Simulate plugin execution
        // This is where the vulnerability could occur
        int *data = malloc(sizeof(int));
        *data = plugins[index].id; // Dereference failure here
        free(data);
    } else {
        printf("Invalid plugin index\n");
    }
}

int main() {
    load_plugins();

    int choice;
    printf("Available plugins:\n");
    for (int i = 0; i < MAX_PLUGINS; i++) {
        printf("%d: %s\n", plugins[i].id, plugins[i].name);
    }

    printf("Enter plugin index to execute: ");
    scanf("%d", &choice);

    execute_plugin(choice);

    return 0;
}
