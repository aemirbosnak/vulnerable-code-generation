//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char choice;
    int room = 1;

    // Map of rooms
    char **map = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++)
    {
        map[i] = (char *)malloc(10 * sizeof(char));
    }

    // Initialize the map
    map[0][0] = 'A';
    map[0][1] = 'B';
    map[0][2] = 'C';
    map[1][0] = 'D';
    map[1][1] = 'E';
    map[1][2] = 'F';
    map[2][0] = 'G';
    map[2][1] = 'H';
    map[2][2] = 'I';
    map[3][0] = 'J';
    map[3][1] = 'K';
    map[3][2] = 'L';
    map[4][0] = 'M';
    map[4][1] = 'N';
    map[4][2] = 'O';

    // Game loop
    while (room != 5)
    {
        // Display the room
        printf("You are in room %d.\n", room);
        printf("What do you want to do? (N/S/E/W/Q) ");

        // Get the player's choice
        scanf(" %c", &choice);

        // Move the player
        switch (choice)
        {
            case 'N':
                if (map[room][0] != '#')
                {
                    room--;
                }
                break;
            case 'S':
                if (map[room][2] != '#')
                {
                    room++;
                }
                break;
            case 'E':
                if (map[room][1] != '#')
                {
                    room += 2;
                }
                break;
            case 'W':
                if (map[room][0] != '#')
                {
                    room--;
                }
                break;
            case 'Q':
                printf("Thank you for playing. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        // Check if the player has won
        if (map[room][0] == 'O')
        {
            printf("You have won! Congratulations!\n");
            exit(0);
        }
    }

    return 0;
}