//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int grid[ROWS][COLS];
int moves = 0;

void init_grid() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid() {
    int i, j;

    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++) {
            printf("%s ", grid[i][j] ? "1" : "_");
        }
        printf("|\n");
    }
}

void flip_square(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (grid[row][col] == -1 || grid[row][col] == grid[row + moves / 2][col + moves % 2]) {
            grid[row][col] = 1;
        } else {
            moves--;
            grid[row][col] = 0;
        }
    }
}

int check_win() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int i, j;
    int row1, col1, row2, col2;

    srand(time(NULL));
    init_grid();
    print_grid();

    while (!check_win()) {
        printf("\nEnter the row and column of the first square: ");
        scanf("%d%d", &row1, &col1);
        grid[row1][col1] = -1;
        print_grid();

        printf("\nEnter the row and column of the second square: ");
        scanf("%d%d", &row2, &col2);
        flip_square(row1, col1);
        flip_square(row2, col2);
        moves++;
        print_grid();
    }

    printf("\nYou won! Total moves: %d\n", moves);

    return 0;
}