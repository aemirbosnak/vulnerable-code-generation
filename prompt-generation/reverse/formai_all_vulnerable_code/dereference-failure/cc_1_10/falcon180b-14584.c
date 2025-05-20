//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define NUM_THREADS 4

typedef struct {
    int thread_id;
    int frame_size;
    float *input_buffer;
    float *output_buffer;
    pthread_t thread_handle;
} ThreadData;

void *process_audio(void *thread_data) {
    ThreadData *data = (ThreadData *) thread_data;
    int thread_id = data->thread_id;
    int frame_size = data->frame_size;
    float *input_buffer = data->input_buffer;
    float *output_buffer = data->output_buffer;

    for (int i = 0; i < frame_size; i++) {
        output_buffer[i] = input_buffer[i] * 0.5f;
    }

    return NULL;
}

int main() {
    int num_samples = SAMPLE_RATE / FRAME_SIZE;
    float *input_buffer = (float *) malloc(num_samples * sizeof(float));
    float *output_buffer = (float *) malloc(num_samples * sizeof(float));

    srand(time(NULL));
    for (int i = 0; i < num_samples; i++) {
        input_buffer[i] = rand() % 1000;
    }

    ThreadData thread_data[NUM_THREADS];
    pthread_t thread_handles[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].frame_size = FRAME_SIZE;
        thread_data[i].input_buffer = input_buffer;
        thread_data[i].output_buffer = output_buffer;
        pthread_create(&thread_handles[i], NULL, process_audio, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_handles[i], NULL);
    }

    free(input_buffer);
    free(output_buffer);

    return 0;
}