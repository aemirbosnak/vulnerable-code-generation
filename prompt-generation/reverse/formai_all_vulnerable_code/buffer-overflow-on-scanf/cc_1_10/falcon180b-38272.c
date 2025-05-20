//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_ARRAY_SIZE 1000000

int arr[MAX_ARRAY_SIZE];
int target;
int num_elements;

void* thread_search(void* arg) {
    int start_index, end_index;
    int thread_num = *(int*) arg;
    start_index = thread_num * (num_elements / NUM_THREADS);
    end_index = (thread_num + 1) * (num_elements / NUM_THREADS) - 1;

    for (int i = start_index; i <= end_index; i++) {
        if (arr[i] == target) {
            printf("Found target %d at index %d in thread %d\n", target, i, thread_num);
            pthread_exit(0);
        }
    }

    pthread_exit(0);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];

    printf("Enter the size of the array: ");
    scanf("%d", &num_elements);

    printf("Enter the elements of the array: ");
    for (i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value: ");
    scanf("%d", &target);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_search, (void*) &i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}