//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define WHITE 'W'
#define BLACK 'B'
#define EMPTY ' '

char board[SIZE][SIZE];

void initialize_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < 3 && (i + j) % 2 != 0) {
                board[i][j] = BLACK; // Black pieces
            } else if (i > 4 && (i + j) % 2 != 0) {
                board[i][j] = WHITE; // White pieces
            } else {
                board[i][j] = EMPTY; // Empty square
            }
        }
    }
}

void print_board() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int from_row, int from_col, int to_row, int to_col, char player) {
    if (to_row < 0 || to_row >= SIZE || to_col < 0 || to_col >= SIZE || board[to_row][to_col] != EMPTY) {
        return 0; // Out of bounds or destination is not empty
    }

    int direction = (player == WHITE) ? -1 : 1;
    if ((to_row == from_row + direction) && (abs(to_col - from_col) == 1)) {
        return 1; // Normal move
    } else if ((to_row == from_row + 2 * direction) && (abs(to_col - from_col) == 2) && 
               (board[from_row + direction][(from_col + to_col) / 2] != EMPTY &&
                board[from_row + direction][(from_col + to_col) / 2] != player)) {
        return 2; // Jump move
    }
    return 0; // Invalid move
}

void make_move(int from_row, int from_col, int to_row, int to_col) {
    char player = board[from_row][from_col];
    board[to_row][to_col] = player; // Move piece
    board[from_row][from_col] = EMPTY; // Empty the original position

    // If jump, remove the jumped piece
    if (abs(to_row - from_row) == 2) {
        int jumped_row = (from_row + to_row) / 2;
        int jumped_col = (from_col + to_col) / 2;
        board[jumped_row][jumped_col] = EMPTY; // Remove jumped piece
    }
}

int main() {
    char player = WHITE;
    int from_row, from_col, to_row, to_col;
    char from_col_letter, to_col_letter;

    initialize_board();
    while (1) {
        print_board();
        printf("%c's turn. Enter move (e.g., B6 C5): ", player);
        
        if (scanf(" %c%d %c%d", &from_col_letter, &from_row, &to_col_letter, &to_row) != 4) {
            printf("Invalid input. Please enter the move in correct format.\n");
            continue;
        }

        from_col = from_col_letter - 'A';
        to_col = to_col_letter - 'A';
        from_row = SIZE - from_row; // Convert to board coordinates
        to_row = SIZE - to_row; // Convert to board coordinates
        
        if (is_valid_move(from_row, from_col, to_row, to_col, player)) {
            make_move(from_row, from_col, to_row, to_col);
            player = (player == WHITE) ? BLACK : WHITE; // Switch player
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    
    return 0;
}