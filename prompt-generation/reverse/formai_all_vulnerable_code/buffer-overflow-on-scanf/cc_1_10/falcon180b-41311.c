//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

int arr[1000];
int n;

void *search(void *arg) {
    int start = *(int *) arg;
    int end = start + 100;
    int target = 42;

    for (int i = start; i < end; i++) {
        if (arr[i] == target) {
            printf("Found %d at index %d\n", target, i);
            pthread_exit(0);
        }
    }

    printf("Not found\n");
    pthread_exit(0);
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        int start = i * n / MAX_THREADS;
        int end = (i + 1) * n / MAX_THREADS;

        pthread_create(&threads[i], NULL, search, &start);
        ids[i] = i;
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}