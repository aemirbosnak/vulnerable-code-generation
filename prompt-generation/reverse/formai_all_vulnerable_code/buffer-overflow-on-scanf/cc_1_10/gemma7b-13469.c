//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GHOST_NUMBER 5
#define GHOST_DELAY 2

int main()
{
    srand(time(NULL));
    int i, j, score = 0, ghosts_left = GHOST_NUMBER;

    // Create a haunted house map
    char map[10][10] = {
        {'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
        {'H', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'H'},
        {'H', 'O', 'R', 'O', 'R', 'O', 'R', 'O', 'O', 'H'},
        {'H', 'O', 'R', 'O', 'R', 'O', 'R', 'O', 'O', 'H'},
        {'H', 'O', 'R', 'O', 'R', 'O', 'R', 'O', 'O', 'H'},
        {'H', 'O', 'R', 'O', 'R', 'O', 'R', 'O', 'O', 'H'},
        {'H', 'O', 'R', 'O', 'R', 'O', 'R', 'O', 'O', 'H'},
        {'H', 'O', 'R', 'O', 'R', 'O', 'R', 'O', 'O', 'H'},
        {'H', 'O', 'R', 'O', 'R', 'O', 'R', 'O', 'O', 'H'},
        {'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'}
    };

    // Move the ghosts
    for (i = 0; i < GHOST_NUMBER; i++)
    {
        int x = rand() % 10;
        int y = rand() % 10;
        map[x][y] = 'G';
    }

    // Play the game
    while (ghosts_left > 0)
    {
        // Get the player's input
        int move_x, move_y;
        printf("Enter move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Check if the move is valid
        if (move_x < 0 || move_x >= 10 || move_y < 0 || move_y >= 10)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is a ghost
        if (map[move_x][move_y] == 'G')
        {
            printf("Boo! You have encountered a ghost.\n");
            ghosts_left--;
            score++;
        }
        else
        {
            printf("You moved to a safe spot.\n");
        }

        // Print the map
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        // Sleep for a while
        sleep(GHOST_DELAY);
    }

    // End the game
    printf("You have won! Your score is: %d\n", score);

    return 0;
}