//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For sleep()

#define MAX_COMMAND_LENGTH 50

typedef struct Drone {
    int altitude;
    int positionX;
    int positionY;
    int isFlying;
} Drone;

void takeOff(Drone* drone) {
    if (drone->isFlying) {
        printf("Drone is already flying at an altitude of %d meters.\n", drone->altitude);
    } else {
        drone->altitude = 10;
        drone->isFlying = 1;
        printf("Drone is taking off... Current altitude: %d meters.\n", drone->altitude);
        sleep(1);
    }
}

void land(Drone* drone) {
    if (!drone->isFlying) {
        printf("Drone is already on the ground.\n");
    } else {
        drone->altitude = 0;
        drone->isFlying = 0;
        printf("Drone is landing... Current altitude: %d meters.\n", drone->altitude);
        sleep(1);
    }
}

void move(Drone* drone, int x, int y) {
    if (!drone->isFlying) {
        printf("Drone must be flying to move!\n");
        return;
    }
    drone->positionX += x;
    drone->positionY += y;
    printf("Drone moved to position (%d, %d).\n", drone->positionX, drone->positionY);
    sleep(1);
}

void status(Drone* drone) {
    printf("Drone status:\n");
    printf("Altitude: %d meters\n", drone->altitude);
    printf("Position: (%d, %d)\n", drone->positionX, drone->positionY);
    printf("Flying: %s\n", drone->isFlying ? "Yes" : "No");
}

void displayInstructions() {
    printf("Welcome to the Drone Remote Control System!\n");
    printf("Available commands:\n");
    printf("1. take off\n");
    printf("2. land\n");
    printf("3. move <x> <y>\n");
    printf("4. status\n");
    printf("5. exit\n");
    printf("Type your command: \n");
}

int main() {
    Drone drone = {0, 0, 0, 0}; // Initialize drone
    char command[MAX_COMMAND_LENGTH];
    int x, y;

    displayInstructions();

    while (1) {
        printf(">> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "take off") == 0) {
            takeOff(&drone);
        } else if (strcmp(command, "land") == 0) {
            land(&drone);
        } else if (sscanf(command, "move %d %d", &x, &y) == 2) {
            move(&drone, x, y);
        } else if (strcmp(command, "status") == 0) {
            status(&drone);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Drone Remote Control System. Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}