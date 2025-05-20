//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define TEMP_THRESHOLD 30
#define MONITOR_INTERVAL 1

// Global variable to store the current temperature
volatile int current_temperature = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to simulate temperature reading
void *temperature_reader(void *arg) {
    while (1) {
        // Simulating temperature between 20 and 40 degrees Celsius
        int simulated_temperature = rand() % 21 + 20; 
        
        // Lock mutex to safely update the shared variable
        pthread_mutex_lock(&mutex);
        current_temperature = simulated_temperature;
        pthread_mutex_unlock(&mutex);

        // Sleep for the monitor interval
        sleep(MONITOR_INTERVAL);
    }
    return NULL;
}

// Function to display temperature periodically
void *temperature_display(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        printf("Current temperature: %d°C\n", current_temperature);
        if (current_temperature > TEMP_THRESHOLD) {
            printf("Warning! High temperature detected: %d°C\n", current_temperature);
        }
        pthread_mutex_unlock(&mutex);
        
        // Sleep for a while before the next display
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t reader_thread, display_thread;
    
    // Seed for random number generation
    srand(time(NULL));

    // Create the temperature reader thread
    if (pthread_create(&reader_thread, NULL, temperature_reader, NULL) != 0) {
        fprintf(stderr, "Error creating temperature reader thread\n");
        return 1;
    }

    // Create the temperature display thread
    if (pthread_create(&display_thread, NULL, temperature_display, NULL) != 0) {
        fprintf(stderr, "Error creating temperature display thread\n");
        return 1;
    }

    // Allow the user to quit with a simple command
    char command[10];
    printf("Type 'exit' to stop the monitor:\n");
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "exit") == 0) {
            break;
        }
    }

    // Clean up and exit
    printf("Stopping the temperature monitor...\n");
    pthread_cancel(reader_thread);
    pthread_cancel(display_thread);
    pthread_join(reader_thread, NULL);
    pthread_join(display_thread, NULL);
    pthread_mutex_destroy(&mutex);

    printf("Temperature monitor stopped. Goodbye!\n");
    return 0;
}