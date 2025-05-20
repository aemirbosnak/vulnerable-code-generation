//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define EMPTY '.'
#define BLACK 'B'
#define WHITE 'W'

char board[SIZE][SIZE];

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initBoard();

    int player = 1;
    while (1) {
        printBoard();
        printf("\nPlayer %d's turn\n", player);
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x][y]!= EMPTY) {
            printf("Invalid move\n");
            continue;
        }
        board[x][y] = (player == 1)? BLACK : WHITE;
        player = (player == 1)? 2 : 1;
        if (checkWin(x, y)) {
            printf("Player %d wins!\n", player);
            break;
        }
    }

    return 0;
}

int checkWin(int x, int y) {
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == board[x][y]) {
            count++;
        }
    }

    if (count >= 5) {
        return 1;
    }

    return 0;
}