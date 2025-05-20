//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>

// function to move the vehicle forward
void moveForward() {
    printf("Vehicle moving forward\n");
}

// function to move the vehicle backward
void moveBackward() {
    printf("Vehicle moving backward\n");
}

// function to turn the vehicle left
void turnLeft() {
    printf("Vehicle turning left\n");
}

// function to turn the vehicle right
void turnRight() {
    printf("Vehicle turning right\n");
}

int main() {
    int input;
    printf("Remote control vehicle simulation\n");

    while (1) {
        printf("Enter direction: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                moveForward(); // call moveForward() function
                break;
            case 2:
                moveBackward(); // call moveBackward() function
                break;
            case 3:
                turnLeft(); // call turnLeft() function
                break;
            case 4:
                turnRight(); // call turnRight() function
                break;
            case 0:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid input\n");
                break; 
        }
    }
    return 0;
}