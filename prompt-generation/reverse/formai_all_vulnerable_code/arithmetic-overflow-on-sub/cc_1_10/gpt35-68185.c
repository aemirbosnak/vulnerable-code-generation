//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int droneSpeed, droneAltitude, droneDirection;
    char command;

    printf("Welcome to the C Drone Remote Control!\n");

    printf("Please enter the initial speed of the drone (in kmph): ");
    scanf("%d", &droneSpeed);

    printf("Please enter the initial altitude of the drone (in meters): ");
    scanf("%d", &droneAltitude);

    printf("Please enter the initial direction of the drone (in degrees North): ");
    scanf("%d", &droneDirection);

    printf("Drone initialized. Speed: %d kmph, Altitude: %d meters, Direction: %d degrees North.\n", droneSpeed, droneAltitude, droneDirection);

    while (1) {
        printf("Enter command (F/B/U/D/L/R/Q): ");
        scanf(" %c", &command);
        switch (command) {
            case 'F':
                droneAltitude += droneSpeed;
                printf("Drone moving forward. New altitude: %d meters.\n", droneAltitude);
                break;
            case 'B':
                droneAltitude -= droneSpeed;
                printf("Drone moving backward. New altitude: %d meters.\n", droneAltitude);
                break;
            case 'U':
                droneAltitude += 100;
                printf("Drone going up 100 meters. New altitude: %d meters.\n", droneAltitude);
                break;
            case 'D':
                droneAltitude -= 100;
                printf("Drone going down 100 meters. New altitude: %d meters.\n", droneAltitude);
                break;
            case 'L':
                droneDirection -= 10;
                printf("Drone turning left 10 degrees. New direction: %d degrees North.\n", droneDirection);
                break;
            case 'R':
                droneDirection += 10;
                printf("Drone turning right 10 degrees. New direction: %d degrees North.\n", droneDirection);
                break;
            case 'Q':
                printf("Quitting program. Thank you for using the C Drone Remote Control!\n");
                return 0;
            default:
                printf("Invalid command. Please choose from F/B/U/D/L/R/Q.\n");
                break;
        }
    }

    return 0;
}