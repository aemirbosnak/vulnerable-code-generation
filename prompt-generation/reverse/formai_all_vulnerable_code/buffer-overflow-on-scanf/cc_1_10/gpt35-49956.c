//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a cell in the Sudoku grid
typedef struct {
    int value;
    int row;
    int col;
    int subgrid;
} Cell;

// Constants
#define DIM 9
#define SUBGRID_DIM 3

// Global variables
Cell grid[DIM][DIM];
int numSolutions = 0;

// Function prototypes
void readInput();
void printGrid();
int isValid(Cell cell, int value);
int solve();
void solveSubgrid(int subgrid);
void solveCell(int row, int col);
int getSubgrid(int row, int col);

int main()
{
    readInput();
    printf("Input grid:\n");
    printGrid();
    numSolutions = solve();
    printf("\nNumber of solutions: %d\n", numSolutions);
    return 0;
}

// Read input from user
void readInput()
{
    printf("Enter Sudoku grid:\n");
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            scanf("%d", &grid[i][j].value);
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].subgrid = getSubgrid(i, j);
        }
    }
}

// Print the Sudoku grid
void printGrid()
{
    for (int i = 0; i < DIM; i++) {
        if (i % SUBGRID_DIM == 0 && i != 0) {
            printf("---------------------\n");
        }
        for (int j = 0; j < DIM; j++) {
            if (j % SUBGRID_DIM == 0 && j != 0) {
                printf("| ");
            }
            printf("%d ", grid[i][j].value);
        }
        printf("\n");
    }
}

// Check whether a value can be placed in a cell
int isValid(Cell cell, int value)
{
    // Check row and column
    for (int i = 0; i < DIM; i++) {
        if (grid[cell.row][i].value == value || grid[i][cell.col].value == value) {
            return 0;
        }
    }
    // Check subgrid
    int startRow = (cell.row / SUBGRID_DIM) * SUBGRID_DIM;
    int startCol = (cell.col / SUBGRID_DIM) * SUBGRID_DIM;
    for (int i = startRow; i < startRow + SUBGRID_DIM; i++) {
        for (int j = startCol; j < startCol + SUBGRID_DIM; j++) {
            if (grid[i][j].value == value) {
                return 0;
            }
        }
    }
    return 1;
}

// Recursive function to solve the Sudoku grid
int solve()
{
    // Find the first empty cell
    Cell cell = {0, 0, 0, 0};
    int foundEmpty = 0;
    for (int i = 0; i < DIM && !foundEmpty; i++) {
        for (int j = 0; j < DIM && !foundEmpty; j++) {
            if (grid[i][j].value == 0) {
                cell = grid[i][j];
                foundEmpty = 1;
            }
        }
    }
    // If all cells are filled, we have found a solution
    if (!foundEmpty) {
        printf("\nSolution:\n");
        printGrid();
        return 1;
    }
    // Try all values in the empty cell
    int numSolutions = 0;
    for (int i = 1; i <= DIM; i++) {
        if (isValid(cell, i)) {
            grid[cell.row][cell.col].value = i;
            numSolutions += solve();
            grid[cell.row][cell.col].value = 0;
        }
    }
    return numSolutions;
}

// Solve a subgrid (i.e. a 3x3 square)
void solveSubgrid(int subgrid)
{
    // Find all cells in the subgrid
    Cell cells[SUBGRID_DIM * SUBGRID_DIM];
    int count = 0;
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (grid[i][j].subgrid == subgrid) {
                cells[count++] = grid[i][j];
            }
        }
    }
    // Try all combinations of values in the subgrid
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            for (int k = 1; k <= DIM; k++) {
                if (isValid(cells[i], k) && isValid(cells[j], k)) {
                    cells[i].value = k;
                    cells[j].value = k;
                    solve();
                    cells[i].value = 0;
                    cells[j].value = 0;
                }
            }
        }
    }
}

// Solve a single cell (i.e. guess a value and check whether it leads to a solution)
void solveCell(int row, int col)
{
    // Try all values in the cell
    for (int i = 1; i <= DIM; i++) {
        if (isValid(grid[row][col], i)) {
            grid[row][col].value = i;
            int result = solve();
            if (result == 1) {
                printf("\nSolution:\n");
                printGrid();
                exit(0);
            }
            grid[row][col].value = 0;
        }
    }
}

// Get the subgrid number (0-8) of a cell
int getSubgrid(int row, int col)
{
    int subgridRow = row / SUBGRID_DIM;
    int subgridCol = col / SUBGRID_DIM;
    return subgridRow * SUBGRID_DIM + subgridCol;
}