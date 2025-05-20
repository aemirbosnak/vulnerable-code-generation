//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8
#define WHITE 1
#define BLACK -1

typedef struct {
    char board[SIZE][SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chessBoard) {
    const char *initial[] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < SIZE; ++i) {
        strcpy(chessBoard->board[i], initial[i]);
    }
}

void printBoard(const ChessBoard *chessBoard) {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d|", SIZE - i);
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", chessBoard->board[i][j] == ' ' ? '.' : chessBoard->board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
}

int isValidMove(const ChessBoard *chessBoard, const char *move) {
    // A very basic implementation just checks if the source and target squares are part of the board
    return (move[0] >= 'a' && move[0] <= 'h' && move[1] >= '1' && move[1] <= '8' &&
            move[2] >= 'a' && move[2] <= 'h' && move[3] >= '1' && move[3] <= '8');
}

void makeMove(ChessBoard *chessBoard, const char *move) {
    int srcX = SIZE - (move[1] - '0') - 1;
    int srcY = move[0] - 'a';
    int destX = SIZE - (move[3] - '0') - 1;
    int destY = move[2] - 'a';

    chessBoard->board[destX][destY] = chessBoard->board[srcX][srcY];
    chessBoard->board[srcX][srcY] = ' ';
}

int main() {
    ChessBoard chessBoard;
    char move[4];

    initializeBoard(&chessBoard);

    while (1) {
        printBoard(&chessBoard);
        printf("Enter your move (e.g., e2e4): ");
        scanf("%s", move);

        if (strcmp(move, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        if (isValidMove(&chessBoard, move)) {
            makeMove(&chessBoard, move);
        } else {
            printf("Invalid move! Please try again.\n");
        }
    }

    return 0;
}