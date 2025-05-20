//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define NUM_TEMP_SENSORS 3
#define MAX_SAMPLES 10
#define SAMPLE_INTERVAL 1 // In seconds

typedef struct {
    char name[64];
    double temp;
    time_t last_sample_time;
} TempSensor;

TempSensor temp_sensors[NUM_TEMP_SENSORS] = {{"CPU Temp", 0, 0}, {"GPU Temp", 0, 0}, {"Ambient Temp", 0, 0}};

void init_temp_sensors() {
    for (int i = 0; i < NUM_TEMP_SENSORS; i++) {
        temp_sensors[i].last_sample_time = 0;
    }
}

void sample_temp_sensors() {
    time_t current_time = time(NULL);

    for (int i = 0; i < NUM_TEMP_SENSORS; i++) {
        if (temp_sensors[i].last_sample_time + SAMPLE_INTERVAL < current_time) {
            temp_sensors[i].temp = rand() % 100; // Simulate temperature reading
            temp_sensors[i].last_sample_time = current_time;
        }
    }
}

void print_temp_sensors() {
    printf("Temperature Sensors:\n");
    for (int i = 0; i < NUM_TEMP_SENSORS; i++) {
        printf("%s: %.2f°C\n", temp_sensors[i].name, temp_sensors[i].temp);
    }
}

int main() {
    init_temp_sensors();

    while (1) {
        sample_temp_sensors();
        print_temp_sensors();
        sleep(SAMPLE_INTERVAL);
    }

    return 0;
}