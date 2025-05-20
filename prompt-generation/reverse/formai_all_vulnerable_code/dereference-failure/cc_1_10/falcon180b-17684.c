//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

typedef struct {
    char *input_file;
    char *output_file;
    int thread_id;
} thread_data;

void *encrypt_thread(void *param) {
    thread_data *data = (thread_data *) param;
    FILE *input_file = fopen(data->input_file, "r");
    FILE *output_file = fopen(data->output_file, "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file(s)\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] = buffer[i] ^ (data->thread_id * i);
        }
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc!= 5) {
        printf("Usage: %s input_file output_file num_threads\n", argv[0]);
        exit(1);
    }

    int num_threads = atoi(argv[3]);
    if (num_threads <= 0 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads\n");
        exit(1);
    }

    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        data[i].input_file = argv[1];
        data[i].output_file = argv[2];
        data[i].thread_id = i;

        int rc = pthread_create(&threads[i], NULL, encrypt_thread, (void *) &data[i]);
        if (rc) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}