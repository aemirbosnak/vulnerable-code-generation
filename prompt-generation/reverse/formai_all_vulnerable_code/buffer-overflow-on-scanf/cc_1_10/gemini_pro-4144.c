//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the states of the light bulb
typedef enum {
    OFF,
    ON,
    DIMMED
} LightState;

// Create a structure to represent the light bulb
typedef struct {
    char *name;
    LightState state;
    int brightness;
} LightBulb;

// Create a function to turn on the light bulb
void turnOn(LightBulb *bulb) {
    bulb->state = ON;
}

// Create a function to turn off the light bulb
void turnOff(LightBulb *bulb) {
    bulb->state = OFF;
}

// Create a function to dim the light bulb
void dim(LightBulb *bulb, int brightness) {
    bulb->state = DIMMED;
    bulb->brightness = brightness;
}

// Create a function to print the state of the light bulb
void printState(LightBulb *bulb) {
    switch (bulb->state) {
        case OFF:
            printf("The light bulb is off.\n");
            break;
        case ON:
            printf("The light bulb is on.\n");
            break;
        case DIMMED:
            printf("The light bulb is dimmed to %d%% brightness.\n", bulb->brightness);
            break;
    }
}

// Create a function to control the light bulb
void controlLightBulb(LightBulb *bulb, char *command) {
    if (strcmp(command, "on") == 0) {
        turnOn(bulb);
    } else if (strcmp(command, "off") == 0) {
        turnOff(bulb);
    } else if (strncmp(command, "dim", 3) == 0) {
        int brightness = atoi(command + 3);
        dim(bulb, brightness);
    } else {
        printf("Invalid command.\n");
    }
}

// Create a main function to test the light bulb
int main() {
    // Create a light bulb
    LightBulb bulb = {"Living Room Light", OFF, 0};

    // Get the user's input
    char command[100];
    printf("Enter a command for the light bulb (on, off, dim <brightness>): ");
    scanf("%s", command);

    // Control the light bulb
    controlLightBulb(&bulb, command);

    // Print the state of the light bulb
    printState(&bulb);

    return 0;
}