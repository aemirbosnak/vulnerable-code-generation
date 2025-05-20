//Falcon-180B DATASET v1.0 Category: Encryption ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define DATA_SIZE 100000
#define KEY_SIZE 16

typedef struct {
    int thread_id;
    char *data;
    char *key;
    char *result;
} thread_data;

void *encrypt_thread(void *arg) {
    thread_data *data = (thread_data *) arg;
    int thread_id = data->thread_id;
    char *key = data->key;
    char *data_chunk = data->data + thread_id * (DATA_SIZE / NUM_THREADS);
    char *result_chunk = data->result + thread_id * (DATA_SIZE / NUM_THREADS);

    for (int i = 0; i < DATA_SIZE / NUM_THREADS; i++) {
        result_chunk[i] = data_chunk[i] ^ key[i % KEY_SIZE];
    }

    pthread_exit(0);
}

int main() {
    char *data = (char *) malloc(DATA_SIZE);
    char *key = (char *) malloc(KEY_SIZE);
    char *result = (char *) malloc(DATA_SIZE);

    srand(time(NULL));
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = rand() % 256;
    }

    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }

    thread_data threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].thread_id = i;
        threads[i].data = data;
        threads[i].key = key;
        threads[i].result = result;
    }

    pthread_t threads_id[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads_id[i], NULL, encrypt_thread, &threads[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads_id[i], NULL);
    }

    printf("Encrypted data:\n");
    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}