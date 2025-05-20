//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP_SENSORS 10
#define MAX_MEASUREMENTS 1000

typedef struct {
    int sensor_id;
    double temperature;
    time_t timestamp;
} TempMeasurement;

void add_measurement(TempMeasurement* measurements, int sensor_id, double temperature) {
    if (measurements->sensor_id == -1) {
        measurements->sensor_id = sensor_id;
        measurements->temperature = temperature;
        measurements->timestamp = time(NULL);
        printf("Sensor %d initialized with temperature %.2f\n", measurements->sensor_id, measurements->temperature);
    } else if (sensor_id == measurements->sensor_id) {
        if (measurements->timestamp + 5 < time(NULL)) {
            measurements->temperature = temperature;
            measurements->timestamp = time(NULL);
            printf("Sensor %d temperature updated to %.2f\n", measurements->sensor_id, measurements->temperature);
        }
    } else {
        printf("Invalid sensor ID\n");
    }
}

void print_measurements(TempMeasurement* measurements) {
    if (measurements->sensor_id!= -1) {
        printf("Sensor %d temperature: %.2f\n", measurements->sensor_id, measurements->temperature);
    }
}

void monitor_temperature(int num_sensors) {
    TempMeasurement measurements[MAX_TEMP_SENSORS];
    for (int i = 0; i < num_sensors; i++) {
        measurements[i].sensor_id = -1;
    }

    int choice;
    do {
        printf("Temperature Monitor\n");
        printf("1. Add sensor\n");
        printf("2. Print measurements\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter sensor ID: ");
                int sensor_id;
                scanf("%d", &sensor_id);
                add_measurement(measurements, sensor_id, 0.0);
                break;
            case 2:
                for (int i = 0; i < MAX_TEMP_SENSORS; i++) {
                    if (measurements[i].sensor_id!= -1) {
                        print_measurements(&measurements[i]);
                    }
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);
}

int main() {
    int num_sensors;
    printf("Enter number of sensors: ");
    scanf("%d", &num_sensors);
    monitor_temperature(num_sensors);
    return 0;
}