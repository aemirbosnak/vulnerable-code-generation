//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 10 // Maximum speed of the vehicle
#define MIN_SPEED 1 // Minimum speed of the vehicle

int main() {
    int speed = MIN_SPEED;
    bool isRunning = false;
    char input;

    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Press 's' to start or stop the vehicle\n");
    printf("Press '+' to increase speed\n");
    printf("Press '-' to decrease speed\n");
    printf("Press 'q' to quit\n");
    
    while (input != 'q') {
        printf("\nSpeed: %d\n", speed);
        printf(">> ");
        scanf(" %c", &input);
        
        if (input == 's') {
            if (isRunning) {
                printf("Stopping the vehicle...\n");
                isRunning = false;
            } else {
                printf("Starting the vehicle...\n");
                isRunning = true;
            }
        } else if (input == '+') {
            if (isRunning) {
                if (speed < MAX_SPEED) {
                    speed++;
                    printf("Increasing speed...\n");
                } else {
                    printf("Vehicle is already at maximum speed!\n");
                }
            } else {
                printf("Vehicle is not running!\n");
            }
        } else if (input == '-') {
            if (isRunning) {
                if (speed > MIN_SPEED) {
                    speed--;
                    printf("Decreasing speed...\n");
                } else {
                    printf("Vehicle is already at minimum speed!\n");
                }
            } else {
                printf("Vehicle is not running!\n");
            }
        } else if (input == 'q') {
            printf("Quitting...\n");
        } else {
            printf("Invalid input!\n");
        }
    }
    return 0;
}