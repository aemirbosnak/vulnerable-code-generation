//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// define constants for vehicle directions
#define STOP 0
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// function to get user input
int getInput() {
    int input;
    scanf("%d", &input);
    return input;
}

int main() {
    // declare and initialize variables
    int direction = STOP;
    int speed = 0;
    int distance = 0;

    // create menu and loop until user exits program
    while (1) {
        printf("Remote Control Vehicle Simulation\n");
        printf("=================================\n");
        printf("Current Direction: ");
        switch(direction) {
            case STOP:
                printf("STOPPED\n");
                break;
            case FORWARD:
                printf("FORWARD\n");
                break;
            case BACKWARD:
                printf("BACKWARD\n");
                break;
            case LEFT:
                printf("LEFT\n");
                break;
            case RIGHT:
                printf("RIGHT\n");
                break;
        }
        printf("Current Speed: %d mph\n", speed);
        printf("Current Distance: %d ft\n", distance);
        printf("\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Increase Speed\n");
        printf("6. Decrease Speed\n");
        printf("7. Exit Program\n");
        printf("\n");

        // get user input and perform corresponding action
        int choice = getInput();
        switch(choice) {
            case 1:
                direction = FORWARD;
                distance += speed * 10;
                break;
            case 2:
                direction = BACKWARD;
                distance += speed * 5;
                break;
            case 3:
                direction = LEFT;
                distance += speed * 3;
                break;
            case 4:
                direction = RIGHT;
                distance += speed * 3;
                break;
            case 5:
                speed += 5;
                break;
            case 6:
                speed -= 5;
                if (speed < 0) {
                    speed = 0;
                }
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice selected. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}