//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(int board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == 2) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int checkWin(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }
    return 0;
}

int checkTie(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int getMove(int board[3][3]) {
    int move;
    do {
        printf("\nEnter your move (1-9): ");
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("\nInvalid move. Please try again.\n");
        }
    } while (move < 1 || move > 9);
    return move;
}

int main() {
    srand(time(NULL));
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    int validMove;
    int i, j;

    do {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        validMove = 0;
        while (!validMove) {
            choice = getMove(board);
            i = choice / 3;
            j = choice % 3;
            if (board[i][j] == 0) {
                board[i][j] = player;
                validMove = 1;
            }
        }
        player =!player;
        if (checkWin(board)) {
            drawBoard(board);
            printf("\nPlayer %d wins!\n", player);
            break;
        } else if (checkTie(board)) {
            drawBoard(board);
            printf("\nIt's a tie!\n");
            break;
        }
    } while (1);

    return 0;
}