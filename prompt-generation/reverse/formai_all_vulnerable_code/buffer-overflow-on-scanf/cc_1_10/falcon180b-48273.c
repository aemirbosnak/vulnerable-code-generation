//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 100

typedef struct {
    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];
    int thread_id;
} thread_data_t;

void *encrypt_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int i, j;

    for (i = 0; i < strlen(data->input_buffer); i++) {
        data->output_buffer[i] = data->input_buffer[i] + data->thread_id;
    }

    printf("Thread %d encrypted message: %s\n", data->thread_id, data->output_buffer);

    pthread_exit(0);
}

void *decrypt_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int i, j;

    for (i = 0; i < strlen(data->output_buffer); i++) {
        data->input_buffer[i] = data->output_buffer[i] - data->thread_id;
    }

    printf("Thread %d decrypted message: %s\n", data->thread_id, data->input_buffer);

    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];
    int i;

    printf("Enter message to encrypt: ");
    scanf("%s", data[0].input_buffer);

    for (i = 0; i < MAX_THREADS; i++) {
        data[i].thread_id = i;
        pthread_create(&threads[i], NULL, encrypt_thread, (void *) &data[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nEnter encrypted message: ");
    scanf("%s", data[0].output_buffer);

    for (i = 0; i < MAX_THREADS; i++) {
        data[i].thread_id = i;
        pthread_create(&threads[i], NULL, decrypt_thread, (void *) &data[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}