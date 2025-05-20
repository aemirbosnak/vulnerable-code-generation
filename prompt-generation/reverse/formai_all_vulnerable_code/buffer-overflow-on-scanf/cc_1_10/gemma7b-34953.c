//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void play_game()
{
    char name[20];
    printf("Welcome to the Text-Based Adventure Game, %s!\n", name);

    // Create a map of the adventure game world.
    int map[5][5] = {{0, 1, 1, 0, 0},
                           {0, 0, 1, 0, 1},
                           {1, 0, 1, 0, 0},
                           {0, 0, 0, 1, 0},
                           {0, 1, 0, 0, 0}};

    // Player's current position.
    int x = 0, y = 0;

    // Game loop.
    while (1)
    {
        // Display the map.
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (map[i][j] == 1)
                {
                    printf("X ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }

        // Get the player's input.
        char input[20];
        printf("Enter your move (N, S, E, W): ");
        scanf("%s", input);

        // Check if the player's input is valid.
        if (input[0] == 'N' && y > 0)
        {
            y--;
        }
        else if (input[0] == 'S' && y < 4)
        {
            y++;
        }
        else if (input[0] == 'E' && x < 4)
        {
            x++;
        }
        else if (input[0] == 'W' && x > 0)
        {
            x--;
        }
        else
        {
            printf("Invalid move.\n");
        }

        // Check if the player has won or lost.
        if (map[x][y] == 2)
        {
            printf("You have won! Congratulations!\n");
            break;
        }
        else if (map[x][y] == 3)
        {
            printf("You have lost. Game over.\n");
            break;
        }
    }

    // Thank the player for playing.
    printf("Thank you for playing, %s.\n", name);
}

int main()
{
    play_game();

    return 0;
}