//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_NUM_THREADS 10
#define BUFFER_SIZE 100

typedef struct {
    char hex[BUFFER_SIZE];
    int decimal;
    int thread_id;
} thread_data_t;

void *convert_to_hex(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;

    sprintf(data->hex, "0x%X", data->decimal);

    return NULL;
}

int main() {
    int num_threads = 0;
    pthread_t threads[MAX_NUM_THREADS];
    thread_data_t thread_data[MAX_NUM_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_NUM_THREADS || num_threads <= 0) {
        printf("Invalid number of threads.\n");
        return 1;
    }

    printf("Enter the decimal number to convert to hexadecimal: ");
    scanf("%d", &thread_data[0].decimal);

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i + 1;
        pthread_create(&threads[i], NULL, convert_to_hex, &thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Hexadecimal number: ");
    for (int i = 0; i < num_threads; i++) {
        printf("%s", thread_data[i].hex);
    }

    return 0;
}