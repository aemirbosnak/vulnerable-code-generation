//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int piece;
    Position position;
} Piece;

typedef struct {
    Piece pieces[16];
    int turn;
} Board;

void print_board(Board board) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            Piece piece = board.pieces[y * BOARD_SIZE + x];
            printf("%c", piece.piece);
        }
        printf("\n");
    }
}

int main() {
    Board board;
    memset(&board, 0, sizeof(board));

    // Initialize the board with the starting position
    board.pieces[0] = (Piece) {'r', {0, 0}};
    board.pieces[1] = (Piece) {'n', {1, 0}};
    board.pieces[2] = (Piece) {'b', {2, 0}};
    board.pieces[3] = (Piece) {'q', {3, 0}};
    board.pieces[4] = (Piece) {'k', {4, 0}};
    board.pieces[5] = (Piece) {'b', {5, 0}};
    board.pieces[6] = (Piece) {'n', {6, 0}};
    board.pieces[7] = (Piece) {'r', {7, 0}};
    for (int i = 0; i < BOARD_SIZE; i++) {
        board.pieces[8 + i] = (Piece) {'p', {i, 1}};
        board.pieces[48 + i] = (Piece) {'P', {i, 6}};
    }

    // Print the starting position
    print_board(board);

    // Get the user's move
    char move[5];
    scanf("%s", move);

    // Parse the move
    Position from;
    Position to;
    from.x = move[0] - 'a';
    from.y = move[1] - '1';
    to.x = move[2] - 'a';
    to.y = move[3] - '1';

    // Make the move
    board.pieces[to.y * BOARD_SIZE + to.x] = board.pieces[from.y * BOARD_SIZE + from.x];
    board.pieces[from.y * BOARD_SIZE + from.x] = (Piece) {0, {-1, -1}};

    // Print the updated board
    print_board(board);

    return 0;
}