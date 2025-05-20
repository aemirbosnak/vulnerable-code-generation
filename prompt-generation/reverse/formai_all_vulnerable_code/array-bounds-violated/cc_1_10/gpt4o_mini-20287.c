//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define BLACK_PAWN 'P'
#define WHITE_PAWN 'p'
#define BLACK_ROOK 'R'
#define WHITE_ROOK 'r'
#define BLACK_KNIGHT 'N'
#define WHITE_KNIGHT 'n'
#define BLACK_BISHOP 'B'
#define WHITE_BISHOP 'b'
#define BLACK_QUEEN 'Q'
#define WHITE_QUEEN 'q'
#define BLACK_KING 'K'
#define WHITE_KING 'k'

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    const char *initial[BOARD_SIZE] = {
        "RNBQKBNR", 
        "PPPPPPPP", 
        "        ", 
        "        ", 
        "        ", 
        "        ", 
        "pppppppp", 
        "rnbqkbnr"
    };
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        strncpy(board[i], initial[i], BOARD_SIZE);
    }
}

void display_board() {
    system("clear"); // Clear terminal (Linux)
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int start_x, int start_y, int end_x, int end_y) {
    // Basic validation: bounds checking and empty squares
    if (end_x < 0 || end_x >= BOARD_SIZE || end_y < 0 || end_y >= BOARD_SIZE) return 0;
    if (board[end_x][end_y] != EMPTY && board[start_x][start_y] == EMPTY) return 0;
    return 1;
}

void make_move(int start_x, int start_y, int end_x, int end_y) {
    board[end_x][end_y] = board[start_x][start_y];
    board[start_x][start_y] = EMPTY;
}

void get_move_from_user(int *start_x, int *start_y, int *end_x, int *end_y) {
    char start[3], end[3];
    printf("Enter your move (e.g., e2 e4): ");
    scanf("%s %s", start, end);
    
    *start_x = BOARD_SIZE - (start[1] - '0');
    *start_y = start[0] - 'a';
    *end_x = BOARD_SIZE - (end[1] - '0');
    *end_y = end[0] - 'a';
}

int main() {
    printf("Welcome to the Energetic C Chess Engine!\n");
    initialize_board();
    
    while (1) {
        display_board();
        
        int start_x, start_y, end_x, end_y;
        get_move_from_user(&start_x, &start_y, &end_x, &end_y);
        
        if (!is_valid_move(start_x, start_y, end_x, end_y)) {
            printf("Invalid move! Please try again.\n");
            continue;
        }
        
        make_move(start_x, start_y, end_x, end_y);
    }

    return 0;
}