//FormAI DATASET v1.0 Category: Chess engine ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
int turn = 0;

void initialize_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i == 1) {
                board[i][j] = 1;
            } else if (i == 6) {
                board[i][j] = -1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void print_board() {
    int i, j;
    printf("   a  b  c  d  e  f  g  h\n");
    printf("  -----------------------\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf("|_|");
            } else if (board[i][j] == 1) {
                printf("|p|");
            } else if (board[i][j] == -1) {
                printf("|P|");
            }
        }
        printf("| %d\n", i + 1);
        printf("  -----------------------\n");
    }
    printf("   a  b  c  d  e  f  g  h\n");
}

void move_piece(int from_x, int from_y, int to_x, int to_y) {
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = 0;
}

void make_move() {
    int from_x, from_y, to_x, to_y;
    printf("Enter move: ");
    scanf("%d%d%d%d", &from_x, &from_y, &to_x, &to_y);
    move_piece(from_x - 1, from_y - 'a', to_x - 1, to_y - 'a');
}

int main() {
    initialize_board();
    while (1) {
        printf("\nTurn %d\n\n", turn);
        print_board();
        make_move();
        turn++;
    }
    return 0;
}