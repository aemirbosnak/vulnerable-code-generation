//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMP_SAMPLES 100
#define MIN_TEMP_SAMPLES 5

struct temperature_sample {
    time_t timestamp;
    double temperature;
};

int main() {
    int i, num_samples = 0;
    struct temperature_sample temp_samples[MAX_TEMP_SAMPLES];
    double avg_temp, min_temp, max_temp;
    FILE *temp_file;

    temp_file = fopen("temperature_log.txt", "r");

    if (temp_file == NULL) {
        printf("Temperature log file not found!\n");
        exit(1);
    }

    while (fscanf(temp_file, "%ld %lf\n", &temp_samples[num_samples].timestamp, &temp_samples[num_samples].temperature)!= EOF) {
        num_samples++;
        if (num_samples == MAX_TEMP_SAMPLES) {
            break;
        }
    }

    fclose(temp_file);

    if (num_samples < MIN_TEMP_SAMPLES) {
        printf("Not enough temperature samples!\n");
        exit(1);
    }

    avg_temp = 0;
    min_temp = temp_samples[0].temperature;
    max_temp = temp_samples[0].temperature;

    for (i = 0; i < num_samples; i++) {
        avg_temp += temp_samples[i].temperature;

        if (temp_samples[i].temperature < min_temp) {
            min_temp = temp_samples[i].temperature;
        }

        if (temp_samples[i].temperature > max_temp) {
            max_temp = temp_samples[i].temperature;
        }
    }

    avg_temp /= num_samples;

    printf("Average temperature: %.2lf\n", avg_temp);
    printf("Minimum temperature: %.2lf\n", min_temp);
    printf("Maximum temperature: %.2lf\n", max_temp);

    return 0;
}