//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000
#define NUM_THREADS 4

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *pixels;
pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;

void *generate_pixels(void *arg) {
    int thread_id = *((int *) arg);
    int start_x = WIDTH / NUM_THREADS * thread_id;
    int end_x = start_x + WIDTH / NUM_THREADS;

    for (int x = start_x; x < end_x; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double noise = 0;
            for (int i = 0; i < 5; i++) {
                noise += rand() % 100 - 50;
            }
            noise /= 5;

            int r = (int) (255 * noise);
            int g = (int) (255 * noise);
            int b = (int) (255 * noise);

            pthread_mutex_lock(&mutex);
            pixels[y * WIDTH + x] = (Pixel) {x, y, r, g, b};
            pthread_mutex_unlock(&mutex);
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    pixels = (Pixel *) malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (pixels == NULL) {
        printf("Error: Failed to allocate memory\n");
        return 1;
    }

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, generate_pixels, (void *) &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%02X%02X%02X ", pixels[y * WIDTH + x].r, pixels[y * WIDTH + x].g, pixels[y * WIDTH + x].b);
        }
        printf("\n");
    }

    free(pixels);
    pthread_mutex_destroy(&mutex);

    return 0;
}