//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");

    // Define variables
    int x = 0, y = 0, direction = 0;
    char map[10][10] = {{'.', '.', '.', '.', '.'},
                              {'.', 'S', '.', '.', '.'},
                              {'.', '.', 'O', '.', '.'},
                              {'.', '.', '.', 'O', '.'},
                              {'.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.'},
                              {'.', '.', 'O', '.', '.'},
                              {'.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.'}};

    // Game loop
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

        // Get the direction
        printf("Enter direction (W, A, S, D): ");
        scanf("%d", &direction);

        // Move the character
        switch (direction)
        {
            case 1:
                y--;
                break;
            case 2:
                x--;
                break;
            case 3:
                y++;
                break;
            case 4:
                x++;
                break;
        }

        // Check if the character has reached the goal
        if (map[y][x] == 'O')
        {
            printf("You win!");
            break;
        }

        // Check if the character has reached a wall
        if (map[y][x] == '#')
        {
            printf("Game over!");
            break;
        }

        // Update the map
        map[y][x] = 'X';
    }

    return 0;
}