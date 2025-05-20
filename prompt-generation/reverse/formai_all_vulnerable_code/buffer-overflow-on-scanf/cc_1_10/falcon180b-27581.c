//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY '-'
#define PLAYER1 'X'
#define PLAYER2 'O'

void drawBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[3][3] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    int player = rand() % 2 + 1;
    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 1 || x > 3 || y < 1 || y > 3) {
            printf("Invalid move\n");
            continue;
        }
        if (board[x-1][y-1]!= EMPTY) {
            printf("Cell already occupied\n");
            continue;
        }
        board[x-1][y-1] = (player == 1)? PLAYER1 : PLAYER2;
        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }
    return 0;
}