//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

char board[SIZE][SIZE] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

void printBoard() {
    printf("  a b c d e f g h\n");
    printf("  -----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  -----------------\n");
}

int isValidMove(int startX, int startY, int endX, int endY) {
    char piece = board[startX][startY];
    // Simplistic move validation for the bishop (as a puzzle!)
    if (piece == 'b' || piece == 'B') {
        if (abs(startX - endX) == abs(startY - endY)) {
            return 1; 
        }
    }
    return 0; 
}

void makeMove(int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = ' ';
}

void getMove(int *startX, int *startY, int *endX, int *endY) {
    char start[3], end[3];
    printf("Enter your move (e.g., 'e2 e4'): ");
    scanf("%s %s", start, end);

    *startX = 8 - (start[1] - '0');
    *startY = start[0] - 'a';
    *endX = 8 - (end[1] - '0');
    *endY = end[0] - 'a';
}

int main() {
    int startX, startY, endX, endY;
    while (1) {
        printBoard();
        getMove(&startX, &startY, &endX, &endY);
        if (isValidMove(startX, startY, endX, endY)) {
            makeMove(startX, startY, endX, endY);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}