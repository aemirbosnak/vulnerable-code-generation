//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 8

typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;
typedef enum { WHITE, BLACK } Color;

typedef struct {
    Piece piece;
    Color color;
} Square;

typedef struct {
    Square board[SIZE][SIZE];
} ChessBoard;

void initialize_board(ChessBoard *chessboard) {
    memset(chessboard->board, 0, sizeof(chessboard->board));

    // Initialize the pieces for both players
    for(int i = 0; i < SIZE; i++) {
        chessboard->board[1][i].piece = PAWN;
        chessboard->board[1][i].color = WHITE;
        chessboard->board[6][i].piece = PAWN;
        chessboard->board[6][i].color = BLACK;
    }
    
    chessboard->board[0][0].piece = chessboard->board[0][7].piece = ROOK;
    chessboard->board[0][1].piece = chessboard->board[0][6].piece = KNIGHT;
    chessboard->board[0][2].piece = chessboard->board[0][5].piece = BISHOP;
    chessboard->board[0][3].piece = QUEEN;
    chessboard->board[0][4].piece = KING;

    for(int i = 0; i < SIZE; i++) {
        chessboard->board[0][i].color = WHITE;
        chessboard->board[7][i].color = BLACK;
    }
}
  
void print_board(ChessBoard *chessboard) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if (chessboard->board[i][j].piece == EMPTY) {
                printf(". ");
            } else {
                switch(chessboard->board[i][j].piece) {
                    case PAWN:   printf("P "); break;
                    case KNIGHT: printf("N "); break;
                    case BISHOP: printf("B "); break;
                    case ROOK:   printf("R "); break;
                    case QUEEN:  printf("Q "); break;
                    case KING:   printf("K "); break;
                    default:     printf("? ");
                }
            }
        }
        printf("\n");
    }
}

bool is_move_valid(ChessBoard *chessboard, int startX, int startY, int endX, int endY) {
    // Simple validation logic for demo purposes
    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE ||
        endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) {
        return false; // Out of bounds
    }
    if (chessboard->board[startX][startY].piece == EMPTY) {
        return false; // No piece to move
    }
    
    return true; // Move is valid (in a real implementation, more checks are needed)
}

void make_move(ChessBoard *chessboard, int startX, int startY, int endX, int endY) {
    if (is_move_valid(chessboard, startX, startY, endX, endY)) {
        chessboard->board[endX][endY] = chessboard->board[startX][startY];
        chessboard->board[startX][startY].piece = EMPTY; // Move the piece
    } else {
        printf("Invalid move! Try again.\n");
    }
}

int main() {
    ChessBoard chessboard;
    initialize_board(&chessboard);
    print_board(&chessboard);
    
    while (true) {
        int startX, startY, endX, endY;
        printf("Enter your move (startX startY endX endY): ");
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
        make_move(&chessboard, startX, startY, endX, endY);
        print_board(&chessboard);
    }
    
    return 0;
}