//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE], n, key, pos;

void* thread_func(void* arg) {
    int tid = *(int*)arg;

    // Divide the search range for each thread
    int start = tid * (n / 4);
    int end = (tid == 3) ? n : (tid + 1) * (n / 4);

    // Search for the key in the assigned range
    for (int i = start; i < end; i++) {
        if (arr[i] == key) {
            pos = i;
            return (void*)0;
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    int tids[4];

    // Read input values
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the search key: ");
    scanf("%d", &key);

    // Create four threads for searching
    for (int i = 0; i < 4; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &tids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the position of the key
    if (pos != -1) {
        printf("The key was found at position %d.\n", pos);
    } else {
        printf("The key was not found in the array.\n");
    }

    pthread_exit(NULL);
}