//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_IMAGES 10

typedef struct {
    int id;
    int start_index;
    int end_index;
} ThreadData;

int **loadImages() {
    int **images = (int **)malloc(NUM_IMAGES * sizeof(int *));
    for (int i = 0; i < NUM_IMAGES; i++) {
        images[i] = (int *)malloc(1024 * sizeof(int));
        for (int j = 0; j < 1024; j++) {
            images[i][j] = rand() % 256;
        }
    }
    return images;
}

void *classifyImage(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int **images = loadImages();
    for (int i = data->start_index; i < data->end_index; i++) {
        int sum = 0;
        for (int j = 0; j < 1024; j++) {
            sum += images[i][j];
        }
        if (sum > 1024 * 256 / 2) {
            printf("Image %d is bright\n", i);
        } else {
            printf("Image %d is dark\n", i);
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData data[NUM_THREADS];
    int chunk_size = NUM_IMAGES / NUM_THREADS;

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].id = i;
        data[i].start_index = i * chunk_size;
        data[i].end_index = (i == NUM_THREADS - 1)? NUM_IMAGES - 1 : (i + 1) * chunk_size - 1;
        pthread_create(&threads[i], NULL, classifyImage, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}