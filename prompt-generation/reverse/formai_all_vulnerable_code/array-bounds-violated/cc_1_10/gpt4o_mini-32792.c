//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE_PAWN 'P'
#define BLACK_PAWN 'p'
#define WHITE_ROOK 'R'
#define BLACK_ROOK 'r'
#define WHITE_KNIGHT 'N'
#define BLACK_KNIGHT 'n'
#define WHITE_BISHOP 'B'
#define BLACK_BISHOP 'b'
#define WHITE_QUEEN 'Q'
#define BLACK_QUEEN 'q'
#define WHITE_KING 'K'
#define BLACK_KING 'k'

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    const char* initial[BOARD_SIZE] = {
        "RNBQKBNR",
        "PPPPPPPP",
        "        ",
        "        ",
        "        ",
        "        ",
        "pppppppp",
        "rnbqkbnr"
    };
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = initial[i][j];
        }
    }
}

void display_board() {
    printf("\n  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("%d|", 8 - i);
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%c|", board[i][j]);
        }
        printf("\n +----------------+\n");
    }
}

int is_valid_move(int startX, int startY, int endX, int endY, char piece) {
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) 
        return 0; // move is out of bounds

    // Add piece-specific movement validations here.
    // For simplicity, let's assume any move is valid for now
    return 1; 
}

void move_piece(int startX, int startY, int endX, int endY) {
    char piece = board[startX][startY];
    board[endX][endY] = piece;
    board[startX][startY] = EMPTY;
}

void get_move(char* move, int* startX, int* startY, int* endX, int* endY) {
    // Convert user input "e2 e4" to coordinates
    char start[3], end[3];
    sscanf(move, "%s %s", start, end);
    *startY = start[0] - 'a';
    *startX = 8 - (start[1] - '0');
    *endY = end[0] - 'a';
    *endX = 8 - (end[1] - '0');
}

int main() {
    initialize_board();
    display_board();

    char move[10];
    while (1) {
        printf("Enter your move (e.g., e2 e4): ");
        fgets(move, sizeof(move), stdin);
        
        int startX, startY, endX, endY;
        get_move(move, &startX, &startY, &endX, &endY);
        
        if (is_valid_move(startX, startY, endX, endY, board[startX][startY])) {
            move_piece(startX, startY, endX, endY);
            display_board();
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    return 0;
}