//FormAI DATASET v1.0 Category: Sudoku solver ; Style: rigorous
// Sudoku Solver in C
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9      // Define the size of the Sudoku grid

bool FindUnassignedLocation(int board[SIZE][SIZE], int *row, int *col);
bool isSafe(int board[SIZE][SIZE], int row, int col, int num);
void PrintSudokuGrid(int board[SIZE][SIZE]);
bool SolveSudokuGrid(int board[SIZE][SIZE]);

/** Function to find unassigned location in the grid */
bool FindUnassignedLocation(int board[SIZE][SIZE], int *row, int *col)
{
    for(*row=0; *row<SIZE; (*row)++)
    {
        for(*col=0; *col<SIZE; (*col)++)
        {
            if(board[*row][*col] == 0)  // If the cell is unassigned
                return true;
        }
    }
    return false;   // Return false if all cells are assigned
}

/** Function to check if the number is safe to place in the cell */
bool isSafe(int board[SIZE][SIZE], int row, int col, int num)
{
    // Check if the number exists in the row
    for(int i=0; i<SIZE; i++)
    {
        if(board[row][i] == num)
            return false;
    }
    
    // Check if the number exists in the column
    for(int i=0; i<SIZE; i++)
    {
        if(board[i][col] == num)
            return false;
    }
    
    // Check if the number exists in the 3x3 grid
    int boxrow = row - row%3;
    int boxcol = col - col%3;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i+boxrow][j+boxcol] == num)
                return false;
        }
    }
    
    // If all conditions met, the number is safe to place in the cell
    return true;
}

/** Function to print the Sudoku grid */
void PrintSudokuGrid(int board[SIZE][SIZE])
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

/** Function to solve the Sudoku grid */
bool SolveSudokuGrid(int board[SIZE][SIZE])
{
    int row, col;
    if(!FindUnassignedLocation(board, &row, &col))
        return true;    // If all cells are assigned, return true
    
    for(int num=1; num<=9; num++)
    {
        if(isSafe(board, row, col, num))
        {
            board[row][col] = num;  // Assign the number to the cell
            
            if(SolveSudokuGrid(board))
                return true;        // If solution is found, return true
            
            board[row][col] = 0;    // Backtrack
        }
    }
    return false;   // Return false if the solution is not found
}

/** Main function */
int main()
{
    int board[SIZE][SIZE];
    printf("Enter the Sudoku grid (Use 0 for unassigned cells):\n");
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    
    if(SolveSudokuGrid(board))
    {
        printf("\nSolution:\n");
        PrintSudokuGrid(board);
    }
    else
    {
        printf("\nNo solution exists\n");
    }
    return 0;
}