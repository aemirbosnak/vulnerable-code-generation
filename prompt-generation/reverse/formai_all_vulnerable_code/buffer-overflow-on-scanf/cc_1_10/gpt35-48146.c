//FormAI DATASET v1.0 Category: Smart home automation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void handleLight(char* command);
void handleTemperature(char* command);
void handleLock(char* command);

int main() {
    char input[50];
    int running = 1;

    printf("Welcome to Smart Home Automation.\n");
    printf("You can control the lights, temperature, and locks.\n");
    printf("Type 'help' to see a list of commands.\n");

    while(running) {
        // Get command input from user
        printf(">> ");
        scanf("%s", input);

        // Handle command
        if(strcmp(input, "help") == 0) {
            printf("List of commands:\n");
            printf("  - lights on\n");
            printf("  - lights off\n");
            printf("  - temperature up\n");
            printf("  - temperature down\n");
            printf("  - lock\n");
            printf("  - unlock\n");
        } else if(strcmp(input, "lights on") == 0 || strcmp(input, "lights off") == 0) {
            handleLight(input);
        } else if(strcmp(input, "temperature up") == 0 || strcmp(input, "temperature down") == 0) {
            handleTemperature(input);
        } else if(strcmp(input, "lock") == 0 || strcmp(input, "unlock") == 0) {
            handleLock(input);
        } else if(strcmp(input, "exit") == 0) {
            running = 0;
        } else {
            printf("Unknown command '%s', type 'help' to see a list of commands.\n", input);
        }
    }

    printf("Goodbye!\n");

    return 0;
}

// Light function
void handleLight(char* command) {
    if(strcmp(command, "lights on") == 0) {
        printf("Turning lights on...\n");
        // Code here to activate the lights
    } else {
        printf("Turning lights off...\n");
        // Code here to turn off the lights
    }
}

// Temperature function
void handleTemperature(char* command) {
    if(strcmp(command, "temperature up") == 0) {
        printf("Increasing temperature...\n");
        // Code here to increase the temperature
    } else {
        printf("Decreasing temperature..\n");
        // Code here to decrease the temperature
    }
}

// Lock function
void handleLock(char* command) {
    if(strcmp(command, "lock") == 0) {
        printf("Locking the door...\n");
        // Code here to activate the lock
    } else {
        printf("Unlocking the door...\n");
        // Code here to deactivate the lock
    }
}