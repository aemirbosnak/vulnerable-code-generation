//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: innovative
#include <stdio.h>
#include <stdbool.h>

#define MAX_DISTANCE 1000 // maximum distance the drone can travel in meters

int main() {
    int distance_traveled = 0; // initialize distance traveled to 0
    int altitude = 0; // initialize altitude to ground level
    bool is_on = false; // initialize drone to off state
    char input;

    printf("Welcome to C Drone Remote Control!\n\n");
    printf("To turn on the drone, press 'o'\n");

    while (true) {
        scanf("%c", &input); // read user input

        if (input == 'o') {
            is_on = true;
            printf("Drone is now on. Current altitude: %d meters\n", altitude);
        }
        else if (input == 'f' && is_on) {
            // move forward
            if (distance_traveled + 10 <= MAX_DISTANCE) {
                distance_traveled += 10;
                printf("Drone has traveled forward 10 meters. Total distance traveled: %d meters\n", distance_traveled);
            } else {
                printf("Drone cannot move forward any further. Maximum distance reached.\n");
            }
        }
        else if (input == 'b' && is_on) {
            // move backward
            if (distance_traveled - 10 >= 0) {
                distance_traveled -= 10;
                printf("Drone has traveled backward 10 meters. Total distance traveled: %d meters\n", distance_traveled);
            } else {
                printf("Drone cannot move backward any further. Already at starting point.\n");
            }
        }
        else if (input == 'u' && is_on) {
            // increase altitude
            if (altitude + 10 <= 100) {
                altitude += 10;
                printf("Drone has increased altitude. Current altitude: %d meters\n", altitude);
            } else {
                printf("Drone cannot increase altitude any further. Maximum altitude reached.\n");
            }
        }
        else if (input == 'd' && is_on) {
            // decrease altitude
            if (altitude - 10 >= 0) {
                altitude -= 10;
                printf("Drone has decreased altitude. Current altitude: %d meters\n", altitude);
            } else {
                printf("Drone cannot decrease altitude any further. Already at ground level.\n");
            }
        }
        else if (input == 's' && is_on) {
            // stop drone
            printf("Drone has been stopped. Total distance traveled: %d meters. Current altitude: %d meters\n", distance_traveled, altitude);
            break; // exit program loop
        }
        else {
            printf("Invalid input. Try again.\n");
        }
    }

    printf("\nThank you for using C Drone Remote Control!\n");

    return 0;
}