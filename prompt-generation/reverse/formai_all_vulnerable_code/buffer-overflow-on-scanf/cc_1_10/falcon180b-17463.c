//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_LIGHTS 10
#define ON 1
#define OFF 0

typedef struct {
    char name[30];
    int status;
} Light;

void setLightStatus(Light* light, int status) {
    light->status = status;
}

int getLightStatus(Light* light) {
    return light->status;
}

void toggleLightStatus(Light* light) {
    if (light->status == ON) {
        setLightStatus(light, OFF);
    } else {
        setLightStatus(light, ON);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    Light lights[MAX_LIGHTS];

    int numLights = 0;
    while (numLights < MAX_LIGHTS) {
        printf("Enter the name of a light: ");
        scanf("%s", command);
        strcpy(lights[numLights].name, command);
        numLights++;
    }

    while (1) {
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "on") == 0) {
            for (int i = 0; i < numLights; i++) {
                toggleLightStatus(&lights[i]);
            }
        } else if (strcmp(command, "off") == 0) {
            for (int i = 0; i < numLights; i++) {
                toggleLightStatus(&lights[i]);
            }
        } else if (strcmp(command, "status") == 0) {
            printf("Light statuses:\n");
            for (int i = 0; i < numLights; i++) {
                if (getLightStatus(&lights[i]) == ON) {
                    printf("%s: ON\n", lights[i].name);
                } else {
                    printf("%s: OFF\n", lights[i].name);
                }
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}