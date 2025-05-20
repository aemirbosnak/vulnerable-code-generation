//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

// Function to validate user input
int validateInput(int input, int min, int max) {
    if (input < min) {
        return min;
    } else if (input > max) {
        return max;
    } else {
        return input;
    }
}

int main() {
    int droneSpeed = 0;
    int armStatus = 0;
    int mode = 1;

    while(1) {
        // Print menu
        printf("Welcome to the drone control console!\n");
        printf("Current drone speed: %d\n", droneSpeed);
        printf("Arm status: %d\n", armStatus);
        printf("Mode: %d\n", mode);
        printf("Menu:\n");
        printf("1. Increase speed\n");
        printf("2. Decrease speed\n");
        printf("3. Arm the drone\n");
        printf("4. Disarm the drone\n");
        printf("5. Change mode\n");
        printf("6. Exit\n");

        // Get user input
        int input;
        scanf("%d", &input);

        switch(input) {
            case 1:
                // Increase speed
                droneSpeed = validateInput(droneSpeed + 10, MIN_SPEED, MAX_SPEED);
                break;
            case 2:
                // Decrease speed
                droneSpeed = validateInput(droneSpeed - 10, MIN_SPEED, MAX_SPEED);
                break;
            case 3:
                // Arm the drone
                if (mode == 1) {
                    armStatus = 1;
                } else {
                    printf("Cannot arm the drone in autonomous mode\n");
                }
                break;
            case 4:
                // Disarm the drone
                armStatus = 0;
                break;
            case 5:
                // Change mode
                if (armStatus == 0) {
                    printf("Cannot change mode while drone is disarmed\n");
                } else {
                    printf("Please enter new mode: ");
                    scanf("%d", &mode);
                }
                break;
            case 6:
                // Exit program
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                // Invalid input
                printf("Invalid input\n");
                break;
        }
    }
}