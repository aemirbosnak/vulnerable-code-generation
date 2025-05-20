//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights that can be controlled
#define MAX_LIGHTS 10

// Define the structure for each light
typedef struct {
    char name[20];
    int status; // 0 = off, 1 = on
} Light;

// Define the main function
int main() {
    // Initialize an array of lights
    Light lights[MAX_LIGHTS];

    // Initialize the lights with default values
    for (int i = 0; i < MAX_LIGHTS; i++) {
        strcpy(lights[i].name, "Light ");
        lights[i].status = 0;
    }

    // Print the initial state of the lights
    printf("The lights are currently:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s %s\n", lights[i].name, lights[i].status? "on" : "off");
    }

    // Prompt the user to enter a command
    char command[50];
    printf("Enter a command (turn on/off light name): ");
    scanf("%s", command);

    // Parse the command and update the light status
    int lightIndex = -1;
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (strcmp(lights[i].name, command) == 0) {
            lightIndex = i;
            break;
        }
    }
    if (lightIndex!= -1) {
        if (strcmp(command, "turn on") == 0 || strcmp(command, "on") == 0) {
            lights[lightIndex].status = 1;
        }
        else if (strcmp(command, "turn off") == 0 || strcmp(command, "off") == 0) {
            lights[lightIndex].status = 0;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    else {
        printf("Light not found.\n");
    }

    // Print the updated state of the lights
    printf("The lights are currently:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s %s\n", lights[i].name, lights[i].status? "on" : "off");
    }

    return 0;
}