//FormAI DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

// function to move the robot in x direction
void moveXDirection(int *x, int distance, int speed) {
    int steps = distance * speed; // calculate the number of steps
    int i;
    for(i = 0; i < steps; i++) {
        if(distance < 0) {
            (*x)--; // decrement x if distance is negative
        }
        else {
            (*x)++; // increment x if distance is positive
        }
        printf("Moved to position (%d, 0)\n", *x); // print the current position
    }
}

// function to move the robot in y direction
void moveYDirection(int *y, int distance, int speed) {
    int steps = distance * speed; // calculate the number of steps
    int i;
    for(i = 0; i < steps; i++) {
        if(distance < 0) {
            (*y)--; // decrement y if distance is negative
        }
        else {
            (*y)++; // increment y if distance is positive
        }
        printf("Moved to position (0, %d)\n", *y); // print the current position
    }
}

// main function
int main() {
    int x = 0, y = 0; // initialize the starting position
    int distance, speed, direction; // variables to take input from the user
    printf("Enter the distance to move: ");
    scanf("%d", &distance);
    printf("Enter the speed (steps/second): ");
    scanf("%d", &speed);
    printf("Enter the direction (0 for x, 1 for y): ");
    scanf("%d", &direction);
    if(direction == 0) { // move in x direction
        moveXDirection(&x, distance, speed);
    }
    else if(direction == 1) { // move in y direction
        moveYDirection(&y, distance, speed);
    }
    else { // invalid direction
        printf("Invalid direction entered!\n");
    }
    return 0;
}