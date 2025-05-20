//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int ghost_chance = 5; // 5% chance of encountering a ghost
    int room_count = 10; // can adjust to change number of rooms
    int current_room = 1; // starting room is 1
    int ghost_in_room = 0; // no ghost in starting room

    printf("Welcome to the Haunted House Simulator!\n");

    while (current_room <= room_count) {

        printf("\nYou are in room %d\n", current_room);

        // check if there is a ghost in the room
        if (rand() % 100 < ghost_chance && current_room != 1) {
            ghost_in_room = 1;
        } else {
            ghost_in_room = 0;
        }

        // display appropriate message based on ghost presence
        if (ghost_in_room) {
            printf("Oh no! There's a ghost in this room!\n");
        } else {
            printf("This room seems safe for now...\n");
        }

        // check if user wants to move to next room
        char move;
        printf("Do you want to move to the next room? (Y/N)\n");
        scanf(" %c", &move);

        if (move == 'Y' || move == 'y') {
            current_room++;
        } else {
            printf("You chose to stay in this room.\n");
        }

        // check if user encounters a ghost
        if (ghost_in_room) {
            printf("The ghost got you! Game over.\n");
            return 0;
        }
    }

    printf("\nCongratulations, you made it through all the rooms!\n");

    return 0;
}