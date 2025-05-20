//FormAI DATASET v1.0 Category: Robot movement control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Grateful C Robot Movement Control Example
// by [Your Name]

int main() {

    printf("-----------------------------\n");
    printf("Welcome to the Grateful C Robot Movement Control Example!\n");
    printf("-----------------------------\n");

    // Set initial position and direction
    int x_pos = 0;
    int y_pos = 0;
    char direction = 'N';

    while (1) {
        // Prompt user for action
        printf("\nWhat would you like to do? (Enter a number)\n");
        printf("[1] Move forward\n");
        printf("[2] Turn left\n");
        printf("[3] Turn right\n");
        printf("[4] Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            // Move forward based on direction
            if (direction == 'N') {
                y_pos++;
            } else if (direction == 'S') {
                y_pos--;
            } else if (direction == 'E') {
                x_pos++;
            } else if (direction == 'W') {
                x_pos--;
            }
            printf("\nMoved forward one step. Current position: (%d, %d)\n", x_pos, y_pos);
        } else if (choice == 2) {
            // Turn left based on direction
            if (direction == 'N') {
                direction = 'W';
            } else if (direction == 'S') {
                direction = 'E';
            } else if (direction == 'E') {
                direction = 'N';
            } else if (direction == 'W') {
                direction = 'S';
            }
            printf("\nTurned left. New direction: %c\n", direction);
        } else if (choice == 3) {
            // Turn right based on direction
            if (direction == 'N') {
                direction = 'E';
            } else if (direction == 'S') {
                direction = 'W';
            } else if (direction == 'E') {
                direction = 'S';
            } else if (direction == 'W') {
                direction = 'N';
            }
            printf("\nTurned right. New direction: %c\n", direction);
        } else if (choice == 4) {
            // Exit program
            printf("\nExiting program. Thank you for using Grateful C Robot Movement Control!\n");
            break;
        } else {
            printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}