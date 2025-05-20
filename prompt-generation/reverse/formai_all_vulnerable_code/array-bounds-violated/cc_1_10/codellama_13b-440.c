//Code Llama-13B DATASET v1.0 Category: Checkers Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 8
#define COLS 8
#define NUM_PIECES 12

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    int type;
    position pos;
} piece;

piece board[NUM_PIECES];

void init_board() {
    for (int i = 0; i < NUM_PIECES; i++) {
        board[i].type = rand() % 2;
        board[i].pos.x = rand() % COLS;
        board[i].pos.y = rand() % ROWS;
    }
}

void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            if (board[i * COLS + j].type == 0) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_board();
    print_board();
    return 0;
}