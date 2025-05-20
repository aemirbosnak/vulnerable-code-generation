//FormAI DATASET v1.0 Category: Chess AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int BOARD_SIZE = 8;
char board[8][8];

void printBoard() {
    printf("    A B C D E F G H\n");
    printf("   -----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|%c", board[i][j]);
        }
        printf("| %d\n", i + 1);
        printf("   -----------------\n");
    }
    printf("    A B C D E F G H\n");
}

bool isInsideBoard(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return false;
    }
    return true;
}

bool isPawnMoveValid(int x, int y, int newX, int newY) {
    if (newX == x + 1 && newY == y) {
        if (board[newX][newY] == '-') {
            return true;
        }
    }
    return false;
}

bool isMoveValid(char piece, int x, int y, int newX, int newY) {
    switch (piece) {
        case 'P':
        case 'p':
            return isPawnMoveValid(x, y, newX, newY);
        default:
            return false;
    }
}

int main() {
    memset(board, '-', sizeof(board));
    board[6][0] = 'P'; // white pawn at A7
    printBoard();
    bool whiteToPlay = true;
    while (true) {
        char input[10];
        if (whiteToPlay) {
            printf("White to play: ");
        } else {
            printf("Black to play: ");
        }
        scanf("%s", input);
        if (strlen(input) != 4) {
            printf("Invalid input\n");
            continue;
        }
        int y = input[0] - 'A';
        int x = input[1] - '1';
        int newY = input[2] - 'A';
        int newX = input[3] - '1';
        if (!isInsideBoard(x, y) || !isInsideBoard(newX, newY)) {
            printf("Invalid input\n");
            continue;
        }
        if (!isMoveValid(board[x][y], x, y, newX, newY)) {
            printf("Invalid move\n");
            continue;
        }
        board[newX][newY] = board[x][y];
        board[x][y] = '-';
        printBoard();
        whiteToPlay = !whiteToPlay;
    }
    return 0;
}