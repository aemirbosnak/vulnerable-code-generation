//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// function prototypes
void print_grid(int grid[SIZE][SIZE]);
int percolates(int grid[SIZE][SIZE]);
void fill_grid(int grid[SIZE][SIZE], float p);

int main() {
    int grid[SIZE][SIZE];
    float p;

    printf("Enter probability of filling a cell: ");
    scanf("%f", &p);

    srand(time(0));  // seed random number generator

    // initialize grid with randomly filled cells
    fill_grid(grid, p);

    printf("\nInitial grid:\n");
    print_grid(grid);

    // check if the system percolates
    if (percolates(grid)) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }

    return 0;
}

// function to fill the grid randomly with cells filled with probability p
void fill_grid(int grid[SIZE][SIZE], float p) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (((float) rand() / RAND_MAX) < p) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// function to print the grid
void print_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if the system percolates
int percolates(int grid[SIZE][SIZE]) {
    int top[SIZE * SIZE], bottom[SIZE * SIZE];  // arrays to store open cells in top and bottom rows
    int top_size = 0, bottom_size = 0;
    int visited[SIZE][SIZE] = {0};  // 2D array to store visited cells
    int queue[SIZE * SIZE][2];  // array to simulate queue for BFS
    int head = 0, tail = 0;

    // add first row cells to queue and mark as visited
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j] == 1) {
            queue[tail][0] = 0;
            queue[tail][1] = j;
            visited[0][j] = 1;
            tail++;
            top[top_size] = j;
            top_size++;
        }
    }

    // BFS to find all open cells connected to the top row
    while (head != tail) {
        int row = queue[head][0];
        int col = queue[head][1];
        head++;

        // check each neighbor to see if it is open and not already visited
        if (row > 0 && grid[row - 1][col] == 1 && visited[row - 1][col] == 0) {
            queue[tail][0] = row - 1;
            queue[tail][1] = col;
            visited[row - 1][col] = 1;
            tail++;
        }
        if (row < SIZE - 1 && grid[row + 1][col] == 1 && visited[row + 1][col] == 0) {
            queue[tail][0] = row + 1;
            queue[tail][1] = col;
            visited[row + 1][col] = 1;
            tail++;
        }
        if (col > 0 && grid[row][col - 1] == 1 && visited[row][col - 1] == 0) {
            queue[tail][0] = row;
            queue[tail][1] = col - 1;
            visited[row][col - 1] = 1;
            tail++;
        }
        if (col < SIZE - 1 && grid[row][col + 1] == 1 && visited[row][col + 1] == 0) {
            queue[tail][0] = row;
            queue[tail][1] = col + 1;
            visited[row][col + 1] = 1;
            tail++;
        }
    }

    // check if any of the open cells in the bottom row are connected to an open cell in the top row
    for (int j = 0; j < SIZE; j++) {
        if (grid[SIZE - 1][j] == 1 && visited[SIZE - 1][j] == 1) {
            for (int k = 0; k < top_size; k++) {
                if (j == top[k]) {
                    return 1;
                }
            }
        }
    }

    return 0;
}