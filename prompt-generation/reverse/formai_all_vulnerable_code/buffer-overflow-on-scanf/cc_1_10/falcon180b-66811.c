//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_NUMBERS 1000
#define SLEEP_TIME 1

int numbers[MAX_NUMBERS];
int num_threads;
pthread_t threads[MAX_THREADS];

void *sort_thread(void *arg) {
    int start = *(int *) arg;
    int end = start + MAX_NUMBERS/num_threads;

    for (int i = start; i < end; i++) {
        for (int j = i; j > 0 && numbers[j-1] > numbers[j]; j--) {
            int temp = numbers[j-1];
            numbers[j-1] = numbers[j];
            numbers[j] = temp;
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    printf("Enter the number of threads to use (1-4): ");
    scanf("%d", &num_threads);

    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads.\n");
        return 1;
    }

    printf("Enter %d integers:\n", MAX_NUMBERS);
    for (int i = 0; i < MAX_NUMBERS; i++) {
        scanf("%d", &numbers[i]);
    }

    int chunk_size = MAX_NUMBERS/num_threads;

    for (int i = 0; i < num_threads; i++) {
        int start = i*chunk_size;
        int end = (i == num_threads-1)? MAX_NUMBERS : (i+1)*chunk_size;

        pthread_create(&threads[i], NULL, sort_thread, &start);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sorted array:\n");
    for (int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}