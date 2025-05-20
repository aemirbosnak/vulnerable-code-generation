//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

int fibonacci(int n);

void *thread_func(void *param);

int main() {
    int num_threads = 0;
    int *fib_numbers = NULL;
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &num_threads);

    fib_numbers = (int *) malloc(num_threads * sizeof(int));

    printf("Enter the starting number: ");
    int start_num = 0;
    scanf("%d", &start_num);

    for (int i = 0; i < num_threads; i++) {
        fib_numbers[i] = start_num + i;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &fib_numbers[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Fibonacci numbers:\n");
    for (int i = 0; i < num_threads; i++) {
        printf("%d ", fib_numbers[i]);
    }

    free(fib_numbers);

    return 0;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void *thread_func(void *param) {
    int num = *(int *) param;
    int result = fibonacci(num);

    printf("%d ", result);

    pthread_exit(0);
}