//Falcon-180B DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    // Check horizontal lines
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check vertical lines
    for (i = 0; i < COLS; i++) {
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

int main() {
    char board[ROWS][COLS] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char mark;
    int player = 1;
    int choice;
    int i, j;

    srand(time(NULL));

    do {
        system("clear");
        drawBoard(board);

        printf("\nPlayer %d's turn. Enter your move: ", player);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        i = (choice - 1) / 3;
        j = (choice - 1) % 3;

        if (board[i][j]!= 'X' && board[i][j]!= 'O') {
            board[i][j] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;

            if (checkWin(board)) {
                printf("\nPlayer %d wins!\n", player);
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }

    } while (1);

    return 0;
}