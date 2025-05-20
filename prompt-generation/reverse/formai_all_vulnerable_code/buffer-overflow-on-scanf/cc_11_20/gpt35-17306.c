//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 100 // maximum speed of the drone
#define MIN_SPEED 0 // minimum speed of the drone
#define MAX_ANGLE 45 // maximum angle of the drone
#define MIN_ANGLE -45 // minimum angle of the drone

int main() {
    int speed = 0; // current speed of the drone
    int angle = 0; // current angle of the drone
    bool isFlying = false; // check if drone is flying

    char input; // stores user input

    printf("Welcome to the C Drone Remote Control Program!\n\n");

    while (true) {
        printf("Current speed: %d | Current angle: %d\n", speed, angle);
        printf("Select an option:\n");
        printf("1. Increase speed\n");
        printf("2. Decrease speed\n");
        printf("3. Increase angle\n");
        printf("4. Decrease angle\n");
        printf("5. Take off\n");
        printf("6. Land\n");
        printf("7. Exit program\n");

        scanf(" %c", &input); // takes user input

        switch (input) {
            case '1':
                if (speed < MAX_SPEED) { // if speed is less than maximum speed
                    speed++; // increase speed by 1
                } else {
                    printf("Cannot increase speed. Maximum speed reached.\n");
                }
                break;

            case '2':
                if (speed > MIN_SPEED) { // if speed is greater than minimum speed
                    speed--; // decrease speed by 1
                } else {
                    printf("Cannot decrease speed. Minimum speed reached.\n");
                }
                break;

            case '3':
                if (angle < MAX_ANGLE) { // if angle is less than maximum angle
                    angle++; // increase angle by 1
                } else {
                    printf("Cannot increase angle. Maximum angle reached.\n");
                }
                break;

            case '4':
                if (angle > MIN_ANGLE) { // if angle is greater than minimum angle
                    angle--; // decrease angle by 1
                } else {
                    printf("Cannot decrease angle. Minimum angle reached.\n");
                }
                break;

            case '5':
                if (isFlying) { // if drone is already flying
                    printf("Drone is already flying.\n");
                } else if (speed == MIN_SPEED) { // if speed is zero
                    printf("Cannot take off. Drone speed is zero.\n");
                } else {
                    isFlying = true; // drone is now flying
                    printf("Drone is now flying.\n");
                }
                break;

            case '6':
                if (!isFlying) { // if drone is already on ground
                    printf("Drone is already on ground.\n");
                } else {
                    isFlying = false; // drone is now on ground
                    printf("Drone has landed.\n");
                }
                break;

            case '7':
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}