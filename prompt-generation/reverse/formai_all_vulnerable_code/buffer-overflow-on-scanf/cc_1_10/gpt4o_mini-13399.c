//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int isFlying;
    int positionX;
    int positionY;
    int orientation; // in degrees (0=North, 90=East, 180=South, 270=West)
} Drone;

void takeOff(Drone* drone) {
    if (drone->isFlying) {
        printf("The drone is already in the air!\n");
    } else {
        drone->isFlying = 1;
        printf("The drone has taken off!\n");
    }
}

void land(Drone* drone) {
    if (!drone->isFlying) {
        printf("The drone is already on the ground!\n");
    } else {
        drone->isFlying = 0;
        printf("The drone has landed!\n");
    }
}

void moveForward(Drone* drone) {
    if (!drone->isFlying) {
        printf("The drone must be in the air to move!\n");
        return;
    }

    switch (drone->orientation) {
        case 0: // North
            drone->positionY += 1;
            break;
        case 90: // East
            drone->positionX += 1;
            break;
        case 180: // South
            drone->positionY -= 1;
            break;
        case 270: // West
            drone->positionX -= 1;
            break;
        default:
            break;
    }
    printf("The drone moved forward to (%d, %d)\n", drone->positionX, drone->positionY);
}

void moveBackward(Drone* drone) {
    if (!drone->isFlying) {
        printf("The drone must be in the air to move!\n");
        return;
    }

    switch (drone->orientation) {
        case 0: // North
            drone->positionY -= 1;
            break;
        case 90: // East
            drone->positionX -= 1;
            break;
        case 180: // South
            drone->positionY += 1;
            break;
        case 270: // West
            drone->positionX += 1;
            break;
        default:
            break;
    }
    printf("The drone moved backward to (%d, %d)\n", drone->positionX, drone->positionY);
}

void rotate(Drone* drone, int degrees) {
    drone->orientation = (drone->orientation + degrees) % 360;
    printf("The drone is now facing %d degrees.\n", drone->orientation);
}

void showStatus(Drone* drone) {
    if (drone->isFlying) {
        printf("The drone is flying at position (%d, %d) facing %d degrees.\n", 
                 drone->positionX, drone->positionY, drone->orientation);
    } else {
        printf("The drone is on the ground at position (%d, %d) facing %d degrees.\n", 
                 drone->positionX, drone->positionY, drone->orientation);
    }
}

int main() {
    Drone myDrone = {0, 0, 0, 0}; // Initialize drone
    char command[20];

    printf("Welcome to the Drone Remote Control!\n");

    while (1) {
        printf("\nEnter command (takeoff, land, forward, backward, rotate, status, exit): ");
        scanf("%s", command);

        if (strcmp(command, "takeoff") == 0) {
            takeOff(&myDrone);
        } else if (strcmp(command, "land") == 0) {
            land(&myDrone);
        } else if (strcmp(command, "forward") == 0) {
            moveForward(&myDrone);
        } else if (strcmp(command, "backward") == 0) {
            moveBackward(&myDrone);
        } else if (strcmp(command, "rotate") == 0) {
            int degrees;
            printf("Enter degrees to rotate (positive=right, negative=left): ");
            scanf("%d", &degrees);
            rotate(&myDrone, degrees);
        } else if (strcmp(command, "status") == 0) {
            showStatus(&myDrone);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting..\n");
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }

    return 0;
}