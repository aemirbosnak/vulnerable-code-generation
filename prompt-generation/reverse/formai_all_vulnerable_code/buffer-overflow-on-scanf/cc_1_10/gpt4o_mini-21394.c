//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For sleep function
#include <stdbool.h>

#define MAX_READINGS 100
#define TEMPERATURE_RANGE 15 // To simulate varying temperatures

typedef struct {
    float readings[MAX_READINGS];
    int count;
} TemperatureData;

void recordTemperature(TemperatureData *data);
void displayTemperatures(const TemperatureData *data);
float calculateAverage(const TemperatureData *data);
float findMaxTemperature(const TemperatureData *data);
float findMinTemperature(const TemperatureData *data);
void displayMenu();

int main() {
    TemperatureData tempData = { .count = 0 };
    bool running = true;

    // Initialize random number generator
    srand(time(NULL));

    while (running) {
        displayMenu();

        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordTemperature(&tempData);
                break;
            case 2:
                displayTemperatures(&tempData);
                break;
            case 3:
                printf("Average Temperature: %.2f°C\n", calculateAverage(&tempData));
                break;
            case 4:
                printf("Max Temperature: %.2f°C\n", findMaxTemperature(&tempData));
                break;
            case 5:
                printf("Min Temperature: %.2f°C\n", findMinTemperature(&tempData));
                break;
            case 0:
                running = false;
                printf("Exiting the temperature monitor. Stay cool!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(1); // Wait for 1 second before showing the menu again
    }

    return 0;
}

void recordTemperature(TemperatureData *data) {
    if (data->count < MAX_READINGS) {
        float temperature = (rand() % TEMPERATURE_RANGE) + 15.0; // Simulating a temperature between 15°C and 30°C
        data->readings[data->count] = temperature;
        data->count++;
        printf("Recorded Temperature: %.2f°C\n", temperature);
    } else {
        printf("Maximum readings reached! Can't record more temperatures.\n");
    }
}

void displayTemperatures(const TemperatureData *data) {
    if (data->count == 0) {
        printf("No temperature readings available.\n");
        return;
    }

    printf("Temperature Readings:\n");
    for (int i = 0; i < data->count; i++) {
        printf("Reading %d: %.2f°C\n", i + 1, data->readings[i]);
    }
}

float calculateAverage(const TemperatureData *data) {
    if (data->count == 0) return 0.0;

    float sum = 0.0;
    for (int i = 0; i < data->count; i++) {
        sum += data->readings[i];
    }
    return sum / data->count;
}

float findMaxTemperature(const TemperatureData *data) {
    if (data->count == 0) return 0.0;

    float maxTemp = data->readings[0];
    for (int i = 1; i < data->count; i++) {
        if (data->readings[i] > maxTemp) {
            maxTemp = data->readings[i];
        }
    }
    return maxTemp;
}

float findMinTemperature(const TemperatureData *data) {
    if (data->count == 0) return 0.0;

    float minTemp = data->readings[0];
    for (int i = 1; i < data->count; i++) {
        if (data->readings[i] < minTemp) {
            minTemp = data->readings[i];
        }
    }
    return minTemp;
}

void displayMenu() {
    printf("\n--- Temperature Monitor ---\n");
    printf("1. Record Temperature\n");
    printf("2. Display All Temperatures\n");
    printf("3. Calculate Average Temperature\n");
    printf("4. Find Maximum Temperature\n");
    printf("5. Find Minimum Temperature\n");
    printf("0. Exit\n");
    printf("---------------------------\n");
}