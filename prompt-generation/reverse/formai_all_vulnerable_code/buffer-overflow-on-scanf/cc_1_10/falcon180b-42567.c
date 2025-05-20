//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void moveRobot(int x, int y, int angle);
void turnLeft();
void turnRight();
void moveForward();
void moveBackward();
void stop();

int main() {
    int x = 0, y = 0, angle = 0;

    printf("Enter initial position of the robot (x,y): ");
    scanf("%d %d", &x, &y);

    printf("Enter initial angle of the robot: ");
    scanf("%d", &angle);

    while (1) {
        printf("\nEnter your command:\n1. Move forward\n2. Move backward\n3. Turn left\n4. Turn right\n5. Stop\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveForward();
                break;
            case 2:
                moveBackward();
                break;
            case 3:
                turnLeft();
                break;
            case 4:
                turnRight();
                break;
            case 5:
                stop();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to move the robot
void moveRobot(int x, int y, int angle) {
    printf("Robot is moving to (%d,%d) with an angle of %d degrees.\n", x, y, angle);
}

// Function to turn the robot left
void turnLeft() {
    int angle = 90;
    moveRobot(0, 0, angle);
}

// Function to turn the robot right
void turnRight() {
    int angle = -90;
    moveRobot(0, 0, angle);
}

// Function to move the robot forward
void moveForward() {
    int distance = 10;
    moveRobot(distance, 0, 0);
}

// Function to move the robot backward
void moveBackward() {
    int distance = -10;
    moveRobot(distance, 0, 0);
}

// Function to stop the robot
void stop() {
    printf("Robot has stopped.\n");
}