//Falcon-180B DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void draw_board(char board[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[ROWS][COLS]) {
    int i;

    // Check horizontal lines
    for (i = 0; i < ROWS; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[i][1] == board[i][2] && board[i][2] == board[i][0])) {
            return 1;
        }
    }

    // Check vertical lines
    for (i = 0; i < COLS; i++) {
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
            (board[1][i] == board[2][i] && board[2][i] == board[0][i])) {
            return 1;
        }
    }

    // Check diagonal lines
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

int main() {
    char board[ROWS][COLS] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int player = 1;
    int choice;
    int i, j;

    srand(time(NULL));

    while (1) {
        system("clear");
        draw_board(board);

        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d%d", &i, &j);

        if (i < 0 || i > 2 || j < 0 || j > 2) {
            printf("Invalid move.\n");
            continue;
        }

        if (board[i][j]!= 'X' && board[i][j]!= 'O') {
            board[i][j] = (player == 1)? 'X' : 'O';
            if (check_winner(board)) {
                printf("\nPlayer %d wins!\n", player);
                break;
            }
            player = (player == 1)? 2 : 1;
        } else {
            printf("Cell already occupied.\n");
        }
    }

    return 0;
}