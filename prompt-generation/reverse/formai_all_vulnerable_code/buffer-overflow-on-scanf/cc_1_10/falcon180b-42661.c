//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int match(char board[ROWS][COLS], int x, int y) {
    if (board[x][y] == '*' && board[x][y+1] == '*') {
        return 1;
    } else if (board[x][y] == '*' && board[x+1][y] == '*') {
        return 1;
    } else {
        return 0;
    }
}

void flip_card(char board[ROWS][COLS], int x, int y) {
    if (board[x][y] == '-') {
        board[x][y] = '*';
    } else if (board[x][y] == '*') {
        board[x][y] = '-';
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    init_board(board);
    int moves = 0;
    int matches = 0;

    while (1) {
        print_board(board);
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
            continue;
        }
        if (board[x][y] == '-') {
            flip_card(board, x, y);
            moves++;
        } else if (board[x][y] == '*') {
            flip_card(board, x, y);
            if (match(board, x, y)) {
                matches++;
            } else {
                flip_card(board, x, y);
            }
        }
        if (matches == 8) {
            printf("Congratulations! You won in %d moves.\n", moves);
            break;
        }
    }

    return 0;
}