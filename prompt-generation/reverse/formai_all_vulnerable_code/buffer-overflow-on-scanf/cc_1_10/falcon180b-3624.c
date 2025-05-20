//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MINES 10

char board[ROWS][COLS];

void init_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }
}

void place_mines() {
    int count = 0;
    while (count < MINES) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        if (board[x][y] == '.') {
            board[x][y] = '*';
            count++;
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '*') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    init_board();
    place_mines();
    print_board();

    int x, y;
    while (1) {
        printf("Enter your move (row, col): ");
        scanf("%d%d", &x, &y);
        if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
            printf("Invalid move.\n");
            continue;
        }
        if (board[x][y] == '*') {
            printf("Game over. You lose.\n");
            return 0;
        } else if (board[x][y] == '.') {
            board[x][y] = 'X';
            if (check_win()) {
                printf("Congratulations! You win!\n");
                return 0;
            }
        } else {
            printf("Invalid move.\n");
            continue;
        }
    }
    return 0;
}