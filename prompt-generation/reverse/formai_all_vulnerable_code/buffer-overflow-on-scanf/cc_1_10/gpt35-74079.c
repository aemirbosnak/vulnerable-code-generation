//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// define constants
#define MAX_ANGLE 90
#define MIN_ANGLE -90
#define MAX_SPEED 100
#define MIN_SPEED 0

// global variables
int currentAngle = 0;
int currentSpeed = 0;

// function to handle user input
void handleInput(char input) {
    switch(input) {
        case 'a':
            if(currentAngle > MIN_ANGLE) {
                currentAngle--;
                printf("Current angle: %d\n", currentAngle);
            } else {
                printf("Error: Cannot decrease angle any further.\n");
            }
            break;
        case 'd':
            if(currentAngle < MAX_ANGLE) {
                currentAngle++;
                printf("Current angle: %d\n", currentAngle);
            } else {
                printf("Error: Cannot increase angle any further.\n");
            }
            break;
        case 'w':
            if(currentSpeed < MAX_SPEED) {
                currentSpeed++;
                printf("Current speed: %d\n", currentSpeed);
            } else {
                printf("Error: Cannot increase speed any further.\n");
            }
            break;
        case 's':
            if(currentSpeed > MIN_SPEED) {
                currentSpeed--;
                printf("Current speed: %d\n", currentSpeed);
            } else {
                printf("Error: Cannot decrease speed any further.\n");
            }
            break;
        default:
            printf("Error: Invalid input.\n");
    }
}

// main function
int main() {
    char input;
    printf("Welcome to the C Drone Remote Control!\n");
    while(1) {
        printf("Please enter a command (a, d, w, s): ");
        scanf("%c", &input);
        handleInput(input);
        while(getchar() != '\n'); // clear input buffer
    }
    return 0;
}