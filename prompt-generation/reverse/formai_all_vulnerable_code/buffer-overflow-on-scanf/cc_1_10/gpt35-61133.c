//FormAI DATASET v1.0 Category: Robot movement control ; Style: complete
#include<stdio.h>

// Function to move robot forward
void moveForward() {
    printf("Moving forward\n");
}

// Function to move robot left
void moveLeft() {
    printf("Moving left\n");
}

// Function to move robot right
void moveRight() {
    printf("Moving right\n");
}

// Function to move robot backward
void moveBackward() {
    printf("Moving backward\n");
}

int main() {
    char input;

    printf("Welcome to Robot Movement Control Program\n");

    while(1) {
        printf("Enter your choice of movement (F for Forward, L for Left, R for Right, B for Backward, Q for Quit): ");
        scanf(" %c", &input); // Taking user input for the movement
        
        switch(input) {
            case 'F':
            case 'f':
                moveForward(); // Calling the moveForward function
                break;
            case 'L':
            case 'l':
                moveLeft(); // Calling the moveLeft function
                break;
            case 'R':
            case 'r':
                moveRight(); // Calling the moveRight function
                break;
            case 'B':
            case 'b':
                moveBackward(); // Calling the moveBackward function
                break;
            case 'Q':
            case 'q':
                printf("Quitting program\n");
                return 0;
            default:
                printf("Invalid input, please try again\n");
                break;
        }
    }
    return 0;
}