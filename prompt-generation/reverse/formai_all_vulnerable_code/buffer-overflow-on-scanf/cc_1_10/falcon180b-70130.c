//Falcon-180B DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_PLAYERS 2

enum Player { X, O };

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[BOARD_SIZE][BOARD_SIZE], enum Player player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL)); // Initialize random seed

    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    enum Player current_player = X;
    int current_player_score = 0;
    int other_player_score = 0;

    while (1) {
        print_board(board);

        int choice;
        printf("Player %c's turn. Enter your move (1-%d): ", current_player == X? 'X' : 'O', BOARD_SIZE - 1);
        scanf("%d", &choice);

        if (choice < 1 || choice > BOARD_SIZE - 1) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (board[0][choice - 1]!= '-') {
            printf("Spot taken. Try again.\n");
            continue;
        }

        board[0][choice - 1] = current_player == X? 'X' : 'O';

        if (check_winner(board, current_player)) {
            printf("Player %c wins!\n", current_player == X? 'X' : 'O');
            break;
        }

        current_player = current_player == X? O : X;
        current_player_score++;
    }

    return 0;
}