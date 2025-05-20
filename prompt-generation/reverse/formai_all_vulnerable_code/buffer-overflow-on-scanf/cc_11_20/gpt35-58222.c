//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10 // maximum speed the drone can fly at

int main() {
    int speed = 0; // initialize the drone speed to 0
    char command; // the user input command

    printf("Welcome to Drone Remote Control Program!\n");

    while (1) { // infinite loop until the user exits the program

        printf("\nEnter a command (f, b, u, d, l, r, s, e): ");
        scanf(" %c", &command);

        switch (command) {
            case 'f':
                if (speed < MAX_SPEED) speed++; // accelerate the drone
                printf("Moving forward with speed %d\n", speed);
                break;
            case 'b':
                if (speed < MAX_SPEED) speed++; // accelerate the drone
                printf("Moving backward with speed %d\n", speed);
                break;
            case 'u':
                if (speed < MAX_SPEED) speed++; // accelerate the drone
                printf("Moving up with speed %d\n", speed);
                break;
            case 'd':
                if (speed < MAX_SPEED) speed++; // accelerate the drone
                printf("Moving down with speed %d\n", speed);
                break;
            case 'l':
                if (speed < MAX_SPEED) speed++; // accelerate the drone
                printf("Moving left with speed %d\n", speed);
                break;
            case 'r':
                if (speed < MAX_SPEED) speed++; // accelerate the drone
                printf("Moving right with speed %d\n", speed);
                break;
            case 's':
                speed = 0; // stop the drone
                printf("Drone stopped\n");
                break;
            case 'e':
                printf("Exiting Drone Remote Control Program...\n");
                exit(0); // exit the program
            default:
                printf("Invalid command\n");
        }
    }

    return 0;
}