//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 80
#define NUM_THREADS 8

// Struct for passing data between threads
typedef struct {
    int x, y;
    int *grid;
} thread_data_t;

// Function for each thread to execute
void *runner(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int x = data->x;
    int y = data->y;
    int *grid = data->grid;

    // Loop through each cell and calculate the next generation
    for (int i = x; i < WIDTH; i += NUM_THREADS) {
        for (int j = y; j < HEIGHT; j += NUM_THREADS) {
            int count = 0;
            if (j > 0 && grid[i - x + (j - 1) * WIDTH] == 1) count++;
            if (j < HEIGHT - 1 && grid[i - x + (j + 1) * WIDTH] == 1) count++;
            if (i > 0 && grid[i - 1 + (j - y) * WIDTH] == 1) count++;
            if (i < WIDTH - 1 && grid[i + 1 + (j - y) * WIDTH] == 1) count++;
            if (count == 3 || count == 2 && grid[i - x + j * WIDTH] == 1) {
                grid[i - x + j * WIDTH] = 1;
            } else {
                grid[i - x + j * WIDTH] = 0;
            }
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    // Initialize the grid with random values
    int **grid = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Create threads
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].x = i;
        data[i].y = 0;
        data[i].grid = grid;
        pthread_create(&threads[i], NULL, runner, &data[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final grid
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}