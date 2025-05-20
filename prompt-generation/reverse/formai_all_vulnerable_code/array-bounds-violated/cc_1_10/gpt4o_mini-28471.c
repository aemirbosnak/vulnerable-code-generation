//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY '-'

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    const char* pieces = "rnbqkbnr";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0) {
                board[i][j] = pieces[j];  // Black pieces
            } else if (i == 1) {
                board[i][j] = 'p';  // Black pawns
            } else if (i == 6) {
                board[i][j] = 'P';  // White pawns
            } else if (i == 7) {
                board[i][j] = pieces[j] - ('a' - 'A');  // White pieces
            } else {
                board[i][j] = EMPTY;  // Empty squares
            }
        }
    }
}

void print_board() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(char piece, int start_row, int start_col, int end_row, int end_col) {
    // Basic validity checks (not exhaustive chess rules)
    if (end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    if (board[end_row][end_col] != EMPTY && 
        ((piece >= 'A' && board[end_row][end_col] >= 'a') || (piece <= 'Z' && board[end_row][end_col] <= 'Z'))) {
        return 0; // Cannot capture own piece
    }
    return 1; // Acceptable move
}

void make_move(int start_row, int start_col, int end_row, int end_col) {
    char piece = board[start_row][start_col];
    if (is_valid_move(piece, start_row, start_col, end_row, end_col)) {
        board[end_row][end_col] = piece;
        board[start_row][start_col] = EMPTY;
        printf("Moved %c from %d%d to %d%d.\n", piece, 8 - start_row, start_col + 1, 8 - end_row, end_col + 1);
    } else {
        printf("Invalid move.\n");
    }
}

void read_move(char *input) {
    char start[3], end[3];
    sscanf(input, "%2s %2s", start, end);
    
    int start_row = 8 - (start[1] - '0');
    int start_col = start[0] - 'a';
    
    int end_row = 8 - (end[1] - '0');
    int end_col = end[0] - 'a';
    
    make_move(start_row, start_col, end_row, end_col);
}

int main() {
    printf("Elementary, my dear Watson. Welcome to the Chess Arena!\n");
    initialize_board();
    
    char move[100];
    while (1) {
        print_board();
        printf("Enter your move (e.g., e2 e4) or 'exit' to quit: ");
        fgets(move, sizeof(move), stdin);
        
        if (strncmp(move, "exit", 4) == 0) {
            printf("Goodbye! Until the next unsolvable mystery.\n");
            break;
        }
        
        read_move(move);
    }
    
    return 0;
}