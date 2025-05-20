//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: light-weight
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct _thread_data_t {
    int tid;
    int *arr;
    int size;
} thread_data_t;

void *thread_fn(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int sum = 0;
    for (int i = 0; i < data->size; i++) {
        sum += data->arr[i];
    }
    printf("Thread %d: sum = %d\n", data->tid, sum);
    return NULL;
}

int main() {
    int num_threads, arr_size;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);
    printf("Enter the size of the array: ");
    scanf("%d", &arr_size);

    // Create an array
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 100;
    }

    // Create thread data structures
    thread_data_t data[num_threads];

    // Create threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        data[i].tid = i;
        data[i].arr = arr;
        data[i].size = arr_size;
        if (pthread_create(&threads[i], NULL, thread_fn, &data[i]) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}