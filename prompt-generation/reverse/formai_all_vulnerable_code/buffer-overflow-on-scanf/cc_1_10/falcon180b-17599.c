//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SENSORS 10
#define MAX_SAMPLES 100

typedef struct {
    char name[20];
    float temp;
} sensor_t;

void read_sensors(sensor_t sensors[], int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        sprintf(sensors[i].name, "Sensor %d", i + 1);
        sensors[i].temp = rand() % 100;
    }
}

void display_sensors(sensor_t sensors[], int num_sensors) {
    printf("Sensor Name\tTemperature\n");
    for (int i = 0; i < num_sensors; i++) {
        printf("%s\t\t%.2f\n", sensors[i].name, sensors[i].temp);
    }
}

void take_sample(sensor_t sensors[], int num_sensors, float samples[]) {
    for (int i = 0; i < num_sensors; i++) {
        samples[i] = sensors[i].temp;
    }
}

void calculate_average(float samples[], int num_samples) {
    float sum = 0.0;
    for (int i = 0; i < num_samples; i++) {
        sum += samples[i];
    }
    printf("Average Temperature: %.2f\n", sum / num_samples);
}

int main() {
    int num_sensors;
    printf("Enter the number of sensors: ");
    scanf("%d", &num_sensors);

    sensor_t sensors[MAX_SENSORS];
    read_sensors(sensors, num_sensors);
    display_sensors(sensors, num_sensors);

    int num_samples;
    printf("Enter the number of samples: ");
    scanf("%d", &num_samples);

    float samples[MAX_SAMPLES];
    for (int i = 0; i < num_samples; i++) {
        take_sample(sensors, num_sensors, samples);
        calculate_average(samples, num_sensors);
    }

    return 0;
}