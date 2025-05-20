//FormAI DATASET v1.0 Category: Chess engine ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[8][8]; // declare the board

void init_board() { // initialize the board
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            board[i][j] = 0;
        }
    }
}

void display_board() { // display the board
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_legal_move(int from_i, int from_j, int to_i, int to_j) { // check if a move is legal
    if (board[to_i][to_j] != 0) { // destination square is not empty
        return 0;
    }
    if (from_i == to_i && from_j == to_j) { // same square
        return 0;
    }
    if (from_i < 0 || from_i > 7 || from_j < 0 || from_j > 7 || to_i < 0 || to_i > 7 || to_j < 0 || to_j > 7) { // out of bounds
        return 0;
    }
    // TODO: check if move follows chess rules
    return 1;
}

void play_game() { // play a game
    int game_over = 0; // game over flag
    int turn = 0; // whose turn it is
    int from_i, from_j, to_i, to_j; // variables for move input
    while (!game_over) {
        printf("It is player %d's turn. Enter move (from_i from_j to_i to_j): ", turn+1);
        scanf("%d %d %d %d", &from_i, &from_j, &to_i, &to_j);
        if (is_legal_move(from_i, from_j, to_i, to_j)) {
            board[to_i][to_j] = board[from_i][from_j];
            board[from_i][from_j] = 0; // empty the square 
            display_board();
            turn = (turn + 1) % 2; // change turn
        } else {
            printf("Invalid move. Try again.\n");
        }
        // TODO: check if game is over
    }
}

int main() {
    init_board();
    display_board();
    play_game();
    return 0;
}