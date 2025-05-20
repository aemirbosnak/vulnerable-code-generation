//Code Llama-13B DATASET v1.0 Category: Smart home automation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_SENSORS 10
#define NUM_ACTUATORS 5

typedef struct {
    float value;
    float min;
    float max;
    float threshold;
} Sensor;

typedef struct {
    int state;
    float value;
} Actuator;

void read_sensors(Sensor *sensors) {
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensors[i].value = (float)rand() / RAND_MAX;
    }
}

void read_actuators(Actuator *actuators) {
    for (int i = 0; i < NUM_ACTUATORS; i++) {
        actuators[i].value = (float)rand() / RAND_MAX;
    }
}

void control_system(Sensor *sensors, Actuator *actuators) {
    for (int i = 0; i < NUM_SENSORS; i++) {
        if (sensors[i].value > sensors[i].threshold) {
            actuators[i].state = 1;
        } else {
            actuators[i].state = 0;
        }
    }
}

void print_sensors(Sensor *sensors) {
    for (int i = 0; i < NUM_SENSORS; i++) {
        printf("Sensor %d: %f\n", i, sensors[i].value);
    }
}

void print_actuators(Actuator *actuators) {
    for (int i = 0; i < NUM_ACTUATORS; i++) {
        printf("Actuator %d: %f\n", i, actuators[i].value);
    }
}

int main() {
    Sensor sensors[NUM_SENSORS];
    Actuator actuators[NUM_ACTUATORS];

    read_sensors(sensors);
    read_actuators(actuators);
    control_system(sensors, actuators);
    print_sensors(sensors);
    print_actuators(actuators);

    return 0;
}