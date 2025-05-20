//Falcon-180B DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define EMPTY 0
#define PLAYER_ONE 1
#define PLAYER_TWO 2
#define WIN 10

void drawBoard(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROWS][COLS]) {
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return EMPTY;
}

int main() {
    int board[ROWS][COLS] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    int player = 1;
    int choice;
    int i, j;

    srand(time(NULL));

    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player);

        if (player == 1) {
            printf("Enter your move (1-%d): ", COLS - 1);
            scanf("%d", &choice);
            choice--;
        } else {
            printf("Computer's move: %d\n", choice);
        }

        if (board[0][choice]!= EMPTY) {
            printf("Invalid move, try again.\n");
            continue;
        }

        board[0][choice] = player;

        if (checkWin(board) == player) {
            printf("Player %d wins!\n", player);
            break;
        } else if (checkWin(board) == EMPTY) {
            printf("Tie game.\n");
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}