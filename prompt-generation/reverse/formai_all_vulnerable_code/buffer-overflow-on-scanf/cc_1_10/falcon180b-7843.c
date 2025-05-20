//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void main() {
    char choice;

    // Initial message
    printf("Welcome to the Puzzle Adventure!\n\n");

    while(1) {
        // Display options
        printf("What would you like to do?\n");
        printf("A. Move forward\n");
        printf("B. Move backward\n");
        printf("C. Check inventory\n");
        printf("D. Quit\n");

        // Get input
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
                // Move forward
                printf("You move forward.\n");
                break;

            case 'B':
                // Move backward
                printf("You move backward.\n");
                break;

            case 'C':
                // Check inventory
                printf("You have:\n");
                printf("- A flashlight\n");
                printf("- A map\n");
                printf("- A key\n");
                break;

            case 'D':
                // Quit
                printf("Thanks for playing!\n");
                exit(0);

            default:
                // Invalid input
                printf("Invalid choice.\n");
        }
    }
}