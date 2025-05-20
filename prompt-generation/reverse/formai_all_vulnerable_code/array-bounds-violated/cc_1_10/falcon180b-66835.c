//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int player = 1;
int moves = 0;
int choice;
int flag = 0;

void drawBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 1)
                printf("X ");
            else if (board[i][j] == -1)
                printf("O ");
            else
                printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    int i, j;
    for (i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return 1;
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return 1;

    return 0;
}

int checkDraw() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] == 0)
                return 0;
    return 1;
}

void changePlayer() {
    if (player == 1)
        player = -1;
    else
        player = 1;
}

void computerMove() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = -1;
                moves++;
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
}

int main() {
    srand(time(NULL));
    int i, j;
    printf("Player 1: X, Player 2: O\n");
    for (i = 0; i < 9; i++) {
        drawBoard();
        int validInput = 0;
        while (!validInput) {
            printf("Player %d, enter your move: ", player);
            scanf("%d", &choice);
            if (choice >= 1 && choice <= 9) {
                if (board[choice / 3][choice % 3] == 0) {
                    board[choice / 3][choice % 3] = player;
                    moves++;
                    validInput = 1;
                } else
                    printf("Invalid move, try again.\n");
            } else
                printf("Invalid move, try again.\n");
        }
        flag = 0;
        while (!flag) {
            computerMove();
            drawBoard();
            if (checkWin()) {
                printf("Player %d wins!\n", -player);
                break;
            } else if (checkDraw()) {
                printf("It's a draw.\n");
                break;
            }
            changePlayer();
        }
    }
    return 0;
}