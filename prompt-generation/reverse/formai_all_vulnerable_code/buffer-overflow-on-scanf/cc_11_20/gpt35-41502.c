//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    // initialize variables
    char input;
    int altitude = 0;
    int speed = 0;
    int direction = 0;

    // print startup message
    printf("Welcome to the C Drone Remote Control Program!\n");

    // loop until user quits
    while (1) {
        // print out current status
        printf("Altitude: %d\n", altitude);
        printf("Speed: %d\n", speed);
        printf("Direction: %d\n", direction);

        // ask for user input
        printf("Enter a command (a=accelerate, d=decelerate, l=left, r=right, u=up, o=down, q=quit): ");
        scanf(" %c", &input);

        // handle user input
        switch(input) {
            case 'a':
                if (speed < 10) {
                    speed++;
                    printf("Accelerating...\n");
                } else {
                    printf("Maximum speed reached!\n");
                }
                break;
            case 'd':
                if (speed > 0) {
                    speed--;
                    printf("Decelerating...\n");
                } else {
                    printf("Already stopped!\n");
                }
                break;
            case 'l':
                if (direction > -10) {
                    direction--;
                    printf("Turning left...\n");
                } else {
                    printf("Cannot turn left any further!\n");
                }
                break;
            case 'r':
                if (direction < 10) {
                    direction++;
                    printf("Turning right...\n");
                } else {
                    printf("Cannot turn right any further!\n");
                }
                break;
            case 'u':
                if (altitude < 100) {
                    altitude++;
                    printf("Going up...\n");
                } else {
                    printf("Maximum altitude reached!\n");
                }
                break;
            case 'o':
                if (altitude > 0) {
                    altitude--;
                    printf("Going down...\n");
                } else {
                    printf("Cannot go down any further!\n");
                }
                break;
            case 'q':
                printf("Quitting. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}