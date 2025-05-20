//FormAI DATASET v1.0 Category: Chess engine ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
} Move;

typedef struct {
    char pieces[8][8];
} Board;

void initializeBoard(Board *board) {
    int i, j;
    char pieces[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                         {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                         {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                         {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                         {' ', '.', ' ', '.', ' ', '.', ' ', ' '},
                         {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                         {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                         {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            board->pieces[i][j] = pieces[i][j];
        }
    }
}

void printBoard(Board *board) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c ", board->pieces[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(Move *move, Board *board) {
    if (move->row < 0 || move->row >= 8 || move->col < 0 || move->col >= 8) {
        return 0;
    }
    char piece = board->pieces[move->row][move->col];
    if (isupper(piece)) {
        return 0;
    }
    return 1;
}

void getMove(Board *board, Move *move) {
    int valid = 0;
    while (!valid) {
        printf("Enter row: ");
        scanf("%d", &(move->row));
        printf("Enter column: ");
        scanf("%d", &(move->col));
        valid = isValidMove(move, board);
    }
}

void makeMove(Board *board, Move *move) {
    board->pieces[move->row][move->col] = 'p';
}

int main() {
    Board board;
    initializeBoard(&board);
    printBoard(&board);
    Move move;
    getMove(&board, &move);
    makeMove(&board, &move);
    printBoard(&board);
    return 0;
}