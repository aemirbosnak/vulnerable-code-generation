//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void moveForward() {
    printf("The robot gracefully moves forward, thank you for guiding it!\n");
}

void moveBackward() {
    printf("With gratitude, the robot gently retreats back, following your lead!\n");
}

void moveLeft() {
    printf("The robot swiftly turns left, showing appreciation for your command!\n");
}

void moveRight() {
    printf("The robot elegantly pivots to the right, thankful for your direction!\n");
}

void displayInstructions() {
    printf("\n=== Robot Movement Control ===\n");
    printf("Please enter a command:\n");
    printf("1: Move Forward\n");
    printf("2: Move Backward\n");
    printf("3: Turn Left\n");
    printf("4: Turn Right\n");
    printf("0: Exit Program\n");
    printf("=============================\n");
}

int main() {
    int command;
    printf("Welcome! This robot is ready to move at your command.\n");

    while (1) {
        displayInstructions();
        printf("Enter your choice (0-4): ");
        if (scanf("%d", &command) != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Clear the input buffer in case of wrong input
            while(getchar() != '\n');
            continue;
        }

        switch (command) {
            case 1:
                moveForward();
                break;
            case 2:
                moveBackward();
                break;
            case 3:
                moveLeft();
                break;
            case 4:
                moveRight();
                break;
            case 0:
                printf("Thank you for interacting with the robot! Exiting the program gracefully...\n");
                exit(0);
            default:
                printf("Oops! That's not a valid command. Please try again.\n");
        }
    }
    
    return 0;
}