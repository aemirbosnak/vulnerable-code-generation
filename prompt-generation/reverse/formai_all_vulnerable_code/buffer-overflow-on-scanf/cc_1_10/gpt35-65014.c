//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define key constants for remote control
#define BUTTON_UP 'w'
#define BUTTON_DOWN 's'
#define BUTTON_LEFT 'a'
#define BUTTON_RIGHT 'd'
#define BUTTON_EXIT 'q'

// Define drone movement constants
#define MOVE_UP 1
#define MOVE_DOWN 2
#define MOVE_LEFT 3
#define MOVE_RIGHT 4

// Function to handle drone movements
void moveDrone(int direction) {
    switch(direction) {
        case MOVE_UP:
            printf("Moving drone up.\n");
            break;
        case MOVE_DOWN:
            printf("Moving drone down.\n");
            break;
        case MOVE_LEFT:
            printf("Moving drone left.\n");
            break;
        case MOVE_RIGHT:
            printf("Moving drone right.\n");
            break;
    }
}

// Main program function
int main() {

    // Initialize variables
    char buttonPress;
    bool exitProgram = false;

    // Welcome message for user
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Please use the following keys to control your drone:\n");
    printf(" - %c: Move drone up\n", BUTTON_UP);
    printf(" - %c: Move drone down\n", BUTTON_DOWN);
    printf(" - %c: Move drone left\n", BUTTON_LEFT);
    printf(" - %c: Move drone right\n", BUTTON_RIGHT);
    printf(" - %c: Exit program\n", BUTTON_EXIT);

    // Loop for getting user input
    while(!exitProgram) {
        printf("Please press a button to control the drone: ");
        scanf("%c", &buttonPress);

        // Check which button was pressed
        switch(buttonPress) {
            case BUTTON_UP:
                moveDrone(MOVE_UP);
                break;
            case BUTTON_DOWN:
                moveDrone(MOVE_DOWN);
                break;
            case BUTTON_LEFT:
                moveDrone(MOVE_LEFT);
                break;
            case BUTTON_RIGHT:
                moveDrone(MOVE_RIGHT);
                break;
            case BUTTON_EXIT:
                exitProgram = true;
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    }

    printf("Exiting the C Drone Remote Control Program.");

    // Return success
    return 0;
}