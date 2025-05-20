//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

// Semaphore for synchronization
sem_t lock;

// Function to roll the dice
void *roll_dice(void *arg) {
    int num_dice = *(int *) arg;
    int i;
    srand(time(NULL));

    for (i = 0; i < num_dice; i++) {
        // Roll the dice
        int dice = rand() % 6 + 1;

        // Print the result
        printf("Dice %d rolled a %d\n", i + 1, dice);

        // Wait for other threads to print their results
        sem_wait(&lock);
    }

    return NULL;
}

int main() {
    int num_dice, num_threads;
    pthread_t threads[10];

    // Get the number of dice to roll
    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    // Get the number of threads
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Initialize the semaphore
    sem_init(&lock, 0, 0);

    // Create the threads
    int i;
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, roll_dice, (void *)&num_dice);
    }

    // Join the threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}