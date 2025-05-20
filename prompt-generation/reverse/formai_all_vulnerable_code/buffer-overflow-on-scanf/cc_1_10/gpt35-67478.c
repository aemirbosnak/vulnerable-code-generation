//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the light modes
#define BRIGHT 1
#define DIM 2
#define OFF 3

// Define function prototypes
void turnOn();
void turnOff();
void setBrightness(int level);
void randomMode();

int main() {

    // Use the time as seed for random number generator
    srand(time(NULL));

    // Start with lights off
    int currentMode = OFF;

    // Loop for accepting user input
    while (1) {
        printf("Enter a command (on, off, bright [0-10], dim [0-10], random): ");
        char command[10];
        scanf("%s", command);

        // Turn on the lights
        if (strcmp(command, "on") == 0) {
            turnOn();
            currentMode = BRIGHT; // Set default mode to bright
        }

        // Turn off the lights
        else if (strcmp(command, "off") == 0) {
            turnOff();
            currentMode = OFF;
        }

        // Set the brightness to a specific level
        else if (strcmp(command, "bright") == 0) {
            int level;
            scanf("%d", &level);
            setBrightness(level);
            currentMode = BRIGHT;
        }

        // Dim the lights to a specific level
        else if (strcmp(command, "dim") == 0) {
            int level;
            scanf("%d", &level);
            setBrightness(level);
            currentMode = DIM;
        }

        // Set random light mode
        else if (strcmp(command, "random") == 0) {
            randomMode();
        }

        // Error handling for invalid commands
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

// Turns on the lights
void turnOn() {
    printf("Lights turned on.\n");
}

// Turns off the lights
void turnOff() {
    printf("Lights turned off.\n");
}

// Sets the brightness of the lights
void setBrightness(int level) {
    printf("Brightness set to %d.\n", level);
}

// Sets a random light mode
void randomMode() {
    int mode = rand() % 3 + 1;
    switch (mode) {
        case BRIGHT:
            printf("Bright mode activated.\n");
            break;
        case DIM:
            printf("Dim mode activated.\n");
            break;
        case OFF:
            printf("Lights turned off.\n");
            break;
    }
}