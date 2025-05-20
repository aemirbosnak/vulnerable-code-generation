//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define NUM_PIECES 12

typedef struct piece {
    int x;
    int y;
} piece;

typedef struct board {
    piece pieces[NUM_PIECES];
} board;

void print_board(board *b) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", b->pieces[i * BOARD_SIZE + j].x != 0 ? 'X' : '_');
        }
        printf("\n");
    }
}

bool is_valid_move(board *b, int piece_index, int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return false;
    }
    if (b->pieces[piece_index].x == x && b->pieces[piece_index].y == y) {
        return false;
    }
    for (int i = 0; i < NUM_PIECES; i++) {
        if (b->pieces[i].x == x && b->pieces[i].y == y) {
            return false;
        }
    }
    return true;
}

void make_move(board *b, int piece_index, int x, int y) {
    b->pieces[piece_index].x = x;
    b->pieces[piece_index].y = y;
}

bool is_game_over(board *b) {
    for (int i = 0; i < NUM_PIECES; i++) {
        if (b->pieces[i].x == BOARD_SIZE - 1 && b->pieces[i].y == BOARD_SIZE - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    board b;
    for (int i = 0; i < NUM_PIECES; i++) {
        b.pieces[i].x = 0;
        b.pieces[i].y = i;
    }

    print_board(&b);

    while (!is_game_over(&b)) {
        int piece_index, x, y;
        printf("Enter piece index, x, y: ");
        scanf("%d %d %d", &piece_index, &x, &y);

        if (is_valid_move(&b, piece_index, x, y)) {
            make_move(&b, piece_index, x, y);
            print_board(&b);
        } else {
            printf("Invalid move!\n");
        }
    }

    printf("Game over!\n");

    return 0;
}