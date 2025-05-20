//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the game map
    int map[5][5] = {{0, 1, 0, 0, 0},
                           {1, 1, 1, 1, 0},
                           {0, 1, 0, 1, 0},
                           {0, 0, 1, 1, 0},
                           {0, 0, 0, 0, 0}};

    // Define the player's position
    int x = 0;
    int y = 0;

    // Define the player's inventory
    int inventory[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Game loop
    while (!map[y][x] || inventory[0] == 1)
    {
        // Display the game map
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (map[i][j] == 1)
                {
                    printf("%c ", 'O');
                }
                else
                {
                    printf("%c ", '.');
                }
            }
            printf("\n");
        }

        // Get the player's input
        char input[2];
        printf("Enter the direction (N/S/E/W): ");
        scanf("%s", input);

        // Move the player
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
        }

        // Check if the player has reached the treasure
        if (map[y][x] == 1)
        {
            inventory[0] = 1;
            printf("You have found the treasure!\n");
        }
    }

    // End of the game
    return 0;
}