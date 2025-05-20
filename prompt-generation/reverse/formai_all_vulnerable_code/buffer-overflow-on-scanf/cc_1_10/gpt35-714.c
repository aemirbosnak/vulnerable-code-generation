//FormAI DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>

#define UNASSIGNED 0
#define N 9

int grid[N][N];

// Function to check if the given digit is already present in the current row
int used_in_row(int row, int num){
    for (int col = 0; col < N; col++){
        if (grid[row][col] == num)
            return 1;
    }
    return 0;
}

// Function to check if the given digit is already present in the current column
int used_in_col(int col, int num){
    for (int row = 0; row < N; row++){
        if (grid[row][col] == num)
            return 1;
    }
    return 0;
}

// Function to check if the given digit is already present within the current 3x3 sub-grid
int used_in_box(int box_start_row, int box_start_col, int num){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (grid[row + box_start_row][col + box_start_col] == num)
                return 1;
        }
    }
    return 0;
}

// Function to determine whether a given location is safe to add a number
int is_safe(int row, int col, int num){
    return !used_in_row(row, num) && !used_in_col(col, num) && !used_in_box(row - row%3, col - col%3, num);
}

// Function to find an unassigned location on the sudoku grid
int find_unassigned_location(int *row, int *col){
    for (*row = 0; *row < N; (*row)++){
        for (*col = 0; *col < N; (*col)++){
            if (grid[*row][*col] == UNASSIGNED)
                return 1;
        }
    }
    return 0;
}

// Function to print the solved sudoku grid
void print_grid(void){
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            printf("%2d", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to solve the sudoku puzzle
int solve_sudoku(void){
    int row, col;
    if (!find_unassigned_location(&row, &col))
        return 1;
    for (int num = 1; num <= N; num++){
        if (is_safe(row, col, num)){
            grid[row][col] = num;
            if (solve_sudoku())
                return 1;
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

int main(void){
    // Enter numbers in the grid, with 0s representing unassigned cells
    printf("Enter the Sudoku puzzle grid:\n");
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            scanf("%d", &grid[row][col]);
        }
    }

    // Solve the sudoku puzzle and print the solution if one exists
    if (solve_sudoku()){
        printf("\nThe solved Sudoku puzzle is:\n");
        print_grid();
    } else {
        printf("\nNo solution exists for the entered Sudoku puzzle.\n");
    }
    return 0;
}