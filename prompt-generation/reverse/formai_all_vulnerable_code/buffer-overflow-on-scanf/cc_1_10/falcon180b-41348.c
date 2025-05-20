//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void drawBoard(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1)
                printf("X ");
            else if (board[i][j] == 2)
                printf("O ");
            else
                printf("_ ");
        }
        printf("\n");
    }
}

int checkWin(int board[ROWS][COLS]) {
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[i][0] == board[i][2] && board[i][2] == board[i][1]) ||
            (board[i][1] == board[i][0] && board[i][0] == board[i][2]))
            return 1;
    }

    // Check columns
    for (i = 0; i < COLS; i++) {
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
            (board[0][i] == board[2][i] && board[2][i] == board[1][i]) ||
            (board[1][i] == board[0][i] && board[0][i] == board[2][i]))
            return 1;
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return 1;

    return 0;
}

void playGame(int board[ROWS][COLS]) {
    int player = 1;
    int choice;
    while (1) {
        drawBoard(board);
        printf("Player %d's turn\n", player);
        printf("Enter your move (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &choice);
        if (choice < 1 || choice > ROWS * COLS - 1) {
            printf("Invalid move, try again.\n");
            continue;
        }

        int row = choice / COLS;
        int col = choice % COLS;

        if (board[row][col]!= 0) {
            printf("Invalid move, try again.\n");
            continue;
        }

        board[row][col] = player;

        if (checkWin(board)) {
            drawBoard(board);
            printf("Player %d wins!\n", player);
            break;
        }

        player =!player;
    }
}

int main() {
    int board[ROWS][COLS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    playGame(board);
    return 0;
}