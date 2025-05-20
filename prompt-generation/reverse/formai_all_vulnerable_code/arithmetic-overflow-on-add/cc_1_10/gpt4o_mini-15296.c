//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_FORTUNES 10
#define MAX_BUFFER 256

// Array of fortunes
char* fortunes[MAX_FORTUNES] = {
    "You will find what you are looking for soon.",
    "Good news is on the way!",
    "An unexpected event will bring you joy.",
    "Someone will show you kindness today.",
    "A new opportunity will present itself.",
    "You will meet someone special.",
    "Your hard work will soon pay off.",
    "An old friend will contact you.",
    "You will discover a hidden talent.",
    "A challenge will lead to personal growth."
};

// Structure to hold thread data
typedef struct {
    int thread_id;
    char fortune[MAX_BUFFER];
} thread_data;

// Function to generate a random fortune
void* generate_fortune(void* threadarg) {
    thread_data* data = (thread_data*) threadarg;

    // Seed random number generator
    srand(time(NULL) + data->thread_id);

    // Generate a random index for fortune
    int index = rand() % MAX_FORTUNES;
    strcpy(data->fortune, fortunes[index]);

    printf("Thread %d: Your fortune is: %s\n", data->thread_id, data->fortune);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data thread_data_array[NUM_THREADS];
    
    // Create multiple threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_array[i].thread_id = i + 1;
        pthread_create(&threads[i], NULL, generate_fortune, (void*)&thread_data_array[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All fortunes have been generated!\n");
    return 0;
}