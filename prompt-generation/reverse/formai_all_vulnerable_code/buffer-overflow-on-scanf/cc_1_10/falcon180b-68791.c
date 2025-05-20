//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SENSORS 10
#define MAX_SAMPLES 1000
#define SAMPLE_INTERVAL 1000 // 1 second

struct sensor {
    char name[20];
    double temperature;
};

void read_sensor_data(struct sensor *sensors, int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        sensors[i].temperature = rand() % 100; // Simulate random temperature readings
    }
}

void print_sensor_data(struct sensor *sensors, int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        printf("%s: %.2f\n", sensors[i].name, sensors[i].temperature);
    }
}

int main() {
    srand(time(NULL));

    struct sensor sensors[MAX_SENSORS];
    int num_sensors = 0;

    while (num_sensors < MAX_SENSORS) {
        printf("Enter sensor name (or press enter to finish): ");
        scanf("%s", sensors[num_sensors].name);

        if (sensors[num_sensors].name[0] == '\0') {
            break;
        }

        num_sensors++;
    }

    while (1) {
        read_sensor_data(sensors, num_sensors);
        print_sensor_data(sensors, num_sensors);

        for (int i = 0; i < num_sensors; i++) {
            if (sensors[i].temperature > 90) {
                printf("WARNING: %s is overheating!\n", sensors[i].name);
            }
        }

        sleep(SAMPLE_INTERVAL);
    }

    return 0;
}