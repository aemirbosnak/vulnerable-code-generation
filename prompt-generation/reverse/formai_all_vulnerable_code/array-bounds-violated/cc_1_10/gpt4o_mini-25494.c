//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[SIZE][SIZE];

void initialize_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i % 2 == j % 2) {
                board[i][j] = EMPTY;
            } else if (i < 3) {
                board[i][j] = PLAYER2; // Player 2 pieces
            } else if (i > 4) {
                board[i][j] = PLAYER1; // Player 1 pieces
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int start_row, int start_col, int end_row, int end_col, char player) {
    if (end_row < 0 || end_row >= SIZE || end_col < 0 || end_col >= SIZE) return 0;
    if (board[end_row][end_col] != EMPTY) return 0;

    int direction = (player == PLAYER1) ? -1 : 1;
    if (end_row == start_row + direction && (end_col == start_col + 1 || end_col == start_col - 1)) {
        return 1; // Normal move
    }

    // Jump move
    if (end_row == start_row + 2 * direction) {
        int jumped_row = start_row + direction;
        int jumped_col = (end_col == start_col + 1) ? start_col + 1 : start_col - 1;
        if (board[jumped_row][jumped_col] != EMPTY && 
            board[jumped_row][jumped_col] != player) {
            return 2; // Jump move
        }
    }
    
    return 0; // Invalid move
}

void make_move(int start_row, int start_col, int end_row, int end_col, char player) {
    board[end_row][end_col] = player;
    board[start_row][start_col] = EMPTY;

    // Check for jumps
    if (end_row == start_row + 2 * ((player == PLAYER1) ? -1 : 1)) {
        int jumped_row = start_row + ((player == PLAYER1) ? -1 : 1);
        int jumped_col = (end_col == start_col + 1) ? start_col + 1 : start_col - 1;
        board[jumped_row][jumped_col] = EMPTY; // Remove the jumped piece
    }
}

int main() {
    initialize_board();
    char current_player = PLAYER1;
    int start_row, start_col, end_row, end_col;
    char col_start, col_end;

    while (1) {
        print_board();
        printf("Player %c's turn. Enter move (e.g. A3 B4) or Q to quit: ", current_player);
        char input[10];
        fgets(input, 10, stdin);
        if (input[0] == 'Q' || input[0] == 'q') break;

        col_start = input[0] - 'A';
        start_row = input[1] - '1';
        col_end = input[3] - 'A';
        end_row = input[4] - '1';

        if (is_valid_move(start_row, col_start, end_row, col_end, current_player)) {
            make_move(start_row, col_start, end_row, col_end, current_player);
            current_player = (current_player == PLAYER1) ? PLAYER2 : PLAYER1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    printf("Game over!\n");
    return 0;
}