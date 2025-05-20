//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, m, r;
    int board[200][200];

    printf("Enter the dimensions of the board (rows, columns): ");
    scanf("%d %d", &n, &m);

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            board[i][j] = rand() % 2;
        }
    }

    printf("Initial state:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    printf("Generation 1:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            r = board[i][j];
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                r = 0;
            }
            if (r == 0 && ((board[i - 1][j] == 1) || (board[i + 1][j] == 1) || (board[i][j - 1] == 1) || (board[i][j + 1] == 1))) {
                r = 1;
            } else if (r == 1 && ((board[i - 1][j] == 0) || (board[i + 1][j] == 0) || (board[i][j - 1] == 0) || (board[i][j + 1] == 0))) {
                r = 0;
            }
            board[i][j] = r;
        }
    }

    printf("\nGeneration 2:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}