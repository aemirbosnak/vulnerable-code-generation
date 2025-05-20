//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NUM_DIGITS 32

typedef struct {
    char binary_num[MAX_NUM_DIGITS];
    int decimal_num;
    int thread_id;
} thread_data;

void *binary_conversion(void *thread_arg) {
    thread_data *data = (thread_data *) thread_arg;
    int i;

    for (i = 0; i < MAX_NUM_DIGITS; i++) {
        if (data->binary_num[i] == '1') {
            data->decimal_num += pow(2, MAX_NUM_DIGITS - i - 1);
        }
    }

    printf("Thread %d: Decimal number is %d\n", data->thread_id, data->decimal_num);
    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];
    int num_threads;
    int i;

    // Get number of threads from user
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Initialize thread data
    for (i = 0; i < num_threads; i++) {
        sprintf(data[i].binary_num, "10101010101010101010101010101010");
        data[i].decimal_num = 0;
        data[i].thread_id = i + 1;
    }

    // Create threads
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, binary_conversion, &data[i]);
    }

    // Join threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}