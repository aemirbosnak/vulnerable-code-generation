//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_ROLLS 100000

int rolls[NUM_THREADS];
pthread_t threads[NUM_THREADS];

void *thread_func(void *arg) {
    int tid = *((int *) arg);
    int count = 0;

    srand(time(NULL) + tid);

    while (count < NUM_ROLLS) {
        int roll = rand() % 6 + 1;
        rolls[tid] += roll;
        count++;
    }

    return NULL;
}

int main() {
    int i;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], &attr, thread_func, (void *) &i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int total_rolls = 0;
    printf("Thread %d rolled %d times.\n", 0, rolls[0]);
    for (i = 1; i < NUM_THREADS; i++) {
        printf("Thread %d rolled %d times.\n", i, rolls[i]);
        total_rolls += rolls[i];
    }

    printf("Total rolls: %d\n", total_rolls);

    return 0;
}