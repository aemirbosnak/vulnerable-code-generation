//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void check_winner() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            printf("Player %d wins!\n", (i+1));
            exit(0);
        }
        // check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            printf("Player %d wins!\n", (i+1));
            exit(0);
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        printf("Player 1 wins!\n");
        exit(0);
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        printf("Player 2 wins!\n");
        exit(0);
    }
}

// player 1 is X, player 2 is O
void play_turn(char player) {
    int row, col;
    printf("Player %c's turn:\n", player);
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);
    row--; col--;
    if (board[row][col]!= 'X' && board[row][col]!= 'O') {
        board[row][col] = player;
        check_winner();
    } else {
        printf("Invalid move, try again.\n");
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 is X, player 2 is O.\n");
    print_board();
    int player = 1;
    while (1) {
        play_turn(player == 1? 'X' : 'O');
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
    return 0;
}