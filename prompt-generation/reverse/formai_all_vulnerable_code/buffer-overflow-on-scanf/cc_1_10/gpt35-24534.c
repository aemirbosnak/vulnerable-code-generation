//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>

#define MAX_SIZE 9

int sudoku[MAX_SIZE][MAX_SIZE];

/* Function to print the Sudoku grid */ 
void printSudoku() { 
    for (int i = 0; i < MAX_SIZE; i++) { 
        for (int j = 0; j < MAX_SIZE; j++) 
            printf("%d ", sudoku[i][j]); 
        printf("\n"); 
    } 
}

/* Function to check if current position is safe */
int isSafe(int row, int col, int num) { 
    // Checking row and column
    for (int i = 0; i < MAX_SIZE; i++) { 
        if (sudoku[row][i] == num || sudoku[i][col] == num) 
            return 0;
    }
      
    // Checking subgrid of 3x3
    int subgrid_row = row - (row % 3), subgrid_col = col - (col % 3);
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            if (sudoku[i + subgrid_row][j + subgrid_col] == num) 
                return 0; 

    return 1; 
} 

/* Function to solve the Sudoku grid */
int solveSudoku(int row, int col) { 
    // If we reached the end of row, move to next row
    if (col == MAX_SIZE) { 
        row++; 
        col = 0; 
    } 

    // If we reached the end of the grid, we are done
    if (row == MAX_SIZE) 
        return 1;
      
    // If the current position is not empty
    if (sudoku[row][col] != 0) 
        return solveSudoku(row, col + 1); 

    // Trying different numbers
    for (int i = 1; i <= MAX_SIZE; i++) { 
        if (isSafe(row, col, i)) { 
            sudoku[row][col] = i; 
            if (solveSudoku(row, col + 1)) 
                return 1; 
        } 
        sudoku[row][col] = 0; 
    } 
    return 0; 
} 

int main() {
    // Initializing Sudoku grid
    for(int i = 0; i < MAX_SIZE; i++) {
      for(int j = 0; j < MAX_SIZE; j++) {
        printf("Enter value for row %d and column %d (0 for empty box): ", i, j);
        scanf("%d", &sudoku[i][j]);
      }
   }
    
   // Solving Sudoku grid
   if (solveSudoku(0, 0) == 1) 
       printSudoku(); 
   else
       printf("No solution exists"); 

    return 0;
}