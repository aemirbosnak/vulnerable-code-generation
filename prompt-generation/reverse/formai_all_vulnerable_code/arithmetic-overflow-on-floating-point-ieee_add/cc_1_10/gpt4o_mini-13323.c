//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define NUM_THREADS 5
#define DOWNLOAD_SIZE 1024 * 1024 // 1 MB

typedef struct {
    int thread_id;
    double speed; // Speed in Mbps
} ThreadData;

void* simulate_download(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    char* buffer = (char*) malloc(DOWNLOAD_SIZE);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        pthread_exit(NULL);
    }

    // Simulate download time
    sleep(rand() % 3 + 1); // Sleep for 1 to 3 seconds

    // Calculate download speed
    // Total bytes downloaded in Megabits = (size in bytes * 8) / (1024 * 1024)
    // In this example, we assume it takes "sleep" seconds to download DOWNLOAD_SIZE bytes
    double time_taken = (rand() % 3 + 1); // Randomly generated simulation time
    data->speed = (DOWNLOAD_SIZE * 8.0 / (1024 * 1024)) / time_taken;

    printf("Thread %d: Download completed in %.2f seconds with speed %.2f Mbps\n", 
           data->thread_id, time_taken, data->speed);

    free(buffer);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    double total_speed = 0.0;

    srand(time(NULL)); // Seed for random number generation

    // Create threads to simulate downloads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i + 1;
        if (pthread_create(&threads[i], NULL, simulate_download, (void*)&thread_data[i])) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_speed += thread_data[i].speed;
    }

    // Calculate and display average speed
    double average_speed = total_speed / NUM_THREADS;
    printf("\nAverage download speed across all threads: %.2f Mbps\n", average_speed);

    return 0;
}