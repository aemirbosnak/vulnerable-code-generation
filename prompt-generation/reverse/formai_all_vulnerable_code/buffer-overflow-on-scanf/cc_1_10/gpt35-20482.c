//FormAI DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>

int main() {
    int direction; // used to store the input entered by user for direction of movement
    int x = 0; // represents the current x-coordinate of the robot
    int y = 0; // represents the current y-coordinate of the robot

    printf("Welcome to Robot Movement Control Program!\n");

    // Print the initial position of the robot
    printf("\nCurrent Position: (%d,%d)\n", x, y);

    // Loop until user quits
    while (1) {
        // Print the available movement options
        printf("\nSelect a direction to move:\n");
        printf("1 - North\n");
        printf("2 - East\n");
        printf("3 - South\n");
        printf("4 - West\n");
        printf("5 - Quit Program\n");

        // Read user input for direction
        scanf("%d", &direction);

        // Based on user input, update the coordinates of the robot
        switch (direction) {
            case 1:
                printf("\nMoving North\n");
                y++;
                break;
            case 2:
                printf("\nMoving East\n");
                x++;
                break;
            case 3:
                printf("\nMoving South\n");
                y--;
                break;
            case 4:
                printf("\nMoving West\n");
                x--;
                break;
            case 5:
                // Exit the program if user enters 5
                printf("\nExiting Program\n");
                return 0;
            default:
                // Prompt user to enter a valid input if input is not 1-5
                printf("\nInvalid Option. Please select 1-5.\n");
        }

        // Print the current position of the robot
        printf("Current Position: (%d,%d)\n", x, y);
    }

    return 0;
}