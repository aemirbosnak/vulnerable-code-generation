//Falcon-180B DATASET v1.0 Category: Game ; Style: standalone
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
    srand(time(NULL));
    char board[ROWS][COLS] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int player = 1;
    int choice;
    int flag = 0;

    while (flag == 0) {
        system("clear");
        print_board(board);
        printf("\nPlayer %d's turn\n", player);

        printf("Enter your move: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        int row = (choice-1)/3;
        int col = (choice-1)%3;

        if (board[row][col]!= 'X' && board[row][col]!= 'O') {
            if (player % 2 == 1) {
                board[row][col] = 'X';
            } else {
                board[row][col] = 'O';
            }

            flag = check_win(board);

            if (flag == 1) {
                printf("\nPlayer %d wins!\n", player);
                break;
            } else {
                player++;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}