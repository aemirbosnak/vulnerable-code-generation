//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define INF 1000000

// Function to check if a cell is reachable from the origin cell
int isReachable(int** board, int n, int m, int i, int j) {
    int visited[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
    visited[0][0] = 1;

    int queue[n * m];
    int front = 0, rear = 0;

    queue[rear++] = 0;
    while (front < rear) {
        int curr_cell = queue[front++];

        if (curr_cell == i && j == 0) {
            return 1;
        }
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < m; l++) {
                if (board[k][l] == 0 &&!visited[k][l] && isReachable(board, n, m, k, l)) {
                    queue[rear++] = k * m + l;
                    visited[k][l] = 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    int n, m;
    printf("Enter the dimensions of the board: ");
    scanf("%d %d", &n, &m);

    int** board = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        board[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = rand() % 2 == 0? 1 : 0;
        }
    }

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                if (isReachable(board, n, m, i, j)) {
                    board[i][j] = 1;
                }
            }
        }
    }

    printf("The percolation simulation for the given board is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    free(board);
    return 0;
}