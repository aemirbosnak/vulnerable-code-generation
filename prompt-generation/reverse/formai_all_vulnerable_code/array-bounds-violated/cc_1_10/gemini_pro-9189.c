//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    bool is_red;
    bool is_king;
} Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
} Board;

void print_board(Board board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.board[i][j].is_red) {
                printf("R");
            } else if (board.board[i][j].is_king) {
                printf("K");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

bool is_valid_move(Board board, Position from, Position to) {
    Piece from_piece = board.board[from.x][from.y];
    Piece to_piece = board.board[to.x][to.y];

    if (from_piece.is_red == to_piece.is_red) {
        return false;
    }

    if (from_piece.is_king) {
        if (abs(from.x - to.x) != abs(from.y - to.y)) {
            return false;
        }
    } else {
        if (from.x - to.x != 1 || abs(from.y - to.y) != 1) {
            return false;
        }
    }

    return true;
}

void make_move(Board *board, Position from, Position to) {
    Piece piece = board->board[from.x][from.y];
    board->board[from.x][from.y] = (Piece){false, false};
    board->board[to.x][to.y] = piece;

    if (piece.is_red && to.x == 0) {
        board->board[to.x][to.y].is_king = true;
    } else if (!piece.is_red && to.x == BOARD_SIZE - 1) {
        board->board[to.x][to.y].is_king = true;
    }
}

bool is_game_over(Board board) {
    int red_pieces = 0;
    int black_pieces = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = board.board[i][j];
            if (piece.is_red) {
                red_pieces++;
            } else if (!piece.is_red) {
                black_pieces++;
            }
        }
    }

    return red_pieces == 0 || black_pieces == 0;
}

int main() {
    Board board;

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board.board[i][j] = (Piece){true, false};
                } else if (i > 4) {
                    board.board[i][j] = (Piece){false, false};
                } else {
                    board.board[i][j] = (Piece){false, false};
                }
            }
        }
    }

    // Print the board
    print_board(board);

    // Get the player's move
    Position from;
    Position to;
    printf("Enter the coordinates of the piece you want to move (from x,y): ");
    scanf("%d %d", &from.x, &from.y);
    printf("Enter the coordinates of the square you want to move to (to x,y): ");
    scanf("%d %d", &to.x, &to.y);

    // Check if the move is valid
    if (!is_valid_move(board, from, to)) {
        printf("Invalid move.\n");
        return 1;
    }

    // Make the move
    make_move(&board, from, to);

    // Print the board
    print_board(board);

    // Check if the game is over
    if (is_game_over(board)) {
        printf("Game over.\n");
        return 0;
    }

    return 0;
}