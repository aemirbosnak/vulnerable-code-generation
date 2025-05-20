//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
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
    char board[BOARD_SIZE][BOARD_SIZE];

    // Initialize board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    // Play game
    int current_player = 1;
    while (1) {
        print_board(board);
        printf("Player %d's turn\n", current_player);
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 1 || x > BOARD_SIZE || y < 1 || y > BOARD_SIZE) {
            printf("Invalid move\n");
            continue;
        }
        if (board[x-1][y-1]!= '-') {
            printf("Spot already taken\n");
            continue;
        }
        board[x-1][y-1] = (current_player == 1)? 'X' : 'O';
        if (check_win(board)) {
            printf("Player %d wins!\n", current_player);
            break;
        }
        current_player = (current_player == 1)? 2 : 1;
    }

    return 0;
}