//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4
#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int id;
    int x;
    int y;
    int width;
    int height;
} thread_data_t;

void *draw_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int x = data->x;
    int y = data->y;
    int width = data->width;
    int height = data->height;
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("*");
        }
        printf("\n");
    }

    return NULL;
}

int main(int argc, char **argv) {
    pthread_t threads[NUM_THREADS];
    int i, j;
    int width = MAX_WIDTH / NUM_THREADS;
    int height = MAX_HEIGHT / NUM_THREADS;

    srand(time(0));

    for (i = 0; i < NUM_THREADS; i++) {
        thread_data_t data;
        data.id = i;
        data.x = i * width;
        data.y = i * height;
        data.width = width;
        data.height = height;

        pthread_create(&threads[i], NULL, draw_thread, (void *) &data);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}