//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Position;

typedef struct {
    char piece;
    Position position;
} Piece;

typedef struct {
    Piece pieces[32];
    int turn;
    int winner;
} Board;

void print_board(Board* board) {
    for (int y = 7; y >= 0; y--) {
        for (int x = 0; x < 8; x++) {
            Piece piece = board->pieces[x + y * 8];
            if (piece.piece == ' ') {
                printf(". ");
            } else {
                printf("%c ", piece.piece);
            }
        }
        printf("\n");
    }
}

int main() {
    Board board;
    memset(&board, 0, sizeof(board));
    board.pieces[0] = (Piece) {'r', {0, 0}};
    board.pieces[1] = (Piece) {'n', {1, 0}};
    board.pieces[2] = (Piece) {'b', {2, 0}};
    board.pieces[3] = (Piece) {'q', {3, 0}};
    board.pieces[4] = (Piece) {'k', {4, 0}};
    board.pieces[5] = (Piece) {'b', {5, 0}};
    board.pieces[6] = (Piece) {'n', {6, 0}};
    board.pieces[7] = (Piece) {'r', {7, 0}};
    for (int i = 0; i < 8; i++) {
        board.pieces[8 + i] = (Piece) {'p', {i, 1}};
        board.pieces[48 + i] = (Piece) {'P', {i, 6}};
    }
    board.turn = 1;
    board.winner = 0;
    print_board(&board);
    while (board.winner == 0) {
        // Get the player's move.
        char move[5];
        printf("Enter your move (e.g. e2e4): ");
        gets(move);
        // Parse the move.
        int from_x = move[0] - 'a';
        int from_y = move[1] - '1';
        int to_x = move[2] - 'a';
        int to_y = move[3] - '1';
        if (board.pieces[from_x + from_y * 8].piece == (board.turn == 1 ? 'P' : 'p') && to_y - from_y == 2) {
            board.pieces[from_x + from_y * 8].position.y++;
        }
        // Move the piece.
        board.pieces[from_x + from_y * 8].position.x = to_x;
        board.pieces[from_x + from_y * 8].position.y = to_y;
        // Check if the game is over.
        if (board.pieces[to_x + to_y * 8].piece == (board.turn == 1 ? 'K' : 'k')) {
            board.winner = board.turn;
        }
        // Switch turns.
        board.turn = -board.turn;
        print_board(&board);
    }
    if (board.winner == 1) {
        printf("White wins!\n");
    } else {
        printf("Black wins!\n");
    }
    return 0;
}