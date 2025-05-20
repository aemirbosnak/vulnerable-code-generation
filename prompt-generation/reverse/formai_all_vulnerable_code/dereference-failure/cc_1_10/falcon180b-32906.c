//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define NUM_THREADS 4

typedef struct {
    char *input_file;
    char *output_file;
    int thread_id;
} thread_data_t;

void *encrypt_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    FILE *input_file = fopen(data->input_file, "r");
    FILE *output_file = fopen(data->output_file, "w");
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, input_file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = buffer[i] ^ (data->thread_id + i);
        }
        fputs(buffer, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    char input_file[100] = "input.txt";
    char output_file[100] = "output.txt";

    for (int i = 0; i < NUM_THREADS; i++) {
        strcpy(data[i].input_file, input_file);
        strcpy(data[i].output_file, output_file);
        data[i].thread_id = i;
        pthread_create(&threads[i], NULL, encrypt_thread, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Encryption completed successfully!\n");
    return 0;
}