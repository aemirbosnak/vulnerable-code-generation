//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 9

// Define the Sudoku board
int board[BOARD_SIZE][BOARD_SIZE];

// Function to check if a number is safe to place in a given cell
int is_safe(int row, int col, int num)
{
    // Check row
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[row][i] == num)
            return 0;
    }

    // Check column
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][col] == num)
            return 0;
    }

    // Check box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 3 * box_row; i < 3 * box_row + 3; i++)
    {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++)
        {
            if (board[i][j] == num)
                return 0;
        }
    }

    // If all checks pass, then the number is safe to place
    return 1;
}

// Function to find an empty cell in the board
int find_empty_cell(int *row, int *col)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

// Function to solve the Sudoku board
int solve_sudoku()
{
    int row, col;

    // Find an empty cell
    if (!find_empty_cell(&row, &col))
        return 1; // Board is solved

    // For each possible number
    for (int num = 1; num <= BOARD_SIZE; num++)
    {
        // Check if the number is safe to place
        if (is_safe(row, col, num))
        {
            // Place the number in the cell
            board[row][col] = num;

            // Recursively solve the rest of the board
            if (solve_sudoku())
                return 1; // Board is solved

            // If the recursive call returns false, then the number is not safe to place
            board[row][col] = 0;
        }
    }

    // If no number is safe to place, then the Sudoku board is unsolvable
    return 0;
}

// Function to print the Sudoku board
void print_board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main()
{
    // Initialize the Sudoku board
    memset(board, 0, sizeof(board));

    // Read the Sudoku board from the user
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    // Solve the Sudoku board
    if (solve_sudoku())
    {
        // Print the solved Sudoku board
        print_board();
    }
    else
    {
        // Print an error message
        printf("The Sudoku board is unsolvable.\n");
    }

    return 0;
}