//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP_SENSORS 10
#define TEMP_SENSOR_NAME_MAX_LEN 50
#define TEMP_SENSOR_DATA_MAX_LEN 100

typedef struct {
    char name[TEMP_SENSOR_NAME_MAX_LEN];
    double temp;
} temp_sensor_data_t;

typedef struct {
    temp_sensor_data_t temp_sensors[MAX_TEMP_SENSORS];
    int num_temp_sensors;
} temp_monitor_t;

temp_monitor_t *temp_monitor_init() {
    temp_monitor_t *monitor = (temp_monitor_t *)malloc(sizeof(temp_monitor_t));
    if (monitor == NULL) {
        printf("Error: Failed to allocate memory for temperature monitor.\n");
        exit(1);
    }
    monitor->num_temp_sensors = 0;
    return monitor;
}

void temp_monitor_add_sensor(temp_monitor_t *monitor, char *name, double temp) {
    if (monitor->num_temp_sensors >= MAX_TEMP_SENSORS) {
        printf("Error: Maximum number of temperature sensors reached.\n");
        return;
    }
    strcpy(monitor->temp_sensors[monitor->num_temp_sensors].name, name);
    monitor->temp_sensors[monitor->num_temp_sensors].temp = temp;
    monitor->num_temp_sensors++;
}

void temp_monitor_print(temp_monitor_t *monitor) {
    printf("Temperature Monitor:\n");
    printf("--------------------\n");
    for (int i = 0; i < monitor->num_temp_sensors; i++) {
        printf("%-50s %10.2f\n", monitor->temp_sensors[i].name, monitor->temp_sensors[i].temp);
    }
}

int main() {
    temp_monitor_t *monitor = temp_monitor_init();
    temp_monitor_add_sensor(monitor, "CPU", 60.5);
    temp_monitor_add_sensor(monitor, "GPU", 65.2);
    temp_monitor_add_sensor(monitor, "HDD", 45.7);
    temp_monitor_print(monitor);
    return 0;
}