//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// This is the board
int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

// Function to print the board
void print_board() {
    printf("   |   |   \n");
    printf("  1 | 2 | 3 \n");
    printf("   |   |   \n");
    printf("   |   |   \n");
    printf("  4 | 5 | 6 \n");
    printf("   |   |   \n");
    printf("   |   |   \n");
    printf("  7 | 8 | 9 \n");
    printf("   |   |   \n");
    printf("   |   |   \n");
}

// Function to check if the board is full
bool is_full() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            return false;
        }
    }
    return true;
}

// Function to check if the game is a draw
bool is_draw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            return false;
        }
        if (board[i] == board[i / 3] && board[i] == board[i / 3 * 3]) {
            return true;
        }
    }
    return false;
}

// Function to check if the game is won
bool is_won() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            continue;
        }
        if (board[i] == board[i / 3] && board[i] == board[i / 3 * 3]) {
            return true;
        }
        if (board[i] == board[3 * (i / 3)] && board[i] == board[3 * (i / 3) * 3]) {
            return true;
        }
    }
    return false;
}

// Function to check if a move is valid
bool is_valid_move(int move) {
    if (move < 1 || move > 9) {
        return false;
    }
    return true;
}

// Function to check if the move has won the game
bool check_win(int move) {
    if (board[move]!= 0) {
        return false;
    }
    board[move] = 1;
    if (is_won()) {
        return true;
    }
    board[move] = 0;
    return false;
}

// Function to check if the move is a draw
bool check_draw(int move) {
    if (board[move]!= 0) {
        return false;
    }
    board[move] = 1;
    if (is_draw()) {
        return true;
    }
    board[move] = 0;
    return false;
}

// Function to make a move
void make_move(int move) {
    if (!is_valid_move(move)) {
        printf("Invalid move.\n");
        return;
    }
    if (check_win(move)) {
        printf("Player 1 won.\n");
    }
    if (check_draw(move)) {
        printf("It's a draw.\n");
    }
    else {
        printf("Player 2's turn.\n");
    }
}

// Function to start the game
int start_game() {
    printf("Welcome to Tic Tac Toe!\n");
    print_board();
    while (true) {
        int move;
        printf("Player 1, enter your move: ");
        scanf("%d", &move);
        if (is_valid_move(move)) {
            make_move(move);
        }
        else {
            printf("Invalid move.\n");
        }
        if (is_full()) {
            printf("It's a draw.\n");
            break;
        }
    }
    return 0;
}

int main() {
    start_game();
    return 0;
}