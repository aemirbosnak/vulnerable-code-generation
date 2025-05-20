#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    char *name;
} GameObject;

GameObject* create_object(const char *name) {
    GameObject *obj = (GameObject *)malloc(sizeof(GameObject));
    obj->name = strdup(name);
    return obj;
}

void destroy_object(GameObject *obj) {
    if (obj != NULL) {
        free(obj->name);
        free(obj);
    }
}

int main() {
    GameObject *player = create_object("Player");
    printf("Welcome, %s!\n", player->name);

    // Simulate some game logic
    while (1) {
        char command[MAX_COMMAND_LENGTH];
        printf("> ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "quit", 4) == 0) {
            break;
        } else if (strncmp(command, "destroy", 7) == 0) {
            destroy_object(player);
            player = NULL; // Object is now freed
        } else if (strncmp(command, "use", 3) == 0) {
            if (player != NULL) {
                printf("Using %s...\n", player->name); // Use-after-free vulnerability
            } else {
                printf("No object to use.\n");
            }
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
