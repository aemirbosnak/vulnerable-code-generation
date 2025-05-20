//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void print_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

int check_winner(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1]!= '-') {
            return 1;
        }
    }

    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j]!= '-') {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= '-') {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]!= '-') {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));

    char board[SIZE][SIZE];
    initialize_board(board);

    int player = 1;
    int choice;

    while (1) {
        printf("Player %d's turn\n", player);
        printf("Enter your move (1-9): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col]!= '-') {
            printf("Spot already taken\n");
            continue;
        }

        board[row][col] = (player == 1)? 'X' : 'O';

        if (check_winner(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    print_board(board);

    return 0;
}