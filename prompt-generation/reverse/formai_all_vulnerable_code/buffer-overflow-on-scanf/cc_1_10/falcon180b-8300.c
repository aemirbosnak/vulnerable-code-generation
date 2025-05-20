//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_KEYS 100

int arr[MAX_KEYS];
int keys[MAX_KEYS];
int num_keys;
int num_threads;
int *thread_arr;
int thread_id;

void *search(void *param) {
    int start = *(int *)param;
    int end = start + (MAX_KEYS / num_threads);

    for (int i = start; i < end; i++) {
        if (arr[i] == keys[0]) {
            printf("Key found at index %d\n", i);
            pthread_exit(0);
        }
    }

    pthread_exit(1);
}

int main() {
    printf("Enter number of keys: ");
    scanf("%d", &num_keys);

    printf("Enter the keys:\n");
    for (int i = 0; i < num_keys; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    thread_arr = (int *)malloc(num_threads * sizeof(int));
    for (int i = 0; i < num_threads; i++) {
        thread_arr[i] = i * (MAX_KEYS / num_threads);
    }

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, search, (void *)&thread_arr[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(thread_arr);

    return 0;
}