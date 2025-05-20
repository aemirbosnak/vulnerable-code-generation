//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_LIGHTS 10

// Light structure definition
typedef struct {
    char name[50];
    bool isOn;
} Light;

// Function prototypes
void initializeLights(Light lights[]);
void printLightStatus(Light light);
void processCommand(char command[], Light lights[]);

int main() {
    Light lights[MAX_LIGHTS];
    initializeLights(lights);

    char command[MAX_COMMAND_LENGTH];
    while (true) {
        printf("Enter a command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        processCommand(command, lights);
    }

    return 0;
}

void initializeLights(Light lights[]) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].isOn = false;
        strcpy(lights[i].name, "Light ");
        int num = i + 1;
        char numStr[3];
        sprintf(numStr, "%d", num);
        strcat(lights[i].name, numStr);
    }
}

void printLightStatus(Light light) {
    if (light.isOn) {
        printf("%s is on\n", light.name);
    } else {
        printf("%s is off\n", light.name);
    }
}

void processCommand(char command[], Light lights[]) {
    char *token = strtok(command, " ");
    if (token == NULL) {
        return;
    }

    if (strcmp(token, "on") == 0 || strcmp(token, "ON") == 0) {
        strtok(NULL, " "); // Skip the light name
        for (int i = 0; i < MAX_LIGHTS; i++) {
            if (strcmp(lights[i].name, token) == 0) {
                lights[i].isOn = true;
                printf("%s turned on\n", token);
                break;
            }
        }
    } else if (strcmp(token, "off") == 0 || strcmp(token, "OFF") == 0) {
        strtok(NULL, " "); // Skip the light name
        for (int i = 0; i < MAX_LIGHTS; i++) {
            if (strcmp(lights[i].name, token) == 0) {
                lights[i].isOn = false;
                printf("%s turned off\n", token);
                break;
            }
        }
    } else {
        printf("Invalid command\n");
    }
}