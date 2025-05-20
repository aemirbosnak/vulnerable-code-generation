//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

#define NUM_SAMPLES 10
#define SAMPLE_INTERVAL_SECONDS 1

double get_cpu_temperature() {
    FILE *file = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    double temperature;
    if (file!= NULL) {
        fscanf(file, "%lf", &temperature);
        fclose(file);
        temperature /= 1000; // Convert from millidegrees Celsius to degrees Celsius
        return temperature;
    } else {
        perror("Error reading temperature file");
        exit(EXIT_FAILURE);
    }
}

int main() {
    struct timespec start, end;
    double temperatures[NUM_SAMPLES];
    int i;

    if (clock_gettime(CLOCK_MONOTONIC, &start) == -1) {
        perror("Error getting start time");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < NUM_SAMPLES; i++) {
        double temperature = get_cpu_temperature();
        temperatures[i] = temperature;
        printf("Sample %d: Temperature = %.2f°C\n", i + 1, temperature);
        sleep(SAMPLE_INTERVAL_SECONDS);
    }

    if (clock_gettime(CLOCK_MONOTONIC, &end) == -1) {
        perror("Error getting end time");
        exit(EXIT_FAILURE);
    }

    double total_time_seconds = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    double average_temperature = 0;
    for (i = 0; i < NUM_SAMPLES; i++) {
        average_temperature += temperatures[i];
    }
    average_temperature /= NUM_SAMPLES;

    printf("Average temperature over %d samples: %.2f°C\n", NUM_SAMPLES, average_temperature);
    printf("Total time: %.2f seconds\n", total_time_seconds);

    return 0;
}