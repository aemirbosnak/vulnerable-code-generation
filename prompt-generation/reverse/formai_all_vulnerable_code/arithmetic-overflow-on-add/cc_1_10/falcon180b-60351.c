//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_THREADS 10
#define MAX_NUM 1000000
#define MAX_VALUE 100000
#define MAX_DELAY 5000

// semaphore for synchronization
sem_t sem;

// function to generate Fibonacci sequence
void *fibonacci(void *arg) {
    int id = *(int *) arg;
    int count = 0;

    // generate random delay
    srand(time(NULL) + id);
    int delay = rand() % MAX_DELAY;
    usleep(delay);

    // generate Fibonacci sequence
    int prev = 0;
    int curr = 1;
    printf("Thread %d generating Fibonacci sequence:\n", id);
    printf("%d %d\n", prev, curr);
    while (curr <= MAX_VALUE) {
        int next = prev + curr;
        printf("%d ", next);
        prev = curr;
        curr = next;
        count++;

        // check if maximum number of terms has been reached
        if (count == MAX_NUM) {
            break;
        }

        // generate random delay
        delay = rand() % MAX_DELAY;
        usleep(delay);
    }
    printf("\n");

    // signal semaphore to indicate completion
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    // create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, fibonacci, &ids[i]);
    }

    // wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed.\n");
    return 0;
}