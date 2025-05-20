//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    printf("Welcome to the Text-Based Adventure Game, %s!\n", name);

    // Create a map of the adventure world
    int map[5][5] = {{0, 1, 0, 0, 0},
                           {1, 0, 1, 0, 0},
                           {0, 1, 0, 1, 0},
                           {0, 0, 1, 0, 1},
                           {0, 0, 0, 1, 0}};

    // Current position of the player
    int x = 0, y = 0;

    // Game loop
    while (1)
    {
        // Display the map
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (map[i][j] == 1)
                {
                    printf("%c ", '*');
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Get the player's input
        char input[20];
        printf("Enter your command: ");
        scanf("%s", input);

        // Process the player's input
        if (strcmp(input, "north") == 0)
        {
            if (map[x][y - 1] == 1)
            {
                y--;
                printf("You moved north.\n");
            }
            else
            {
                printf("You cannot move north.\n");
            }
        }
        else if (strcmp(input, "south") == 0)
        {
            if (map[x][y + 1] == 1)
            {
                y++;
                printf("You moved south.\n");
            }
            else
            {
                printf("You cannot move south.\n");
            }
        }
        else if (strcmp(input, "east") == 0)
        {
            if (map[x + 1][y] == 1)
            {
                x++;
                printf("You moved east.\n");
            }
            else
            {
                printf("You cannot move east.\n");
            }
        }
        else if (strcmp(input, "west") == 0)
        {
            if (map[x - 1][y] == 1)
            {
                x--;
                printf("You moved west.\n");
            }
            else
            {
                printf("You cannot move west.\n");
            }
        }
        else
        {
            printf("Invalid command.\n");
        }

        // Check if the player has won
        if (x == 4 && y == 4)
        {
            printf("You have won the game!\n");
            break;
        }
    }

    return 0;
}