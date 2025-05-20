//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX 10
#define NUM_THREADS 5
#define NUM_ELEMENTS 10000

int arr[MAX];
int search_key;
int found = 0;

void *search(void *arg) {
    int start = *(int *) arg;
    int end = start + MAX - 1;

    for (int i = start; i <= end; i++) {
        if (arr[i] == search_key) {
            found = 1;
            break;
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
    }

    int search_key = rand() % 100;

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int start = i * (MAX / NUM_THREADS);
        int end = (i == NUM_THREADS - 1)? MAX - 1 : (i + 1) * (MAX / NUM_THREADS) - 1;

        pthread_create(&threads[i], NULL, search, &start);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    if (found) {
        printf("Found %d in the array.\n", search_key);
    } else {
        printf("Could not find %d in the array.\n", search_key);
    }

    return 0;
}