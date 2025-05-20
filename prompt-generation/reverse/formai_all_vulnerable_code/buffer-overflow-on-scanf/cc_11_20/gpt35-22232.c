//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Define the rooms in the haunted house.
    char* rooms[5];
    rooms[0] = "the foyer";
    rooms[1] = "the living room";
    rooms[2] = "the kitchen";
    rooms[3] = "the dining room";
    rooms[4] = "the bedroom";

    // Set the starting room to the foyer.
    int current_room = 0;

    // Loop through the haunted house until the player exits or dies.
    while (1) {
        // Print the current room.
        printf("You are in %s.\n", rooms[current_room]);

        // Roll a dice to randomly determine what happens.
        int roll = rand() % 6 + 1;
        if (roll == 1) {
            printf("You hear a ghostly moan and feel a cold breeze.\n");
        } else if (roll == 2) {
            printf("You see a shadowy figure dart across the room.\n");
        } else if (roll == 3) {
            printf("You smell rotting flesh and feel something brush past you.\n");
        } else if (roll == 4) {
            printf("You hear a door slam shut in another room.\n");
        } else if (roll == 5) {
            printf("You feel a hand on your shoulder, but when you turn around, no one is there.\n");
        } else if (roll == 6) {
            printf("You see a ghostly apparition materialize in front of you.\n");
        }

        // Prompt the player for their next action.
        int next_room;
        printf("Where would you like to go next?\n");
        printf("1. %s\n", rooms[(current_room + 1) % 5]);
        printf("2. %s\n", rooms[(current_room + 2) % 5]);
        printf("3. %s\n", rooms[(current_room + 3) % 5]);
        printf("4. %s\n", rooms[(current_room + 4) % 5]);
        printf("Enter your choice: ");
        scanf("%d", &next_room);

        // Move the player to the next room.
        if (next_room == 1) {
            current_room = (current_room + 1) % 5;
        } else if (next_room == 2) {
            current_room = (current_room + 2) % 5;
        } else if (next_room == 3) {
            current_room = (current_room + 3) % 5;
        } else if (next_room == 4) {
            current_room = (current_room + 4) % 5;
        }

        // Check if the player has exited or died.
        if (current_room == 0) {
            printf("You have escaped the haunted house alive! Congratulations!\n");
            break;
        } else {
            int death_roll = rand() % 6 + 1;
            if (death_roll <= current_room) {
                printf("You have been killed by a ghost! Game over.\n");
                break;
            }
        }
    }

    return 0;
}