//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define NUM_MINES 10

typedef struct {
    int row;
    int col;
    char symbol;
} Cell;

Cell grid[ROWS][COLS];

void init_grid(void) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].symbol = '.';
        }
    }
}

void place_mines(void) {
    int count = 0;
    int row, col;

    while (count < NUM_MINES) {
        row = rand() % ROWS;
        col = rand() % COLS;

        if (grid[row][col].symbol!= '*') {
            grid[row][col].symbol = '*';
            count++;
        }
    }
}

void print_grid(void) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j].symbol);
        }
        printf("\n");
    }
}

int reveal_cell(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return -1;
    }

    if (grid[row][col].symbol == '*') {
        printf("You hit a mine! Game over.\n");
        exit(0);
    } else if (grid[row][col].symbol == '.') {
        printf("Empty cell.\n");
    } else {
        printf("Cell contains: %d\n", grid[row][col].symbol - '0');
    }

    return 0;
}

int main(void) {
    srand(time(NULL));
    init_grid();
    place_mines();

    int game_over = 0;

    while (!game_over) {
        printf("Current grid:\n");
        print_grid();

        int choice;
        printf("Enter your choice (row and column): ");
        scanf("%d %d", &choice, &choice);

        int row = choice / COLS;
        int col = choice % COLS;

        reveal_cell(row, col);

        if (game_over) {
            break;
        }
    }

    return 0;
}