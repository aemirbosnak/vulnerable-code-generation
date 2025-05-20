//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PIECE_EMPTY 0
#define PIECE_WHITE 1
#define PIECE_BLACK 2

#define BOARD_SIZE 8
#define NUM_PIECES 16
#define NUM_MOVES 4096

typedef struct {
    int piece;
    int color;
    int x, y;
} Piece;

Piece board[NUM_PIECES];
int moves[NUM_MOVES];
int move_count = 0;

void init_board() {
    int i;
    for (i = 0; i < NUM_PIECES; i++) {
        board[i].piece = PIECE_EMPTY;
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i * BOARD_SIZE + j].piece == PIECE_EMPTY) {
                printf(" ");
            } else if (board[i * BOARD_SIZE + j].piece == PIECE_WHITE) {
                printf("W");
            } else {
                printf("B");
            }
        }
        printf("\n");
    }
}

void make_move(int from_x, int from_y, int to_x, int to_y) {
    if (board[from_x * BOARD_SIZE + from_y].piece == PIECE_EMPTY) {
        return;
    }
    if (board[from_x * BOARD_SIZE + from_y].color!= (to_x + to_y) % 2) {
        return;
    }
    board[to_x * BOARD_SIZE + to_y] = board[from_x * BOARD_SIZE + from_y];
    board[from_x * BOARD_SIZE + from_y].piece = PIECE_EMPTY;
}

int is_checkmate(int color) {
    int i;
    for (i = 0; i < NUM_PIECES; i++) {
        if (board[i].piece!= PIECE_EMPTY && board[i].color == color) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    init_board();
    print_board();

    int x, y;
    while (1) {
        printf("Enter move (format: from_x from_y to_x to_y): ");
        scanf("%d %d %d %d", &x, &y, &x, &y);
        if (move_count >= NUM_MOVES) {
            printf("Too many moves.\n");
            break;
        }
        if (board[x * BOARD_SIZE + y].piece == PIECE_EMPTY) {
            printf("Invalid move.\n");
            continue;
        }
        make_move(x * BOARD_SIZE + y, x * BOARD_SIZE + y, x * BOARD_SIZE + y, x * BOARD_SIZE + y);
        move_count++;
        if (is_checkmate(board[x * BOARD_SIZE + y].color)) {
            printf("Checkmate!\n");
            break;
        }
        print_board();
    }

    return 0;
}