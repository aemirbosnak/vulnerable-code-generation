//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_THREADS 10
#define MAX_ROWS 20
#define DELAY 100 // in milliseconds

// mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// semaphore for synchronization
sem_t sem;

// initialize semaphore
void init_sem() {
    int ret;
    ret = sem_init(&sem, 0, 0);
    if (ret!= 0) {
        printf("Error initializing semaphore\n");
        exit(1);
    }
}

// print pattern
void print_pattern(int id) {
    int rows = (MAX_ROWS / MAX_THREADS) * id + 1;
    int cols = (MAX_ROWS / MAX_THREADS) * (MAX_THREADS - 1);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// thread function
void *thread_func(void *arg) {
    int id = (int) arg;

    sleep(id * DELAY);

    pthread_mutex_lock(&mutex);
    print_pattern(id);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];

    // initialize semaphore
    init_sem();

    // create threads
    for (int i = 0; i < MAX_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void *) &ids[i]);
    }

    // wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}