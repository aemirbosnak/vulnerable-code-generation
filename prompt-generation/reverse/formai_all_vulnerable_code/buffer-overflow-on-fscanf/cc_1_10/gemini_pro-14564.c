//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdatomic.h>

#define N 9

struct cell {
    int value;
    bool fixed;
    uint64_t possibilities;
};

struct grid {
    struct cell cells[N][N];
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    atomic_int solved;
};

void print_grid(struct grid *grid)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid->cells[i][j].value);
        }
        printf("\n");
    }
}

bool is_valid_move(struct grid *grid, int row, int col, int value)
{
    for (int i = 0; i < N; i++) {
        if (grid->cells[row][i].value == value || grid->cells[i][col].value == value) {
            return false;
        }
    }

    int box_row = row / 3;
    int box_col = col / 3;

    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (grid->cells[i][j].value == value) {
                return false;
            }
        }
    }

    return true;
}

void *solve_sudoku(void *arg)
{
    struct grid *grid = (struct grid *)arg;

    pthread_mutex_lock(&grid->mutex);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid->cells[i][j].fixed) {
                continue;
            }

            for (int k = 0; k < N; k++) {
                if ((grid->cells[i][j].possibilities >> k) & 1) {
                    if (is_valid_move(grid, i, j, k + 1)) {
                        grid->cells[i][j].value = k + 1;
                        grid->cells[i][j].possibilities = 0;

                        pthread_cond_broadcast(&grid->cond);

                        if (atomic_load_explicit(&grid->solved, memory_order_acquire)) {
                            pthread_mutex_unlock(&grid->mutex);
                            return NULL;
                        }

                        solve_sudoku(grid);

                        if (!atomic_load_explicit(&grid->solved, memory_order_acquire)) {
                            grid->cells[i][j].value = 0;
                            grid->cells[i][j].possibilities = (1 << N) - 1;
                        }
                    }
                }
            }
        }
    }

    pthread_mutex_unlock(&grid->mutex);

    return NULL;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    struct grid grid;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value;
            fscanf(fp, "%d ", &value);

            grid.cells[i][j].value = value;
            grid.cells[i][j].fixed = (value != 0);
            grid.cells[i][j].possibilities = (1 << N) - 1;
        }
    }

    fclose(fp);

    pthread_t thread;

    pthread_mutex_init(&grid.mutex, NULL);
    pthread_cond_init(&grid.cond, NULL);

    atomic_store_explicit(&grid.solved, false, memory_order_release);

    pthread_create(&thread, NULL, solve_sudoku, &grid);

    pthread_mutex_lock(&grid.mutex);

    while (!atomic_load_explicit(&grid.solved, memory_order_acquire)) {
        pthread_cond_wait(&grid.cond, &grid.mutex);
    }

    pthread_mutex_unlock(&grid.mutex);

    pthread_join(thread, NULL);

    print_grid(&grid);

    pthread_mutex_destroy(&grid.mutex);
    pthread_cond_destroy(&grid.cond);

    return EXIT_SUCCESS;
}