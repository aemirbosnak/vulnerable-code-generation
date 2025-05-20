//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the map of the dungeon
    int map[5][5] = {{0, 0, 0, 0, 1},
                           {0, 0, 0, 1, 1},
                           {0, 0, 1, 1, 1},
                           {0, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1}};

    // Create the player character
    int x = 0, y = 0, health = 100, inventory[] = {0, 0, 0, 0};

    // Initialize the game loop
    int game_loop = 1;

    // Begin the game loop
    while (game_loop)
    {
        // Display the map
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (map[i][j] == 1)
                {
                    printf("O ");
                }
                else
                {
                    printf(". ");
                }
            }
            printf("\n");
        }

        // Get the player's input
        char input[10];
        printf("Enter your move (N, S, E, W): ");
        scanf("%s", input);

        // Process the player's input
        switch (input[0])
        {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check if the player has moved onto a trap
        if (map[x][y] == 2)
        {
            printf("You have triggered a trap! Your health has been reduced to 50%.\n");
            health = 50;
        }

        // Check if the player has reached the treasure
        if (map[x][y] == 3)
        {
            printf("You have found the treasure! You have won the game!\n");
            game_loop = 0;
        }

        // Check if the player has run out of health
        if (health <= 0)
        {
            printf("You have run out of health and have died. Game over.\n");
            game_loop = 0;
        }
    }

    return 0;
}