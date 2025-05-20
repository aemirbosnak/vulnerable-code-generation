//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Define the main character
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);

    // Create a map of the dungeon
    int map[5][5] = {{0, 1, 0, 0, 0},
                           {1, 0, 1, 0, 0},
                           {0, 1, 0, 1, 0},
                           {0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 1}};

    // Set the player's position
    int x = 0;
    int y = 0;

    // Initialize the game loop
    int running = 1;

    // While the game is running, continue
    while (running)
    {
        // Print the map
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (map[i][j] == 1)
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

        // Get the player's move
        int move = 0;
        printf("Enter your move (north, south, east, west): ");
        scanf("%d", &move);

        // Move the player
        switch (move)
        {
            case 1:
                y--;
                break;
            case 2:
                y++;
                break;
            case 3:
                x++;
                break;
            case 4:
                x--;
                break;
        }

        // Check if the player has won
        if (map[x][y] == 1)
        {
            running = 0;
            printf("You have won!");
        }

        // Check if the player has lost
        if (x < 0 || x >= 5 || y < 0 || y >= 5)
        {
            running = 0;
            printf("You have lost!");
        }
    }

    // End the game
    printf("Thank you for playing, %s!", name);
}