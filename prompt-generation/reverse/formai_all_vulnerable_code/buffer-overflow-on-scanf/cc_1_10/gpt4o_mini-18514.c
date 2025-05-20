//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_TEMPERATURES 100
#define TEMP_THRESHOLD 75.0

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureRecord;

TemperatureRecord tempRecords[MAX_TEMPERATURES];
int recordCount = 0;

void logTemperature(float temperature) {
    if (recordCount < MAX_TEMPERATURES) {
        tempRecords[recordCount].timestamp = time(NULL);
        tempRecords[recordCount].temperature = temperature;
        recordCount++;
    } else {
        printf("Temperature log is full. Please clear the records.\n");
    }
}

void displayTemperatureLog() {
    printf("\nTemperature Log:\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < recordCount; i++) {
        char buffer[26];
        struct tm* tm_info;
        tm_info = localtime(&tempRecords[i].timestamp);
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%s - Temperature: %.2f°F\n", buffer, tempRecords[i].temperature);
    }
    printf("-----------------------------------\n");
}

void checkThreshold(float temperature) {
    if (temperature > TEMP_THRESHOLD) {
        printf("Warning! High temperature detected: %.2f°F\n", temperature);
    }
}

float simulateTemperatureReading() {
    return ((rand() % 10000) / 100.0);  // Simulate a temperature between 0.00°F to 99.99°F
}

void clearRecords() {
    memset(tempRecords, 0, sizeof(tempRecords));
    recordCount = 0;
    printf("Temperature records cleared.\n");
}

int main() {
    srand(time(NULL));
    char command[20];
    float temperature;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Commands: record, display, clear, exit\n");

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", command);

        if (strcmp(command, "record") == 0) {
            temperature = simulateTemperatureReading();
            logTemperature(temperature);
            printf("Recorded Temperature: %.2f°F\n", temperature);
            checkThreshold(temperature);

        } else if (strcmp(command, "display") == 0) {
            displayTemperatureLog();

        } else if (strcmp(command, "clear") == 0) {
            clearRecords();

        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Temperature Monitor. Goodbye!\n");
            break;

        } else {
            printf("Unknown command. Please try again.\n");
        }

        sleep(1);  // Pause before the next command
    }

    return 0;
}