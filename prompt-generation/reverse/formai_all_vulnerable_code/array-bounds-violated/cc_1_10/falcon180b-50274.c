//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void initBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void movePiece(char board[SIZE][SIZE], int x1, int y1, int x2, int y2, char piece) {
    if (board[x1][y1] == piece && board[x2][y2] == '.') {
        board[x1][y1] = '.';
        board[x2][y2] = piece;
    }
}

int checkWin(char board[SIZE][SIZE], char piece) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == piece) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(0));
    char board[SIZE][SIZE];
    initBoard(board);
    int player = 1;
    while (1) {
        system("clear");
        printBoard(board);
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x][y] == '.' && (x + y) % 2 == player) {
            movePiece(board, x, y, x, y, 'X');
            player++;
        }
        if (checkWin(board, 'X')) {
            printf("Player %d wins!\n", player);
            break;
        }
    }
    return 0;
}