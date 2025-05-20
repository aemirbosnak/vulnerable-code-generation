//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int **)malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Game loop
    while (1)
    {
        // Print the board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Get the next move
        int x, y;
        printf("Enter the x coordinate: ");
        scanf("%d", &x);

        printf("Enter the y coordinate: ");
        scanf("%d", &y);

        // Check if the move is valid
        if (x < 0 || x >= rows || y < 0 || y >= cols)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[x][y] = 1;

        // Check if the game is over
        if (check_game_over(board, rows, cols))
        {
            printf("Game over.\n");
            break;
        }
    }

    return 0;
}

int check_game_over(int **board, int rows, int cols)
{
    // Check if the player has won
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (board[r][c] == 1)
            {
                // Check if the player has won vertically
                if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == board[r][3])
                {
                    return 1;
                }

                // Check if the player has won horizontally
                if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == board[3][c])
                {
                    return 1;
                }
            }
        }
    }

    // If the player has not won, check if the board is full
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (board[r][c] == 0)
            {
                return 0;
            }
        }
    }

    // If the board is full, the game is over
    return 1;
}