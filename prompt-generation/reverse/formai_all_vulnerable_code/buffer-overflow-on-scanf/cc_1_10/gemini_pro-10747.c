//GEMINI-pro DATASET v1.0 Category: Game ; Style: multi-threaded
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    int *arr;
    int size;
} thread_arg_t;

void *thread_function(void *arg) {
    thread_arg_t *args = (thread_arg_t *)arg;

    for (int i = 0; i < args->size; i++) {
        args->arr[i] *= 2;
        printf("Thread %ld doubled element %d to %d\n", pthread_self(), i, args->arr[i]);
    }

    return NULL;
}

int main() {
    int num_threads;
    printf("Enter the number of threads to create: ");
    scanf("%d", &num_threads);

    int arr[100]; // Array of size 100

    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 100; // Initialize the array with random numbers
    }

    pthread_t threads[num_threads];
    thread_arg_t thread_args[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_args[i].arr = arr;
        thread_args[i].size = 100 / num_threads;

        pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The doubled array is:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}