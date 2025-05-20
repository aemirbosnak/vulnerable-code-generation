//FormAI DATASET v1.0 Category: Robot movement control ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100

// function to turn robot left
void turnLeft(int speed) {
    printf("Robot turning left at speed %d\n", speed);
    // code to turn left
}

// function to turn robot right
void turnRight(int speed) {
    printf("Robot turning right at speed %d\n", speed);
    // code to turn right
}

// function to move robot forward
void moveForward(int speed) {
    printf("Robot moving forward at speed %d\n", speed);
    // code to move forward
}

// function to stop robot movement
void stopRobot() {
    printf("Robot stopping\n");
    // code to stop robot
}

int main() {
    int direction; // variable to store direction of movement
    int speed; // variable to store speed of movement

    printf("Enter direction of movement (1 for left, 2 for forward, 3 for right): ");
    scanf("%d", &direction);

    printf("Enter speed of movement (0-%d): ", MAX_SPEED);
    scanf("%d", &speed);

    switch(direction) {
        case 1: // movement to left
            turnLeft(speed);
            break;
        case 2: // movement forward
            moveForward(speed);
            break;
        case 3: // movement to right
            turnRight(speed);
            break;
        default: // invalid direction entered
            printf("Invalid direction entered\n");
            stopRobot(); // stop robot movement
            return 0;
    }

    stopRobot(); // stop robot movement

    return 0;
}