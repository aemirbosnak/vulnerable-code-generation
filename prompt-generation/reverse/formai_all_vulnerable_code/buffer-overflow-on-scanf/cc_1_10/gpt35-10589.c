//FormAI DATASET v1.0 Category: Robot movement control ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// forward declarations for functions
void forward(int steps);
void backward(int steps);
void turn_left();
void turn_right();

int main() {
    printf("Welcome to the Robot Movement Program\n");

    // prompt the user for the number of steps
    printf("How many steps would you like to move forward? ");
    int steps;
    scanf("%d", &steps);

    // move the robot forward
    forward(steps);

    // prompt the user for the number of steps to move backward
    printf("How many steps would you like to move backward? ");
    scanf("%d", &steps);

    // move the robot backward
    backward(steps);

    // turn the robot left
    printf("Turning left...\n");
    turn_left();

    // move the robot forward
    printf("Moving forward...\n");
    forward(10);

    // turn the robot right
    printf("Turning right...\n");
    turn_right();

    // move the robot forward
    printf("Moving forward...\n");
    forward(5);

    printf("Program finished.\n");
    return 0;
}

// function for moving the robot forward
void forward(int steps) {
    printf("Moving forward %d steps...\n", steps);
    // insert code for moving the robot forward
}

// function for moving the robot backward
void backward(int steps) {
    printf("Moving backward %d steps...\n", steps);
    // insert code for moving the robot backward
}

// function for turning the robot left
void turn_left() {
    printf("Turning left...\n");
    // insert code for turning the robot left
}

// function for turning the robot right
void turn_right() {
    printf("Turning right...\n");
    // insert code for turning the robot right
}