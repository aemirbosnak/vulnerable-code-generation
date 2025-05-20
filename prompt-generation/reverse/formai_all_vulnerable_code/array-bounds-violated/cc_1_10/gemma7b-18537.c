//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int is_board_full() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

int is_player_win(char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == player) {
        return 1;
    }

    return 0;
}

int main() {
    char current_player = 'X';
    int game_state = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Play until someone wins or the board is full
    while (!game_state) {
        // Get the player's move
        int move = rand() % 9 + 1;

        // If the move is valid, make it
        if (board[move / BOARD_SIZE][move % BOARD_SIZE] == ' ') {
            board[move / BOARD_SIZE][move % BOARD_SIZE] = current_player;

            // Check if the player has won or if the board is full
            game_state = is_player_win(current_player) || is_board_full();

            // Switch to the next player
            current_player = 'O' == current_player ? 'X' : 'O';
        }
    }

    // Print the winner or draw
    if (game_state) {
        printf("Winner: %c!\n", current_player);
    } else {
        printf("Draw!\n");
    }

    return 0;
}