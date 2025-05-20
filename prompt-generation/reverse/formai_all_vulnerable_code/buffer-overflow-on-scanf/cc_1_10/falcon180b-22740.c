//Falcon-180B DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 10
#define STACK_SIZE 1000
#define MAX_NUMBERS 100

int numbers[MAX_NUMBERS];
int num_threads;
pthread_t threads[MAX_THREADS];

void *sum_thread(void *arg) {
    int start, end;
    int sum = 0;

    start = *(int *) arg;
    end = start + STACK_SIZE / 2;

    for (int i = start; i < end; i++) {
        sum += numbers[i];
    }

    printf("Thread %d: Sum of numbers from %d to %d is %d\n", (int) arg, start, end - 1, sum);

    return NULL;
}

int main() {
    int i;
    srand(time(NULL));

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter %d integers:\n", MAX_NUMBERS);
    for (i = 0; i < MAX_NUMBERS; i++) {
        scanf("%d", &numbers[i]);
    }

    pthread_t thread_id;
    int thread_num = 0;

    for (i = 0; i < num_threads; i++) {
        int start = i * STACK_SIZE / num_threads;
        int end = (i + 1) * STACK_SIZE / num_threads - 1;

        if (i == num_threads - 1) {
            end = MAX_NUMBERS - 1;
        }

        pthread_create(&thread_id, NULL, sum_thread, (void *) thread_num);
        thread_num++;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}