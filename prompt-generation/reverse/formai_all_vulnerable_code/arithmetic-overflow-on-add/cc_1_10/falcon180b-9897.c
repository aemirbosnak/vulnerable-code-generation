//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>

#define NUM_THREADS 4
#define MAX_PIXELS 1000
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int id;
    int start_row;
    int end_row;
} thread_data;

int pixel_value(int row, int col, int width, int height, int *image) {
    int value = 0;
    if (row >= 0 && row < height && col >= 0 && col < width) {
        value = image[row * width + col];
    }
    return value;
}

void *thread_function(void *arg) {
    thread_data *data = (thread_data *) arg;
    int start_row = data->start_row;
    int end_row = data->end_row;
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;
    int *image = (int *) malloc(height * width * sizeof(int));

    for (int row = start_row; row < end_row; row++) {
        for (int col = 0; col < width; col++) {
            int value = pixel_value(row, col, width, height, image);
            int new_value = value + 50;
            if (new_value > 255) {
                new_value = 255;
            } else if (new_value < 0) {
                new_value = 0;
            }
            image[row * width + col] = new_value;
        }
    }

    free(image);
    return NULL;
}

int main() {
    int num_threads = NUM_THREADS;
    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_data data;
        data.id = i;
        data.start_row = i * (MAX_HEIGHT / num_threads);
        data.end_row = (i + 1) * (MAX_HEIGHT / num_threads) - 1;
        pthread_create(&threads[i], NULL, thread_function, (void *) &data);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}