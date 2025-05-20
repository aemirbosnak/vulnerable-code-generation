//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    position position;
    int color;
} piece;

int board[8][8];

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j] ? 'X' : '.');
        }
        printf("\n");
    }
}

int get_piece(position position) {
    return board[position.x][position.y];
}

void set_piece(position position, int color) {
    board[position.x][position.y] = color;
}

int is_valid_move(piece piece, position new_position) {
    int dx = abs(new_position.x - piece.position.x);
    int dy = abs(new_position.y - piece.position.y);

    if (dx != dy || dx != 1) {
        return 0;
    }

    if (get_piece(new_position) != 0) {
        return 0;
    }

    return 1;
}

void move_piece(piece piece, position new_position) {
    set_piece(piece.position, 0);
    set_piece(new_position, piece.color);
}

int main() {
    init_board();

    piece black_piece = { .position = { .x = 0, .y = 0 }, .color = -1 };
    piece white_piece = { .position = { .x = 7, .y = 7 }, .color = 1 };

    while (1) {
        print_board();

        printf("Black's turn: ");
        position new_position;
        scanf("%d %d", &new_position.x, &new_position.y);

        if (is_valid_move(black_piece, new_position)) {
            move_piece(black_piece, new_position);
        } else {
            printf("Invalid move!\n");
        }

        printf("White's turn: ");
        scanf("%d %d", &new_position.x, &new_position.y);

        if (is_valid_move(white_piece, new_position)) {
            move_piece(white_piece, new_position);
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}