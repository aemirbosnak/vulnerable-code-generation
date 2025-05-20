//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: complete
#include <stdio.h>

int main()
{
    char name[20];
    printf("What is your name?\n");
    scanf("%s", name);

    printf("Hello, %s, welcome to the Text-Based Adventure Game!\n", name);

    // Create a map of the game world
    int map[5][5] = {{0, 0, 1, 0, 0},
                           {0, 1, 1, 0, 0},
                           {1, 1, 1, 1, 0},
                           {0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0}};

    // Player's current position
    int x = 0, y = 0;

    // Game loop
    while (1)
    {
        // Display the game world
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

        // Get the player's move
        char move;

        printf("Enter your move (N, S, E, W): ");
        scanf("%c", &move);

        // Move the player
        switch (move)
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
                printf("Invalid move.\n");
                break;
        }

        // Check if the player has won or lost
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

    return 0;
}