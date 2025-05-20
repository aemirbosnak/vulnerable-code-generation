//Falcon-180B DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define NUM_MINES 10

int board[MAX_ROWS][MAX_COLS];
int num_rows, num_cols, num_mines;

void init_board() {
    srand(time(NULL));
    num_rows = rand() % MAX_ROWS + 1;
    num_cols = rand() % MAX_COLS + 1;
    num_mines = rand() % NUM_MINES + 1;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < num_mines; i++) {
        int x, y;
        do {
            x = rand() % num_rows;
            y = rand() % num_cols;
        } while (board[x][y] == -1);

        board[x][y] = -1;
    }
}

void print_board() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (board[i][j] == -1) {
                printf("*");
            } else {
                printf("%d", board[i][j]);
            }

            if (j < num_cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    init_board();
    print_board();

    int x, y;
    printf("Enter coordinates: ");
    scanf("%d %d", &x, &y);

    if (board[x][y] == -1) {
        printf("Game over! You hit a mine.\n");
    } else {
        printf("You uncovered a %d.\n", board[x][y]);
    }

    return 0;
}