//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define PIECES 6
#define BOARD_SIZE (ROWS * COLS)

typedef struct {
    char name[20];
    int row, col;
} Piece;

Piece pieces[PIECES] = {
    {"X", 0, 0},
    {"O", 1, 0},
    {"X", 2, 0},
    {"O", 0, 1},
    {"X", 1, 1},
    {"O", 2, 1},
    {"X", 0, 2},
    {"O", 1, 2},
    {"X", 2, 2}
};

void init_board(void);
void print_board(void);
void move_piece(int, int);
void check_win(void);
void roll_die(void);

int main(void) {
    srand(time(NULL));

    init_board();

    while (1) {
        roll_die();
        move_piece(pieces[rand() % PIECES].row, pieces[rand() % PIECES].col);
        check_win();
    }

    return 0;
}

void init_board(void) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            pieces[i * COLS + j].row = i;
            pieces[i * COLS + j].col = j;
        }
    }
}

void print_board(void) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", pieces[i * COLS + j].name[0]);
        }
        printf("\n");
    }
}

void move_piece(int row, int col) {
    int index = (row * COLS + col);
    Piece temp = pieces[index];
    pieces[index] = pieces[row * COLS + (col + 1) % COLS];
    pieces[row * COLS + (col + 1) % COLS] = temp;
}

void check_win(void) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (pieces[i * COLS + j].name[0] == 'X' && pieces[i * COLS + j].row == ROWS - 1) {
                printf("X wins!\n");
                return;
            } else if (pieces[i * COLS + j].name[0] == 'O' && pieces[i * COLS + j].row == 0) {
                printf("O wins!\n");
                return;
            }
        }
    }
}

void roll_die(void) {
    int die_value = rand() % 6 + 1;
    pieces[rand() % PIECES].name[0] = die_value == 1 ? 'X' : 'O';
}