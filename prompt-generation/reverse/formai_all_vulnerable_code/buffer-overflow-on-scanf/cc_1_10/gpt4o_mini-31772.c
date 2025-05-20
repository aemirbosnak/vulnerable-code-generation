//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READINGS 100

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureReading;

void log_temperature(TemperatureReading readings[], int count);
void display_readings(TemperatureReading readings[], int count);
float calculate_average(TemperatureReading readings[], int count);
float calculate_max(TemperatureReading readings[], int count);
float calculate_min(TemperatureReading readings[], int count);

int main() {
    TemperatureReading readings[MAX_READINGS];
    int count = 0;
    char choice[10];

    printf("Welcome to the Temperature Monitoring Program\n\n");

    while (1) {
        printf("1. Log Temperature Reading\n");
        printf("2. Display All Readings\n");
        printf("3. Calculate Average Temperature\n");
        printf("4. Calculate Max Temperature\n");
        printf("5. Calculate Min Temperature\n");
        printf("6. Exit\n");
        printf("Please select an option (1-6): ");
        fgets(choice, sizeof(choice), stdin);
        
        switch (atoi(choice)) {
            case 1: {
                if (count >= MAX_READINGS) {
                    printf("Maximum readings reached. Cannot log more readings.\n");
                    break;
                }
                float temp;
                printf("Enter temperature reading (in Celsius): ");
                scanf("%f", &temp);
                getchar(); // consume newline

                readings[count].temperature = temp;
                readings[count].timestamp = time(NULL);
                count++;

                log_temperature(readings, count);
                printf("Temperature logged successfully.\n");
                break;
            }
            case 2:
                display_readings(readings, count);
                break;
            case 3:
                printf("Average Temperature: %.2f °C\n", calculate_average(readings, count));
                break;
            case 4:
                printf("Max Temperature: %.2f °C\n", calculate_max(readings, count));
                break;
            case 5:
                printf("Min Temperature: %.2f °C\n", calculate_min(readings, count));
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
}

void log_temperature(TemperatureReading readings[], int count) {
    FILE *file = fopen("temperature_log.txt", "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Timestamp: %sTemperature: %.2f °C\n", ctime(&readings[count - 1].timestamp), readings[count - 1].temperature);
    fclose(file);
}

void display_readings(TemperatureReading readings[], int count) {
    if (count == 0) {
        printf("No temperature readings recorded yet.\n");
        return;
    }

    printf("\nRecorded Temperature Readings:\n");
    for (int i = 0; i < count; ++i) {
        printf("Reading %d: %.2f °C at %s", i + 1, readings[i].temperature, ctime(&readings[i].timestamp));
    }
}

float calculate_average(TemperatureReading readings[], int count) {
    if (count == 0) return 0.0f;

    float sum = 0.0f;
    for (int i = 0; i < count; ++i) {
        sum += readings[i].temperature;
    }
    return sum / count;
}

float calculate_max(TemperatureReading readings[], int count) {
    if (count == 0) return 0.0f;

    float max = readings[0].temperature;
    for (int i = 1; i < count; ++i) {
        if (readings[i].temperature > max) {
            max = readings[i].temperature;
        }
    }
    return max;
}

float calculate_min(TemperatureReading readings[], int count) {
    if (count == 0) return 0.0f;

    float min = readings[0].temperature;
    for (int i = 1; i < count; ++i) {
        if (readings[i].temperature < min) {
            min = readings[i].temperature;
        }
    }
    return min;
}