//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define SYMBOLS_COUNT 4

typedef struct {
    int row;
    int col;
} symbol;

void print_grid(symbol grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (grid[i][j].row == -1)
                printf(" __ ");
            else
                printf(" %d ", grid[i][j].row);
        }
        printf("\n");
    }
}

void shuffle_symbols(symbol symbols[SYMBOLS_COUNT]) {
    for (int i = SYMBOLS_COUNT - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        symbol temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    symbol grid[ROWS][COLS];
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            grid[i][j] = (symbol){-1, -1};

    symbol symbols[SYMBOLS_COUNT];
    for (int i = 0; i < SYMBOLS_COUNT; ++i) {
        symbols[i] = (symbol){i + 1, -1};
        grid[rand() % ROWS][rand() % COLS] = symbols[i];
    }

    shuffle_symbols(symbols);

    print_grid(grid);
    printf("\n");

    for (int i = 0; i < SYMBOLS_COUNT; ++i) {
        int user_row, user_col;
        do {
            printf("Enter the row and column of symbol %d: ", symbols[i].row);
            scanf("%d%d", &user_row, &user_col);
        } while (user_row != grid[user_row][user_col].row || user_row < 0 || user_row >= ROWS ||
                 user_col < 0 || user_col >= COLS);

        grid[user_row][user_col].row = -1;
    }

    int correct_answers = 0;
    for (int i = 0; i < SYMBOLS_COUNT; ++i) {
        if (grid[symbols[i].row][symbols[i].col].row == symbols[i].row + 1)
            ++correct_answers;
    }

    if (correct_answers == SYMBOLS_COUNT)
        printf("Congratulations! You have won the game!\n");
    else
        printf("Sorry, you have lost the game.\n");

    return 0;
}