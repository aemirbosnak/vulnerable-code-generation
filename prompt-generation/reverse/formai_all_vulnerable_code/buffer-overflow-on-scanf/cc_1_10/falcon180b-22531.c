//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define NUM_SENSORS 3
#define SENSOR_NAME_LENGTH 20
#define MAX_DATA_POINTS 100

struct sensor_data {
    char name[SENSOR_NAME_LENGTH];
    float temperature;
    time_t timestamp;
};

void read_sensors(struct sensor_data sensors[]) {
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensors[i].temperature = rand() % 100;
        sensors[i].timestamp = time(NULL);
    }
}

void print_sensors(struct sensor_data sensors[]) {
    for (int i = 0; i < NUM_SENSORS; i++) {
        printf("Sensor %d: %.2f°C at %s\n", i + 1, sensors[i].temperature, ctime(&sensors[i].timestamp));
    }
}

void save_to_file(struct sensor_data sensors[]) {
    FILE *file = fopen("sensor_data.txt", "a");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    for (int i = 0; i < NUM_SENSORS; i++) {
        fprintf(file, "%.2f,%.2f,%s\n", sensors[i].temperature, sensors[i].timestamp, sensors[i].name);
    }

    fclose(file);
}

int main() {
    struct sensor_data sensors[NUM_SENSORS];

    for (int i = 0; i < NUM_SENSORS; i++) {
        printf("Enter sensor name (%d): ", i + 1);
        scanf("%s", sensors[i].name);
    }

    while (1) {
        read_sensors(sensors);
        print_sensors(sensors);
        save_to_file(sensors);

        sleep(5);
    }

    return 0;
}