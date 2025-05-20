//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

char board[SIZE][SIZE];

void initialize_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) { // Only populate black squares
                if (i < 3) board[i][j] = 'B'; // Player 1
                else if (i > 4) board[i][j] = 'R'; // Player 2
                else board[i][j] = ' '; // Empty square
            } else {
                board[i][j] = ' '; // White squares are empty
            }
        }
    }
}

void print_board() {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
}

int is_valid_move(int start_x, int start_y, int end_x, int end_y, char player) {
    if (end_x < 0 || end_x >= SIZE || end_y < 0 || end_y >= SIZE) return 0; // Out of bounds
    if (board[end_x][end_y] != ' ') return 0; // Target square not empty

    int direction = (player == 'B') ? 1 : -1; // Direction of movement
    if (end_x == start_x + direction && (end_y == start_y + 1 || end_y == start_y - 1)) {
        return 1; // Simple movement
    }

    // Check for jump
    if (end_x == start_x + direction * 2) {
        int mid_x = start_x + direction; 
        int mid_y = (end_y + start_y) / 2; 
        if (board[mid_x][mid_y] != ' ' && board[mid_x][mid_y] != player) {
            return 2; // Jump
        }
    }
    return 0; // Invalid move 
}

void make_move(int start_x, int start_y, int end_x, int end_y, char player) {
    board[end_x][end_y] = player;
    board[start_x][start_y] = ' ';
    if (end_x == start_x + 2 || end_x == start_x - 2) {
        int mid_x = (start_x + end_x) / 2;
        int mid_y = (start_y + end_y) / 2;
        board[mid_x][mid_y] = ' '; // Remove jumped piece
    }
}

int main() {
    initialize_board();
    print_board();
    char current_player = 'B';
    
    while (1) {
        char start_col, end_col;
        int start_row, end_row;

        printf("Player %c's turn. Enter move (e.g., a3 b4): ", current_player);
        scanf(" %c%d %c%d", &start_col, &start_row, &end_col, &end_row);
        
        int start_x = 8 - start_row; // Convert to array index
        int start_y = start_col - 'a';
        int end_x = 8 - end_row; // Convert to array index
        int end_y = end_col - 'a';

        int move_type = is_valid_move(start_x, start_y, end_x, end_y, current_player);
        
        if (move_type > 0) {
            make_move(start_x, start_y, end_x, end_y, current_player);
            print_board();
            current_player = (current_player == 'B') ? 'R' : 'B'; // Switch players
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    return 0;
}