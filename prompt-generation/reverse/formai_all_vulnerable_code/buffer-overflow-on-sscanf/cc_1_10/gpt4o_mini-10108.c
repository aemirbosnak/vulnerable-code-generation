//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    const char *initialSetup[BOARD_SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        strncpy(board[i], initialSetup[i], BOARD_SIZE);
    }
}

void printBoard() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j] == ' ' ? '.' : board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startX, int startY, int endX, int endY) {
    // Simple validation: check if move is within bounds and if starting position has a piece
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE ||
        endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    if (board[startX][startY] == ' ') {
        return 0; // No piece at starting position
    }

    // Further validation can be added here based on piece type, etc.
    
    return 1; // Valid move
}

void movePiece(int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = ' ';
}

void convertPosition(char *pos, int *x, int *y) {
    *y = pos[0] - 'a';
    *x = 8 - (pos[1] - '0');
}

int main() {
    initializeBoard();
    printBoard();

    char input[6];
    int turn = 0; // 0 for player 1, 1 for player 2
    char playerSymbols[2] = {'X', 'O'};
    
    while (1) {
        printf("Player %d (%c), enter your move (e.g., e2 e4): ", turn + 1, playerSymbols[turn]);
        fgets(input, sizeof(input), stdin);

        int startX, startY, endX, endY;
        char start[3], end[3];
        sscanf(input, "%s %s", start, end);

        convertPosition(start, &startX, &startY);
        convertPosition(end, &endX, &endY);

        if (isValidMove(startX, startY, endX, endY)) {
            movePiece(startX, startY, endX, endY);
            printBoard();
            turn = 1 - turn; // Switch players
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}