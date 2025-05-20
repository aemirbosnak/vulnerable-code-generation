//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: brave
/* Brave C Percolation Simulator */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define OPEN 1
#define BLOCKED 0
#define PERCOLATED 2

int grid[ROWS][COLS];
int virtual_top[COLS];
int virtual_bottom[COLS];

// Function to check if a site is open
int is_open(int row, int col) {
    if (grid[row][col] == OPEN) {
        return 1;
    }
    return 0;
}

// Function to open a site
void open_site(int row, int col) {
    grid[row][col] = OPEN;
}

// Function to initialize the grid
void initialize() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = BLOCKED;
        }
    }
}

// Function to print the current grid
void print_grid() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == OPEN) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Function to connect two sites
void connect(int row1, int col1, int row2, int col2) {
    int index1 = row1 * COLS + col1;
    int index2 = row2 * COLS + col2;
    virtual_top[index1] = index2;
    virtual_bottom[index1] = index2;
}

// Function to check if a site is full
int is_full(int row, int col) {
    int index1 = row * COLS + col;
    if (grid[row][col] == OPEN) {
        if (virtual_top[index1] == index1) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the system percolates
int percolates() {
    for (int i = 0; i < COLS; i++) {
        int index1 = COLS + i;
        if (virtual_top[i] == index1 && virtual_bottom[i] == index1) {
            return PERCOLATED;
        }
    }
    return BLOCKED;
}

int main() {
    srand(time(0));
    initialize();
    print_grid();

    // Connect top row to virtual top
    for (int i = 0; i < COLS; i++) {
        virtual_top[i] = i;
    }

    // Connect bottom row to virtual bottom
    for (int i = 0; i < COLS; i++) {
        int index = (ROWS - 1) * COLS + i;
        virtual_bottom[index] = index;
    }

    // Simulation starts here
    int opened_count = 0;
    while (percolates() == BLOCKED) {
        int random_row = rand() % ROWS;
        int random_col = rand() % COLS;
        if (!is_open(random_row, random_col)) {
            open_site(random_row, random_col);
            connect(random_row, random_col, random_row - 1, random_col);
            connect(random_row, random_col, random_row + 1, random_col);
            connect(random_row, random_col, random_row, random_col - 1);
            connect(random_row, random_col, random_row, random_col + 1);
            opened_count++;
        }
        print_grid();
    }

    printf("\nPercolation achieved after %d sites opened.\n", opened_count);
    return 0;
}