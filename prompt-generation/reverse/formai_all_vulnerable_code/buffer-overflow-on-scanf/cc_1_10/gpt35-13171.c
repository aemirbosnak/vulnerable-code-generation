//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // Seed random number generator

    printf("Welcome to the Haunted House!\n");

    int room = 1;
    int has_key = 0; // Player does not have key at start

    while (room <= 5)
    {
        printf("You are in Room %d\n", room);

        int ghost_chance = rand() % 100 + 1;
        if (ghost_chance <= 20) // 20% chance of encountering ghost
        {
            printf("Oh no! You encountered a ghost!\n");
            if (has_key) // If player has key, they can escape
            {
                printf("But luckily, you have a key to unlock the door and escape!\n");
                break;
            }
            else // If player does not have key, they are trapped forever
            {
                printf("And unfortunately, you do not have a key to escape, you are trapped forever!\n");
                return 0;
            }
        }

        int key_chance = rand() % 100 + 1;
        if (key_chance <= 30 && !has_key) // 30% chance of finding key (if player doesn't have one yet)
        {
            printf("You found a key!\n");
            has_key = 1;
        }

        printf("What do you want to do? (1-3)\n");
        printf("1. Move to next room\n");
        printf("2. Search for hidden items\n");
        printf("3. Quit game\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            room++;
        }
        else if (choice == 2)
        {
            int item_chance = rand() % 100 + 1;
            if (item_chance <= 50) // 50% chance of finding item
            {
                printf("You found a hidden item!\n");
            }
            else
            {
                printf("You didn't find anything...\n");
            }
        }
        else if (choice == 3)
        {
            printf("Quitting game...\n");
            return 0;
        }
        else
        {
            printf("Invalid input, please try again\n");
        }
    }

    printf("Congratulations! You escaped the haunted house!\n");

    return 0;
}