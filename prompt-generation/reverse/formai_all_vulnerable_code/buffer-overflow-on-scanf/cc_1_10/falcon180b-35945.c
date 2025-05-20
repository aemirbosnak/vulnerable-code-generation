//Falcon-180B DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int player = 1;
    int choice;
    int flag = 0;

    while (flag == 0) {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        print_board(board);
        printf("\nPlayer %d's Turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col]!= 'X' && board[row][col]!= 'O') {
            if (player % 2 == 1) {
                board[row][col] = 'X';
            } else {
                board[row][col] = 'O';
            }
            player++;
        } else {
            printf("Sorry the row %d and column %d is already marked with %c\n", row + 1, col + 1, board[row][col]);
        }

        if (player % 2 == 0) {
            flag = 1;
        }
    }

    if (player % 2 == 1) {
        printf("\nPlayer 2 Wins!!!\n");
    } else {
        printf("\nIt's a Draw!!!\n");
    }

    return 0;
}