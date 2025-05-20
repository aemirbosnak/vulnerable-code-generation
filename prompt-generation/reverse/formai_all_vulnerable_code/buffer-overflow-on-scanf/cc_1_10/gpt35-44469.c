//FormAI DATASET v1.0 Category: Robot movement control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the maximum speed of the robot
#define MAX_SPEED 100

// Define the minimum speed of the robot
#define MIN_SPEED 0

// Define the possible directions for the robot
enum DIRECTION {LEFT, RIGHT, UP, DOWN};

// Define the starting position of the robot
int posX = 0;
int posY = 0;

// Define the default direction of the robot
enum DIRECTION dir = RIGHT;

// Define the current speed of the robot
int speed = 50;

// Function to update the position of the robot
void updatePosition() {
    switch (dir) {
        case LEFT:
            posX--;
            break;
        case RIGHT:
            posX++;
            break;
        case UP:
            posY++;
            break;
        case DOWN:
            posY--;
            break;
    }
}

// Function to check if the robot has reached the boundaries
int checkBoundaries() {
    if (posX < 0 || posX > 100 || posY < 0 || posY > 100) {
        printf("Robot has reached the boundaries.\n");
        return 1;
    }
    return 0;
}

// Function to update the direction of the robot
void updateDirection(int newDir) {
    dir = newDir;
    printf("Robot direction updated to ");
    switch (dir) {
        case LEFT:
            printf("LEFT\n");
            break;
        case RIGHT:
            printf("RIGHT\n");
            break;
        case UP:
            printf("UP\n");
            break;
        case DOWN:
            printf("DOWN\n");
            break;
    }
}

// Function to update the speed of the robot
void updateSpeed(int newSpeed) {
    if (newSpeed < MIN_SPEED) {
        speed = MIN_SPEED;
    } else if (newSpeed > MAX_SPEED) {
        speed = MAX_SPEED;
    } else {
        speed = newSpeed;
    }
    printf("Robot speed updated to %d\n", speed);
}

int main() {
    int input;
    while (1) {
        printf("Enter a command:\n");
        printf("1 - Move left\n");
        printf("2 - Move right\n");
        printf("3 - Move up\n");
        printf("4 - Move down\n");
        printf("5 - Update direction\n");
        printf("6 - Update speed\n");
        printf("7 - Exit\n");
        scanf("%d", &input);

        switch (input) {
            case 1:
                updatePosition();
                if (checkBoundaries()) {
                    exit(0);
                }
                break;
            case 2:
                updatePosition();
                if (checkBoundaries()) {
                    exit(0);
                }
                break;
            case 3:
                updatePosition();
                if (checkBoundaries()) {
                    exit(0);
                }
                break;
            case 4:
                updatePosition();
                if (checkBoundaries()) {
                    exit(0);
                }
                break;
            case 5:
                printf("Enter a direction:\n");
                printf("1 - Left\n");
                printf("2 - Right\n");
                printf("3 - Up\n");
                printf("4 - Down\n");
                scanf("%d", &input);
                updateDirection(input-1);
                break;
            case 6:
                printf("Enter a speed (0-100):\n");
                scanf("%d", &input);
                updateSpeed(input);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        // Print the new position of the robot
        printf("Robot position: (%d, %d)\n", posX, posY);
    }

    return 0;
}