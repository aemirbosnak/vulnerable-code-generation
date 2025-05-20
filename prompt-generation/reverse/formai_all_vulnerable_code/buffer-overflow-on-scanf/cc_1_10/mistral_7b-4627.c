//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define CELLS_COUNT (ROWS * COLS)

typedef struct Cell {
    int value;
    int revealed;
} Cell;

Cell memory_grid[ROWS][COLS];
int revealed_cells_count = 0;
int moves_count = 0;

void init_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            memory_grid[i][j].value = rand() % 4 + 1;
            memory_grid[i][j].revealed = 0;
        }
    }
}

void reveal_cell(int row, int col) {
    if (memory_grid[row][col].revealed || row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        puts("Invalid move.");
        return;
    }

    memory_grid[row][col].revealed = 1;
    revealed_cells_count++;
    moves_count++;

    printf("Row: %d, Column: %d, Value: %d\n", row + 1, col + 1, memory_grid[row][col].value);

    if (revealed_cells_count == CELLS_COUNT / 2) {
        int matched = 1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (memory_grid[i][j].revealed && memory_grid[i][j].value != memory_grid[(i + ROWS / 2) % ROWS][(j + COLS / 2) % COLS].value) {
                    matched = 0;
                    break;
                }
            }
            if (matched == 0)
                break;
        }

        if (matched) {
            puts("You've won!");
            exit(EXIT_SUCCESS);
        }
    }
}

void print_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%s", memory_grid[i][j].revealed ? (memory_grid[i][j].value > 0 ? (" %d", memory_grid[i][j].value) : ("   ")) : (" __ "));
            if (j < COLS - 1)
                printf("|");
        }
        puts("\n");
        if (i < ROWS - 1)
            puts("---------------------");
    }
}

int main() {
    srand(time(NULL));
    init_grid();
    print_grid();

    while (1) {
        int row, col;
        scanf("%d %d", &row, &col);
        reveal_cell(row - 1, col - 1);
        print_grid();
        puts("Moves: ");
        printf("%d\n", moves_count);
    }

    return 0;
}