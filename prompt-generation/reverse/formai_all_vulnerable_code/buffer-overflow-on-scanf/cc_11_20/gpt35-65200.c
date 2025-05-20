//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>

// Define constants for the vehicle speeds
#define SLOW_SPEED 20
#define MED_SPEED 40
#define FAST_SPEED 60

// Define constant for the maximum distance the vehicle can travel in one turn
#define MAX_DISTANCE 100

int main() {
    // Declare and initialize variables
    int speed = SLOW_SPEED;
    int distance = 0;
    bool isMoving = false;

    // Print welcome message
    printf("Welcome to the Remote Control Vehicle Simulation.\n");
    printf("Use the following commands to control the vehicle:\n");
    printf("S - Start/Stop the vehicle\n");
    printf("1 - Set speed to slow\n");
    printf("2 - Set speed to medium\n");
    printf("3 - Set speed to fast\n");
    printf("F - Move the vehicle forward\n");
    printf("B - Move the vehicle backward\n");
    printf("Q - Quit the simulation\n\n");

    // Loop until user quits
    char input;
    bool quit = false;
    while (!quit) {
        // Read user input
        printf("Enter your command: ");
        scanf("%c", &input);
        getchar(); // consume remaining newline character

        // Process user input
        switch(input) {
            case 'S':
            case 's':
                if (isMoving) {
                    isMoving = false;
                    printf("Vehicle stopped.\n");
                } else {
                    isMoving = true;
                    printf("Vehicle started.\n");
                }
                break;
            case '1':
                speed = SLOW_SPEED;
                printf("Vehicle speed set to slow.\n");
                break;
            case '2':
                speed = MED_SPEED;
                printf("Vehicle speed set to medium.\n");
                break;
            case '3':
                speed = FAST_SPEED;
                printf("Vehicle speed set to fast.\n");
                break;
            case 'F':
            case 'f':
                if (isMoving) {
                    int moveDistance = speed;
                    if (distance + moveDistance <= MAX_DISTANCE) {
                        distance += moveDistance;
                        printf("Vehicle moved forward %d units.\n", moveDistance);
                    } else {
                        printf("Vehicle cannot move forward that far.\n");
                    }
                } else {
                    printf("Vehicle is not currently moving.\n");
                }
                break;
            case 'B':
            case 'b':
                if (isMoving) {
                    int moveDistance = speed;
                    if (distance - moveDistance >= 0) {
                        distance -= moveDistance;
                        printf("Vehicle moved backward %d units.\n", moveDistance);
                    } else {
                        printf("Vehicle cannot move backward that far.\n");
                    }
                } else {
                    printf("Vehicle is not currently moving.\n");
                }
                break;
            case 'Q':
            case 'q':
                quit = true;
                printf("Exiting simulation. Goodbye!\n");
                break;
            default:
                printf("Invalid command. Try again.\n");
                break;
        }
    }

    return 0;
}