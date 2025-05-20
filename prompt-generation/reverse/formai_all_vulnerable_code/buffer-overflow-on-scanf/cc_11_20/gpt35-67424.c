//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    int batteryLife = 100; // Initialize battery life of RC vehicle
    int speed = 0; // Initialize speed of RC vehicle
    int distance = 0; // Initialize distance traveled by RC vehicle
    int direction = 0; // Initialize direction of RC vehicle (0: Forward, 1: Backward, 2: Left, 3: Right)
    char command; // To hold user input of command

    printf("Welcome to the Remote Control Vehicle Simulation\n\n");

    while (batteryLife > 0) {

        printf("Battery Life: %d%%\n", batteryLife);
        printf("Speed: %d m/s\n", speed);
        printf("Distance Traveled: %d m\n", distance);
        printf("Direction: %s\n\n", direction == 0 ? "Forward" : direction == 1 ? "Backward" : direction == 2 ? "Left" : "Right");

        printf("Enter Command: ");
        scanf(" %c", &command);

        switch(command) {
            case 'f':
                distance += speed;
                direction = 0;
                break;
            case 'b':
                distance += speed;
                direction = 1;
                break;
            case 'l':
                direction = 2;
                break;
            case 'r':
                direction = 3;
                break;
            case 'a':
                if (batteryLife < 100) {
                    batteryLife += ((rand() % 21) + 10);
                    if (batteryLife > 100) {
                        batteryLife = 100;
                    }
                    printf("Battery Successfully Charged. Battery Life Now: %d%%\n\n", batteryLife);
                } else {
                    printf("Battery Life is Already at 100%%. Cannot be Charged Further.\n\n");
                }
                break;
            case 's':
                if (speed > 0) {
                    speed--;
                    printf("Speed Reduced by 1 m/s\n\n");
                } else {
                    printf("Speed Already at Minimum. Cannot be Reduced Further.\n\n");
                }
                break;
            case 'x':
                if (speed < 10) {
                    speed++;
                    printf("Speed Increased by 1 m/s\n\n");
                } else {
                    printf("Speed Already at Maximum. Cannot be Increased Further.\n\n");
                }
                break;
            case 'q':
                printf("System Terminated.\n");
                exit(0); // Terminate program
            default:
                printf("Invalid Command. Try Again.\n\n");
        }

        batteryLife--; // Decrement battery life by 1% after each command
    }

    printf("Battery Life has been Depleted. System Terminated.\n");

    return 0;
}