//Falcon-180B DATASET v1.0 Category: Game ; Style: happy
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

int check_win(char board[ROWS][COLS]) {
    // check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // check diagonals
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
        printf("Player %d's Turn\n", player);
        print_board(board);
        printf("\n");

        if (player % 2 == 1) {
            printf("Enter your choice: ");
            scanf("%d", &choice);
            if (choice < 1 || choice > 9) {
                printf("Invalid move. Try again.\n");
            } else if (board[0][choice - 1]!= 'X' && board[0][choice - 1]!= 'O') {
                board[0][choice - 1] = 'X';
                flag = check_win(board);
            } else {
                printf(" cell %d is already marked with %c\n", choice, board[0][choice - 1]);
            }
        } else {
            printf("Enter your choice: ");
            scanf("%d", &choice);
            if (choice < 1 || choice > 9) {
                printf("Invalid move. Try again.\n");
            } else if (board[0][choice - 1]!= 'X' && board[0][choice - 1]!= 'O') {
                board[0][choice - 1] = 'O';
                flag = check_win(board);
            } else {
                printf(" cell %d is already marked with %c\n", choice, board[0][choice - 1]);
            }
        }

        if (flag == 1) {
            printf("\nPlayer %d Wins!!!\n", player);
            break;
        } else if (flag == -1) {
            printf("\nIt's a draw.\n");
            break;
        }

        player++;
        if (player > 2) {
            player = 1;
        }
    }

    return 0;
}