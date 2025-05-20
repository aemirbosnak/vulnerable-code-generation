//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

char board[SIZE][SIZE];

void initializeBoard() {
    const char* initial[] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    for (int i = 0; i < SIZE; i++) {
        strcpy(board[i], initial[i]);
    }
}

void printBoard() {
    printf("  a b c d e f g h\n");
    printf("  -----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j] == ' ' ? '.' : board[i][j]);
        }
        printf("|\n");
    }
    printf("  -----------------\n");
}

int isValidMove(char piece, int startRow, int startCol, int endRow, int endCol) {
    // Basic validation for pawns and knights only; expand yourself!
    if (piece == 'P' && startRow - 1 == endRow && startCol == endCol && board[endRow][endCol] == ' ') return 1; // Pawn move
    if (piece == 'p' && startRow + 1 == endRow && startCol == endCol && board[endRow][endCol] == ' ') return 1; // Pawn move
    if (piece == 'N' || piece == 'n') {
        return (startRow + 2 == endRow && (startCol + 1 == endCol || startCol - 1 == endCol)) ||
               (startRow - 2 == endRow && (startCol + 1 == endCol || startCol - 1 == endCol)) ||
               (startCol + 2 == endCol && (startRow + 1 == endRow || startRow - 1 == endRow)) ||
               (startCol - 2 == endCol && (startRow + 1 == endRow || startRow - 1 == endRow));
    }
    return 0; // More piece logic needed!
}

void movePiece(char piece, int startRow, int startCol, int endRow, int endCol) {
    board[endRow][endCol] = piece;
    board[startRow][startCol] = ' ';
}

int main() {
    char currentPlayer = 'W'; // Start with White
    initializeBoard();
    
    while (1) {
        printBoard();
        printf("Player %c's turn! Enter your move (e.g., e2 e4): ", currentPlayer);
        
        char start[3], end[3];
        if (scanf("%s %s", start, end) != 2) {
            printf("Invalid input! Please enter in the format e2 e4.\n");
            continue;
        }

        int startRow = SIZE - (start[1] - '0');
        int startCol = start[0] - 'a';
        int endRow = SIZE - (end[1] - '0');
        int endCol = end[0] - 'a';

        if (startRow < 0 || startRow >= SIZE || startCol < 0 || startCol >= SIZE ||
            endRow < 0 || endRow >= SIZE || endCol < 0 || endCol >= SIZE) {
            printf("Move out of bounds! Try again.\n");
            continue;
        }

        char piece = board[startRow][startCol];
        if ((currentPlayer == 'W' && piece < 'a') || (currentPlayer == 'B' && piece > 'Z')) {
            if (isValidMove(piece, startRow, startCol, endRow, endCol)) {
                movePiece(piece, startRow, startCol, endRow, endCol);
                currentPlayer = (currentPlayer == 'W') ? 'B' : 'W'; // Switch player
            } else {
                printf("Invalid move! Try again.\n");
            }
        } else {
            printf("It's not your turn! Try again.\n");
        }
    }

    return 0;
}