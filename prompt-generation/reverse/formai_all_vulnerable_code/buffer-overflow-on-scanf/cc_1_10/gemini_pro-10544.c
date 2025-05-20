//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define RED 1
#define BLACK 2

typedef struct {
    int color;
    int king;
} piece;

typedef struct {
    piece board[BOARD_SIZE][BOARD_SIZE];
} board;

void init_board(board *b) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    b->board[i][j].color = BLACK;
                    b->board[i][j].king = 0;
                } else if (i > 4) {
                    b->board[i][j].color = RED;
                    b->board[i][j].king = 0;
                } else {
                    b->board[i][j].color = 0;
                    b->board[i][j].king = 0;
                }
            }
        }
    }
}

void print_board(board *b) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (b->board[i][j].color == RED) {
                    printf("R ");
                } else if (b->board[i][j].color == BLACK) {
                    printf("B ");
                } else {
                    printf("  ");
                }
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int valid_move(board *b, int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE || x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return 0;
    }
    if ((x2 - x1) * (y2 - y1) != 1 && (x2 - x1) * (y2 - y1) != -1) {
        return 0;
    }
    if (b->board[x1][y1].color == 0) {
        return 0;
    }
    if (b->board[x2][y2].color != 0) {
        return 0;
    }
    if (b->board[x1][y1].king == 0 && (x2 > x1 || y2 > y1)) {
        return 0;
    }
    return 1;
}

int main() {
    board b;
    init_board(&b);
    print_board(&b);

    int x1, y1, x2, y2;
    while (1) {
        printf("Enter move (x1, y1) (x2, y2): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (valid_move(&b, x1, y1, x2, y2)) {
            b.board[x2][y2] = b.board[x1][y1];
            b.board[x1][y1].color = 0;
            if (x2 == 0 || x2 == BOARD_SIZE - 1) {
                b.board[x2][y2].king = 1;
            }
            print_board(&b);
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}