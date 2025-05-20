//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

struct shared_data {
    int temperature;
    int threshold;
    sem_t semaphore;
};

void *monitor_temperature(void *arg) {
    struct shared_data *data = (struct shared_data *) arg;
    int current_temperature;
    int i;

    for (i = 0; i < 10; i++) {
        // Simulate temperature readings with a random value between 20 and 30
        current_temperature = rand() % 11 + 20;

        printf("Temperature reading %d: %d°C\n", i+1, current_temperature);

        // Check if temperature exceeds threshold
        if (current_temperature > data->threshold) {
            printf("Temperature exceeded threshold of %d°C!\n", data->threshold);
        }

        // Sleep for 1 second between readings
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread_id;
    struct shared_data shared_data;
    int threshold;

    // Get user input for temperature threshold
    printf("Enter temperature threshold: ");
    scanf("%d", &threshold);

    // Initialize shared data
    shared_data.temperature = 0;
    shared_data.threshold = threshold;
    sem_init(&shared_data.semaphore, 0, 1);

    // Create monitor thread
    pthread_create(&thread_id, NULL, monitor_temperature, &shared_data);

    // Wait for monitor thread to finish
    pthread_join(thread_id, NULL);

    return 0;
}