//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RECORDS 100
#define ALERT_THRESHOLD_HIGH 75.0
#define ALERT_THRESHOLD_LOW 32.0
#define LOG_FILE "temperature_log.txt"

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureRecord;

void logTemperature(const TemperatureRecord *record) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file != NULL) {
        fprintf(file, "Timestamp: %s, Temperature: %.2f\n", ctime(&(record->timestamp)), record->temperature);
        fclose(file);
    } else {
        perror("Error opening log file");
    }
}

void checkTemperature(float temperature) {
    if (temperature > ALERT_THRESHOLD_HIGH) {
        printf("ALERT: Temperature is too high! (%.2f°F)\n", temperature);
    } else if (temperature < ALERT_THRESHOLD_LOW) {
        printf("ALERT: Temperature is too low! (%.2f°F)\n", temperature);
    } else {
        printf("Temperature is normal (%.2f°F)\n", temperature);
    }
}

void getTemperatureInput(float *temperature) {
    printf("Enter the current temperature in Fahrenheit: ");
    scanf("%f", temperature);
}

void displayLog() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file != NULL) {
        char line[256];
        printf("\n--- Temperature Log ---\n");
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        perror("Error opening log file");
    }
}

int main() {
    TemperatureRecord records[MAX_RECORDS];
    int recordCount = 0;
    float temperature;
    char choice;

    while (1) {
        printf("\nTemperature Monitor Menu:\n");
        printf("1. Enter current temperature\n");
        printf("2. Display temperature log\n");
        printf("3. Exit\n");
        printf("\nChoose an option: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (recordCount < MAX_RECORDS) {
                    getTemperatureInput(&temperature);
                    time(&(records[recordCount].timestamp));  
                    records[recordCount].temperature = temperature;
                    logTemperature(&(records[recordCount]));
                    checkTemperature(temperature);
                    recordCount++;
                } else {
                    printf("Log is full. Cannot record more temperatures.\n");
                }
                break;

            case '2':
                displayLog();
                break;

            case '3':
                printf("Exiting the temperature monitor. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}