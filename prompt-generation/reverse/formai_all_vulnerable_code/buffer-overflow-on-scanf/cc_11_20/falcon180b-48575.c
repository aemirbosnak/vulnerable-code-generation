//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIGHTS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    int value;
} Light;

int main() {
    int numLights;
    printf("Enter the number of lights: ");
    scanf("%d", &numLights);

    if (numLights > MAX_LIGHTS) {
        printf("Error: Maximum number of lights is %d\n", MAX_LIGHTS);
        return 1;
    }

    Light lights[numLights];
    for (int i = 0; i < numLights; i++) {
        printf("Enter the name of light %d: ", i+1);
        scanf("%s", lights[i].name);
        lights[i].value = 0;
    }

    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter a command (on/off/toggle light name): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        int lightIndex = -1;
        for (int i = 0; i < numLights; i++) {
            if (strcmp(lights[i].name, command) == 0) {
                lightIndex = i;
                break;
            }
        }

        if (lightIndex == -1) {
            printf("Error: Light not found\n");
            continue;
        }

        if (strcmp(command, "on") == 0) {
            lights[lightIndex].value = 1;
        } else if (strcmp(command, "off") == 0) {
            lights[lightIndex].value = 0;
        } else if (strcmp(command, "toggle") == 0) {
            lights[lightIndex].value =!lights[lightIndex].value;
        }
    }

    return 0;
}