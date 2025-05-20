//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: genious
#include <stdio.h>

/* Declare global variable for drone status */
int droneStatus;

/* Function to initialize the drone */
void initDrone() {
    droneStatus = 0;
    printf("Drone initialized.\n");
}

/* Function to take off the drone */
void takeOff() {
    if (droneStatus == 0) {
        droneStatus = 1;
        printf("Drone has taken off.\n");
    }
    else {
        printf("Drone is already in the air.\n");
    }
}

/* Function to land the drone */
void land() {
    if (droneStatus != 0) {
        droneStatus = 0;
        printf("Drone has landed.\n");
    }
    else {
        printf("Drone is already on the ground.\n");
    }
}

/* Function to move the drone forward */
void moveForward() {
    if (droneStatus == 1) {
        printf("Drone is moving forward.\n");
    }
    else {
        printf("Drone needs to be in the air to move.\n");
    }
}

/* Function to move the drone backward */
void moveBackward() {
    if (droneStatus == 1) {
        printf("Drone is moving backward.\n");
    }
    else {
        printf("Drone needs to be in the air to move.\n");
    }
}

int main() {
    initDrone();

    int input;
    do {
        printf("\nDrone Control - Enter a command:\n");
        printf("1 - Take off\n");
        printf("2 - Land\n");
        printf("3 - Move forward\n");
        printf("4 - Move backward\n");
        printf("5 - Exit\n");
        scanf("%d", &input);

        switch (input) {
            case 1:
                takeOff();
                break;
            case 2:
                land();
                break;
            case 3:
                moveForward();
                break;
            case 4:
                moveBackward();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    } while (input != 5);

    return 0;
}