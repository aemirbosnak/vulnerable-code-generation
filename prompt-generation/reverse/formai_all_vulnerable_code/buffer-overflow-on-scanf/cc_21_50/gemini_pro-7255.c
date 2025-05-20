//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

int main() {
    int a[N][N], b[N][N], r[N][N], c[N][N], v[N][N][N];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    memset(v, 0, sizeof(v));
    int i, j, k, n = 0, x, y, z;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j]) {
                b[i][j] = 1;
                r[i][a[i][j]] = 1;
                c[j][a[i][j]] = 1;
                v[i / 3][j / 3][a[i][j]] = 1;
            } else {
                n++;
            }
        }
    }
    while (n) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (!a[i][j]) {
                    for (k = 1; k <= N; k++) {
                        if (!r[i][k] && !c[j][k] && !v[i / 3][j / 3][k]) {
                            a[i][j] = k;
                            r[i][k] = 1;
                            c[j][k] = 1;
                            v[i / 3][j / 3][k] = 1;
                            n--;
                            break;
                        }
                    }
                }
            }
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (a[i][j]) {
                    continue;
                }
                for (x = 0, k = 1; k <= N; k++) {
                    x += !r[i][k];
                }
                if (x == 1) {
                    for (k = 1; k <= N; k++) {
                        if (!r[i][k]) {
                            a[i][j] = k;
                            r[i][k] = 1;
                            c[j][k] = 1;
                            v[i / 3][j / 3][k] = 1;
                            n--;
                            break;
                        }
                    }
                }
                for (y = 0, k = 1; k <= N; k++) {
                    y += !c[j][k];
                }
                if (y == 1) {
                    for (k = 1; k <= N; k++) {
                        if (!c[j][k]) {
                            a[i][j] = k;
                            r[i][k] = 1;
                            c[j][k] = 1;
                            v[i / 3][j / 3][k] = 1;
                            n--;
                            break;
                        }
                    }
                }
                for (z = 0, k = 1; k <= N; k++) {
                    z += !v[i / 3][j / 3][k];
                }
                if (z == 1) {
                    for (k = 1; k <= N; k++) {
                        if (!v[i / 3][j / 3][k]) {
                            a[i][j] = k;
                            r[i][k] = 1;
                            c[j][k] = 1;
                            v[i / 3][j / 3][k] = 1;
                            n--;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}