//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LOG_SIZE 100
#define MAX_TEMP 50
#define MIN_TEMP -10

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureLog;

TemperatureLog tempLog[LOG_SIZE];
int logIndex = 0;

void logTemperature(float temp) {
    if (logIndex < LOG_SIZE) {
        tempLog[logIndex].timestamp = time(NULL);
        tempLog[logIndex].temperature = temp;
        logIndex++;
    } else {
        printf("Log is full! Cannot log more temperatures.\n");
    }
}

void displayLog() {
    printf("\n--- Temperature Log ---\n");
    for (int i = 0; i < logIndex; i++) {
        printf("Timestamp: %sTemperature: %.2f°C\n", ctime(&tempLog[i].timestamp), tempLog[i].temperature);
    }
    printf("-----------------------\n");
}

float generateRandomTemperature() {
    return (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP + (float)(rand() % 100) / 100;
}

void displayMenu() {
    printf("=== Temperature Monitor ===\n");
    printf("1. Log a new temperature\n");
    printf("2. Display all logged temperatures\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    srand(time(NULL));
    int choice = 0;

    while (choice != 3) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Log a new temperature
                float newTemperature = generateRandomTemperature();
                logTemperature(newTemperature);
                printf("Logged Temperature: %.2f°C\n", newTemperature);
                break;
            }
            case 2:
                // Display the temperature log
                displayLog();
                break;
            case 3:
                // Exit the program
                printf("Exiting the program. Stay cool!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(1);  // Pause before the next input
    }

    return 0;
}