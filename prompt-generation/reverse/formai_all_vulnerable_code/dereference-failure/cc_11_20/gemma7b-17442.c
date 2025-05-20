//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void draw_board(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Place some random cells
    board[5][5] = 1;
    board[1][1] = 1;
    board[1][3] = 1;
    board[3][3] = 1;

    // Game loop
    int generation = 0;
    while (1)
    {
        draw_board(board);
        printf("Generation: %d\n", generation++);

        // Calculate the next generation
        for (int r = 0; r < MAX_SIZE; r++)
        {
            for (int c = 0; c < MAX_SIZE; c++)
            {
                int neighbours = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] && board[r + dr][c + dc] != 0)
                        {
                            neighbours++;
                        }
                    }
                }

                if (board[r][c] == 0 && neighbours == 3)
                {
                    board[r][c] = 1;
                }
                else if (board[r][c] == 1 && (neighbours < 2 || neighbours > 3))
                {
                    board[r][c] = 0;
                }
            }
        }

        // Check if the game is over
        if (board[MAX_SIZE - 1][MAX_SIZE - 1] == 1)
        {
            break;
        }
    }

    draw_board(board);
    printf("Game Over!\n");

    // Free the memory
    for (int r = 0; r < MAX_SIZE; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}