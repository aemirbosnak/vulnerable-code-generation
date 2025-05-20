//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up variables
    char *name = "John Doe";
    char *room = "living room";
    int x = 0;
    int y = 0;
    int direction = 0;

    // Prompt user for name
    printf("What is your name? ");
    scanf("%s", name);

    // Print welcome message
    printf("Welcome, %s!\n", name);

    // Initialize room and directions
    while (1) {
        // Print room description
        printf("%s\n", room);

        // Print options
        printf("Options:\n");
        printf("1. Go North\n");
        printf("2. Go South\n");
        printf("3. Go East\n");
        printf("4. Go West\n");

        // Get user input
        printf("Enter a number: ");
        scanf("%d", &direction);

        // Handle input
        switch (direction) {
            case 1:
                // Move north
                room = "hallway";
                break;
            case 2:
                // Move south
                room = "kitchen";
                break;
            case 3:
                // Move east
                room = "bedroom";
                break;
            case 4:
                // Move west
                room = "bathroom";
                break;
            default:
                printf("Invalid input. Try again.\n");
        }
    }
    return 0;
}