//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int maze[HEIGHT][WIDTH];
bool visited[HEIGHT][WIDTH];
pthread_mutex_t mutex;
int num_threads;

void *generate_maze(void *arg) {
    int tid = *((int *)arg);
    srand(time(NULL) + tid);
    for (int i = tid; i < HEIGHT; i += num_threads) {
        for (int j = 0; j < WIDTH; j++) {
            if (visited[i][j]) {
                continue;
            }
            pthread_mutex_lock(&mutex);
            if (!visited[i][j]) {
                visited[i][j] = true;
                maze[i][j] = rand() % 4;
            }
            pthread_mutex_unlock(&mutex);
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[4];
    int tid[4];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 4; i++) {
        tid[i] = i;
        pthread_create(&threads[i], NULL, generate_maze, &tid[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}