//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 20
#define HEIGHT 10
#define NUM_THREADS 4

char maze[HEIGHT][WIDTH];
int start[2] = {0, 0};
int end[2] = {HEIGHT - 1, WIDTH - 1};

void *runner(void *arg) {
    int *thread_id = arg;
    int x = *thread_id * (WIDTH / NUM_THREADS);
    int y = *thread_id * (HEIGHT / NUM_THREADS);

    while (y < HEIGHT && x < WIDTH) {
        if (maze[y][x] == 'S') {
            start[0] = y;
            start[1] = x;
        } else if (maze[y][x] == 'E') {
            end[0] = y;
            end[1] = x;
        }
        y++;
        x++;
    }

    pthread_exit(0);
}

int main() {
    FILE *fp;
    char c;
    int i, j;

    fp = fopen("maze.txt", "r");
    if (fp == NULL) {
        printf("Error opening maze file\n");
        exit(1);
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%c", &c);
            maze[i][j] = c;
        }
    }

    fclose(fp);

    pthread_t threads[NUM_THREADS];
    int thread_id;

    for (thread_id = 0; thread_id < NUM_THREADS; thread_id++) {
        pthread_create(&threads[thread_id], NULL, runner, &thread_id);
    }

    for (thread_id = 0; thread_id < NUM_THREADS; thread_id++) {
        pthread_join(threads[thread_id], NULL);
    }

    printf("Start: (%d, %d)\n", start[0], start[1]);
    printf("End: (%d, %d)\n", end[0], end[1]);

    return 0;
}