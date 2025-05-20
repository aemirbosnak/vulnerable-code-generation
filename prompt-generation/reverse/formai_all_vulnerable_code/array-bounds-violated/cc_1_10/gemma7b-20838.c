//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int row;
    int col;
    char state;
} Cell;

Cell cells[BOARD_SIZE][BOARD_SIZE] = {{
    {0, 0, ' '},
    {1, 0, ' '},
    {2, 0, ' '},
    {0, 1, ' '},
    {1, 1, ' '},
    {2, 1, ' '},
    {0, 2, ' '},
    {1, 2, ' '},
    {2, 2, ' '}
}};

int is_board_full() {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (cells[r][c].state == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

int check_win(char player) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (cells[r][0].state == player && cells[r][1].state == player && cells[r][2].state == player) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (cells[0][c].state == player && cells[1][c].state == player && cells[2][c].state == player) {
            return 1;
        }
    }

    // Check diagonals
    if (cells[0][0].state == player && cells[1][1].state == player && cells[2][2].state == player) {
        return 1;
    }

    if (cells[0][2].state == player && cells[1][1].state == player && cells[2][0].state == player) {
        return 1;
    }

    return 0;
}

int main() {
    char current_player = 'X';

    // Game loop
    while (!is_board_full() && !check_win(current_player)) {
        // Get the move
        int move_row, move_col;

        // Make the move
        cells[move_row][move_col].state = current_player;

        // Switch the player
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    // Game over
    if (check_win(current_player)) {
        printf("%s won!", current_player);
    } else {
        printf("It's a draw!");
    }

    return 0;
}