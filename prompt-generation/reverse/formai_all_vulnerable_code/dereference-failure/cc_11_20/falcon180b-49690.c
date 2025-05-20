//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    int value;
} Light;

int main() {
    Light lights[MAX_LIGHTS];
    int num_lights = 0;
    char input[MAX_COMMAND_LENGTH];

    // Initialize lights
    lights[0] = (Light) {.name = "Living Room",.value = 0};
    lights[1] = (Light) {.name = "Bedroom",.value = 0};
    lights[2] = (Light) {.name = "Kitchen",.value = 0};
    num_lights = 3;

    // Main loop
    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Parse command
        char *command = strtok(input, " ");
        if (command == NULL)
            continue;

        if (strcmp(command, "on") == 0) {
            char *light_name = strtok(NULL, " ");
            for (int i = 0; i < num_lights; i++) {
                if (strcmp(lights[i].name, light_name) == 0) {
                    lights[i].value = 1;
                    printf("Light %s turned on.\n", light_name);
                    break;
                }
            }
        } else if (strcmp(command, "off") == 0) {
            char *light_name = strtok(NULL, " ");
            for (int i = 0; i < num_lights; i++) {
                if (strcmp(lights[i].name, light_name) == 0) {
                    lights[i].value = 0;
                    printf("Light %s turned off.\n", light_name);
                    break;
                }
            }
        } else if (strcmp(command, "status") == 0) {
            for (int i = 0; i < num_lights; i++) {
                printf("Light %s is %s.\n", lights[i].name, lights[i].value? "on" : "off");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}