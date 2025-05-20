//Falcon-180B DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void generateBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = (i + j) % 2 + '0';
        }
    }
}

int checkWin(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    generateBoard(board);

    int player = 1;
    int choice;

    while (1) {
        system("clear");
        printf("Player %d's turn\n", player);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        printf("Enter your move (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &choice);

        if (choice < 1 || choice > ROWS * COLS - 1) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (board[choice / COLS][choice % COLS]!= 'X' &&
            board[choice / COLS][choice % COLS]!= 'O') {
            board[choice / COLS][choice % COLS] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;

            if (checkWin(board)) {
                printf("Player %d wins!\n", player);
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}