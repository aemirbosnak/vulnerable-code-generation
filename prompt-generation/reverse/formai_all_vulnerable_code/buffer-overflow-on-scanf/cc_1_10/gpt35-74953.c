//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Initializing variables
    int x = 0;
    int y = 0;
    int z = 0;

    // Displaying welcome message
    printf("Welcome to Brave C Drone Remote Control Program!\n\n");

    // Looping through the program until user exits
    while (1) {
        // Displaying options
        printf("Please choose an option:\n");
        printf("1. Move left\n");
        printf("2. Move right\n");
        printf("3. Move up\n");
        printf("4. Move down\n");
        printf("5. Move forward\n");
        printf("6. Move backward\n");
        printf("7. Display current position\n");
        printf("8. Exit\n\n");

        // Reading user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handling user choice
        switch (choice) {
            case 1:
                x--;
                printf("Drone moved left.\n\n");
                break;
            case 2:
                x++;
                printf("Drone moved right.\n\n");
                break;
            case 3:
                y++;
                printf("Drone moved up.\n\n");
                break;
            case 4:
                y--;
                printf("Drone moved down.\n\n");
                break;
            case 5:
                z++;
                printf("Drone moved forward.\n\n");
                break;
            case 6:
                z--;
                printf("Drone moved backward.\n\n");
                break;
            case 7:
                printf("Current position: (%d, %d, %d)\n\n", x, y, z);
                break;
            case 8:
                // Exiting the program
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}