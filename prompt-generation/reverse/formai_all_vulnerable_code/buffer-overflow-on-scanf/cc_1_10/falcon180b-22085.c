//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

// Drone remote control commands
char commands[MAX_COMMANDS][MAX_COMMAND_LENGTH] = {
    "Take off",
    "Land",
    "Move forward",
    "Move backward",
    "Move left",
    "Move right",
    "Rotate left",
    "Rotate right",
    "Increase altitude",
    "Decrease altitude"
};

int main() {
    int numCommands;
    char input[MAX_COMMAND_LENGTH];

    // Get number of commands from user
    printf("Enter number of commands: ");
    scanf("%d", &numCommands);

    // Loop through each command
    for (int i = 0; i < numCommands; i++) {
        // Get command from user
        printf("Enter command %d: ", i+1);
        scanf("%s", input);

        // Check if command is valid
        int isValid = 0;
        for (int j = 0; j < MAX_COMMANDS; j++) {
            if (strcmp(input, commands[j]) == 0) {
                isValid = 1;
                break;
            }
        }

        // Send command to drone if valid
        if (isValid) {
            printf("Sending command: %s\n", input);
        } else {
            printf("Invalid command: %s\n", input);
        }
    }

    return 0;
}