//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing random number generator
    srand(time(NULL));

    // Defining drone's initial coordinates
    int droneX = 0;
    int droneY = 0;

    // Defining remote control's joystick values
    int joystickX = 0;
    int joystickY = 0;

    // Opening communication with the drone
    printf("Opening communication with the drone...\n");

    // Main control loop
    while(1) {
        // Reading joystick values
        printf("Please enter joystick X position: ");
        scanf("%d", &joystickX);
        printf("Please enter joystick Y position: ");
        scanf("%d", &joystickY);

        // Calculating drone's new coordinates
        droneX += joystickX;
        droneY += joystickY;

        // Checking boundaries
        if(droneX < -100 || droneX > 100) {
            printf("Drone crashed into a wall! Game over.\n");
            break;
        }
        if(droneY < -100 || droneY > 100) {
            printf("Drone crashed into a wall! Game over.\n");
            break;
        }

        // Checking altitude randomly
        int altitude = rand() % 200;
        if(altitude > 170) {
            printf("Drone is flying too high! Game over.\n");
            break;
        }

        // Printing drone's status
        printf("Drone current position: %d, %d, altitude: %d\n", droneX, droneY, altitude);

        // Asking user if they want to continue
        printf("Do you want to continue controlling the drone? (y/n): ");
        char choice[10];
        scanf("%s", choice);
        if(choice[0] == 'n') {
            printf("Closing communication with the drone...\n");
            break;
        }
    }

    return 0;
}