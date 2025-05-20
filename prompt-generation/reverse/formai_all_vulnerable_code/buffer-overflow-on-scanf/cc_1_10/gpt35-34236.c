//FormAI DATASET v1.0 Category: Sudoku solver ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

pthread_mutex_t lock;

// Function to print the grid
void print_grid()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

// Function to check if a value can be placed in a specific cell of the grid
bool check(int row, int col, int val)
{
    // Check if value is already present in the same row
    for (int j = 0; j < GRID_SIZE; j++)
        if (grid[row][j] == val)
            return false;
    
    // Check if value is already present in the same column
    for (int i = 0; i < GRID_SIZE; i++)
        if (grid[i][col] == val)
            return false;

    // Check if value is already present in the same 3x3 block
    int row_start = row - row % 3;
    int col_start = col - col % 3;
    for (int i = row_start; i < row_start + 3; i++)
        for (int j = col_start; j < col_start + 3; j++)
            if (grid[i][j] == val)
                return false;

    // If none of the above cases are true, the value can be placed in the cell
    return true;
}

// Function to solve the Sudoku puzzle
void* solve_sudoku(void* arg)
{
    int* ptr = (int*) arg;
    int row = ptr[0];
    int col = ptr[1];

    // If the row exceeds the grid size it means that the puzzle is solved!
    if (row == GRID_SIZE)
        return true;

    if (grid[row][col] != 0)
    {
        // If the cell already has a value, move on to the next one
        if (col == GRID_SIZE - 1)
            return solve_sudoku((void*) (int[2]){row + 1, 0});
        else
            return solve_sudoku((void*) (int[2]){row, col + 1});
    }
    
    // Try each value from 1 to 9
    for (int i = 1; i <= GRID_SIZE; i++)
    {
        if (check(row, col, i))
        {
            pthread_mutex_lock(&lock);

            grid[row][col] = i;

            if (col == GRID_SIZE - 1)
            {
                if (solve_sudoku((void*) (int[2]){row + 1, 0}))
                    return true;
            }
            else
            {
                if (solve_sudoku((void*) (int[2]){row, col + 1}))
                    return true;
            }

            grid[row][col] = 0;

            pthread_mutex_unlock(&lock);
        }
    }

    return false;
}

int main()
{
    printf("Enter your Sudoku puzzle: \n");
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            scanf("%d", &grid[i][j]);

    printf("Input puzzle:\n");
    print_grid();

    pthread_t thread;
    pthread_mutex_init(&lock, NULL);
    
    // Start solving the puzzle from the first cell
    int arg[2] = {0, 0};
    solve_sudoku((void*) arg);

    pthread_mutex_destroy(&lock);

    printf("Output puzzle:\n");
    print_grid();

    return 0;
}