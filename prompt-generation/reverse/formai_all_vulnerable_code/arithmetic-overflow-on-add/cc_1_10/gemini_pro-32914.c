//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {
    EMPTY,
    BLACK,
    WHITE
} Piece;

typedef struct {
    Piece pieces[BOARD_SIZE][BOARD_SIZE];
    int black_count;
    int white_count;
} Board;

void init_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->pieces[i][j] = EMPTY;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->pieces[i][j] = BLACK;
            board->black_count++;
        }
    }

    for (int i = BOARD_SIZE - 3; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->pieces[i][j] = WHITE;
            board->white_count++;
        }
    }
}

void print_board(Board *board) {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board->pieces[i][j]) {
                case EMPTY:
                    printf("  ");
                    break;
                case BLACK:
                    printf("██");
                    break;
                case WHITE:
                    printf("██");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Board board;
    init_board(&board);

    print_board(&board);

    return 0;
}