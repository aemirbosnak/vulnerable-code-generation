//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;
    char map[5][5] = {
        {'A', 'A', 'A', 'A', 'A'},
        {'A', 'S', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A'}
    };

    printf("Welcome to the cave!");

    // Get the player's position
    printf("Enter your position (x, y): ");
    scanf("%d %d", &x, &y);

    // Check if the player's position is valid
    if (x < 0 || x >= 5 || y < 0 || y >= 5)
    {
        printf("Invalid position.\n");
        return 1;
    }

    // Check if the player has already been there
    if (map[x][y] == 'S')
    {
        printf("You have already been there.\n");
        return 1;
    }

    // Set the player's position to 'S'
    map[x][y] = 'S';

    // Print the map
    for (z = 0; z < 5; z++)
    {
        for (int w = 0; w < 5; w++)
        {
            printf("%c ", map[z][w]);
        }
        printf("\n");
    }

    // Check if the player has won
    if (map[2][2] == 'S')
    {
        printf("You have won!\n");
    }
    else
    {
        printf("Try again.\n");
    }

    return 0;
}