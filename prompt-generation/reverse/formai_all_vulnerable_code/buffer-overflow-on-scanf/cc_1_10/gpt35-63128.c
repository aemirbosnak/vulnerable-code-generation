//FormAI DATASET v1.0 Category: Robot movement control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool robot_on = true; // Robot is on by default

int main() {
    int position = 0; // Starting position of the Robot
    char command; // Variable for storing user input commands

    printf("Welcome to the Robot Movement Control Program!\n");

    // Start Loop
    while(robot_on) {

        printf("Current Position: %d\n", position);

        // Get User Input
        printf("Enter Command: ");
        scanf(" %c", &command);
        printf("\n");

        // Switch-Case for User Commands
        switch(command) {

            case 'F':
                // Move Forward
                printf("Moving Forward...\n");
                position++;
                break;

            case 'B':
                // Move Backward
                printf("Moving Backward...\n");
                position--;
                break;

            case 'L':
                // Turn Left
                printf("Turning Left...\n");
                break;

            case 'R':
                // Turn Right
                printf("Turning Right...\n");
                break;

            case 'S':
                // Stop the Robot and Exit Program
                printf("Stopping the Robot and Exiting the Program...\n");
                robot_on = false;
                break;

            default:
                // Invalid Input Command
                printf("Invalid Input Command. Try again...\n");
        }

        printf("\n\n");
    }

    system("pause");
    return 0;
}