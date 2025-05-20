//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_SAMPLES 100
#define SAMPLE_INTERVAL 1

typedef struct {
    double temperature;
    time_t timestamp;
} TemperatureReading;

void read_temperature(TemperatureReading* reading) {
    FILE* fp = fopen("/dev/cpu_temperature", "r");
    if (fp == NULL) {
        perror("Error: Could not open temperature file");
        exit(1);
    }

    if (fscanf(fp, "%lf", &reading->temperature)!= 1) {
        fprintf(stderr, "Error: Invalid temperature value\n");
        exit(1);
    }

    time_t now = time(NULL);
    reading->timestamp = now;

    fclose(fp);
}

void print_temperature_history(TemperatureReading* readings, int num_readings) {
    printf("Temperature History:\n");
    for (int i = 0; i < num_readings; i++) {
        TemperatureReading reading = readings[i];
        time_t seconds_since_epoch = difftime(time(NULL), reading.timestamp);

        struct tm* tm = localtime(&seconds_since_epoch);
        char timestamp_str[32];
        strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", tm);

        printf("%s: %.2lf C\n", timestamp_str, reading.temperature);
    }
}

int main() {
    TemperatureReading readings[NUM_SAMPLES];
    int num_readings = 0;

    while (num_readings < NUM_SAMPLES) {
        TemperatureReading reading;
        read_temperature(&reading);

        if (num_readings == 0) {
            printf("Initial temperature: %.2lf C\n", reading.temperature);
        }

        readings[num_readings] = reading;
        num_readings++;

        sleep(SAMPLE_INTERVAL);
    }

    print_temperature_history(readings, num_readings);

    return 0;
}