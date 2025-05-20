//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4
#define NUM_DICE_ROLLS 1000
#define NUM_DICE_SIDES 6

int dice_rolls[NUM_THREADS][NUM_DICE_ROLLS];

void *thread_func(void *arg) {
    int thread_id = *(int *)arg;
    srand(time(NULL) + thread_id);

    for (int i = 0; i < NUM_DICE_ROLLS; i++) {
        dice_rolls[thread_id][i] = rand() % NUM_DICE_SIDES + 1;
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1, 2, 3};
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        for (int j = 0; j < NUM_DICE_ROLLS; j++) {
            printf("%d ", dice_rolls[i][j]);
        }
        printf("\n");
    }

    return 0;
}