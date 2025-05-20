//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SAMPLES 100
#define SAMPLE_RATE 1.0

struct sample {
    time_t timestamp;
    double temperature;
};

int main() {
    FILE *fp;
    struct sample samples[MAX_SAMPLES];
    int num_samples = 0;
    double avg_temp = 0.0;
    double max_temp = -9999.0;
    double min_temp = 9999.0;

    if ((fp = fopen("temperature_data.txt", "r")) == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%ld %lf\n", &samples[num_samples].timestamp, &samples[num_samples].temperature)!= EOF) {
        num_samples++;
        if (num_samples >= MAX_SAMPLES) {
            break;
        }
    }

    fclose(fp);

    printf("Number of samples: %d\n", num_samples);

    for (int i = 0; i < num_samples; i++) {
        avg_temp += samples[i].temperature;
        if (samples[i].temperature > max_temp) {
            max_temp = samples[i].temperature;
        }
        if (samples[i].temperature < min_temp) {
            min_temp = samples[i].temperature;
        }
    }

    avg_temp /= num_samples;

    printf("Average temperature: %.2lf\n", avg_temp);
    printf("Maximum temperature: %.2lf\n", max_temp);
    printf("Minimum temperature: %.2lf\n", min_temp);

    return 0;
}