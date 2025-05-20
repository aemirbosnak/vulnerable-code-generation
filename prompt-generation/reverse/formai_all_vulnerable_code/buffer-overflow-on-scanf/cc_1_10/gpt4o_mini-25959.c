//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_THREADS 5

typedef struct {
    int dice_count;
    int thread_id;
} ThreadData;

void *roll_dice(void *data) {
    ThreadData *thread_data = (ThreadData *)data;
    int dice_count = thread_data->dice_count;
    int thread_id = thread_data->thread_id;
    int results[MAX_DICE];

    printf("Thread %d: Rolling %d dice...\n", thread_id, dice_count);
    for (int i = 0; i < dice_count; i++) {
        results[i] = (rand() % 6) + 1; // Roll a 6-sided die
    }

    printf("Thread %d rolled: ", thread_id);
    for (int i = 0; i < dice_count; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
    
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    int total_dice = 0;
    printf("Enter the total number of dice to roll (max %d): ", MAX_DICE * MAX_THREADS);
    scanf("%d", &total_dice);

    if (total_dice > MAX_DICE * MAX_THREADS) {
        printf("Error: Exceeds maximum dice limit.\n");
        return EXIT_FAILURE;
    }

    int dice_per_thread = total_dice / MAX_THREADS;
    int remaining_dice = total_dice % MAX_THREADS;

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].thread_id = i + 1;
        thread_data[i].dice_count = dice_per_thread + (i < remaining_dice ? 1 : 0); // Distribute remaining dice
        pthread_create(&threads[i], NULL, roll_dice, (void *)&thread_data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed their dice rolls!\n");
    return EXIT_SUCCESS;
}