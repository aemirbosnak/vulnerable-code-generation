//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the map of the adventure game
    int map[5][5] = {{1, 1, 0, 0, 0},
                           {1, 1, 1, 0, 0},
                           {1, 1, 1, 1, 0},
                           {0, 0, 1, 1, 0},
                           {0, 0, 0, 0, 0}};

    // Create a character
    int character_x = 0;
    int character_y = 0;

    // Initialize the game loop
    int game_loop = 1;

    // While the game loop is active
    while (game_loop)
    {
        // Display the map
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                if (map[y][x] == 1)
                {
                    printf("%c ", '#');
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Get the user input
        char input;

        // Switch case to handle user input
        switch (input)
        {
            case 'w':
                character_y--;
                break;
            case 'a':
                character_x--;
                break;
            case 's':
                character_y++;
                break;
            case 'd':
                character_x++;
                break;
            case 'q':
                game_loop = 0;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check if the character has reached the end of the map
        if (map[character_y][character_x] == 0)
        {
            printf("You have reached the end of the map!\n");
            game_loop = 0;
        }
    }

    return 0;
}