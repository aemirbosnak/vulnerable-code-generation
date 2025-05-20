//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

int board[ROW][COL];
int player = 1;

void init() {
    int i, j;
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            board[i][j] = -1;
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            if (board[i][j] == -1) {
                printf("_ ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int check_win() {
    int i, j;
    for (i = 0; i < ROW; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    init();
    int i, j;
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            board[i][j] = rand() % 9 + 1;
        }
    }
    while (1) {
        print_board();
        int x, y;
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < ROW && y >= 0 && y < COL && board[x][y] == -1) {
            board[x][y] = player;
            if (check_win()) {
                printf("Player %d wins!\n", player);
                break;
            } else if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}