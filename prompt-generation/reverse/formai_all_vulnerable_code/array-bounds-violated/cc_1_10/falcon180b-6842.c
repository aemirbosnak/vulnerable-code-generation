//Falcon-180B DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    char board[ROWS][COLS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int player = 1;
    int choice;
    int flag = 0;

    while (!flag) {
        system("clear");
        printBoard(board);
        printf("\nPlayer %d's turn\n", player);

        choice = rand() % 9 + 1;

        if (board[choice/3][choice%3]!= 'X' && board[choice/3][choice%3]!= 'O') {
            board[choice/3][choice%3] = (player == 1)? 'X' : 'O';
            player++;

            if (player == 4) {
                flag = 1;
                printf("\nTie game!\n");
            }
        } else {
            printf("\nInvalid move, try again.\n");
        }
    }

    return 0;
}