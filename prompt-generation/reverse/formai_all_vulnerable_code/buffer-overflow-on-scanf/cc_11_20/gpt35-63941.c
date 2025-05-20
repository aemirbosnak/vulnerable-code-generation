//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int room = 1;
    int player_health = 100;
    int ghost_health = 50;
    int key = 0;
    int ghost_appearance_limit = 4;
    int ghost_appearance_count = 0;

    srand(time(NULL)); // seed random number generator

    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are trapped in a spooky haunted house. You must find the key to unlock the door and escape, but beware of the ghosts that haunt this place!\n\n");

    while (1) {
        printf("You are in room %d.\n", room);

        // Check if player has key
        if (key == 1) {
            printf("You have the key. You can now unlock the door and escape!\n");
            break;
        }

        // Randomly decide if ghost appears
        if (rand() % 2 == 0 && ghost_appearance_count < ghost_appearance_limit) {
            printf("Oh no! A ghost appears and attacks you!\n");
            player_health -= 25;
            ghost_appearance_count++;
        }

        // Check if player is dead
        if (player_health <= 0) {
            printf("Game over. You are dead.\n");
            break;
        }

        // Ask player for next move
        printf("What do you want to do? (1) Search the room for the key, (2) Rest and regain health, (3) Move to another room: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int rng = rand() % 4; // randomize key location
            if (rng == room) {
                printf("You found the key!\n");
                key = 1;
            } else {
                printf("You search the room but cannot find the key.\n");
            }
        } else if (choice == 2) {
            printf("You rest and your health improves by 25 points.\n");
            player_health += 25;
        } else if (choice == 3) {
            printf("Which room do you want to move to? (1, 2, or 3): ");
            int next_room;
            scanf("%d", &next_room);

            // Check if next room is valid
            if (next_room < 1 || next_room > 3) {
                printf("That is not a valid choice. Please choose a room between 1 and 3.\n");
            } else if (next_room == room) {
                printf("You are already in that room. Please choose another room.\n");
            } else {
                printf("You move to room %d.\n", next_room);
                room = next_room;
                ghost_appearance_count = 0; // reset ghost appearance for new room
            }
        } else {
            printf("That is not a valid choice. Please choose 1, 2, or 3.\n");
        }
        
        printf("Your current health is %d.\n\n", player_health);
    }
    
    printf("\nCongratulations! You escaped the haunted house and lived to tell the tale!\n");

    return 0;
}