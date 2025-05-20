//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 5
#define ROLLS_PER_THREAD 10

// Struct to hold thread arguments
typedef struct {
    int thread_id;
    int rolls[ROLLS_PER_THREAD];
} thread_data_t;

// Function to simulate dice rolling
void* roll_dice(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    srand(time(NULL) + data->thread_id); // Seed random with unique value

    printf("Thread %d rolling dice:\n", data->thread_id);
    for (int i = 0; i < ROLLS_PER_THREAD; i++) {
        data->rolls[i] = (rand() % 6) + 1; // Roll a die (1 to 6)
        printf("Thread %d rolled: %d\n", data->thread_id, data->rolls[i]);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    // Create threads and start the rolling
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        pthread_create(&threads[i], NULL, roll_dice, (void*)&thread_data[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Collate results
    printf("\nCollated results from all threads:\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Results from Thread %d: ", i);
        for (int j = 0; j < ROLLS_PER_THREAD; j++) {
            printf("%d ", thread_data[i].rolls[j]);
        }
        printf("\n");
    }

    return 0;
}