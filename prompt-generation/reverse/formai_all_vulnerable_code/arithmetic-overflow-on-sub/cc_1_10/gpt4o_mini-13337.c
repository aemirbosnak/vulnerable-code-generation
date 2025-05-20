//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
} ChessBoard;

void initBoard(ChessBoard *board) {
    const char *initialSetup[SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < SIZE; i++) {
        strncpy(board->board[i], initialSetup[i], SIZE);
    }
}

void printBoard(const ChessBoard *board) {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board->board[i][j] == '.' ? ' ' : board->board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
}

int isValidMove(char piece, int startRow, int startCol, int endRow, int endCol) {
    // Basic move validation (not comprehensive)
    if (piece == 'P') {
        return startRow == endRow + 1 && startCol == endCol; // Simple pawn move
    } else if (piece == 'R') {
        return startRow == endRow || startCol == endCol; // Rook move rule
    } else if (piece == 'N') {
        return (abs(startRow - endRow) == 2 && abs(startCol - endCol) == 1) ||
               (abs(startRow - endRow) == 1 && abs(startCol - endCol) == 2); // Knight move rule
    }
    return 0; // Default not valid
}

void makeMove(ChessBoard *board, int startRow, int startCol, int endRow, int endCol) {
    char piece = board->board[startRow][startCol];
    board->board[endRow][endCol] = piece;
    board->board[startRow][startCol] = '.';
}

int main() {
    ChessBoard board;
    initBoard(&board);
    printBoard(&board);

    int startRow, startCol, endRow, endCol;
    char columnStart, columnEnd;
    char player = 'W';

    while (1) {
        printf("Player %c, enter move (e.g., e2 e4): ", player);
        scanf(" %c%d %c%d", &columnStart, &startRow, &columnEnd, &endRow);

        startCol = columnStart - 'a';
        endCol = columnEnd - 'a';
        startRow = SIZE - startRow;
        endRow = SIZE - endRow;

        if (startCol < 0 || startCol >= SIZE || endCol < 0 || endCol >= SIZE || 
            startRow < 0 || startRow >= SIZE || endRow < 0 || endRow >= SIZE) {
            printf("Invalid move. Out of board boundaries. Try again.\n");
            continue;
        }

        char piece = board.board[startRow][startCol];
        if (piece == '.' || (player == 'W' && piece < 'A') || (player == 'B' && piece > 'Z')) {
            printf("Invalid piece selection. Try again.\n");
            continue;
        }

        if (!isValidMove(piece, startRow, startCol, endRow, endCol)) {
            printf("Invalid move for the piece. Try again.\n");
            continue;
        }

        makeMove(&board, startRow, startCol, endRow, endCol);
        printBoard(&board);

        // Switch player
        player = (player == 'W') ? 'B' : 'W';
    }

    return 0;
}