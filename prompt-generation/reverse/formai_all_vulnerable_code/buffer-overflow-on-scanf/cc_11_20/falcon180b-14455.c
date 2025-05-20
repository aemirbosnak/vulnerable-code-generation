//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_SIZE 32
#define MAX_LIGHTS 10

typedef struct {
    char name[MAX_COMMAND_SIZE];
    int value;
} command_t;

typedef struct {
    char name[MAX_COMMAND_SIZE];
    int status;
} light_t;

int main() {
    light_t lights[MAX_LIGHTS];
    int num_lights = 0;
    int i;

    // Initialize lights
    for (i = 0; i < MAX_LIGHTS; i++) {
        lights[i].status = 0;
    }

    // Add lights
    while (num_lights < MAX_LIGHTS) {
        printf("Enter name of light: ");
        scanf("%s", lights[num_lights].name);
        printf("Enter status (0/1): ");
        scanf("%d", &lights[num_lights].status);
        num_lights++;
    }

    // Main loop
    while (1) {
        printf("Enter command: ");
        scanf("%s", lights[0].name);

        if (strcmp(lights[0].name, "turn on") == 0) {
            for (i = 0; i < num_lights; i++) {
                lights[i].status = 1;
            }
        } else if (strcmp(lights[0].name, "turn off") == 0) {
            for (i = 0; i < num_lights; i++) {
                lights[i].status = 0;
            }
        } else if (strcmp(lights[0].name, "set") == 0) {
            printf("Enter name of light: ");
            scanf("%s", lights[0].name);
            printf("Enter status (0/1): ");
            scanf("%d", &lights[0].status);
        } else if (strcmp(lights[0].name, "status") == 0) {
            for (i = 0; i < num_lights; i++) {
                printf("%s: %d\n", lights[i].name, lights[i].status);
            }
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}