//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[100][100];
int n;

void initBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
}

void drawBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int countAdj(int x, int y) {
    int count = 0;
    if (x > 0 && board[x-1][y] == 1) {
        count++;
    }
    if (x < n-1 && board[x+1][y] == 1) {
        count++;
    }
    if (y > 0 && board[x][y-1] == 1) {
        count++;
    }
    if (y < n-1 && board[x][y+1] == 1) {
        count++;
    }
    return count;
}

void percolate() {
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                int count = countAdj(i, j);
                if (count >= 3) {
                    continue;
                } else if (count == 2) {
                    srand(time(0));
                    int r = rand() % 2;
                    if (r == 0) {
                        board[i][j] = 0;
                    } else {
                        board[i][j] = 2;
                    }
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    srand(time(0));
    printf("Enter board size: ");
    scanf("%d", &n);
    initBoard();
    int x, y;
    printf("Enter starting point (x y): ");
    scanf("%d %d", &x, &y);
    board[x][y] = 1;
    int steps = 0;
    while (steps < n*n) {
        drawBoard();
        percolate();
        steps++;
    }
    return 0;
}