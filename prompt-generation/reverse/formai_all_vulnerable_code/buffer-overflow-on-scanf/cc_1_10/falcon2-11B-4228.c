//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 50
#define MAX_REPORT 50

typedef struct {
    char command[MAX_COMMANDS];
    int state;
} Command;

Command commands[MAX_COMMANDS];

int main() {
    // Initialize commands
    memset(commands, 0, sizeof(commands));
    commands[0].command[0] = 'R';
    commands[0].state = 0;

    // Simulate the vehicle's movement
    while (1) {
        // Get user input
        printf("Enter command (R, L, F, B): ");
        scanf("%s", commands[1].command);

        // Execute the command
        switch (commands[1].command[0]) {
            case 'R':
                commands[1].state = 1;
                break;
            case 'L':
                commands[1].state = 2;
                break;
            case 'F':
                commands[1].state = 3;
                break;
            case 'B':
                commands[1].state = 4;
                break;
            default:
                printf("Invalid command!\n");
                break;
        }

        // Report the vehicle's state
        printf("Command executed: %c - State: %d\n", commands[1].command[0], commands[1].state);
    }

    return 0;
}