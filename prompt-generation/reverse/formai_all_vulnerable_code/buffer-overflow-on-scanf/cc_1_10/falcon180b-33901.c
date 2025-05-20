//Falcon-180B DATASET v1.0 Category: Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = (i + j) % 3 + 1;
        }
    }
}

void printBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[][3]) {
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
    char board[3][3];
    generateBoard(board);
    printBoard(board);

    int player = 1;
    while (1) {
        int row, col;
        printf("Player %d's turn. Enter your move (row and column): ", player);
        scanf("%d%d", &row, &col);
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1]!= 0) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        board[row - 1][col - 1] = player;
        printBoard(board);

        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }

    return 0;
}