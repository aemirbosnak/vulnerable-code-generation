//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

char board[SIZE][SIZE];

void initialize_board() {
    // Initialize empty board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    // Place pieces for Player 1
    for (int i = 0; i < 3; i++) {
        for (int j = (i % 2); j < SIZE; j += 2) {
            board[i][j] = 'A'; // Player 1's pieces
        }
    }
    // Place pieces for Player 2
    for (int i = 5; i < 8; i++) {
        for (int j = (i % 2); j < SIZE; j += 2) {
            board[i][j] = 'B'; // Player 2's pieces
        }
    }
}

void display_board() {
    printf("   a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int from_row, int from_col, int to_row, int to_col, char player) {
    // Check if destination is within bounds and empty
    if (to_row < 0 || to_row >= SIZE || to_col < 0 || to_col >= SIZE || board[to_row][to_col] != ' ') {
        return 0;
    }
    // Check jumping rules for captures
    if (abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2) {
        int mid_row = (from_row + to_row) / 2;
        int mid_col = (from_col + to_col) / 2;
        if (board[mid_row][mid_col] != ' ' && board[mid_row][mid_col] != player) {
            return 1; // Valid jump
        }
    }
    // Check normal move rules
    if (abs(to_row - from_row) == 1 && abs(to_col - from_col) == 1) {
        return player == 'A' ? to_row > from_row : to_row < from_row; // Directional move
    }
    return 0;
}

void move_piece(int from_row, int from_col, int to_row, int to_col) {
    char player = board[from_row][from_col];
    board[to_row][to_col] = player;
    board[from_row][from_col] = ' ';
    if (abs(to_row - from_row) == 2) {
        int mid_row = (from_row + to_row) / 2;
        int mid_col = (from_col + to_col) / 2;
        board[mid_row][mid_col] = ' '; // Remove captured piece
    }
}

int main() {
    initialize_board();
    display_board();
    
    int from_row, from_col, to_row, to_col;
    char from_col_char, to_col_char;
    char current_player = 'A'; // Starting with Player 1 'A'
    
    while (1) {
        printf("Player %c's turn. Enter move (e.g., 'a3 b4'): ", current_player);
        scanf(" %c%d %c%d", &from_col_char, &from_row, &to_col_char, &to_row);
        
        from_col = from_col_char - 'a';
        to_col = to_col_char - 'a';
        from_row = SIZE - from_row;
        to_row = SIZE - to_row;

        if (from_row < 0 || from_row >= SIZE || from_col < 0 || from_col >= SIZE ||
            to_row < 0 || to_row >= SIZE || to_col < 0 || to_col >= SIZE ||
            board[from_row][from_col] != current_player) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (is_valid_move(from_row, from_col, to_row, to_col, current_player)) {
            move_piece(from_row, from_col, to_row, to_col);
            display_board();
            current_player = (current_player == 'A') ? 'B' : 'A'; // Switch player
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    return 0;
}