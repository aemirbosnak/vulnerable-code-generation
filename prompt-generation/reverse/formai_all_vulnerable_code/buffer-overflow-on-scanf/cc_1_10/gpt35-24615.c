//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_ANGLE 180
#define MIN_ANGLE 0

void validateInput(int *var, int max, int min) {
    while (*var > max || *var < min) {
        printf("Invalid input, please enter a value between %d and %d: ", min, max);
        scanf("%d", var);
    }
}

int main() {
    int speed = 0;
    int angle = 0;

    printf("Welcome to the C Drone Remote Control program!\n\n");

    printf("Please enter the speed (0-100): ");
    scanf("%d", &speed);
    validateInput(&speed, MAX_SPEED, MIN_SPEED);

    printf("\nPlease enter the angle (0-180): ");
    scanf("%d", &angle);
    validateInput(&angle, MAX_ANGLE, MIN_ANGLE);

    printf("Speed: %d%%\nAngle: %d degrees\n", speed, angle);

    printf("\nConnecting to drone...\n");
    // Code to connect to the drone
    printf("Connection successful! Drone ready for operation.\n\n");

    int choice = 0;
    while (choice != 4) {
        printf("Please choose an action:\n");
        printf("1. Change speed\n");
        printf("2. Change angle\n");
        printf("3. Fly drone\n");
        printf("4. Quit program\n");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPlease enter the new speed (0-100): ");
                scanf("%d", &speed);
                validateInput(&speed, MAX_SPEED, MIN_SPEED);
                printf("Speed set to %d%%.\n\n", speed);
                break;
            case 2:
                printf("\nPlease enter the new angle (0-180): ");
                scanf("%d", &angle);
                validateInput(&angle, MAX_ANGLE, MIN_ANGLE);
                printf("Angle set to %d degrees.\n\n", angle);
                break;
            case 3:
                printf("\nFlying drone with speed %d%% and angle %d degrees...\n", speed, angle);
                // Code to fly the drone with the given speed and angle
                printf("Drone flying.\n\n");
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid input, please choose a valid option.\n");
        }
    }

    printf("Program terminated.");

    return 0;
}