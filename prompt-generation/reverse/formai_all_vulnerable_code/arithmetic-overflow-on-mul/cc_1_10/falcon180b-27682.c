//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define M 1000
#define T 1000

int percolation(int *grid, int n) {
    int i, j, k, count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i * n + j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void init(int *grid, int n) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            grid[i * n + j] = rand() % 2;
        }
    }
}

void display(int *grid, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i * n + j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    int *grid, n, m, t, i, j, count;
    printf("Enter the number of iterations: ");
    scanf("%d", &t);
    printf("Enter the size of the grid: ");
    scanf("%d", &n);
    printf("Enter the number of occupied cells: ");
    scanf("%d", &m);
    grid = (int *)malloc(n * n * sizeof(int));
    init(grid, n);
    display(grid, n);
    for (i = 0; i < t; i++) {
        for (j = 0; j < m; j++) {
            int x, y;
            do {
                x = rand() % n;
                y = rand() % n;
            } while (grid[y * n + x] == 1);
            grid[y * n + x] = 1;
        }
        count = percolation(grid, n);
        if (count == n * n) {
            printf("The system has percolated after %d iterations.\n", i + 1);
            break;
        }
    }
    display(grid, n);
    free(grid);
    return 0;
}