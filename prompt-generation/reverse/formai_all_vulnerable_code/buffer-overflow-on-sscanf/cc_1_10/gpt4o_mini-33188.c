//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 256

typedef struct {
    bool isFlying;
    float altitude;
    float positionX;
    float positionY;
    float speed;
} Drone;

void initDrone(Drone* drone) {
    drone->isFlying = false;
    drone->altitude = 0.0;
    drone->positionX = 0.0;
    drone->positionY = 0.0;
    drone->speed = 0.0;
}

void takeOff(Drone* drone) {
    if (!drone->isFlying) {
        drone->isFlying = true;
        drone->altitude = 10.0;  // Takeoff to an initial altitude of 10 meters
        printf("Drone has taken off. Current altitude: %.2f meters\n", drone->altitude);
    } else {
        printf("Drone is already flying!\n");
    }
}

void land(Drone* drone) {
    if (drone->isFlying) {
        drone->altitude = 0.0;
        drone->isFlying = false;
        printf("Drone has landed.\n");
    } else {
        printf("Drone is already on the ground!\n");
    }
}

void moveForward(Drone* drone) {
    if (drone->isFlying) {
        drone->positionY += drone->speed;
        printf("Drone moved forward. Current Y position: %.2f\n", drone->positionY);
    } else {
        printf("Drone needs to take off before moving!\n");
    }
}

void moveBackward(Drone* drone) {
    if (drone->isFlying) {
        drone->positionY -= drone->speed;
        printf("Drone moved backward. Current Y position: %.2f\n", drone->positionY);
    } else {
        printf("Drone needs to take off before moving!\n");
    }
}

void moveLeft(Drone* drone) {
    if (drone->isFlying) {
        drone->positionX -= drone->speed;
        printf("Drone moved left. Current X position: %.2f\n", drone->positionX);
    } else {
        printf("Drone needs to take off before moving!\n");
    }
}

void moveRight(Drone* drone) {
    if (drone->isFlying) {
        drone->positionX += drone->speed;
        printf("Drone moved right. Current X position: %.2f\n", drone->positionX);
    } else {
        printf("Drone needs to take off before moving!\n");
    }
}

void updateSpeed(Drone* drone, float newSpeed) {
    drone->speed = newSpeed;
    printf("Drone speed updated to: %.2f m/s\n", drone->speed);
}

void displayStatus(Drone* drone) {
    printf("Drone Status:\n");
    printf("Flying: %s\n", drone->isFlying ? "Yes" : "No");
    printf("Altitude: %.2f meters\n", drone->altitude);
    printf("Position: (%.2f, %.2f)\n", drone->positionX, drone->positionY);
    printf("Speed: %.2f m/s\n", drone->speed);
}

int main() {
    Drone myDrone;
    initDrone(&myDrone);
    
    char command[MAX_COMMAND_LENGTH];

    printf("Welcome to the Drone Remote Control System!\n");

    while (true) {
        printf("\nEnter a command (takeoff, land, forward, backward, left, right, speed <value>, status, exit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // remove newline character

        if (strcmp(command, "takeoff") == 0) {
            takeOff(&myDrone);
        } else if (strcmp(command, "land") == 0) {
            land(&myDrone);
        } else if (strcmp(command, "forward") == 0) {
            moveForward(&myDrone);
        } else if (strcmp(command, "backward") == 0) {
            moveBackward(&myDrone);
        } else if (strcmp(command, "left") == 0) {
            moveLeft(&myDrone);
        } else if (strcmp(command, "right") == 0) {
            moveRight(&myDrone);
        } else if (strncmp(command, "speed", 5) == 0) {
            float newSpeed;
            if (sscanf(command + 6, "%f", &newSpeed) == 1) {
                updateSpeed(&myDrone, newSpeed);
            } else {
                printf("Invalid speed value.\n");
            }
        } else if (strcmp(command, "status") == 0) {
            displayStatus(&myDrone);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Drone Remote Control System.\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}