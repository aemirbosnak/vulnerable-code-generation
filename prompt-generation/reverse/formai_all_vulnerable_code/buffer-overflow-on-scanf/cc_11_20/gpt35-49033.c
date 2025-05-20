//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Set up the haunted house
    int rooms[10] = { 0 };
    int current_room = 0;
    int ghost_room = rand() % 10;
    int has_key = 0;

    // Start the game
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in the entrance hall.\n");

    while (1) {
        // Print options
        printf("What would you like to do?\n");
        printf("1. Move to another room\n");
        printf("2. Search the current room\n");
        printf("3. Quit the game\n");

        // Get user input
        int choice;
        scanf("%d", &choice);

        // Handle user choices
        if (choice == 1) {
            // Move to another room
            printf("Which room would you like to move to? (0-9)\n");
            int new_room;
            scanf("%d", &new_room);
            if (new_room < 0 || new_room > 9) {
                printf("Invalid room number!\n");
            } else {
                current_room = new_room;
                printf("You are now in room %d.\n", current_room);
                if (current_room == ghost_room) {
                    printf("Oh no! You've been caught by the ghost.\n");
                    printf("Game over!\n");
                    return 0;
                }
            }
        } else if (choice == 2) {
            // Search the current room
            printf("You search the room...\n");
            if (current_room == ghost_room) {
                printf("You found the ghost's key!\n");
                has_key = 1;
            } else if (rooms[current_room] == 0) {
                printf("You didn't find anything.\n");
                rooms[current_room] = 1;
            } else {
                printf("You already searched this room.\n");
            }
        } else if (choice == 3) {
            // Quit the game
            printf("Thanks for playing!\n");
            return 0;
        } else {
            // Invalid choice
            printf("Invalid choice!\n");
        }

        // Check if the player has won
        int all_rooms_searched = 1;
        for (int i = 0; i < 10; i++) {
            if (rooms[i] == 0) {
                all_rooms_searched = 0;
                break;
            }
        }
        if (all_rooms_searched && has_key) {
            printf("Congratulations! You found the ghost's key and searched every room.\n");
            printf("You win!\n");
            return 0;
        }
    }
}