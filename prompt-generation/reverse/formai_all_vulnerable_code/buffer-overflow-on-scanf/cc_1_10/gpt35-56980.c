//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {EMPTY, RED, BLACK} Piece;
typedef struct {int x, y;} Point;

Piece board[8][8] = {0};

void clear_board(void) {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if ((x + y) % 2 == 0) board[x][y] = EMPTY;
            else board[x][y] = ((y < 3) ? BLACK : (y >= 5 ? RED : EMPTY));
        }
    }
}

void draw_board(void) {
    // code for drawing the board in cyberpunk style
}

bool check_move(Point src, Point dst) {
    // code for checking if move is valid
}

void make_move(Point src, Point dst) {
    // code for making the move
}

bool game_over(void) {
    // code for checking if game is over
}

int main(void) {
    clear_board();
    while (1) {
        draw_board();
        printf("Red's turn\n");
        Point src, dst;
        scanf("%d,%d %d,%d", &src.x, &src.y, &dst.x, &dst.y);
        if (check_move(src, dst)) make_move(src, dst);
        else printf("Illegal move\n");
        if (game_over()) break;
        draw_board();
        printf("Black's turn\n");
        scanf("%d,%d %d,%d", &src.x, &src.y, &dst.x, &dst.y);
        if (check_move(src, dst)) make_move(src, dst);
        else printf("Illegal move\n");
        if (game_over()) break;
    }
    printf("Game over\n");
    return 0;
}