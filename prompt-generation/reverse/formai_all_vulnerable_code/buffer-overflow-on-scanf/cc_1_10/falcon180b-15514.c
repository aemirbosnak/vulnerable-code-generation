//Falcon-180B DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_PLAYERS 2

void drawBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkForWinner(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void playGame(char board[BOARD_SIZE][BOARD_SIZE], int turn) {
    int x, y;
    printf("Player %d's turn.\n", turn + 1);
    printf("Enter your move (row and column): ");
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == '\0') {
        board[x][y] = (turn % 2 == 0)? 'X' : 'O';
        if (checkForWinner(board) == 1) {
            printf("Player %d wins!\n", turn + 1);
            exit(0);
        }
        turn++;
    } else {
        printf("Invalid move. Try again.\n");
    }
}

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE] = { { '\0', '\0', '\0' },
                                             { '\0', '\0', '\0' },
                                             { '\0', '\0', '\0' } };

    int turn = 0;
    while (1) {
        drawBoard(board);
        playGame(board, turn);
    }

    return 0;
}