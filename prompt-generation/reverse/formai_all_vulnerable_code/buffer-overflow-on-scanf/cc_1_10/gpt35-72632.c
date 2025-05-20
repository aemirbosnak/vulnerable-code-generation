//FormAI DATASET v1.0 Category: Robot movement control ; Style: unmistakable
#include <stdio.h>

//Defines movement commands as macros to increase code readability
#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'

//Defines the maximum allowed limit for X and Y movements
const int MAX_COORDINATE = 10;

//Function to move the robot forward
void moveForward(int *x, int *y) {
    *y += 1;
}

//Function to move the robot backward
void moveBackward(int *x, int *y) {
    *y -= 1;
}

//Function to move the robot left
void moveLeft(int *x, int *y) {
    *x -= 1;
}

//Function to move the robot right
void moveRight(int *x, int *y) {
    *x += 1;
}

//Function to print the coordinates of the robot
void printCoordinates(int x, int y) {
    printf("Current coordinates: (%d, %d)\n", x, y);
}

int main() {
    //Initialize the variables for X and Y coordinates
    int x = 0;
    int y = 0;
    
    printf("Welcome to Robot Movement Control Program!\n");
    printf("Enter 'F' to move forward, 'B' to move backward, 'L' to move left, 'R' to move right and 'Q' to quit!\n");
    
    //Loop to read in the movement commands and move the robot accordingly
    while (1) {
        char command;
        scanf("%c", &command);
        
        switch (command) {
            case FORWARD:
                if (y < MAX_COORDINATE) {
                    moveForward(&x, &y);
                } else {
                    printf("Max limit reached! Cannot move forward.\n");
                }
                break;
                
            case BACKWARD:
                if (y > -MAX_COORDINATE) {
                    moveBackward(&x, &y);
                } else {
                    printf("Max limit reached! Cannot move backward.\n");
                }
                break;
                
            case LEFT:
                if (x > -MAX_COORDINATE) {
                    moveLeft(&x, &y);
                } else {
                    printf("Max limit reached! Cannot move left.\n");
                }
                break;
                
            case RIGHT:
                if (x < MAX_COORDINATE) {
                    moveRight(&x, &y);
                } else {
                    printf("Max limit reached! Cannot move right.\n");
                }
                break;
                
            case 'Q':
                printf("Quitting!\n");
                return 0;
                
            default:
                printf("Invalid Command! Try again.\n");
                break;
        }
        
        //Print the current coordinates of the robot
        printCoordinates(x, y);
    }
    
    return 0;
}