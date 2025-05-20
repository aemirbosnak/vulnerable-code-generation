//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;
typedef enum { WHITE, BLACK } Color;

typedef struct {
    Piece piece;
    Color color;
} Square;

Square board[SIZE][SIZE];

void initializeBoard() {
    // Place pawns
    for (int i = 0; i < SIZE; i++) {
        board[1][i] = (Square){PAWN, WHITE};
        board[6][i] = (Square){PAWN, BLACK};
    }

    // Place other pieces
    Piece pieces[] = { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK };
    for (int i = 0; i < SIZE; i++) {
        board[0][i] = (Square){pieces[i], WHITE};
        board[7][i] = (Square){pieces[i], BLACK};
    }

    // Initialize empty squares
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = (Square){EMPTY, WHITE}; // Color doesn't matter for empty squares
}

void printBoard() {
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            switch (board[i][j].piece) {
                case PAWN:   printf("P "); break;
                case KNIGHT: printf("N "); break;
                case BISHOP: printf("B "); break;
                case ROOK:   printf("R "); break;
                case QUEEN:  printf("Q "); break;
                case KING:   printf("K "); break;
                case EMPTY:  printf(". "); break;
            }
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int isMoveValid(int fromX, int fromY, int toX, int toY, Color color) {
    // This function will just check basic validity such as bounds and piece color
    if (toX < 0 || toX >= SIZE || toY < 0 || toY >= SIZE)
        return 0; // Out of bounds
    
    if (board[fromX][fromY].piece == EMPTY)
        return 0; // No piece there
    
    if (board[fromX][fromY].color != color)
        return 0; // Wrong color piece
    
    return 1; // Move is valid
}

void makeMove(int fromX, int fromY, int toX, int toY) {
    board[toX][toY] = board[fromX][fromY]; // Move the piece
    board[fromX][fromY].piece = EMPTY; // Empty the old square
}

void playGame() {
    Color currentPlayer = WHITE;
    char from[3], to[3];

    while (1) {
        printBoard();
        printf("Player %s, enter your move (from to), e.g., e2 e4: ", currentPlayer == WHITE ? "White" : "Black");
        scanf("%s %s", from, to);

        int fromX = from[1] - '1'; // Convert row '1'-'8' to 0-7
        int fromY = from[0] - 'a'; // Convert column 'a'-'h' to 0-7
        int toX = to[1] - '1';
        int toY = to[0] - 'a';

        if (isMoveValid(fromX, fromY, toX, toY, currentPlayer)) {
            makeMove(fromX, fromY, toX, toY);
            currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE; // Switch players
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the C Chess Engine!\n");
    initializeBoard();
    playGame();
    return 0;
}