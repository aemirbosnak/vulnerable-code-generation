//Falcon-180B DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define SYMBOLS 4

void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
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
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % SYMBOLS + 1;
        }
    }

    int player = 1;
    int choice;
    int flag = 0;

    while (!flag) {
        system("clear");
        printf("Player 1: X  Player 2: O\n");
        print_board(board);
        if (player % 2 == 1) {
            printf("Player %d's turn\n", player);
        } else {
            printf("Player %d's turn\n", player);
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > COLS) {
            printf("Invalid choice, try again.\n");
            continue;
        }
        if (board[0][choice - 1]!= 0) {
            printf("Invalid choice, try again.\n");
            continue;
        }
        board[0][choice - 1] = player;
        player++;
        flag = check_winner(board);
    }

    if (player % 2 == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}