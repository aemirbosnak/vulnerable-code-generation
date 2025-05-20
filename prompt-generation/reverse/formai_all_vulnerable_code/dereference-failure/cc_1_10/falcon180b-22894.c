//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define HEIGHT 20
#define WIDTH 30
#define PIPE_SIZE 100
#define RANDOM_SEED (unsigned int) time(NULL)

typedef struct {
    int x, y;
    int *pipe;
} Cell;

Cell grid[HEIGHT][WIDTH];
int top_pipe[HEIGHT][WIDTH];
int bottom_pipe[HEIGHT][WIDTH];

void init_grid() {
    srand(RANDOM_SEED);
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].pipe = malloc(PIPE_SIZE * sizeof(int));
            for (int k = 0; k < PIPE_SIZE; ++k) {
                grid[i][j].pipe[k] = -1;
            }
        }
    }
}

void *fill_thread(void *arg) {
    int id = *(int *) arg;
    int x = id % WIDTH;
    int y = id / WIDTH;
    grid[y][x].pipe[0] = 1;
    pthread_exit(NULL);
}

int main() {
    init_grid();
    int num_threads = HEIGHT * WIDTH;
    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; ++i) {
        pthread_create(&threads[i], NULL, fill_thread, &i);
    }

    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}