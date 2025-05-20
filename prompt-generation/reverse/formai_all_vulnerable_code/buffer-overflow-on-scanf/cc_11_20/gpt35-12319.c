//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DRONE_MIN_HEIGHT 0
#define DRONE_MAX_HEIGHT 10

int main(void) {
    bool isFlying = false;
    int droneHeight = DRONE_MIN_HEIGHT;

    printf("Welcome to Drone Remote Control System\n");
    printf("-------------------------------------\n");

    while (true) {
        printf("Current Status: %s. Current Height: %dm\n", isFlying ? "Flying" : "Landed", droneHeight);
        printf("Select an action: \n");
        printf("1. Takeoff/Land\n");
        printf("2. Increase Height\n");
        printf("3. Decrease Height\n");
        printf("4. Exit\n");

        int userChoice;
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: {
                if (isFlying) {
                    printf("Landing...\n");
                    droneHeight = DRONE_MIN_HEIGHT;
                    isFlying = false;
                } else {
                    printf("Taking off...\n");
                    droneHeight++;
                    isFlying = true;
                }
                break;
            }
            case 2: {
                if (!isFlying) {
                    printf("The drone is landed. Takeoff first.\n");
                    break;
                }
                if (droneHeight == DRONE_MAX_HEIGHT) {
                    printf("Reached maximum height.\n");
                    break;
                } 
                printf("Increasing height...\n");
                droneHeight++;
                break;
            }
            case 3: {
                if (!isFlying) {
                    printf("The drone is landed. Takeoff first.\n");
                    break;
                }
                if (droneHeight == DRONE_MIN_HEIGHT) {
                    printf("Already at minimum height.\n");
                    break;
                } 
                printf("Decreasing height...\n");
                droneHeight--;
                break;
            }
            case 4: {
                printf("Exiting... \n");
                exit(0);
            }
            default: {
                printf("Invalid option. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}