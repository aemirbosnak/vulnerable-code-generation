//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "temperature_log.txt"
#define MAX_ENTRIES 100

typedef struct {
    int entry_id;
    float temperature;
} TemperatureEntry;

TemperatureEntry temperatureLog[MAX_ENTRIES];
int entryCount = 0;

float readTemperature() {
    // Simulating temperature reading (e.g., from a sensor)
    return (float)(rand() % 1000) / 10.0; // Values between 0.0 and 100.0
}

void logTemperature(float temp) {
    if (entryCount < MAX_ENTRIES) {
        temperatureLog[entryCount].entry_id = entryCount + 1;
        temperatureLog[entryCount].temperature = temp;
        entryCount++;
    } else {
        printf("Log is full! Cannot log more entries.\n");
    }
}

void displayLogs() {
    printf("\nTemperature Log:\n");
    printf("Entry ID\tTemperature (°C)\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d\t\t%.2f\n", temperatureLog[i].entry_id, temperatureLog[i].temperature);
    }
}

void saveLogsToFile() {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%d, %.2f\n", temperatureLog[i].entry_id, temperatureLog[i].temperature);
    }
    fclose(file);
    printf("Logs saved to %s.\n", LOG_FILE);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int choice;
    float temperature;

    while (1) {
        printf("\nTemperature Monitor Menu:\n");
        printf("1. Read Temperature\n");
        printf("2. Display Logs\n");
        printf("3. Save Logs to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                temperature = readTemperature();
                printf("Current Temperature: %.2f °C\n", temperature);
                logTemperature(temperature);
                break;
            case 2:
                displayLogs();
                break;
            case 3:
                saveLogsToFile();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        sleep(1); // Sleep for a second before the next iteration
    }

    return 0;
}