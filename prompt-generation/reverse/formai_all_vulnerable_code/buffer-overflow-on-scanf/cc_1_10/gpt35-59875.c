//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int choice, speed = 0;
    char direction = 'S';

    // Show welcome message
    printf("Welcome to Remote Control Vehicle Simulation\n");

    // Start loop for user interaction
    while (1) {
        // Prompt user for choice
        printf("\nPlease select a choice:\n");
        printf("1 - Move Forward\n");
        printf("2 - Move Backward\n");
        printf("3 - Turn Left\n");
        printf("4 - Turn Right\n");
        printf("5 - Increase Speed\n");
        printf("6 - Decrease Speed\n");
        printf("7 - Quit Program\n");

        // Get user input
        scanf("%d", &choice);

        // Process user input
        switch (choice) {
            case 1:
                direction = 'F';
                break;
            case 2:
                direction = 'B';
                break;
            case 3:
                direction = 'L';
                break;
            case 4:
                direction = 'R';
                break;
            case 5:
                speed++;
                break;
            case 6:
                speed--;
                break;
            case 7:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
                continue;
        }

        // Print out vehicle status
        printf("\nVehicle is moving %c at speed %d\n", direction, speed);
    }

    return 0;
}