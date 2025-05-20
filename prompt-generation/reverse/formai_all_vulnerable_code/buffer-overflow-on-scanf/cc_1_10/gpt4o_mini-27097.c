//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TEMP_RECORDS 100
#define TEMPERATURE_THRESHOLD 75

typedef struct {
    float temperatures[MAX_TEMP_RECORDS];
    int count;
    pthread_mutex_t lock;
} TemperatureData;

TemperatureData tempData;

void* read_temperature(void* args) {
    while (1) {
        pthread_mutex_lock(&tempData.lock);
        
        if (tempData.count < MAX_TEMP_RECORDS) {
            float temp = (rand() % 101) / 1.0; // Simulating temperature readings between 0 and 100
            tempData.temperatures[tempData.count] = temp;
            tempData.count++;
            printf("Temperature Recorded: %.2f\n", temp);
        } else {
            printf("Temperature records are full. No more readings can be added.\n");
        }
        
        pthread_mutex_unlock(&tempData.lock);
        sleep(2); // Simulating time delay between readings
    }
    return NULL;
}

void* monitor_temperature(void* args) {
    while (1) {
        pthread_mutex_lock(&tempData.lock);
        
        for (int i = 0; i < tempData.count; i++) {
            if (tempData.temperatures[i] > TEMPERATURE_THRESHOLD) {
                printf("Warning: High temperature alert! %.2f exceeded the threshold\n", 
                       tempData.temperatures[i]);
            }
        }
        
        pthread_mutex_unlock(&tempData.lock);
        sleep(5); // Monitor at a different interval
    }
    return NULL;
}

void display_recorded_temperatures() {
    pthread_mutex_lock(&tempData.lock);
    printf("\nRecorded Temperatures:\n");
    for (int i = 0; i < tempData.count; i++) {
        printf("%.2f ", tempData.temperatures[i]);
    }
    printf("\n\n");
    pthread_mutex_unlock(&tempData.lock);
}

int main() {
    pthread_t reader_thread, monitor_thread;

    tempData.count = 0;
    pthread_mutex_init(&tempData.lock, NULL);

    // Create threads for reading temperatures and monitoring
    pthread_create(&reader_thread, NULL, read_temperature, NULL);
    pthread_create(&monitor_thread, NULL, monitor_temperature, NULL);

    // Main loop to display recorded temperatures
    char command[10];
    while (1) {
        printf("Type 'show' to display recorded temperatures or 'exit' to quit: ");
        scanf("%s", command);

        if (strcmp(command, "show") == 0) {
            display_recorded_temperatures();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the temperature monitor.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    // Cleanup and exit
    pthread_cancel(reader_thread);
    pthread_cancel(monitor_thread);
    pthread_mutex_destroy(&tempData.lock);
    return 0;
}