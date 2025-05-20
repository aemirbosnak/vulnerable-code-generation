//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10
#define SIDES 6
#define MAX_ROLLS 1000

int rolls[NUM_THREADS][MAX_ROLLS];
pthread_t threads[NUM_THREADS];

void *roll_dice(void *arg) {
    int thread_id = *((int *) arg);
    srand(time(NULL) + thread_id);

    for (int i = 0; i < MAX_ROLLS; i++) {
        int roll = rand() % SIDES + 1;
        rolls[thread_id][i] = roll;
    }

    return NULL;
}

int main() {
    int i;
    pthread_t thread_id;

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread_id, NULL, roll_dice, (void *) &i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int total_rolls = 0;

    for (i = 0; i < NUM_THREADS; i++) {
        int thread_total_rolls = 0;

        printf("Thread %d rolled:\n", i + 1);

        for (int j = 0; j < MAX_ROLLS; j++) {
            printf("%d ", rolls[i][j]);
            thread_total_rolls++;
        }

        printf("\nTotal rolls: %d\n\n", thread_total_rolls);

        total_rolls += thread_total_rolls;
    }

    printf("Total rolls across all threads: %d\n", total_rolls);

    return 0;
}