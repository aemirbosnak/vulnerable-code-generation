//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TEMPERATURE 100.0
#define TEMP_SENSOR_INTERVAL 2 // seconds

volatile bool monitorActive = true;

void* temperatureSensor(void* arg) {
    double temperature;
    
    while (monitorActive) {
        // Simulate reading from a temperature sensor
        temperature = (double)(rand() % 150); // Random temperature between 0 - 150
        
        // Check if the temperature exceeds the maximum threshold
        if (temperature > MAX_TEMPERATURE) {
            printf("!!! ALERT !!! Temperature exceeded safe limit: %.2f°C\n", temperature);
        } else {
            printf("Current Temperature: %.2f°C\n", temperature);
        }

        // Sleep for defined interval before next reading
        sleep(TEMP_SENSOR_INTERVAL);
    }
    
    return NULL;
}

void* userInput(void* arg) {
    char command[10];

    while (monitorActive) {
        printf("Enter 'exit' to stop monitoring: ");
        scanf("%s", command);
        
        if (strcmp(command, "exit") == 0) {
            monitorActive = false;
            printf("Terminating temperature monitoring...\n");
        }
    }
    
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed random number generator

    pthread_t sensorThread, userInputThread;

    // Create the temperature sensor thread
    if (pthread_create(&sensorThread, NULL, temperatureSensor, NULL) != 0) {
        perror("Failed to create sensor thread");
        return EXIT_FAILURE;
    }

    // Create the user input thread
    if (pthread_create(&userInputThread, NULL, userInput, NULL) != 0) {
        perror("Failed to create user input thread");
        return EXIT_FAILURE;
    }

    // Wait for the threads to finish
    pthread_join(sensorThread, NULL);
    pthread_join(userInputThread, NULL);

    printf("Monitoring stopped. Goodbye!\n");
    return EXIT_SUCCESS;
}