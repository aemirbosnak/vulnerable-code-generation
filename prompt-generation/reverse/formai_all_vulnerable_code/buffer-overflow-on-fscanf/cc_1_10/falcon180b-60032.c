//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP_SENSORS 10
#define THERM_DEVICE_PATH "/sys/class/thermal/thermal_zone0/temp"

typedef struct {
    char name[20];
    int id;
} temp_sensor_t;

int num_sensors = 0;
temp_sensor_t sensors[MAX_TEMP_SENSORS];

void add_sensor(char* name, int id) {
    if (num_sensors >= MAX_TEMP_SENSORS) {
        printf("Error: Maximum number of sensors reached.\n");
        return;
    }

    strcpy(sensors[num_sensors].name, name);
    sensors[num_sensors].id = id;
    num_sensors++;
}

void remove_sensor(int id) {
    int i;

    for (i = 0; i < num_sensors; i++) {
        if (sensors[i].id == id) {
            memmove(&sensors[i], &sensors[i+1], sizeof(temp_sensor_t) * (num_sensors - i - 1));
            num_sensors--;
            break;
        }
    }
}

void print_sensors() {
    int i;

    for (i = 0; i < num_sensors; i++) {
        printf("%s (%d)\n", sensors[i].name, sensors[i].id);
    }
}

int get_temp(int id) {
    char path[50];
    FILE* file;
    int temp;

    sprintf(path, "/sys/class/thermal/thermal_zone%d/temp", id);

    file = fopen(path, "r");

    if (file == NULL) {
        printf("Error: Invalid sensor ID.\n");
        return -1;
    }

    fscanf(file, "%d", &temp);

    fclose(file);

    return temp;
}

void monitor_temps() {
    int i;

    for (i = 0; i < num_sensors; i++) {
        int temp = get_temp(sensors[i].id);

        if (temp == -1) {
            continue;
        }

        printf("%s: %d°C\n", sensors[i].name, temp);
    }
}

int main() {
    add_sensor("CPU", 0);
    add_sensor("GPU", 1);

    while (1) {
        monitor_temps();
        sleep(5);
    }

    return 0;
}