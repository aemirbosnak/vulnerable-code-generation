//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: inquisitive
// A chess engine masterpiece in the making!

#include <stdio.h>
#include <stdlib.h>

// Define board size and player types
#define BOARD_SIZE 8
enum Player { WHITE, BLACK };

// Initialize board with all pieces in their starting positions
void initBoard(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 1 || i == 6) // Pawns
                board[i][j] = (i == 1) ? WHITE : BLACK;
            else if (i == 0 || i == 7) { // Back row pieces
                switch (j) {
                    case 0: case 7: board[i][j] = (i == 0) ? WHITE : BLACK; break; // Rooks
                    case 1: case 6: board[i][j] = (i == 0) ? WHITE : BLACK; break; // Knights
                    case 2: case 5: board[i][j] = (i == 0) ? WHITE : BLACK; break; // Bishops
                    case 3: board[i][j] = (i == 0) ? WHITE : BLACK; break; // Queens
                    case 4: board[i][j] = (i == 0) ? WHITE : BLACK; break; // Kings
                }
            }
            else // Empty squares
                board[i][j] = 0;
        }
    }
}

// Display the chessboard in its current state
void printBoard(int board[][BOARD_SIZE]) {
    printf("   a b c d e f g h\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            char piece = (board[i][j] == WHITE) ? 'W' : (board[i][j] == BLACK) ? 'B' : ' ';
            printf(" %c |", piece);
        }
        printf("\n  +---+---+---+---+---+---+---+---+\n");
    }
}

// Check if a given move is valid
int isValidMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, enum Player player) {
    // Check if the move is within the board boundaries
    if (fromRow < 0 || fromRow >= BOARD_SIZE || fromCol < 0 || fromCol >= BOARD_SIZE || toRow < 0 || toRow >= BOARD_SIZE || toCol < 0 || toCol >= BOARD_SIZE)
        return 0;

    // Check if the piece at the 'from' square belongs to the player making the move
    if (board[fromRow][fromCol] != player)
        return 0;

    // Check if the 'to' square is not occupied by a piece of the same color
    if (board[toRow][toCol] == player)
        return 0;

    // Check if the move is a valid move for the piece being moved
    switch (player) {
        case WHITE:
            if (toRow - fromRow > 1)
                return 0;
            break;
        case BLACK:
            if (fromRow - toRow > 1)
                return 0;
            break;
    }

    return 1;
}

// Make a move on the board, if it is valid
int makeMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, enum Player player) {
    if (!isValidMove(board, fromRow, fromCol, toRow, toCol, player)) {
        printf("Invalid move!\n");
        return 0;
    }

    // Move the piece from the 'from' square to the 'to' square
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = 0;

    return 1;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    initBoard(board);
    printBoard(board);

    enum Player player = WHITE;
    while (1) {
        int fromRow, fromCol, toRow, toCol;

        printf("Player %s's turn: ", (player == WHITE) ? "White" : "Black");
        scanf("%d %d %d %d", &fromRow, &fromCol, &toRow, &toCol);

        if (makeMove(board, fromRow, fromCol, toRow, toCol, player)) {
            player = (player == WHITE) ? BLACK : WHITE;
            printBoard(board);
        }
    }

    return 0;
}