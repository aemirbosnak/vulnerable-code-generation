//Falcon-180B DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[ROWS][COLS]) {
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
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
    char player = 'X';
    int i, j, choice, result;

    srand(time(NULL));

    while (1) {
        system("clear");
        print_board(board);
        printf("\nPlayer %c's turn.\n", player);

        result = 0;
        do {
            printf("Enter your move (1-9): ");
            scanf("%d", &choice);
            i = choice / 3;
            j = choice % 3;

            if (board[i][j]!= 'X' && board[i][j]!= 'O') {
                board[i][j] = player;
                result = check_win(board);
            } else {
                printf("Invalid move.\n");
            }
        } while (result == 0);

        if (result == 1) {
            printf("%c wins!\n", player);
            break;
        } else {
            player = (player == 'X')? 'O' : 'X';
        }
    }

    return 0;
}