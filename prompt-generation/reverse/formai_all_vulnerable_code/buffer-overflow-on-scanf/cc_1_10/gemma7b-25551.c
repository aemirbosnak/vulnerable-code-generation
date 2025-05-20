//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house(void) {
    int i, j, r, choice, haunted_room_num;

    // Create a haunted house with 5 rooms
    int rooms[5] = {1, 2, 3, 4, 5};

    // Randomly select a haunted room
    haunted_room_num = rooms[rand() % 5];

    // Set the room's description
    switch (haunted_room_num) {
        case 1:
            printf("You are in the Entry Hall. A cold wind blows through the cracked windows.\n");
            break;
        case 2:
            printf("You are in the Dining Hall. The smell of burnt food and decay fills the air.\n");
            break;
        case 3:
            printf("You are in the Living Room. The furniture is overturned, and the walls are covered in blood.\n");
            break;
        case 4:
            printf("You are in the Bedroom. The bed is stained with blood, and the walls are covered in arcane symbols.\n");
            break;
        case 5:
            printf("You are in the Secret Room. The walls are adorned with gruesome paintings, and the air is thick with the scent of decay.\n");
            break;
    }

    // Ask the player to choose a direction
    printf("Choose a direction (N, S, E, W): ");

    // Get the player's choice
    scanf("%c", &choice);

    // Move the player through the haunted house
    switch (choice) {
        case 'N':
            printf("You moved north. You hear a shuffling sound behind you.\n");
            break;
        case 'S':
            printf("You moved south. You see a ghostly figure standing in the doorway.\n");
            break;
        case 'E':
            printf("You moved east. You find a hidden room.\n");
            break;
        case 'W':
            printf("You moved west. You hear a scream and run away.\n");
            break;
    }

    // Play the haunted house again
    play_haunted_house();
}

int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Play the haunted house
    play_haunted_house();

    return 0;
}