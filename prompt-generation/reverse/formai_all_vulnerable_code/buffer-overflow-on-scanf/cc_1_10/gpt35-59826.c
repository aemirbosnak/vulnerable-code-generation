//FormAI DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVES 50 // Maximum moves robot can make
#define MAX_SPEED 6 // Maximum speed robot can move

// Function to generate random integer between min and max
int randomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to move robot forward
void moveForward(int speed) {
    printf("MOVING FORWARD: Speed %d\n", speed);
}

// Function to move robot backward
void moveBackward(int speed) {
    printf("MOVING BACKWARD: Speed %d\n", speed);
}

// Function to turn robot left
void turnLeft() {
    printf("TURNING LEFT\n");
}

// Function to turn robot right
void turnRight() {
    printf("TURNING RIGHT\n");
}

int main() {
    srand(time(NULL)); // Initialize random seed

    int i, moves, speed;

    printf("Enter the number of moves: ");
    scanf("%d", &moves); // Read number of moves from user

    if (moves > MAX_MOVES) {
        printf("Error: Maximum moves allowed is %d\n", MAX_MOVES);
        return 1; // Exit program with error code
    }

    for (i = 0; i < moves; i++) {
        speed = randomInt(1, MAX_SPEED); // Generate random speed
        switch(randomInt(1, 4)) { // Generate random direction
            case 1:
                moveForward(speed);
                break;
            case 2:
                moveBackward(speed);
                break;
            case 3:
                turnLeft();
                break;
            case 4:
                turnRight();
                break;
        }
    }

    return 0; // Exit program with success code
}