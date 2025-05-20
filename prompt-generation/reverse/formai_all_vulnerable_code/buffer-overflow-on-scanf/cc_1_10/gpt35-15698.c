//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>

// Function to display the current location and options
void displayLocation(int location) {
    printf("You are in room %d.\n", location);
    printf("What would you like to do?\n");
    printf("1. Go to the next room\n");
    printf("2. Search the room for clues\n");
    printf("3. Check your inventory\n");
}

// Function to prompt the user for their choice
int getUserChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    int location = 1; // starting location
    int choice;

    printf("Welcome to the Adventure Game!\n");

    // Game loop
    while (1) {
        // Display location and options
        displayLocation(location);

        // Get user choice
        choice = getUserChoice();

        // Handle user choice
        switch (choice) {
            case 1: // Go to the next room
                if (location == 3) {
                    printf("Congratulations! You have escaped the dungeon!\n");
                    return 0;
                } else {
                    location++;
                }
                break;
            case 2: // Search the room
                printf("You search the room but find nothing of interest.\n");
                break;
            case 3: // Check inventory
                printf("You have nothing in your inventory.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}