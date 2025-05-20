//Falcon-180B DATASET v1.0 Category: Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_ROUNDS 10
#define MAX_SCORE 100

// Struct to hold thread data
typedef struct {
    int id;
    int score;
} thread_data_t;

// Function for each thread to execute
void *runner(void *arg) {
    int id = *(int *) arg;
    int score = 0;

    srand(time(NULL) + id);

    for (int i = 0; i < NUM_ROUNDS; i++) {
        int roll = rand() % 6 + 1;
        score += roll;
        printf("Thread %d rolled a %d in round %d\n", id, roll, i + 1);
    }

    pthread_exit((void *) &score);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    // Initialize thread data
    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].id = i + 1;
        data[i].score = 0;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, runner, &data[i].id);
    }

    // Join threads and print results
    for (int i = 0; i < NUM_THREADS; i++) {
        void *result;
        pthread_join(threads[i], &result);

        int score = *(int *) result;
        printf("Thread %d final score: %d\n", data[i].id, score);
    }

    return 0;
}