//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RECORDS 1000

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureRecord;

typedef struct {
    TemperatureRecord records[MAX_RECORDS];
    int count;
} TemperatureMonitor;

void initialize_monitor(TemperatureMonitor* monitor) {
    monitor->count = 0;
}

void record_temperature(TemperatureMonitor* monitor, float temperature) {
    if (monitor->count >= MAX_RECORDS) {
        printf("Error: Maximum records reached, cannot record more temperatures.\n");
        return;
    }
    monitor->records[monitor->count].timestamp = time(NULL);
    monitor->records[monitor->count].temperature = temperature;
    monitor->count++;
    printf("Temperature of %.2f recorded at %s", temperature, ctime(&monitor->records[monitor->count - 1].timestamp));
}

void display_all_temperatures(TemperatureMonitor* monitor) {
    printf("\nAll Recorded Temperatures:\n");
    printf("-----------------------------------------------------\n");
    printf("|   Timestamp           |   Temperature (°C)      |\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < monitor->count; i++) {
        printf("| %s | %19.2f |\n", ctime(&monitor->records[i].timestamp), monitor->records[i].temperature);
    }
    printf("-----------------------------------------------------\n");
}

float calculate_average(TemperatureMonitor* monitor) {
    float sum = 0;
    for (int i = 0; i < monitor->count; i++) {
        sum += monitor->records[i].temperature;
    }
    return (monitor->count == 0) ? 0 : (sum / monitor->count);
}

void display_statistics(TemperatureMonitor* monitor) {
    if (monitor->count == 0) {
        printf("No temperature records available for statistics.\n");
        return;
    }

    float average = calculate_average(monitor);
    float min = monitor->records[0].temperature;
    float max = monitor->records[0].temperature;

    for (int i = 1; i < monitor->count; i++) {
        if (monitor->records[i].temperature < min) {
            min = monitor->records[i].temperature;
        }
        if (monitor->records[i].temperature > max) {
            max = monitor->records[i].temperature;
        }
    }

    printf("\nTemperature Statistics:\n");
    printf("-----------------------------------------------------\n");
    printf("|   Average Temperature: %.2f °C                    |\n", average);
    printf("|   Minimum Temperature: %.2f °C                    |\n", min);
    printf("|   Maximum Temperature: %.2f °C                    |\n", max);
    printf("-----------------------------------------------------\n");
}

int main() {
    TemperatureMonitor monitor;
    initialize_monitor(&monitor);

    int option;
    float temp;

    while (1) {
        printf("\nTemperature Monitor Menu:\n");
        printf("1. Record Temperature\n");
        printf("2. Display All Temperatures\n");
        printf("3. Display Statistics\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temp);
                record_temperature(&monitor, temp);
                break;
            case 2:
                display_all_temperatures(&monitor);
                break;
            case 3:
                display_statistics(&monitor);
                break;
            case 4:
                printf("Exiting Temperature Monitor. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
        }
    }
    return 0;
}