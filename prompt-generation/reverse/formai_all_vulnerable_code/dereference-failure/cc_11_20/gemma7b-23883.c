//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main() {
    int **board = NULL;
    int i, j, k;

    board = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++) {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            board[i][j] = 0;
        }
    }

    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    k = 0;
    while (k < 10) {
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                int neighbors = 0;
                if (i > 0) neighbors++;
                if (i < MAX - 1) neighbors++;
                if (j > 0) neighbors++;
                if (j < MAX - 1) neighbors++;

                if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }

        k++;
    }

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    free(board);

    return 0;
}