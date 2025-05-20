//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
/*
 * percolation_sim.c
 *
 * Percolation Simulator Example Program
 *
 * Created by Ken Thompson
 * Last Modified on 2023-03-15
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void percolation(int n) {
    int i, j;
    int grid[N][N];

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    printf("Initial grid:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    int top, bottom, left, right;
    int count = 0;

    while (count < n * n) {
        top = rand() % n;
        bottom = rand() % n;
        left = rand() % n;
        right = rand() % n;

        if (grid[top][bottom] == 1 && grid[left][right] == 1) {
            count++;
        }

        grid[top][bottom] = grid[left][right];
    }

    printf("Final grid:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows and columns: ");
    scanf("%d", &n);
    percolation(n);
    return 0;
}