//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>
#include <time.h>

int main() {
    // Initializing variables
    int forward = 0;
    int backward = 0;
    int left = 0;
    int right = 0;
    int stop = 0;
    int direction = 0;

    while (1) {
        // Getting user input
        printf("Enter command (0 - stop, 1 - forward, 2 - backward, 3 - left, 4 - right): ");
        int command = 0;
        scanf("%d", &command);

        // Executing the command
        switch (command) {
            case 0:
                printf("Stopping...\n");
                stop = 1;
                break;
            case 1:
                printf("Moving forward...\n");
                forward = 1;
                break;
            case 2:
                printf("Moving backward...\n");
                backward = 1;
                break;
            case 3:
                printf("Turning left...\n");
                left = 1;
                break;
            case 4:
                printf("Turning right...\n");
                right = 1;
                break;
            default:
                printf("Invalid command.\n");
        }

        // Simulating movement
        if (forward) {
            printf("Moving forward for 2 seconds...\n");
            sleep(2);
            forward = 0;
        }
        if (backward) {
            printf("Moving backward for 2 seconds...\n");
            sleep(2);
            backward = 0;
        }
        if (left) {
            printf("Turning left for 2 seconds...\n");
            sleep(2);
            left = 0;
        }
        if (right) {
            printf("Turning right for 2 seconds...\n");
            sleep(2);
            right = 0;
        }

        // Stopping the car
        if (stop) {
            printf("Stopping...\n");
            stop = 0;
        }
    }

    return 0;
}