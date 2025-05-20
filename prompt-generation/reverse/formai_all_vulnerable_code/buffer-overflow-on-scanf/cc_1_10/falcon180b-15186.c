//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    char name;
    int value;
} Piece;

Piece board[8][8];
Point king_pos[2];
int turn;

void init() {
    srand(time(NULL));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j].name = '.';
        }
    }
    for (int i = 0; i < 2; i++) {
        king_pos[i].x = rand() % 8;
        king_pos[i].y = rand() % 8;
        board[king_pos[i].x][king_pos[i].y].name = 'K';
    }
    turn = 1;
}

void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j].name);
        }
        printf("\n");
    }
}

int check_win() {
    // check for win conditions
    return 0;
}

int main() {
    init();
    while (1) {
        print_board();
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x][y].name == '.') {
            board[x][y].name = (turn % 2 == 0)? 'X' : 'O';
            turn++;
        } else if (board[x][y].name == 'K') {
            // move king
        } else {
            // move piece
        }
        if (check_win()) {
            printf("Player %d wins!\n", (turn % 2) + 1);
            break;
        }
    }
    return 0;
}