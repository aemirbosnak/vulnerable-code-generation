//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, cols;

    // Allocate memory for the game board
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    board = (int **)malloc(rows * sizeof(int *) + rows);
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int) + cols);
    }

    // Initialize the game board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Play the game
    int game_over = 0;
    while (!game_over)
    {
        // Display the game board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Get the next move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Check if the move is valid
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[row][col] = 1;

        // Check if the game is over
        game_over = check_game_over(board, rows, cols);
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}

int check_game_over(int **board, int rows, int cols)
{
    // Check if any of the rows has won
    for (int r = 0; r < rows; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == board[r][3])
        {
            return 1;
        }
    }

    // Check if any of the columns has won
    for (int c = 0; c < cols; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == board[3][c])
        {
            return 1;
        }
    }

    // Check if the diagonal has won
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3])
    {
        return 1;
    }

    // If there has not been a winner, return 0
    return 0;
}