//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_THREADS 8

typedef struct {
    int x;
    int y;
    int color;
} Pixel;

Pixel *pixels = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *draw_pixel(void *arg) {
    int thread_id = *(int *) arg;
    int start_x = thread_id * WIDTH / NUM_THREADS;
    int end_x = (thread_id + 1) * WIDTH / NUM_THREADS;

    for (int x = start_x; x < end_x; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            pthread_mutex_lock(&mutex);
            pixels[y * WIDTH + x] = (Pixel) {x, y, rand() % 256};
            pthread_mutex_unlock(&mutex);
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    pixels = calloc(WIDTH * HEIGHT, sizeof(Pixel));

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, draw_pixel, (void *) &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", pixels[y * WIDTH + x].color);
        }
        printf("\n");
    }

    return 0;
}