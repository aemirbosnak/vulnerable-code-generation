//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int main() {
    int grid[SIZE][SIZE];
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    grid[0][0] = 1;
    grid[0][1] = 2;
    grid[0][2] = 3;
    grid[0][3] = 4;
    grid[1][0] = 5;
    grid[1][1] = 6;
    grid[1][2] = 7;
    grid[1][3] = 8;
    grid[2][0] = 9;
    grid[2][1] = 10;
    grid[2][2] = 11;
    grid[2][3] = 12;
    grid[3][0] = 13;
    grid[3][1] = 14;
    grid[3][2] = 15;
    grid[3][3] = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    while (1) {
        printf("Enter the number you want to move (0 to quit): ");
        scanf("%d", &x);
        if (x == 0) {
            break;
        }
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (grid[i][j] == x) {
                    a = i;
                    b = j;
                }
                if (grid[i][j] == 0) {
                    c = i;
                    d = j;
                }
            }
        }
        if (abs(a - c) + abs(b - d) != 1) {
            printf("Invalid move!\n");
        } else {
            grid[a][b] = 0;
            grid[c][d] = x;
        }
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}