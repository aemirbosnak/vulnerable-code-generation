//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the robot's movement capabilities
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

// Initialize the robot's position and direction
int x = 0, y = 0;
int direction = STOP;

// Function to move the robot in the given direction
void move(int dir) {
    switch(dir) {
        case FORWARD:
            printf("Moving forward...\n");
            break;
        case BACKWARD:
            printf("Moving backward...\n");
            break;
        case LEFT:
            printf("Turning left...\n");
            break;
        case RIGHT:
            printf("Turning right...\n");
            break;
        case STOP:
            printf("Stopping...\n");
            break;
    }
}

// Function to check if the given move is valid
int isValidMove(int move) {
    if(move >= FORWARD && move <= STOP)
        return 1;
    else
        return 0;
}

// Main function to control the robot's movement
int main() {
    int choice;

    srand(time(NULL));

    // Initialize the robot's position and direction
    x = rand() % 10;
    y = rand() % 10;
    direction = STOP;

    while(1) {
        system("clear");
        printf("Robot is at position (%d,%d)\n", x, y);
        printf("Current direction: %s\n", (direction == FORWARD)? "Forward" : 
                (direction == BACKWARD)? "Backward" :
                (direction == LEFT)? "Left" :
                (direction == RIGHT)? "Right" : "Stopped");

        printf("\nEnter your move (1-5): ");
        scanf("%d", &choice);

        if(isValidMove(choice)) {
            move(choice);
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}