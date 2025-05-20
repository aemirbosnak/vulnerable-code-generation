//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Haunted House Simulator!\n");

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Set up variables
    int numRooms = 5;
    int currentRoom = 0;
    int ghostRoom = rand() % numRooms; // Choose a random room for the ghost
    int hasKey = 0;
    int hasExited = 0;

    // Main game loop
    while (!hasExited) {
        // Print current room and options
        printf("\nCURRENT ROOM: %d\n", currentRoom);
        printf("OPTIONS: \n");
        if (currentRoom > 0) {
            printf("  1. Go back to room %d\n", currentRoom - 1);
        }
        if (currentRoom < numRooms - 1) {
            printf("  2. Go forward to room %d\n", currentRoom + 1);
        }
        if (currentRoom == ghostRoom) {
            printf("  3. OH NO! You've encountered the ghost! \n");
        }
        if (currentRoom == numRooms - 1 && hasKey) {
            printf("  4. Use key to unlock the exit\n");
        }
        printf("Enter your choice (1-4): ");
        int choice;
        scanf("%d", &choice);

        // Process user input
        switch (choice) {
            case 1:
                if (currentRoom > 0) {
                    currentRoom--;
                } else {
                    printf("You hit a wall! There's nowhere to go!\n");
                }
                break;
            case 2:
                if (currentRoom < numRooms - 1) {
                    currentRoom++;
                } else {
                    printf("You hit a wall! There's nowhere to go!\n");
                }
                break;
            case 3:
                if (currentRoom == ghostRoom) {
                    printf("EEK! The ghost got you! GAME OVER.\n");
                    hasExited = 1;
                } else {
                    printf("There's no ghost here! Keep moving...\n");
                }
                break;
            case 4:
                if (currentRoom == numRooms - 1 && hasKey) {
                    printf("You use the key to unlock the door and escape! You win!\n");
                    hasExited = 1;
                } else {
                    printf("You don't have a key! Keep searching...\n");
                }
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 4.\n");
                break;
        }
        // Generate a key if they haven't found one yet
        if (currentRoom == ghostRoom && !hasKey) {
            hasKey = 1;
            printf("\nYou found a key in the ghost room! Maybe it can unlock the exit...\n");
        }
    }
    return 0;
}