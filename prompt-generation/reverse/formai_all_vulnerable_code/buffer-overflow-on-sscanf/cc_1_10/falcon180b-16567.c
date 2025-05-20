//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMMANDS 100
#define PI 3.14159265358979323846

// Define the remote control commands
typedef struct {
    char *name;
    int (*func)(int arg);
} Command;

void moveForward(int arg) {
    printf("Moving forward at %d units per second\n", arg);
}

void turnLeft(int arg) {
    printf("Turning left at %d degrees per second\n", arg);
}

void turnRight(int arg) {
    printf("Turning right at %d degrees per second\n", arg);
}

void stop(int arg) {
    printf("Stopping\n");
}

// Initialize the remote control commands
Command commands[MAX_COMMANDS] = {
    {"moveForward", moveForward},
    {"turnLeft", turnLeft},
    {"turnRight", turnRight},
    {"stop", stop}
};

int main() {
    // Simulate the remote control vehicle
    int speed = 0;
    int direction = 0;

    while (1) {
        printf("Enter a command (e.g. moveForward 50): ");
        char command[100];
        scanf("%s", command);

        // Parse the command
        int arg = 0;
        if (sscanf(command, "%s %d", command, &arg)!= 2) {
            printf("Invalid command\n");
            continue;
        }

        // Execute the command
        Command *cmd = NULL;
        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(command, commands[i].name) == 0) {
                cmd = &commands[i];
                break;
            }
        }
        if (cmd == NULL) {
            printf("Unknown command\n");
            continue;
        }
        cmd->func(arg);
    }

    return 0;
}