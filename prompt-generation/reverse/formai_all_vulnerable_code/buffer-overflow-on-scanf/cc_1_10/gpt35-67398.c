//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seeding the random number generator

    int room = 1; // starting room
    int ghost = 0; // has the player encountered a ghost yet?
    int num_ghosts = 0; // number of ghosts encountered
    int num_rooms_visited = 1; // number of rooms visited by the player
    int num_items = 0; // number of items picked up by the player

    printf("Welcome to the Haunted House Simulator.\n");
    printf("You find yourself in a dark and eerie mansion...\n\n");

    while (room <= 10) { // there are 10 rooms in the mansion
        printf("You are in room %d.\n", room);
        printf("What would you like to do?\n");
        printf("1. Search the room.\n");
        printf("2. Move to the next room.\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) { // searching the room
            int found_item = rand() % 2; // 50% chance of finding an item

            if (found_item) {
                printf("You found an item!\n");
                num_items++;
            } else {
                printf("You did not find an item.\n");
            }

        } else if (choice == 2) { // moving to the next room
            int ghost_encounter = rand() % 4; // 25% chance of encountering a ghost

            if (ghost_encounter && !ghost) { // if the player has not yet encountered a ghost
                printf("You encounter a ghastly ghost!\n");
                ghost = 1;
                num_ghosts++;
            } else {
                printf("You move to the next room.\n");
                num_rooms_visited++;
            }

            room++;

        } else { // invalid choice
            printf("Invalid choice. Please choose again.\n");
        }

        printf("\n");
    }

    printf("Congratulations! You made it out of the mansion alive!\n");
    printf("You visited %d rooms and found %d items.\n", num_rooms_visited, num_items);

    if (num_ghosts == 0) {
        printf("You did not encounter any ghosts. Excellent!\n");
    } else if (num_ghosts == 1) {
        printf("You encountered 1 ghost. Spooky!\n");
    } else {
        printf("You encountered %d ghosts. Very spooky!\n", num_ghosts);
    }

    return 0;
}