//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <pthread.h>

#define MAX_THREADS 5
#define BUFFER_SIZE 1000

unsigned char hash[SHA256_DIGEST_LENGTH];

struct thread_data {
    char buffer[BUFFER_SIZE];
    int size;
};

void* hash_thread(void* thread_arg) {
    struct thread_data* data = (struct thread_data*)thread_arg;
    SHA256(data->buffer, data->size, hash);
    pthread_exit(NULL);
}

int main() {
    char input[BUFFER_SIZE];
    int input_size, i, rc;
    pthread_t threads[MAX_THREADS];
    struct thread_data thread_data_array[MAX_THREADS];

    printf("Enter a string to hash:\n");
    fgets(input, BUFFER_SIZE, stdin);
    input_size = strlen(input) - 1;
    input[input_size] = '\0';

    if (input_size % MAX_THREADS != 0) {
        printf("Input size must be a multiple of %d\n", MAX_THREADS);
        return 1;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        thread_data_array[i].size = input_size / MAX_THREADS;
        strncpy(thread_data_array[i].buffer, input + (i * thread_data_array[i].size), thread_data_array[i].size);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, hash_thread, (void*)&thread_data_array[i]);
        if (rc) {
            printf("Error: pthread_create() returned code %d\n", rc);
            return 1;
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: pthread_join() returned code %d\n", rc);
            return 1;
        }
    }

    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}