//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SAMPLES 100
#define WARNING_THRESHOLD 75.0
#define CRITICAL_THRESHOLD 90.0

typedef struct {
    float temperatures[MAX_SAMPLES];
    int count;
} TemperatureData;

void recordTemperature(TemperatureData* data) {
    if (data->count >= MAX_SAMPLES) {
        printf("Maximum data samples reached.\n");
        return;
    }
    data->temperatures[data->count] = (float)(rand() % 101); 
    data->count++;
}

void displayTemperatures(const TemperatureData* data) {
    printf("Recorded Temperatures:\n");
    for (int i = 0; i < data->count; i++) {
        printf("Sample %d: %.2f °C\n", i + 1, data->temperatures[i]);
    }
}

void analyzeTemperatures(const TemperatureData* data) {
    float sum = 0.0, max = 0.0, min = 100.0;
    int warnings = 0, criticals = 0;

    for (int i = 0; i < data->count; i++) {
        float temp = data->temperatures[i];
        sum += temp;
        
        if (temp > WARNING_THRESHOLD) {
            warnings++;
            if (temp > CRITICAL_THRESHOLD) {
                criticals++;
            }
        }

        if (temp > max) {
            max = temp;
        }
        if (temp < min) {
            min = temp;
        }
    }

    float average = sum / data->count;

    printf("Analysis:\n");
    printf("Average Temp: %.2f °C\n", average);
    printf("Max Temp: %.2f °C\n", max);
    printf("Min Temp: %.2f °C\n", min);
    printf("Warnings: %d\n", warnings);
    printf("Critical Alerts: %d\n", criticals);

    if (criticals > 0) {
        printf("*** CRITICAL ALERT! Temperature exceeded %0.2f °C ***\n", CRITICAL_THRESHOLD);
    } else if (warnings > 0) {
        printf("Warning: Temperatures exceeded %0.2f °C\n", WARNING_THRESHOLD);
    }
}

void displayMenu() {
    printf("\nTemperature Monitoring System\n");
    printf("1. Record Temperature\n");
    printf("2. Display Recorded Temperatures\n");
    printf("3. Analyze Recorded Temperatures\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    TemperatureData tempData = { .count = 0 };
    srand(time(NULL));
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordTemperature(&tempData);
                break;
            case 2:
                displayTemperatures(&tempData);
                break;
            case 3:
                analyzeTemperatures(&tempData);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}