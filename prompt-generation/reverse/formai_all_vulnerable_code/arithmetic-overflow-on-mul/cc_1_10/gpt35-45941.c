//FormAI DATASET v1.0 Category: Robot movement control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

// Function to move the robot in the specified direction 
void moveRobot(int direction) {
    switch(direction) {
        case FORWARD:
            printf("Robot moved forward!\n");
            break;
        case BACKWARD:
            printf("Robot moved backward!\n");
            break;
        case LEFT:
            printf("Robot turned left!\n");
            break;
        case RIGHT:
            printf("Robot turned right!\n");
            break;
        default:
            printf("Invalid direction!\n");
    }
}

int main() {
    int numMoves, maxSteps, step, direction;
    srand(time(NULL)); // Seed the random number generator

    // Reading configuration parameters from user
    printf("Enter the maximum number of moves: ");
    scanf("%d", &numMoves);

    printf("Enter the maximum number of steps per move: ");
    scanf("%d", &maxSteps);

    // Loop to move the robot randomly
    for(int i=0; i<numMoves; i++) {
        printf("Move %d: \n", i+1);
        step = rand() % maxSteps + 1; // Randomly generate number of steps
        direction = rand() % 4 + 1; // Randomly generate direction
        switch(direction) {
            case 1:
                moveRobot(FORWARD * step); // Move forward
                break;
            case 2:
                moveRobot(BACKWARD * step); // Move backward
                break;
            case 3:
                moveRobot(LEFT); // Turn left
                break;
            case 4:
                moveRobot(RIGHT); // Turn right
                break;
        }
    }

    return 0;
}