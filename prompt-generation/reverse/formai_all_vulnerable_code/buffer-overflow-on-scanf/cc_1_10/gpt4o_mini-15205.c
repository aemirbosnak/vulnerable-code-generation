//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE 'W'
#define BLACK 'B'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initialize_board(ChessBoard *chessBoard) {
    memset(chessBoard->board, EMPTY, sizeof(chessBoard->board));
    
    // Set up pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        chessBoard->board[1][i] = WHITE; // White pawns
        chessBoard->board[6][i] = BLACK; // Black pawns
    }
    
    // Set up other pieces
    chessBoard->board[0][0] = chessBoard->board[0][7] = WHITE;
    chessBoard->board[0][1] = chessBoard->board[0][6] = WHITE;
    chessBoard->board[0][2] = chessBoard->board[0][5] = WHITE;
    chessBoard->board[0][3] = WHITE;
    chessBoard->board[0][4] = WHITE;

    chessBoard->board[7][0] = chessBoard->board[7][7] = BLACK;
    chessBoard->board[7][1] = chessBoard->board[7][6] = BLACK;
    chessBoard->board[7][2] = chessBoard->board[7][5] = BLACK;
    chessBoard->board[7][3] = BLACK;
    chessBoard->board[7][4] = BLACK;
}

void print_board(const ChessBoard *chessBoard) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chessBoard->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(ChessBoard *chessBoard, int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE ||
        endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    
    char piece = chessBoard->board[startX][startY];
    if (piece == EMPTY) {
        return 0; // No piece at starting position
    }
    
    if (chessBoard->board[endX][endY] != EMPTY && 
        chessBoard->board[endX][endY] == piece) {
        return 0; // Cannot land on own piece
    }
    
    return 1; // Valid move
}

void move_piece(ChessBoard *chessBoard, int startX, int startY, int endX, int endY) {
    if (is_valid_move(chessBoard, startX, startY, endX, endY)) {
        chessBoard->board[endX][endY] = chessBoard->board[startX][startY];
        chessBoard->board[startX][startY] = EMPTY;
    } else {
        printf("Invalid move!\n");
    }
}

void get_move_from_user(int *startX, int *startY, int *endX, int *endY) {
    char start[3], end[3];
    printf("Enter your move (e.g. e2 e4): ");
    scanf("%s %s", start, end);
    
    // Convert from algebraic notation to array indices
    *startX = BOARD_SIZE - (start[1] - '0');
    *startY = start[0] - 'a';
    *endX = BOARD_SIZE - (end[1] - '0');
    *endY = end[0] - 'a';
}

int main() {
    ChessBoard chessBoard;
    initialize_board(&chessBoard);
    
    int startX, startY, endX, endY;
    
    while (1) {
        print_board(&chessBoard);
        get_move_from_user(&startX, &startY, &endX, &endY);
        move_piece(&chessBoard, startX, startY, endX, endY);
    }
    
    return 0;
}