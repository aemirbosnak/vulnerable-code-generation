//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

void draw_board(int **board)
{
    for(int r = 0; r < HEIGHT; r++)
    {
        for(int c = 0; c < WIDTH; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int**)malloc(HEIGHT * sizeof(int*));
    for(int r = 0; r < HEIGHT; r++)
    {
        board[r] = (int*)malloc(WIDTH * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board
    for(int r = 0; r < HEIGHT; r++)
    {
        for(int c = 0; c < WIDTH; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Simulate the game of life
    int generation = 0;
    while(1)
    {
        draw_board(board);
        printf("Generation: %d\n", generation++);

        // Calculate the next generation
        int **next_board = (int**)malloc(HEIGHT * sizeof(int*));
        for(int r = 0; r < HEIGHT; r++)
        {
            next_board[r] = (int*)malloc(WIDTH * sizeof(int));
        }

        for(int r = 0; r < HEIGHT; r++)
        {
            for(int c = 0; c < WIDTH; c++)
            {
                int neighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] && board[r + dr][c + dc] != 0)
                        {
                            neighbors++;
                        }
                    }
                }

                next_board[r][c] = (neighbors == 2 || neighbors == 3) && board[r][c] != 0 ? 1 : 0;
            }
        }

        // Free the old board
        for(int r = 0; r < HEIGHT; r++)
        {
            free(board[r]);
        }
        free(board);

        // Copy the next generation to the current board
        board = next_board;

        // Check if the game is over
        if(board[0][0] == 0 && board[HEIGHT - 1][WIDTH - 1] == 0)
        {
            break;
        }
    }

    draw_board(board);
    printf("Game Over!\n");

    // Free the board
    for(int r = 0; r < HEIGHT; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}