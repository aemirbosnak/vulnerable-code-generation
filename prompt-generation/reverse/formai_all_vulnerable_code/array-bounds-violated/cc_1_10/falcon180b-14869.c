//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[100][100];
int n, m, k, x, y, count = 0;
int top, bottom, left, right;

void init_board() {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void display_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int check_neighbors(int i, int j) {
    int count = 0;
    if (i > 0 && board[i - 1][j] == 1) {
        count++;
    }
    if (i < n - 1 && board[i + 1][j] == 1) {
        count++;
    }
    if (j > 0 && board[i][j - 1] == 1) {
        count++;
    }
    if (j < m - 1 && board[i][j + 1] == 1) {
        count++;
    }
    return count;
}

void percolate() {
    int x, y, i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    }
    board[x][y] = 0;
    for (k = 0; k < 4; k++) {
        if (check_neighbors(x, y) == 1) {
            board[x][y] = 1;
            break;
        }
    }
    if (board[x][y] == 0) {
        count++;
    }
}

int main() {
    printf("Enter the size of the board (n and m): ");
    scanf("%d%d", &n, &m);
    init_board();
    printf("Initial board:\n");
    display_board();
    while (count < n * m) {
        percolate();
        printf("\n");
        printf("Board after %d percolations:\n", count + 1);
        display_board();
    }
    printf("\nGame over! Total percolations: %d\n", count);
    return 0;
}