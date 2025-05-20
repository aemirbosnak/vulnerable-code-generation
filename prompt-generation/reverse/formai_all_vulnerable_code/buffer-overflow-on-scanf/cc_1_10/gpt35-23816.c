//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIM 100
#define THRESHOLD 0.55

void print_array(int arr[MAX_DIM][MAX_DIM], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int is_percolated(int grid[MAX_DIM][MAX_DIM], int n) {
    int top_row[MAX_DIM] = {0}, bottom_row[MAX_DIM] = {0};
    int top_row_count = 0, bottom_row_count = 0;
    for (int i = 0; i < n; i++) {
        if (grid[0][i] == 1) {
            top_row[i] = 1;
            top_row_count++;
        }
        if (grid[n-1][i] == 1) {
            bottom_row[i] = 1;
            bottom_row_count++;
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (top_row[i] == 1 && bottom_row[i] == 1) {
            flag = 1;
            break;
        }
    }
    return flag;
}

void percolation(int grid[MAX_DIM][MAX_DIM], int n) {
    srand(time(NULL)); // seed random number generator with current time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float rand_num = (float)rand() / RAND_MAX;
            if (rand_num < THRESHOLD) {
                grid[i][j] = 1;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter dimension of grid: ");
    scanf("%d", &n);
    int grid[MAX_DIM][MAX_DIM] = {0};
    percolation(grid, n);
    printf("Percolation status:\n");
    print_array(grid, n);
    if (is_percolated(grid, n)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    return 0;
}