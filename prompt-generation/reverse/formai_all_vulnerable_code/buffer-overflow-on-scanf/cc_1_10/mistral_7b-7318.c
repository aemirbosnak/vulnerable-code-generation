//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 10 // Maximum size of the memory game
#define ELEMENT_VALUE 0 // Value of an empty memory location

typedef struct {
    int rows;
    int cols;
    int **memory;
} MemoryGame;

void initialize_memory_game(MemoryGame *game, int rows, int cols) {
    game->rows = rows;
    game->cols = cols;

    game->memory = (int **) calloc(rows, sizeof(int *));
    for (int i = 0; i < game->rows; i++) {
        game->memory[i] = (int *) calloc(cols, sizeof(int));
        for (int j = 0; j < cols; j++) {
            game->memory[i][j] = ELEMENT_VALUE;
        }
    }
}

void print_memory_game(MemoryGame game) {
    for (int i = 0; i < game.rows; i++) {
        for (int j = 0; j < game.cols; j++) {
            printf("%d ", game.memory[i][j]);
        }
        printf("\n");
    }
}

bool mark_memory_location(MemoryGame *game, int row, int col) {
    if (row >= 0 && row < game->rows && col >= 0 && col < game->cols) {
        if (game->memory[row][col] == ELEMENT_VALUE) {
            game->memory[row][col] = !ELEMENT_VALUE;
            return true;
        }
        return false;
    }
    return false;
}

bool check_memory_location(MemoryGame game, int row, int col) {
    if (mark_memory_location(&game, row, col)) {
        if (game.rows == 1 || game.cols == 1) {
            return true;
        }
        int revealed_elements = 0;
        for (int i = 0; i < game.rows; i++) {
            for (int j = 0; j < game.cols; j++) {
                if (game.memory[i][j] != ELEMENT_VALUE) {
                    revealed_elements++;
                }
            }
        }
        if (revealed_elements == (game.rows * game.cols) / 2) {
            return true;
        }
    }
    return false;
}

void free_memory_game(MemoryGame game) {
    for (int i = 0; i < game.rows; i++) {
        free(game.memory[i]);
    }
    free(game.memory);
}

int main() {
    int rows, cols;
    MemoryGame game;
    bool game_over = false;
    int attempts = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    initialize_memory_game(&game, rows, cols);

    srand(time(NULL));
    for (int i = 0; i < rows / 2; i++) {
        int r = rand() % rows;
        int c = rand() % cols;
        game.memory[r][c] = 1;
    }

    while (!game_over) {
        print_memory_game(game);

        printf("Enter the row number: ");
        int row;
        scanf("%d", &row);
        printf("Enter the column number: ");
        int col;
        scanf("%d", &col);

        attempts++;

        if (check_memory_location(game, row, col)) {
            printf("Congratulations! You have won the game.\n");
            game_over = true;
        } else {
            game.memory[row][col] = ELEMENT_VALUE;
            printf("Incorrect! Try again.\n");
        }

        if (attempts >= (game.rows * game.cols)) {
            printf("You have lost the game.\n");
            game_over = true;
        }
    }

    free_memory_game(game);

    return 0;
}