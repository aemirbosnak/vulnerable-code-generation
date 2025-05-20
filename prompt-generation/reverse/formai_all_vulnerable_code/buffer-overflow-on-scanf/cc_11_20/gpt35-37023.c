//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up random number generator seed
    srand(time(NULL));

    // Define variables
    int room = 1;
    int ghost_here = 0;
    int key_here = 0;
    int has_key = 0;
    int player_choice = 0;

    // Print initial room description
    printf("Welcome to the haunted house!\n");
    printf("You find yourself in a dark room. You hear mysterious creaking noises.\n");

    while (room != 4) {
        // Determine if there is a ghost in the room
        if (rand() % 2 == 0) {
            ghost_here = 1;
        } else {
            ghost_here = 0;
        }

        // Determine if there is a key in the room
        if (rand() % 3 == 0) {
            key_here = 1;
        } else {
            key_here = 0;
        }

        // Print room description and prompt player for choice
        printf("\nYou are in room %d. ", room);
        printf("There is %sghost here. ", ghost_here ? "a " : "no ");
        printf("There is %sa key here. ", key_here ? " " : "no ");
        printf("What do you want to do?\n");
        printf("1. Move to the next room\n");
        printf("2. Try to open the door\n");
        printf("3. Quit the game\n");
        scanf("%d", &player_choice);

        // Process player choice
        switch (player_choice) {
            case 1:
                room++;
                printf("You move to room %d.\n", room);
                break;
            case 2:
                // If the player has the key, they win the game
                if (key_here && has_key == 1) {
                    printf("You found the key and escape the haunted house!\n");
                    room = 4;
                } 
                // If there is a ghost, the player loses the game
                else if (ghost_here) {
                    printf("You open the door and see a ghost! You lose!\n");
                    room = 4;
                } 
                // If there is no key, tell the player they can't open the door
                else if (!key_here) {
                    printf("You try to open the door but it's locked.\n");
                } 
                // If the player doesn't have the key yet, update the has_key variable
                else {
                    printf("You found the key! Now you can escape the haunted house if you can find the door.\n");
                    has_key = 1;
                }
                break;
            case 3:
                printf("Thanks for playing!\n");
                room = 4;
                break;
            default:
                printf("That is not a valid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}