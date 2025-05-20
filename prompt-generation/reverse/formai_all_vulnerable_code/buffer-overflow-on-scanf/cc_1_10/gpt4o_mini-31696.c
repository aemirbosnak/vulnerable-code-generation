//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_READINGS 100
#define FILE_NAME "temperature_data.txt"

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureReading;

void record_temperature(TemperatureReading readings[], int *count) {
    if (*count >= MAX_READINGS) {
        printf("Maximum readings reached. Cannot record new temperature.\n");
        return;
    }
    
    // Simulate temperature reading from a sensor
    float new_temp = (rand() % 401 - 200) / 10.0; // Random temperature from -20.0 to +20.0
    readings[*count].timestamp = time(NULL);
    readings[*count].temperature = new_temp;
    (*count)++;
    
    printf("Recorded Temperature: %.1f °C at %s", new_temp, ctime(&readings[*count - 1].timestamp));
}

void write_data_to_file(TemperatureReading readings[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s, %.1f\n", ctime(&readings[i].timestamp), readings[i].temperature);
    }
    fclose(file);
    printf("Data written to %s\n", FILE_NAME);
}

void display_readings(TemperatureReading readings[], int count) {
    printf("\nTemperature Readings:\n");
    printf("----------------------\n");
    printf("%-25s %s\n", "Timestamp", "Temperature (°C)");
    printf("----------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-25s %.1f\n", ctime(&readings[i].timestamp), readings[i].temperature);
    }
    printf("----------------------\n");
}

void display_menu() {
    printf("\nTemperature Monitor Menu:\n");
    printf("1. Record Temperature\n");
    printf("2. Display All Readings\n");
    printf("3. Save Readings to File\n");
    printf("4. Quit\n");
}

int main() {
    srand(time(NULL));
    TemperatureReading readings[MAX_READINGS];
    int count = 0;
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                record_temperature(readings, &count);
                break;
            case 2:
                display_readings(readings, count);
                break;
            case 3:
                write_data_to_file(readings, count);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);
    
    return 0;
}