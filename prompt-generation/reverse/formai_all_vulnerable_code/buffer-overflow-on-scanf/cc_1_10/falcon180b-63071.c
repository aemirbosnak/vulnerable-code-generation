//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4

int arr[100], n, target;
sem_t mutex;

void *search(void *arg) {
    int start = (*(int *) arg) * n / NUM_THREADS;
    int end = ((*(int *) arg) + 1) * n / NUM_THREADS - 1;

    for (int i = start; i <= end; i++) {
        sem_wait(&mutex);
        if (arr[i] == target) {
            printf("Element found at index %d by thread %d\n", i, *(int *) arg);
            return NULL;
        }
        sem_post(&mutex);
    }

    return NULL;
}

int main() {
    int i, sum = 0;
    pthread_t threads[NUM_THREADS];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    sem_init(&mutex, 0, 1);

    for (i = 0; i < NUM_THREADS; i++) {
        int part = n / NUM_THREADS;
        int *t = (int *) malloc(sizeof(int));
        *t = i;
        pthread_create(&threads[i], NULL, search, t);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sum of the elements in the array: %d\n", sum);

    return 0;
}