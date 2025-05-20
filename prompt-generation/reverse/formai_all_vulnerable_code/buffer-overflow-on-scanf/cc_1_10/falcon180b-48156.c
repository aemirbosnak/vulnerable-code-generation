//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_SIZE 100

int arr[MAX_SIZE];
int size;

void *search_thread(void *arg) {
    int start = *(int *) arg;
    int end = start + size / MAX_THREADS;
    int target = *(int *) arg;

    for (int i = start; i < end; i++) {
        if (arr[i] == target) {
            printf("%d found at index %d\n", target, i);
            pthread_exit(0);
        }
    }

    printf("%d not found\n", target);
    pthread_exit(0);
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value: ");
    int target = *(int *) malloc(sizeof(int));
    scanf("%d", &target);

    pthread_t threads[MAX_THREADS];
    int thread_size = size / MAX_THREADS;

    for (int i = 0; i < MAX_THREADS; i++) {
        int start = i * thread_size;
        int end = (i == MAX_THREADS - 1)? size : (i + 1) * thread_size;
        pthread_create(&threads[i], NULL, search_thread, &target);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}