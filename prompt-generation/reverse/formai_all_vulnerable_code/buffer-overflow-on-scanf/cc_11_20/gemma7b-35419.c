//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int choice, room_num = 1, ghosts_encountered = 0, item_found = 0;
    char item_name[20];

    // Haunted House Map
    int map[5][5] = {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1}
    };

    // Loop until the player chooses to leave
    while (choice != 3)
    {
        // Display the room description
        switch (room_num)
        {
            case 1:
                printf("You are in the grand hall. The air is thick with the scent of roses and decay.\n");
                break;
            case 2:
                printf("You are in the dining hall. The table is set for a feast, but the food is cold and maggots are crawling on the floor.\n");
                break;
            case 3:
                printf("You are in the library. The bookshelves are overflowing with ancient texts and a ghostly presence fills the air.\n");
                break;
            case 4:
                printf("You are in the bedroom. The bed is made, but the pillows are missing and the door creaks open and shut on its own.\n");
                break;
            case 5:
                printf("You are in the attic. The air is thick with the scent of mothballs and decay. The only sound is your own breathing.\n");
                break;
        }

        // Get the player's choice
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);

        // Move through the haunted house
        switch (choice)
        {
            case 1:
                room_num++;
                break;
            case 2:
                item_found = 1;
                sprintf(item_name, "A silver candlestick");
                room_num++;
                break;
            case 3:
                ghosts_encountered++;
                room_num--;
                break;
        }

        // Encounter a ghost
        if (ghosts_encountered > 0)
        {
            printf("You encountered a ghost! Prepare for a fright...\n");
            // Add your own spooky sound effects here
            system("pause");
        }

        // Found an item
        if (item_found > 0)
        {
            printf("You found a %s!\n", item_name);
            item_found = 0;
        }
    }

    // End the game
    printf("Thank you for visiting the haunted house. You have escaped!\n");

    return 0;
}