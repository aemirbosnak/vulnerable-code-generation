//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#define MAX_SAMPLES 10000
#define SAMPLE_INTERVAL 1000 // in ms

struct sample {
    time_t timestamp;
    double temperature;
};

int main() {
    FILE *fp;
    struct sample samples[MAX_SAMPLES];
    int num_samples = 0;
    double avg_temperature = 0;
    double max_temperature = -273.15; // absolute zero in Celsius
    double min_temperature = 1000; // initialize to a high value
    time_t start_time = time(NULL);
    time_t end_time = start_time + (SAMPLE_INTERVAL / 1000); // in seconds

    if ((fp = fopen("temperature.log", "w")) == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (difftime(time(NULL), start_time) < SAMPLE_INTERVAL)
        ; // wait for the first sample interval to elapse

    while (difftime(time(NULL), end_time) >= 0) {
        double temperature = rand() % 101 - 50; // generate a random temperature between -50 and 50 degrees Celsius
        samples[num_samples].timestamp = time(NULL);
        samples[num_samples].temperature = temperature;
        num_samples++;

        if (num_samples == MAX_SAMPLES) {
            break;
        }

        fprintf(fp, "%ld,%.2f\n", samples[num_samples - 1].timestamp, samples[num_samples - 1].temperature);

        if (max_temperature < temperature) {
            max_temperature = temperature;
        }

        if (min_temperature > temperature) {
            min_temperature = temperature;
        }

        avg_temperature += temperature;
    }

    fclose(fp);

    printf("Average temperature: %.2f degrees Celsius\n", avg_temperature / num_samples);
    printf("Maximum temperature: %.2f degrees Celsius\n", max_temperature);
    printf("Minimum temperature: %.2f degrees Celsius\n", min_temperature);

    return 0;
}