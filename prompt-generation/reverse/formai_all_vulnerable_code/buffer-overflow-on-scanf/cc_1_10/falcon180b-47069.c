//Falcon-180B DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
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

    initBoard(board);

    while (1) {
        int x, y;
        printf("Enter your move (row and column): ");
        scanf("%d %d", &x, &y);

        if (x < 1 || x > 2 || y < 1 || y > 2) {
            printf("Invalid move.\n");
            continue;
        }

        if (board[x - 1][y - 1]!= '-') {
            printf("Spot already taken.\n");
            continue;
        }

        board[x - 1][y - 1] = (char)('1' + rand() % 2);
        drawBoard(board);

        if (checkWin(board)) {
            printf("Player %c wins!\n", board[0][0]);
            break;
        }
    }

    return 0;
}