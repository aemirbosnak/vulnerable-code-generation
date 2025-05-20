//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, room_num, treasure_found = 0;
    char character_name[20];

    printf("Enter your character name: ");
    scanf("%s", character_name);

    printf("Welcome, %s, to the mysterious mansion!\n", character_name);

    // Create a map of rooms
    int rooms[5] = {1, 2, 3, 4, 5};

    // Start in the first room
    room_num = rooms[0];

    // Main loop
    while (!treasure_found)
    {
        // Print room description
        switch (room_num)
        {
            case 1:
                printf("You are in the grand hall. There is a portrait of a mysterious figure on the wall.\n");
                break;
            case 2:
                printf("You are in the dining hall. There is a table with a feast of food.\n");
                break;
            case 3:
                printf("You are in the library. There are bookshelves filled with books.\n");
                break;
            case 4:
                printf("You are in the ballroom. There is a dance floor and a bar.\n");
                break;
            case 5:
                printf("You have found the treasure!\n");
                treasure_found = 1;
                break;
        }

        // Get the user's choice
        printf("What do you want to do? (1) go north, (2) go south, (3) go east, (4) go west: ");
        scanf("%d", &choice);

        // Move to the next room
        switch (choice)
        {
            case 1:
                room_num = rooms[room_num + 1];
                break;
            case 2:
                room_num = rooms[room_num - 1];
                break;
            case 3:
                room_num = rooms[room_num + 2];
                break;
            case 4:
                room_num = rooms[room_num - 2];
                break;
        }
    }

    // End the game
    printf("Thank you for playing, %s. See you next time.\n", character_name);
}