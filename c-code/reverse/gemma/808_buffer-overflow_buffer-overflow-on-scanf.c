#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, i, j, treasure_x, treasure_y;

    // Seed the random number generator
    srand(time(NULL));

    // Create a 5x5 grid
    char grid[25] = {'#'};
    grid[rand() % 25] = 'T';

    // Get the player's input
    printf("Enter your move (w/a/s/d): ");
    scanf("%c", &x);

    // Check if the player has won
    if (grid[x + 5 * y] == 'T')
    {
        printf("You have won!");
    }
    else
    {
        printf("You have lost.");
    }

    return 0;
}
