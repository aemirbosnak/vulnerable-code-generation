//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdint.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_THREADS 4

typedef struct {
    int thread_id;
    int start_row;
    int end_row;
} thread_data_t;

uint8_t *image_data;
uint8_t *temp_data;

void *thread_func(void *arg) {
    thread_data_t *data = arg;
    int thread_id = data->thread_id;
    int start_row = data->start_row;
    int end_row = data->end_row;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int index = i * WIDTH + j;
            temp_data[index] = image_data[index];
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    image_data = malloc(WIDTH * HEIGHT * sizeof(uint8_t));
    temp_data = malloc(WIDTH * HEIGHT * sizeof(uint8_t));

    // Initialize image data
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image_data[i] = rand() % 256;
    }

    int row_size = HEIGHT / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].thread_id = i;
        data[i].start_row = i * row_size;
        data[i].end_row = (i == NUM_THREADS - 1)? HEIGHT : (i + 1) * row_size;

        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Save temp data to file
    FILE *fp = fopen("image.raw", "wb");
    fwrite(temp_data, sizeof(uint8_t), WIDTH * HEIGHT, fp);
    fclose(fp);

    free(image_data);
    free(temp_data);

    return 0;
}