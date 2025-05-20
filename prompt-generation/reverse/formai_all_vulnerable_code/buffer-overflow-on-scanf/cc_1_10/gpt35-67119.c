//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 20
#define MAX_DRONE_DISTANCE 1000

int droneX = 0;
int droneY = 0;
int distance = 0;

void printStatus() {
    printf("Drone Location: (%d,%d) - Distance from origin: %d\n", droneX, droneY, distance);
}

void moveDrone(char command[]){
    if (strcmp(command, "left") == 0) {
        droneX--;
        distance++;
    } else if (strcmp(command, "right") == 0) {
        droneX++;
        distance++;
    } else if (strcmp(command, "up") == 0) {
        droneY++;
        distance++;
    } else if (strcmp(command, "down") == 0) {
        droneY--;
        distance++;
    }
}

int main() {
    printf("Welcome to Retro Drone Remote Control\n");
    printf("Commands: left, right, up, down, status, exit\n");
    printf("Distance is limited to %d units away from origin\n\n", MAX_DRONE_DISTANCE);
    printStatus();

    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else if (strcmp(command, "status") == 0) {
            printStatus();
        } else {
            moveDrone(command);
            if (distance > MAX_DRONE_DISTANCE) {
                printf("Drone has gone too far from origin!\n");
                break;
            }
            printStatus();
        }
    }

    return 0;
}