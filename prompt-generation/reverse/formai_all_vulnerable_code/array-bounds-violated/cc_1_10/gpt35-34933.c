//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DISTANCE 100

// Function to randomly generate a distance traveled by the vehicle
int generateRandomDistance() {
    srand(time(NULL));
    int distance = rand() % (MAX_DISTANCE + 1); // Generate a random distance between 0 and MAX_DISTANCE
    return distance;
}

// Function to simulate the remote control vehicle
void simulateRCVehicle() {
    char command[10];
    int distance = 0;
    int batteryRemaining = 100;

    printf("Welcome to the Medieval RC Vehicle Simulation!\n");
    printf("Here are the available commands:\n");
    printf("forward <distance>\n");
    printf("back <distance>\n");
    printf("left <degrees>\n");
    printf("right <degrees>\n");
    printf("battery\n");
    printf("exit\n");

    while (1) {
        printf("Enter a command: ");
        fgets(command, 10, stdin);
        command[strlen(command) - 1] = '\0'; // Remove newline character

        if (strncmp(command, "forward", 7) == 0) {
            char* pEnd;
            int d = strtol(&command[8], &pEnd, 10); // Get the distance from the command
            if (d < 0) {
                printf("Invalid command: distance must be positive.\n");
            } else if (batteryRemaining < d / 10) {
                printf("Cannot run forward command: battery low.\n");
            } else {
                distance += d;
                batteryRemaining -= d / 10;
                printf("Vehicle moved forward %d meters.\n", d);
                printf("Total distance traveled: %d meters.\n", distance);
                printf("Battery remaining: %d%%.\n", batteryRemaining);
            }
        } else if (strncmp(command, "back", 4) == 0) {
            char* pEnd;
            int d = strtol(&command[5], &pEnd, 10); // Get the distance from the command
            if (d < 0) {
                printf("Invalid command: distance must be positive.\n");
            } else if (distance - d < 0) {
                printf("Cannot run back command: the vehicle has not traveled that far yet.\n");
            } else {
                distance -= d;
                batteryRemaining -= d / 10;
                printf("Vehicle moved back %d meters.\n", d);
                printf("Total distance traveled: %d meters.\n", distance);
                printf("Battery remaining: %d%%.\n", batteryRemaining);
            }
        } else if (strncmp(command, "left", 4) == 0) {
            char* pEnd;
            int d = strtol(&command[5], &pEnd, 10); // Get the degrees from the command
            if (d < 0 || d > 360) {
                printf("Invalid command: degrees must be between 0 and 360.\n");
            } else {
                printf("Vehicle turned left %d degrees.\n", d);
            }
        } else if (strncmp(command, "right", 5) == 0) {
            char* pEnd;
            int d = strtol(&command[6], &pEnd, 10); // Get the degrees from the command
            if (d < 0 || d > 360) {
                printf("Invalid command: degrees must be between 0 and 360.\n");
            } else {
                printf("Vehicle turned right %d degrees.\n", d);
            }
        } else if (strncmp(command, "battery", 7) == 0) {
            printf("Battery remaining: %d%%.\n", batteryRemaining);
        } else if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting simulation.\n");
            break;
        } else {
            printf("Unknown command.\n");
        }

        // Randomly generate a distance if the vehicle has not moved in a while
        if (distance == 0) {
            distance = generateRandomDistance();
            printf("Vehicle moved forward %d meters.\n", distance);
            printf("Total distance traveled: %d meters.\n", distance);
        }
    }
}

int main() {
    simulateRCVehicle();
    return 0;
}