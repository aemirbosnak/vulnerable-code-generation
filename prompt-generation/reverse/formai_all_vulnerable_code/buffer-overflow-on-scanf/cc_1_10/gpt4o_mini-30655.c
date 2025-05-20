//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define MAX_READINGS 100
#define THRESHOLD_HIGH 30.0
#define THRESHOLD_LOW 10.0

typedef struct {
    float readings[MAX_READINGS];
    int count;
    pthread_mutex_t lock;
} TemperatureData;

TemperatureData tempData;

void* generate_reading(void* arg) {
    while (1) {
        float newReading = (float)(rand() % 401) / 10.0; // Generates a reading between 0.0 to 40.0
        pthread_mutex_lock(&tempData.lock);
        
        if (tempData.count < MAX_READINGS) {
            tempData.readings[tempData.count++] = newReading;
            printf("Generated Reading: %.1f°C\n", newReading);
        } else {
            printf("Max readings reached. Clearing data...\n");
            tempData.count = 0; // Clear data after reaching the limit
        }
        
        pthread_mutex_unlock(&tempData.lock);
        sleep(1); // Sleep for 1 second before generating a new reading
    }
    return NULL;
}

void monitor_temperature() {
    while (1) {
        pthread_mutex_lock(&tempData.lock);
        if (tempData.count > 0) {
            for (int i = 0; i < tempData.count; i++) {
                float reading = tempData.readings[i];
                if (reading > THRESHOLD_HIGH) {
                    printf("Alert: High temperature detected! %.1f°C\n", reading);
                } else if (reading < THRESHOLD_LOW) {
                    printf("Alert: Low temperature detected! %.1f°C\n", reading);
                }
            }
        }
        pthread_mutex_unlock(&tempData.lock);
        sleep(3); // Monitor every 3 seconds
    }
}

void display_menu() {
    printf("\n===== Temperature Monitor =====\n");
    printf("1. Start Monitoring\n");
    printf("2. Exit Program\n");
    printf("Choose an option: ");
}

int main() {
    srand(time(NULL));
    tempData.count = 0;
    pthread_mutex_init(&tempData.lock, NULL);
    
    pthread_t generator_thread;
    if (pthread_create(&generator_thread, NULL, generate_reading, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Monitoring started...\n");
            monitor_temperature();
        } else if (choice == 2) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    pthread_cancel(generator_thread);
    pthread_join(generator_thread, NULL);
    pthread_mutex_destroy(&tempData.lock);
   
    return 0;
}