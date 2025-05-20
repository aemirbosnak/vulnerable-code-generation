//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;
typedef enum { WHITE, BLACK } Color;
typedef struct {
    Piece piece;
    Color color;
} Square;

typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initChessBoard(ChessBoard *board) {
    // Initialize the board with pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = (Square) { EMPTY, WHITE };
        }
    }

    // Place Pawns
    for (int j = 0; j < BOARD_SIZE; j++) {
        board->board[1][j] = (Square) { PAWN, WHITE };
        board->board[6][j] = (Square) { PAWN, BLACK };
    }

    // Place Rooks
    board->board[0][0] = board->board[0][7] = (Square) { ROOK, WHITE };
    board->board[7][0] = board->board[7][7] = (Square) { ROOK, BLACK };

    // Place Knights
    board->board[0][1] = board->board[0][6] = (Square) { KNIGHT, WHITE };
    board->board[7][1] = board->board[7][6] = (Square) { KNIGHT, BLACK };

    // Place Bishops
    board->board[0][2] = board->board[0][5] = (Square) { BISHOP, WHITE };
    board->board[7][2] = board->board[7][5] = (Square) { BISHOP, BLACK };

    // Place Queens and Kings
    board->board[0][3] = (Square) { QUEEN, WHITE };
    board->board[0][4] = (Square) { KING, WHITE };
    board->board[7][3] = (Square) { QUEEN, BLACK };
    board->board[7][4] = (Square) { KING, BLACK };
}

void printBoard(const ChessBoard *board) {
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1); // Print row number
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board->board[i][j].piece) {
                case PAWN:   printf(board->board[i][j].color == WHITE ? "P " : "p "); break;
                case KNIGHT: printf(board->board[i][j].color == WHITE ? "N " : "n "); break;
                case BISHOP: printf(board->board[i][j].color == WHITE ? "B " : "b "); break;
                case ROOK:   printf(board->board[i][j].color == WHITE ? "R " : "r "); break;
                case QUEEN:  printf(board->board[i][j].color == WHITE ? "Q " : "q "); break;
                case KING:   printf(board->board[i][j].color == WHITE ? "K " : "k "); break;
                default:     printf(". "); break; // Empty square
            }
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n"); // Print column labels
}

bool isMoveValid(const ChessBoard *board, int srcRow, int srcCol, int destRow, int destCol) {
    // Simple bounds checking and piece occupancy check
    if (destRow < 0 || destRow >= BOARD_SIZE || destCol < 0 || destCol >= BOARD_SIZE) return false;
    if (board->board[srcRow][srcCol].piece == EMPTY) return false;
    if (board->board[destRow][destCol].color == board->board[srcRow][srcCol].color) return false;
    return true;
}

void makeMove(ChessBoard *board, int srcRow, int srcCol, int destRow, int destCol) {
    if (isMoveValid(board, srcRow, srcCol, destRow, destCol)) {
        board->board[destRow][destCol] = board->board[srcRow][srcCol];
        board->board[srcRow][srcCol] = (Square) { EMPTY, WHITE };
    }
}

int main() {
    ChessBoard board;
    initChessBoard(&board);
    
    char input[10];
    int srcRow, srcCol, destRow, destCol;

    while (true) {
        printBoard(&board);
        printf("Enter your move (e.g., e2 e4): ");
        fgets(input, sizeof(input), stdin);
        
        // Convert algebraic notation to indices
        if (sscanf(input, "%c%d %c%d", (char*)&srcCol, &srcRow, (char*)&destCol, &destRow) != 4) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        srcCol -= 'a';
        srcRow -= 1;
        destCol -= 'a';
        destRow -= 1;

        makeMove(&board, srcRow, srcCol, destRow, destCol);
    }

    return 0;
}