//FormAI DATASET v1.0 Category: Data validation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 2
#define NUM_VALUES 10

int inputArray[NUM_VALUES];
int validatedArray[NUM_VALUES];
int count = 0;

pthread_mutex_t lock;

void *validateValues(void *arg) {
    int i = 0;
    int value = 0;

    for (i = *(int *)arg; i < NUM_VALUES; i += THREADS) {
        value = inputArray[i];

        pthread_mutex_lock(&lock);

        if (value >= 0 && value <= 100) {
            validatedArray[count] = value;
            count++;
        }

        pthread_mutex_unlock(&lock);
    }

    pthread_exit(NULL);
}

int main() {
    int i = 0;
    pthread_t threads[THREADS];
    int threadArgs[THREADS];

    pthread_mutex_init(&lock, NULL);

    printf("Enter %d integer values:\n", NUM_VALUES);

    for (i = 0; i < NUM_VALUES; i++) {
        scanf("%d", &inputArray[i]);
    }

    for (i = 0; i < THREADS; i++) {
        threadArgs[i] = i;
        pthread_create(&threads[i], NULL, validateValues, &threadArgs[i]);
    }

    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Validated values:\n");

    for (i = 0; i < count; i++) {
        printf("%d ", validatedArray[i]);
    }

    pthread_mutex_destroy(&lock);

    return 0;
 }