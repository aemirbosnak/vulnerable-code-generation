//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include <stdio.h>

#define ROWS 3
#define COLS 3

void drawBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[ROWS][COLS]) {
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < COLS; i++) {
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return 1;
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

int main() {
    char board[ROWS][COLS] = { {'X', 'O', 'X'}, {'O', 'X', 'O'}, {'X', 'O', 'X'} };
    char player = 'X';
    int i, j, choice;

    drawBoard(board);

    while (1) {
        printf("\nPlayer %c's turn.\n", player);
        printf("Enter your choice (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &choice);

        if ((choice < 1) || (choice > ROWS * COLS - 1)) {
            printf("Invalid choice.\n");
            continue;
        }

        i = choice / COLS;
        j = choice % COLS;

        if (board[i][j]!= 'X' && board[i][j]!= 'O') {
            board[i][j] = player;

            if (checkWin(board)) {
                printf("\n%c wins!\n", player);
                break;
            }

            player = (player == 'X')? 'O' : 'X';
        } else {
            printf("Invalid choice.\n");
        }

        drawBoard(board);
    }

    return 0;
}