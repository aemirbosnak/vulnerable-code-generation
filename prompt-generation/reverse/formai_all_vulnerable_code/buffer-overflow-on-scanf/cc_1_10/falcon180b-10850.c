//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SENSORS 10
#define MAX_SAMPLES 1000
#define SAMPLE_INTERVAL 1000 // in milliseconds

struct sensor {
    char name[20];
    double temperature;
    double last_temperature;
};

void init_sensor(struct sensor *s) {
    s->temperature = 0.0;
    s->last_temperature = 0.0;
}

void read_sensor(struct sensor *s) {
    printf("Enter temperature for sensor %s: ", s->name);
    scanf("%lf", &s->temperature);
}

void update_sensor_temperature(struct sensor *s) {
    s->last_temperature = s->temperature;
    s->temperature = rand() % 50 + 20; // simulate random temperature changes
}

void print_sensor_info(struct sensor *s) {
    printf("Sensor %s: Temperature: %.2lf\u00B0C, Change: %.2lf\u00B0C\n", s->name, s->temperature, s->temperature - s->last_temperature);
}

int main() {
    struct sensor sensors[MAX_SENSORS];
    int num_sensors = 0;
    bool running = true;

    srand(time(NULL));

    while (running) {
        printf("Enter number of sensors (1-10): ");
        scanf("%d", &num_sensors);

        if (num_sensors <= 0 || num_sensors > MAX_SENSORS) {
            printf("Invalid number of sensors.\n");
        } else {
            running = false;
        }
    }

    for (int i = 0; i < num_sensors; i++) {
        printf("Enter name for sensor %d: ", i + 1);
        scanf("%s", sensors[i].name);
        init_sensor(&sensors[i]);
    }

    for (int i = 0; i < num_sensors; i++) {
        read_sensor(&sensors[i]);
    }

    while (true) {
        for (int i = 0; i < num_sensors; i++) {
            update_sensor_temperature(&sensors[i]);
            print_sensor_info(&sensors[i]);
        }

        usleep(SAMPLE_INTERVAL * 1000); // sleep for sample interval in microseconds
    }

    return 0;
}