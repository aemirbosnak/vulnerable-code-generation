//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SENSORS 10
#define TEMPERATURE_THRESHOLD 75.0 // Customize your threshold as needed

typedef struct {
    int id;
    float temperature;
    time_t timestamp;
} TemperatureSensor;

void recordTemperature(TemperatureSensor *sensor) {
    sensor->temperature = (rand() % 10000) / 100.0; // Generate a temperature between 0.00 and 99.99
    sensor->timestamp = time(NULL);
}

void logTemperature(TemperatureSensor *sensor) {
    FILE *file = fopen("temperature_log.txt", "a");
    if (file == NULL) {
        perror("Error opening file for logging");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Sensor ID: %d, Temperature: %.2f, Timestamp: %s",
            sensor->id, sensor->temperature, ctime(&sensor->timestamp));
    fclose(file);
}

void displayTemperature(const TemperatureSensor *sensor) {
    printf("Sensor ID: %d\n", sensor->id);
    printf("Current Temperature: %.2f\n", sensor->temperature);
    printf("Last Recorded: %s\n", ctime(&sensor->timestamp));
    
    if (sensor->temperature > TEMPERATURE_THRESHOLD) {
        printf("Warning: Temperature exceeds threshold!\n");
    }
}

void initializeSensors(TemperatureSensor sensors[], int count) {
    for (int i = 0; i < count; i++) {
        sensors[i].id = i + 1;
        recordTemperature(&sensors[i]);
        if (sensors[i].temperature > TEMPERATURE_THRESHOLD) {
            logTemperature(&sensors[i]);
        }
    }
}

void updateSensors(TemperatureSensor sensors[], int count) {
    for (int i = 0; i < count; i++) {
        recordTemperature(&sensors[i]);
        displayTemperature(&sensors[i]);
        
        if (sensors[i].temperature > TEMPERATURE_THRESHOLD) {
            logTemperature(&sensors[i]);
        }
    }
}

void printMenu() {
    printf("\nTemperature Monitoring System\n");
    printf("1. Initialize Sensors\n");
    printf("2. Update Sensors\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    TemperatureSensor sensors[MAX_SENSORS];
    int option, initialized = 0;

    while (1) {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                initializeSensors(sensors, MAX_SENSORS);
                initialized = 1;
                printf("Sensors have been initialized.\n");
                break;
            case 2:
                if (!initialized) {
                    printf("Please initialize sensors first.\n");
                } else {
                    updateSensors(sensors, MAX_SENSORS);
                }
                break;
            case 3:
                printf("Exiting the Temperature Monitoring System.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}