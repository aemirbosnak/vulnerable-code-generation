//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 10

typedef struct {
    float temperatures[MAX_HISTORY];
    int count;
    float alert_min;
    float alert_max;
} TemperatureMonitor;

// Function to initialize the temperature monitor
void init_monitor(TemperatureMonitor *monitor) {
    monitor->count = 0;
    monitor->alert_min = -1; // -1 indicates no alert set
    monitor->alert_max = -1; // -1 indicates no alert set
}

// Function to simulate a temperature reading
float get_temperature_reading() {
    float min_temp = -10.0;
    float max_temp = 40.0;
    return (rand() / (RAND_MAX + 1.0)) * (max_temp - min_temp) + min_temp;
}

// Function to store a temperature reading
void store_temperature(TemperatureMonitor *monitor, float temperature) {
    if (monitor->count < MAX_HISTORY) {
        monitor->temperatures[monitor->count++] = temperature;
    } else {
        for (int i = 1; i < MAX_HISTORY; i++) {
            monitor->temperatures[i - 1] = monitor->temperatures[i];
        }
        monitor->temperatures[MAX_HISTORY - 1] = temperature;
    }
}

// Function to display temperature history
void display_history(TemperatureMonitor *monitor) {
    printf("\nTemperature History:\n");
    for (int i = 0; i < monitor->count; i++) {
        printf("%.2f ", monitor->temperatures[i]);
    }
    printf("\n");
}

// Function to check current temperature and alert if necessary
void check_alerts(TemperatureMonitor *monitor, float temperature) {
    if (monitor->alert_min != -1 && temperature < monitor->alert_min) {
        printf("Alert! Temperature %.2f is below the minimum threshold of %.2f.\n", temperature, monitor->alert_min);
    }
    if (monitor->alert_max != -1 && temperature > monitor->alert_max) {
        printf("Alert! Temperature %.2f is above the maximum threshold of %.2f.\n", temperature, monitor->alert_max);
    }
}

// Function to set alert thresholds
void set_alerts(TemperatureMonitor *monitor, float min, float max) {
    monitor->alert_min = min;
    monitor->alert_max = max;
}

int main() {
    TemperatureMonitor monitor;
    init_monitor(&monitor);

    srand(time(0)); // Seed for random temperature reading
    int choice;
    float temp, min_alert, max_alert;

    do {
        printf("\nTemperature Monitor Menu:\n");
        printf("1. Get Current Temperature\n");
        printf("2. Display Temperature History\n");
        printf("3. Set Temperature Alerts\n");
        printf("4. Visualize Temperature History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                temp = get_temperature_reading();
                printf("Current Temperature: %.2f\n", temp);
                store_temperature(&monitor, temp);
                check_alerts(&monitor, temp);
                break;
            case 2:
                display_history(&monitor);
                break;
            case 3:
                printf("Set Minimum Alert Temperature: ");
                scanf("%f", &min_alert);
                printf("Set Maximum Alert Temperature: ");
                scanf("%f", &max_alert);
                set_alerts(&monitor, min_alert, max_alert);
                printf("Alert thresholds set: Min=%.2f, Max=%.2f\n", min_alert, max_alert);
                break;
            case 4:
                printf("\nVisualizing Temperature History:\n");
                for (int i = 0; i < monitor.count; i++) {
                    printf("%.2f: ", monitor.temperatures[i]);
                    for (int j = 0; j < (int)(monitor.temperatures[i] + 10); j++) {
                        printf("*");
                    }
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting Temperature Monitor...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}