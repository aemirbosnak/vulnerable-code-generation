//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define constants
#define MAX_COMMAND_LENGTH 20
#define MAX_DRONE_DISTANCE 100

// Declare functions
void printCommands();
void executeCommand(char* command, int* dronePosition);

// Entry point of program
int main() {
    int dronePosition[2] = {0, 0};

    printf("Welcome to C Drone Remote Control\n\n");

    while (true) {
        printf("Drone position: (%d, %d)\n", dronePosition[0], dronePosition[1]);
        printCommands();

        char command[MAX_COMMAND_LENGTH];
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting program...");
            break;
        }

        executeCommand(command, dronePosition);
    }

    return 0;
}

// Function to print the available commands
void printCommands() {
    printf("\nAvailable commands:\n");
    printf("up\n");
    printf("down\n");
    printf("left\n");
    printf("right\n");
    printf("exit\n");
}

// Function to execute a command
void executeCommand(char* command, int* dronePosition) {
    int x = dronePosition[0];
    int y = dronePosition[1];

    if (strcmp(command, "up") == 0) {
        y += 1;
    } else if (strcmp(command, "down") == 0) {
        y -= 1;
    } else if (strcmp(command, "left") == 0) {
        x -= 1;
    } else if (strcmp(command, "right") == 0) {
        x += 1;
    } else {
        printf("Invalid command, please try again.\n");
        return;
    }

    if (abs(x) > MAX_DRONE_DISTANCE || abs(y) > MAX_DRONE_DISTANCE) {
        printf("Drone is out of range, please enter another command.\n");
        return;
    }

    dronePosition[0] = x;
    dronePosition[1] = y;

    printf("Executed command: %s\n", command);
}