//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Enum for piece types
typedef enum {
    EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
} Piece;

// Enum for piece colors
typedef enum {
    NONE, WHITE, BLACK
} Color;

// Structure to represent a chess piece
typedef struct {
    Piece piece;
    Color color;
} Square;

// Chessboard representation
Square board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the chessboard
void initBoard() {
    // Initialize empty squares
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].piece = EMPTY;
            board[i][j].color = NONE;
        }
    }
    // Set up pieces for both sides
    // Adding pawns
    for (int j = 0; j < BOARD_SIZE; j++) {
        board[1][j].piece = PAWN;
        board[1][j].color = WHITE;
        board[6][j].piece = PAWN;
        board[6][j].color = BLACK;
    }
    // Adding rooks
    board[0][0].piece = board[0][7].piece = ROOK;
    board[0][0].color = board[0][7].color = WHITE;
    board[7][0].piece = board[7][7].piece = ROOK;
    board[7][0].color = board[7][7].color = BLACK;

    // Adding knights
    board[0][1].piece = board[0][6].piece = KNIGHT;
    board[0][1].color = board[0][6].color = WHITE;
    board[7][1].piece = board[7][6].piece = KNIGHT;
    board[7][1].color = board[7][6].color = BLACK;

    // Adding bishops
    board[0][2].piece = board[0][5].piece = BISHOP;
    board[0][2].color = board[0][5].color = WHITE;
    board[7][2].piece = board[7][5].piece = BISHOP;
    board[7][2].color = board[7][5].color = BLACK;

    // Adding queens and kings
    board[0][3].piece = QUEEN; board[0][3].color = WHITE;
    board[0][4].piece = KING;  board[0][4].color = WHITE;
    board[7][3].piece = QUEEN; board[7][3].color = BLACK;
    board[7][4].piece = KING;  board[7][4].color = BLACK;
}

// Function to print the chessboard
void printBoard() {
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j].piece) {
                case PAWN:   printf("P "); break;
                case KNIGHT: printf("N "); break;
                case BISHOP: printf("B "); break;
                case ROOK:   printf("R "); break;
                case QUEEN:  printf("Q "); break;
                case KING:   printf("K "); break;
                default:     printf(". ");
            }
        }
        printf("%d\n", i + 1);
    }
    printf("  a b c d e f g h\n");
}

// Function to convert coordinates from algebraic notation to indices
void parseMove(char *move, int *fromRow, int *fromCol, int *toRow, int *toCol) {
    *fromCol = move[0] - 'a';
    *fromRow = move[1] - '1';
    *toCol = move[2] - 'a';
    *toRow = move[3] - '1';
}

// Function to move a piece on the board
int makeMove(char *move) {
    int fromRow, fromCol, toRow, toCol;
    parseMove(move, &fromRow, &fromCol, &toRow, &toCol);
    
    if (fromRow < 0 || fromRow >= BOARD_SIZE || fromCol < 0 || fromCol >= BOARD_SIZE ||
        toRow < 0 || toRow >= BOARD_SIZE || toCol < 0 || toCol >= BOARD_SIZE) {
        printf("Invalid move. Out of bounds.\n");
        return 0;
    }

    Square *fromSquare = &board[fromRow][fromCol];
    Square *toSquare = &board[toRow][toCol];

    // Basic move validation (ignoring rules like check, specific piece moves, etc.)
    if (fromSquare->piece == EMPTY) {
        printf("Invalid move. No piece at source square.\n");
        return 0;
    }

    // Move the piece
    toSquare->piece = fromSquare->piece;
    toSquare->color = fromSquare->color;
    fromSquare->piece = EMPTY;
    fromSquare->color = NONE;

    return 1;
}

int main() {
    initBoard();
    char move[5];

    printf("Welcome to Simple C Chess Engine!\n");
    printBoard();

    while (1) {
        printf("Enter your move (e.g., e2e4): ");
        scanf("%s", move);
        if (strcmp(move, "exit") == 0) {
            break;
        }
        if (makeMove(move)) {
            printBoard();
        }
    }

    return 0;
}