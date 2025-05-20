//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9

// The 3x3 subgrids are:
// 0 1 2
// 3 4 5
// 6 7 8
typedef struct {
    int grid[MAX][MAX];
    int solved;
    int time;
} Sudoku;

// Check if the given number is in the row
int in_row(Sudoku *s, int r, int n)
{
    for (int c = 0; c < MAX; c++)
        if (s->grid[r][c] == n)
            return 1;
    return 0;
}

// Check if the given number is in the column
int in_col(Sudoku *s, int c, int n)
{
    for (int r = 0; r < MAX; r++)
        if (s->grid[r][c] == n)
            return 1;
    return 0;
}

// Check if the given number is in the 3x3 subgrid
int in_box(Sudoku *s, int r, int c, int n)
{
    int box_r = r / 3;
    int box_c = c / 3;
    for (int i = box_r * 3; i < box_r * 3 + 3; i++)
        for (int j = box_c * 3; j < box_c * 3 + 3; j++)
            if (s->grid[i][j] == n)
                return 1;
    return 0;
}

// Check if the given number is valid in the given cell
int is_valid(Sudoku *s, int r, int c, int n)
{
    return !in_row(s, r, n) && !in_col(s, c, n) && !in_box(s, r, c, n);
}

// Solve the Sudoku recursively
void solve(Sudoku *s)
{
    // If all cells are filled, the Sudoku is solved
    if (s->solved)
        return;

    // Find an empty cell
    int r, c;
    for (r = 0; r < MAX; r++) {
        for (c = 0; c < MAX; c++) {
            if (s->grid[r][c] == 0)
                goto found;
        }
    }

found:
    // Try all possible numbers for the empty cell
    for (int n = 1; n <= MAX; n++) {
        if (is_valid(s, r, c, n)) {
            // Fill the cell with the number
            s->grid[r][c] = n;

            // Recursively solve the Sudoku
            solve(s);

            // If the Sudoku is solved, return
            if (s->solved)
                return;

            // If the Sudoku is not solved, reset the cell to empty
            s->grid[r][c] = 0;
        }
    }

    // If no valid number can be placed in the cell, the Sudoku is unsolvable
    s->solved = 0;
}

// Print the Sudoku
void print(Sudoku *s)
{
    for (int r = 0; r < MAX; r++) {
        for (int c = 0; c < MAX; c++) {
            printf("%d ", s->grid[r][c]);
        }
        printf("\n");
    }
}

// Get the Sudoku from the user
void get(Sudoku *s)
{
    for (int r = 0; r < MAX; r++) {
        for (int c = 0; c < MAX; c++) {
            scanf("%d ", &s->grid[r][c]);
        }
    }
}

// Main function
int main()
{
    Sudoku s;
    get(&s);
    solve(&s);
    if (s.solved) {
        printf("Solved:\n");
        print(&s);
    } else {
        printf("Unsolvable\n");
    }
    return 0;
}