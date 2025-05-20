//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SAMPLES 1000
#define MIN_TEMP -273.15
#define MAX_TEMP 1000.0

struct sample {
    double temperature;
    time_t timestamp;
};

int main() {
    FILE *fp;
    struct sample samples[MAX_SAMPLES];
    int num_samples = 0;
    double avg_temp = 0.0;
    double min_temp = MAX_TEMP;
    double max_temp = MIN_TEMP;
    time_t start_time = time(NULL);

    // Open the temperature sensor and initialize it
    fp = fopen("/dev/ttyS0", "r+");
    if (fp == NULL) {
        printf("Error opening temperature sensor\n");
        exit(1);
    }

    // Read temperature samples
    while (num_samples < MAX_SAMPLES) {
        struct sample sample;
        char buff[10];
        int n = fread(buff, sizeof(char), 10, fp);
        if (n!= 10) {
            printf("Error reading temperature sample\n");
            exit(1);
        }
        sample.temperature = atof(buff);
        if (sample.temperature < MIN_TEMP || sample.temperature > MAX_TEMP) {
            printf("Invalid temperature sample: %.2f\n", sample.temperature);
            continue;
        }
        sample.timestamp = time(NULL);
        samples[num_samples++] = sample;
    }

    // Calculate average, minimum, and maximum temperature
    for (int i = 0; i < num_samples; i++) {
        avg_temp += samples[i].temperature;
        if (samples[i].temperature < min_temp) {
            min_temp = samples[i].temperature;
        }
        if (samples[i].temperature > max_temp) {
            max_temp = samples[i].temperature;
        }
    }
    avg_temp /= num_samples;

    // Print temperature statistics
    printf("Temperature statistics:\n");
    printf("  Samples: %d\n", num_samples);
    printf("  Average: %.2f C\n", avg_temp);
    printf("  Minimum: %.2f C at %s\n", min_temp, ctime(&samples[0].timestamp));
    printf("  Maximum: %.2f C at %s\n", max_temp, ctime(&samples[num_samples - 1].timestamp));

    // Close the temperature sensor
    fclose(fp);

    return 0;
}