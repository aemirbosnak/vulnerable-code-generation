//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
/*
 * Sudoku Solver in C by [Your Name]
 * Inspired by Linus Torvalds' coding style
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9

/* Cross-platform clear terminal function */
void clear_screen()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    system("cls");
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif
}

/* Function to print the current state of the sudoku board */
void print_board(int board[ROWS][COLS])
{
    printf("+-------+-------+-------+\n");
    for (int i = 0; i < ROWS; i++)
    {
        if (i % 3 == 0)
        {
            printf("|-------+-------+-------|\n");
        }
        printf("| ");
        for (int j = 0; j < COLS; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                printf("| ");
            }
            printf("%d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("+-------+-------+-------+\n");
}

/* Helper function to check if a number is safe to be placed in a specific cell */
int is_safe(int board[ROWS][COLS], int row, int col, int num)
{
    /* Check if the same number exists in the current row */
    for (int c = 0; c < COLS; c++)
    {
        if (board[row][c] == num)
        {
            return 0;
        }
    }

    /* Check if the same number exists in the current column */
    for (int r = 0; r < ROWS; r++)
    {
        if (board[r][col] == num)
        {
            return 0;
        }
    }

    /* Check if the same number exists in the current 3x3 box */
    int box_start_row = row - (row % 3);
    int box_start_col = col - (col % 3);
    for (int r = box_start_row; r < box_start_row + 3; r++)
    {
        for (int c = box_start_col; c < box_start_col + 3; c++)
        {
            if (board[r][c] == num)
            {
                return 0;
            }
        }
    }

    /* If the number doesn't exist in the current row, column or box, it's safe to be placed in the cell */
    return 1;
}

/* Recursive function to solve the sudoku puzzle */
int solve_sudoku(int board[ROWS][COLS], int row, int col)
{
    /* If we reached the end of the board, the puzzle is solved */
    if (row == ROWS)
    {
        return 1;
    }

    /* If we reached the end of the current row, move to the next row */
    if (col == COLS)
    {
        return solve_sudoku(board, row + 1, 0);
    }

    /* If the cell is already filled, move to the next column */
    if (board[row][col] != 0)
    {
        return solve_sudoku(board, row, col + 1);
    }

    /* Try numbers from 1 to 9 */
    for (int num = 1; num <= 9; num++)
    {
        /* Check if the current number is safe to be placed in the current cell */
        if (is_safe(board, row, col, num))
        {
            /* Place the current number in the current cell */
            board[row][col] = num;

            /* Recursively solve the rest of the puzzle */
            if (solve_sudoku(board, row, col + 1))
            {
                return 1;
            }
        }

        /* Backtrack if the current number couldn't solve the puzzle */
        board[row][col] = 0;
    }

    /* If no number from 1 to 9 can solve the puzzle, backtrack and try a different number */
    return 0;
}

int main()
{
    int sudoku[ROWS][COLS];

    /* Read the initial state of the sudoku board */
    printf("Enter the initial state of the sudoku board:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scanf("%d", &sudoku[i][j]);
        }
    }

    /* Solve the sudoku puzzle */
    solve_sudoku(sudoku, 0, 0);

    /* Print the solved puzzle */
    clear_screen();
    printf("Solved Sudoku:\n");
    print_board(sudoku);

    return 0;
}