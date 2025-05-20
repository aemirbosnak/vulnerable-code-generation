//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CELLS 10
#define PAIRS_COUNT NUM_CELLS / 2

typedef struct cell {
    int value;
    int visited;
} Cell;

Cell cells[NUM_CELLS];
int score = 0;
int current_pair = 0;

void initialize_cells() {
    int i;
    for (i = 0; i < NUM_CELLS; ++i) {
        cells[i].value = 0;
        cells[i].visited = 0;
    }
}

void shuffle_cells() {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < PAIRS_COUNT; ++i) {
        do {
            j = rand() % NUM_CELLS;
        } while (cells[j].visited);
        cells[i * 2].value = cells[j].value;
        cells[i * 2].visited = 1;
        cells[j].visited = 1;
    }
}

int main() {
    int i, j, user_input;
    initialize_cells();
    shuffle_cells();

    while (current_pair < PAIRS_COUNT) {
        printf("Memory cell pair %d:\n", current_pair + 1);
        printf("Cell 1 value: %d\n", cells[2 * current_pair].value);
        printf("Cell 2 value: %d\n", cells[2 * current_pair + 1].value);

        scanf("%d", &user_input);

        if (user_input == cells[2 * current_pair].value) {
            printf("Correct!\n");
            ++score;
        } else {
            printf("Incorrect. Try again.\n");
            --score;
        }

        int empty_cell_index = -1;
        for (i = 0; i < NUM_CELLS; ++i) {
            if (!cells[i].visited) {
                empty_cell_index = i;
                break;
            }
        }

        if (empty_cell_index != -1) {
            cells[empty_cell_index].value = cells[2 * current_pair].value;
            cells[empty_cell_index].visited = 1;
        }

        current_pair++;
    }

    printf("Final score: %d\n", score);

    return 0;
}