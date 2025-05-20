//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TRIES 3 // Maximum number of tries before game over

int main() {
    // Set up random number generator
    srand(time(NULL));
    
    // Declare variables
    int room_number = 1; // Starting room
    int tries = 0; // Number of tries
    bool has_key = false; // Whether the player has the key or not
    
    // Introduction
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You've entered a spooky old house and need to find your way out.\n");
    printf("You only have %d tries before you become trapped forever!\n\n", MAX_TRIES);
    
    // Game loop
    while (room_number != 8) { // Player hasn't reached the exit yet
        // Display room description
        switch (room_number) {
            case 1:
                printf("You're in a dusty old foyer. There's a coat rack and a staircase leading up to a dark hallway.\n");
                break;
            case 2:
                printf("You're in a creepy library. There are cobwebs all over the shelves, and an eerie wind is blowing through the room.\n");
                break;
            case 3:
                if (!has_key) {
                    printf("You've entered a dimly lit kitchen. There's a locked pantry in the corner.\n");
                } else {
                    printf("You've entered a dimly lit kitchen. There's an open pantry revealing a staircase leading down to a damp cellar.\n");
                }
                break;
            case 4:
                printf("You've entered what appears to be a living room. The furniture is old and tattered, and there's a musty smell in the air.\n");
                break;
            case 5:
                printf("You've entered a dark hallway. There's a door at the end of the hall that seems to be the only way out.\n");
                break;
            case 6:
                printf("You're in a spooky bedroom. The bed is unmade and the curtains are tattered.\n");
                break;
            case 7:
                printf("You've entered a bathroom. The sink is rusted and the tiles are cracked.\n");
                break;
        }
        
        // Prompt user for input
        printf("Where would you like to go? (use numbers 1-9)\n");
        if (room_number == 3 && !has_key) { // Player is in room 3 and doesn't have the key yet
            printf("(you can type 'find key' to check for the key)\n");
        }
        int choice;
        scanf("%d", &choice);
        
        // Handle user input
        switch (choice) {
            case 1:
                if (room_number == 1) {
                    room_number = 2;
                } else {
                    printf("You can't go there from here.\n");
                    tries++;
                }
                break;
            case 2:
                if (room_number == 2) {
                    room_number = 1;
                } else {
                    printf("You can't go there from here.\n");
                    tries++;
                }
                break;
            case 3:
                if (room_number == 1) {
                    if (!has_key) {
                        printf("The pantry is locked. You need to find the key.\n");
                        tries++;
                    } else {
                        room_number = 5;
                    }
                } else {
                    printf("You can't go there from here.\n");
                    tries++;
                }
                break;
            case 4:
                if (room_number == 1) {
                    room_number = 6;
                } else {
                    printf("You can't go there from here.\n");
                    tries++;
                }
                break;
            case 5:
                if (room_number == 2 || room_number == 4 || room_number == 6) {
                    room_number = 7;
                } else if (room_number == 3 && has_key) {
                    room_number = 8; // Player wins!
                } else {
                    printf("You can't go there from here.\n");
                    tries++;
                }
                break;
            case 6:
                if (room_number == 5) {
                    room_number = 4;
                } else {
                    printf("You can't go there from here.\n");
                    tries++;
                }
                break;
            case 7:
                if (room_number == 5) {
                    room_number = 6;
                } else {
                    printf("You can't go there from here.\n");
                    tries++;
                }
                break;
            case 8:
                if (room_number == 3 && !has_key) {
                    printf("You search the kitchen and find a key hidden behind a bag of flour!\n");
                    has_key = true;
                } else {
                    printf("You can't find anything here.\n");
                    tries++;
                }
                break;
            case 9:
                printf("You've chosen to quit. Thanks for playing!\n");
                exit(0); // End the game early
            case 666:
                printf("You've been possessed by a demon and died.\n");
                exit(0); // End the game early
            default:
                printf("Invalid choice. Please try again.\n");
                tries++;
                break;
        }
        
        // Check if player has run out of tries
        if (tries >= MAX_TRIES) {
            printf("You've run out of tries and are now trapped in the haunted house forever!\n");
            exit(0); // End the game early
        }
    }
    
    // Exit the game
    printf("You've reached the exit and escaped the haunted house! Congratulations!\n");
    return 0;
}