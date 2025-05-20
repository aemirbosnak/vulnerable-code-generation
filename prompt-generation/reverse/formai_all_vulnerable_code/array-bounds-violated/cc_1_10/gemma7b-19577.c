//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROOM_COUNT 5
#define PLAYER_START_ROOM 1

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a map of rooms
    int rooms[ROOM_COUNT] = {
        0,
        1,
        2,
        3,
        4
    };

    // Set the player's starting room
    int player_room = PLAYER_START_ROOM;

    // Loop until the player escapes or dies
    while (rooms[player_room] != 4)
    {
        // Display the current room
        printf("You are in room %d.\n", player_room);

        // Randomly choose a direction
        int direction = rand() % 4;

        // Move the player to the next room
        switch (direction)
        {
            case 0:
                player_room--;
                break;
            case 1:
                player_room++;
                break;
            case 2:
                player_room += 2;
                break;
            case 3:
                player_room -= 2;
                break;
        }

        // Check if the player has escaped or died
        if (rooms[player_room] == 4)
        {
            printf("You have escaped the haunted house!\n");
        }
        else if (rooms[player_room] == 5)
        {
            printf("You have died. Game over.\n");
        }
    }

    return 0;
}