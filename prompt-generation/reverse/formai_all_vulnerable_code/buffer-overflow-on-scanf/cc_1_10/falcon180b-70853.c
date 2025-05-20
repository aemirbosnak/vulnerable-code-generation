//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[100][100];
int n;
int m;
int count;
int threshold;

void initBoard() {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void printBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

void percolate() {
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                x = rand() % 3 - 1 + i;
                y = rand() % 3 - 1 + j;
                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 0) {
                    board[x][y] = 1;
                    count++;
                    if (count == threshold) {
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    printf("Enter the size of the board (n * m): ");
    scanf("%d %d", &n, &m);
    printf("Enter the threshold: ");
    scanf("%d", &threshold);
    initBoard();
    printBoard();
    percolate();
    printf("\nPercolation threshold reached in %d steps.\n", count);
    return 0;
}