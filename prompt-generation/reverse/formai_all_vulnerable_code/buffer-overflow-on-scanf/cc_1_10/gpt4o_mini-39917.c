//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READINGS 100
#define FILENAME "temperature_readings.txt"

typedef struct {
    float *readings;
    int count;
    int capacity;
} TemperatureMonitor;

TemperatureMonitor* create_monitor(int capacity) {
    TemperatureMonitor* monitor = (TemperatureMonitor*)malloc(sizeof(TemperatureMonitor));
    if (!monitor) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }
    monitor->readings = (float*)malloc(capacity * sizeof(float));
    if (!monitor->readings) {
        fprintf(stderr, "Memory allocation for readings failed!\n");
        free(monitor);
        return NULL;
    }
    monitor->count = 0;
    monitor->capacity = capacity;
    return monitor;
}

void delete_monitor(TemperatureMonitor* monitor) {
    if (monitor) {
        free(monitor->readings);
        free(monitor);
    }
}

void add_reading(TemperatureMonitor* monitor, float temperature) {
    if (monitor->count >= monitor->capacity) {
        monitor->capacity *= 2;
        monitor->readings = (float*)realloc(monitor->readings, monitor->capacity * sizeof(float));
        if (!monitor->readings) {
            fprintf(stderr, "Reallocation failed!\n");
            return;
        }
    }
    monitor->readings[monitor->count++] = temperature;
}

void display_readings(const TemperatureMonitor* monitor) {
    printf("Temperature Readings:\n");
    for (int i = 0; i < monitor->count; i++) {
        printf("%.2f °C\n", monitor->readings[i]);
    }
}

void check_temperature_alert(float temperature) {
    if (temperature > 30.0) {
        printf("Alert: High Temperature! Current: %.2f °C\n", temperature);
    } else if (temperature < 0.0) {
        printf("Alert: Low Temperature! Current: %.2f °C\n", temperature);
    }
}

void save_readings_to_file(const TemperatureMonitor* monitor) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < monitor->count; i++) {
        fprintf(file, "%.2f\n", monitor->readings[i]);
    }
    fclose(file);
    printf("Readings saved to %s\n", FILENAME);
}

int main() {
    TemperatureMonitor* monitor = create_monitor(MAX_READINGS);
    if (!monitor) {
        return EXIT_FAILURE;
    }

    char command[10];
    float temperature;
    
    while (1) {
        printf("Enter command (add, display, save, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter temperature (°C): ");
            scanf("%f", &temperature);
            add_reading(monitor, temperature);
            check_temperature_alert(temperature);
        } else if (strcmp(command, "display") == 0) {
            display_readings(monitor);
        } else if (strcmp(command, "save") == 0) {
            save_readings_to_file(monitor);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    delete_monitor(monitor);
    return EXIT_SUCCESS;
}