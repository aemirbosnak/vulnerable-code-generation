//MISTRAL-7B DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SZ 9
#define BS 3

typedef struct { int v[SZ][SZ]; } mat;

void print(mat a) {
        int i, j;
        for (i = 0; i < SZ; i++) {
                for (j = 0; j < SZ; j++)
                        printf(j == 0 ? "%d" : "%d ", a.v[i][j]);
                putchar('\n');
        }
}

int empty(mat a, int r, int c) {
        return a.v[r][c] == 0;
}

int valid(mat a, int r, int c, int n) {
        int i, j, b, m;

        for (i = 0; i < SZ; i++)
                if (a.v[r][i] == n || a.v[i][c] == n) return 0;

        for (i = r, i -= BS; i >= 0; i -= BS)
                for (j = c, j -= BS; j >= 0; j -= BS)
                        if (a.v[i][j] == n) return 0;

        for (b = r, b += BS; b < SZ; b += BS)
                for (m = c, m += BS; m < SZ; m += BS)
                        if (a.v[b][m] == n) return 0;

        return 1;
}

int solve(mat a, int r, int c) {
        int n;

        if (c >= SZ) return r < SZ;

        if (empty(a, r, c))
                for (n = 1; n <= SZ; n++)
                        if (valid(a, r, c, n)) {
                                a.v[r][c] = n;
                                if (solve(a, r, c + 1)) return 1;
                                a.v[r][c] = 0;
                        }

        return 0;
}

int main() {
        mat a;
        int i, j, k;

        for (i = 0; i < SZ; i++)
                for (j = 0; j < SZ; j++)
                        if (scanf("%d", &a.v[i][j]) != 1 || a.v[i][j] < 1 || a.v[i][j] > SZ) {
                                fprintf(stderr, "Bad input!\n");
                                return 1;
                        }

        for (k = 0; k < 81 && solve(a, 0, k); k++);

        if (k < 81) {
                fprintf(stderr, "Cannot solve this Sudoku!\n");
                return 1;
        }

        print(a);

        return 0;
}