//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **board = NULL;
    int size = 0;
    int i = 0, j = 0, k = 0, l = 0;
    int **direction = NULL;
    int moves = 0;

    board = malloc(sizeof(char *) * 5);
    for (i = 0; i < 5; i++)
    {
        board[i] = malloc(sizeof(char) * 5);
    }

    direction = malloc(sizeof(int *) * 5);
    for (i = 0; i < 5; i++)
    {
        direction[i] = malloc(sizeof(int) * 5);
    }

    // Initialize the board and direction
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            board[i][j] = ' ';
            direction[i][j] = -1;
        }
    }

    board[2][2] = 'O';

    // Game loop
    while (board[2][2] != 'X')
    {
        // Get the move
        printf("Enter your move (e.g. 0-4,0-4): ");
        scanf("%d-%d", &k, &l);

        // Validate the move
        if (k < 0 || k >= 5 || l < 0 || l >= 5)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        direction[k][l] = 1;
        board[k][l] = 'O';

        // Check if the player has won
        if (board[k][l] == 'X')
        {
            printf("You have won!\n");
            break;
        }

        // Increment the number of moves
        moves++;

        // Print the board
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Print the number of moves
        printf("Number of moves: %d\n", moves);
    }

    // Free the memory
    for (i = 0; i < 5; i++)
    {
        free(board[i]);
    }
    free(board);

    for (i = 0; i < 5; i++)
    {
        free(direction[i]);
    }
    free(direction);

    return 0;
}