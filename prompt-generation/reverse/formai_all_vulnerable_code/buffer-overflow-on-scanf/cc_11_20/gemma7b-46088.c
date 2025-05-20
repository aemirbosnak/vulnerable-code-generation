//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls"); // Clear the console
    printf("Welcome to the Quest for the Stolen Gemstone!\n");

    // Create a simple text-based map of the dungeon
    char map[10][10] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'S', ' ', 'A', 'R', 'M', 'A', ' ', ' ', ' '},
        {' ', ' ', 'R', ' ', ' ', ' ', ' ', 'T', ' ', ' '},
        {' ', ' ', ' ', 'G', ' ', 'N', 'A', 'T', 'R', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'A', ' ', 'R', 'O', 'W', 'S', 'H', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'A', ' ', 'R', 'E', 'C', 'T'}
    };

    // Initialize the player's position
    int x = 0;
    int y = 0;

    // Main game loop
    while (1)
    {
        // Display the map
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        // Get the player's input
        char input[20];
        printf("Enter your move (N, S, E, W): ");
        scanf("%s", input);

        // Check if the player has moved validly
        switch (input[0])
        {
            case 'N':
                if (y - 1 >= 0)
                {
                    y--;
                }
                break;
            case 'S':
                if (y + 1 < 10)
                {
                    y++;
                }
                break;
            case 'E':
                if (x + 1 < 10)
                {
                    x++;
                }
                break;
            case 'W':
                if (x - 1 >= 0)
                {
                    x--;
                }
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check if the player has won or lost
        if (map[y][x] == 'G')
        {
            printf("You have won! The gemstone is yours.\n");
            break;
        }
        else if (map[y][x] == 'R')
        {
            printf("You have lost! The gemstone has been stolen.\n");
            break;
        }
    }

    return 0;
}