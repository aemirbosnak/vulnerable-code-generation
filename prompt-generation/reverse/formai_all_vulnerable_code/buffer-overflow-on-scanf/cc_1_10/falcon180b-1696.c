//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[3][3], char player) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    char board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
    int player = rand() % 2;
    char mark;
    if (player == 0) {
        mark = 'X';
    } else {
        mark = 'O';
    }

    while (1) {
        system("clear");
        printf("Player 1: X, Player 2: O\n");
        drawBoard(board);
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) {
            printf("Invalid move, try again.\n");
            continue;
        }
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (board[row][col]!= '-') {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[row][col] = mark;
        if (checkWin(board, mark)) {
            drawBoard(board);
            printf("%c wins!\n", mark);
            break;
        }
        player =!player;
        if (player == 0) {
            mark = 'X';
        } else {
            mark = 'O';
        }
    }

    return 0;
}