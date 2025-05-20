//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_RECORDS 100
#define FILENAME "temperature_log.txt"

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureRecord;

TemperatureRecord records[MAX_RECORDS];
int record_count = 0;

// Function prototypes
void log_temperature(float temp);
void display_records();
void generate_fake_temperature();

int main() {
    int choice;
    float simulated_temp;

    while (1) {
        printf("Temperature Monitor\n");
        printf("1. Log new temperature\n");
        printf("2. Display recorded temperatures\n");
        printf("3. Generate and log fake temperature data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the temperature: ");
                scanf("%f", &simulated_temp);
                log_temperature(simulated_temp);
                break;
            case 2:
                display_records();
                break;
            case 3:
                generate_fake_temperature();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void log_temperature(float temp) {
    if (record_count >= MAX_RECORDS) {
        printf("Maximum record limit reached. Cannot log more temperatures.\n");
        return;
    }

    time(&records[record_count].timestamp);
    records[record_count].temperature = temp;
    record_count++;

    // Write the new temperature to the log file
    FILE *file = fopen(FILENAME, "a");
    if (file != NULL) {
        fprintf(file, "Time: %sTemperature: %.2f°C\n", ctime(&records[record_count - 1].timestamp), temp);
        fclose(file);
    } else {
        printf("Error opening the log file.\n");
    }

    printf("Temperature logged: %.2f°C\n", temp);
}

void display_records() {
    if (record_count == 0) {
        printf("No temperature records found.\n");
        return;
    }

    printf("Recorded Temperatures:\n");
    for (int i = 0; i < record_count; i++) {
        printf("Time: %sTemperature: %.2f°C\n", ctime(&records[i].timestamp), records[i].temperature);
    }
}

void generate_fake_temperature() {
    float fake_temp = (float)(rand() % 100); // Generate a random temperature between 0 and 99 degrees
    log_temperature(fake_temp);
    printf("Generated and logged fake temperature: %.2f°C\n", fake_temp);
}