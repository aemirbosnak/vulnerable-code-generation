//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];
char current_player;

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    current_player = 'X';
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0]!= '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j]!= '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0]!= '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2]!= '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void switch_player() {
    if (current_player == 'X') {
        current_player = 'O';
    } else {
        current_player = 'X';
    }
}

int main() {
    srand(time(NULL));
    init_board();
    int player_won = 0;

    while (player_won == 0) {
        print_board();
        int row, col;
        printf("Player %c, enter your move (row, col): ", current_player);
        scanf("%d%d", &row, &col);

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == '-') {
            board[row][col] = current_player;

            player_won = check_winner();

            if (player_won == 0) {
                switch_player();
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    print_board();
    printf("Player %c wins!\n", current_player);

    return 0;
}