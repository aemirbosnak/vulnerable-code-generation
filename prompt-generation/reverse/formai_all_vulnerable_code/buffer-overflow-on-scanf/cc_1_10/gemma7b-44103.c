//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int choice, room_num, treasure_loc, items_collected = 0;
    char character_name[20];

    printf("Enter your character's name: ");
    scanf("%s", character_name);

    // Create a map of rooms
    int rooms[5] = {1, 2, 3, 4, 5};

    // Choose a random room
    room_num = rooms[rand() % 5];

    // Describe the room
    switch (room_num)
    {
        case 1:
            printf("You are in a cozy cottage.\n");
            break;
        case 2:
            printf("You are in a haunted castle.\n");
            break;
        case 3:
            printf("You are in a pirate ship.\n");
            break;
        case 4:
            printf("You are in a goblin's lair.\n");
            break;
        case 5:
            printf("You are in a secret chamber.\n");
            break;
    }

    // Search for treasure
    treasure_loc = rand() % 10;

    // If the treasure is found, collect it
    if (treasure_loc == 0)
    {
        items_collected++;
        printf("You have found a treasure!\n");
    }

    // Display items collected
    printf("Items collected: %d\n", items_collected);

    // End the game
    return 0;
}