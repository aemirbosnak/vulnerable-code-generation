//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define THREADS 8

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *pixels;

void *generate_pixels(void *arg) {
    int thread_id = *(int *) arg;
    int start_x = thread_id * WIDTH / THREADS;
    int end_x = (thread_id + 1) * WIDTH / THREADS;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = start_x; x < end_x; x++) {
            pixels[y * WIDTH + x].r = rand() % 256;
            pixels[y * WIDTH + x].g = rand() % 256;
            pixels[y * WIDTH + x].b = rand() % 256;
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    pixels = (Pixel *) malloc(WIDTH * HEIGHT * sizeof(Pixel));

    pthread_t threads[THREADS];

    for (int i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, generate_pixels, (void *) &i);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d %d %d\n", pixels[y * WIDTH + x].r, pixels[y * WIDTH + x].g, pixels[y * WIDTH + x].b);
        }
    }

    return 0;
}