//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

#define WIDTH 800
#define HEIGHT 600
#define THREAD_COUNT 4
#define MAX_COLOR 255

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *canvas = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *generate_art(void *arg) {
    int id = *(int *) arg;
    int start_y = id * HEIGHT / THREAD_COUNT;
    int end_y = (id + 1) * HEIGHT / THREAD_COUNT;

    for (int y = start_y; y < end_y; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            pthread_mutex_lock(&mutex);
            canvas[y * WIDTH + x].r = rand() % MAX_COLOR;
            canvas[y * WIDTH + x].g = rand() % MAX_COLOR;
            canvas[y * WIDTH + x].b = rand() % MAX_COLOR;
            pthread_mutex_unlock(&mutex);
        }
    }

    return NULL;
}

int main() {
    canvas = (Pixel *) malloc(WIDTH * HEIGHT * sizeof(Pixel));

    pthread_t threads[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; ++i) {
        pthread_create(&threads[i], NULL, generate_art, (void *) &i);
    }

    for (int i = 0; i < THREAD_COUNT; ++i) {
        pthread_join(threads[i], NULL);
    }

    FILE *fp = fopen("art.ppm", "w");
    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLOR);

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            fprintf(fp, "%d %d %d ", canvas[y * WIDTH + x].r, canvas[y * WIDTH + x].g, canvas[y * WIDTH + x].b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}