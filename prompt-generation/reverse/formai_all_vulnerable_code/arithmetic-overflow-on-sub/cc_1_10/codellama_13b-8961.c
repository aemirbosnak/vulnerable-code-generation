//Code Llama-13B DATASET v1.0 Category: Checkers Game ; Style: automated
/*
 * Checkers Game
 *
 * A unique C program that plays a game of checkers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define PLAYER1 'X'
#define PLAYER2 'O'
#define EMPTY ' '

typedef struct {
    int row;
    int col;
} Coord;

typedef struct {
    Coord coord;
    int player;
} Piece;

int board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void place_pieces() {
    initialize_board();
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    board[i][j] = PLAYER1;
                }
            } else {
                if (j % 2 == 1) {
                    board[i][j] = PLAYER1;
                }
            }
        }
    }
}

int get_piece(Coord coord) {
    return board[coord.row][coord.col];
}

int is_valid_coord(Coord coord) {
    return (coord.row >= 0 && coord.row < BOARD_SIZE && coord.col >= 0 && coord.col < BOARD_SIZE);
}

int is_occupied_coord(Coord coord) {
    return get_piece(coord) != EMPTY;
}

int is_king_coord(Coord coord) {
    return get_piece(coord) == PLAYER2;
}

int is_movement_valid(Coord from, Coord to) {
    if (!is_valid_coord(to)) {
        return 0;
    }
    if (is_occupied_coord(to)) {
        return 0;
    }
    if (is_king_coord(to)) {
        return 0;
    }
    if (from.row != to.row && from.col != to.col) {
        return 0;
    }
    if (from.row - to.row != 0 && from.col - to.col != 0) {
        return 0;
    }
    return 1;
}

int move_piece(Coord from, Coord to) {
    if (!is_movement_valid(from, to)) {
        return 0;
    }
    board[to.row][to.col] = get_piece(from);
    board[from.row][from.col] = EMPTY;
    return 1;
}

int is_game_over() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == PLAYER1) {
                return 0;
            }
        }
    }
    return 1;
}

void play_game() {
    place_pieces();
    print_board();
    int player = 1;
    while (!is_game_over()) {
        Coord from, to;
        printf("Enter the coordinates of the piece you want to move (row, col): ");
        scanf("%d %d", &from.row, &from.col);
        printf("Enter the coordinates of the destination (row, col): ");
        scanf("%d %d", &to.row, &to.col);
        if (move_piece(from, to)) {
            player = player == 1 ? 2 : 1;
            print_board();
        } else {
            printf("Invalid movement!\n");
        }
    }
    printf("Player %d wins!\n", player);
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}