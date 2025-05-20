//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define M 1000
#define P 0.5
#define T 3

int **grid;
int n, m, count = 0;

void create_grid() {
    grid = (int **) malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *) malloc(M * sizeof(int));
        for (int j = 0; j < M; j++) {
            grid[i][j] = 0;
        }
    }
}

void percolate() {
    int x, y, dx, dy;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) {
                dx = (rand() % 3) - 1;
                dy = (rand() % 3) - 1;
                while (dx < 0) {
                    dx++;
                }
                while (dy < 0) {
                    dy++;
                }
                while (dx >= 0 && dx < 3 && dy >= 0 && dy < 3) {
                    x = i + dx;
                    y = j + dy;
                    if (x >= 0 && x < N && y >= 0 && y < M && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        count++;
                    }
                    dx++;
                    dy++;
                }
            }
        }
    }
}

void display_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    create_grid();
    for (int t = 0; t < T; t++) {
        percolate();
    }
    display_grid();
    printf("Total sites occupied: %d\n", count);
    return 0;
}