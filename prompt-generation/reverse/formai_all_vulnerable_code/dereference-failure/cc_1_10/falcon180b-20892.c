//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 10
#define P 0.5
#define T 1

int **create_grid();
void percolation(int **grid);
void print_grid(int **grid);
int check_neighbors(int **grid, int i, int j);

int main() {
    srand(time(NULL));
    int **grid = create_grid();
    percolation(grid);
    print_grid(grid);
    return 0;
}

int **create_grid() {
    int **grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(M * sizeof(int));
        for (int j = 0; j < M; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}

void percolation(int **grid) {
    int n, m, p, t;
    printf("Enter the number of rows (N): ");
    scanf("%d", &n);
    printf("Enter the number of columns (M): ");
    scanf("%d", &m);
    printf("Enter the probability of a site being open (P): ");
    scanf("%d", &p);
    printf("Enter the number of trials (T): ");
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int x = rand() % n;
        int y = rand() % m;
        if (check_neighbors(grid, x, y)) {
            grid[x][y] = 1;
        }
    }
}

void print_grid(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int check_neighbors(int **grid, int i, int j) {
    int count = 0;
    if (i > 0 && grid[i - 1][j] == 1) {
        count++;
    }
    if (i < N - 1 && grid[i + 1][j] == 1) {
        count++;
    }
    if (j > 0 && grid[i][j - 1] == 1) {
        count++;
    }
    if (j < M - 1 && grid[i][j + 1] == 1) {
        count++;
    }
    return count > 0? 1 : 0;
}