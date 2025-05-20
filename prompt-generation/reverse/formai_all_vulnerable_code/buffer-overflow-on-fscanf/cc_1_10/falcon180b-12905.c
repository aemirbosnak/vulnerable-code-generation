//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP_SAMPLES 100

struct temp_sample {
    int temp;
    time_t timestamp;
};

int main() {
    int i, num_samples = 0;
    struct temp_sample samples[MAX_TEMP_SAMPLES];
    FILE *fp;

    // Initialize samples array with zeros
    for (i = 0; i < MAX_TEMP_SAMPLES; i++) {
        samples[i].temp = 0;
        samples[i].timestamp = 0;
    }

    // Open input file
    fp = fopen("temp_data.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    // Read temperature samples from input file
    while (fscanf(fp, "%d %ld", &samples[num_samples].temp, &samples[num_samples].timestamp) == 2) {
        num_samples++;
        if (num_samples >= MAX_TEMP_SAMPLES) {
            printf("Error: reached maximum number of samples\n");
            exit(1);
        }
    }

    // Close input file
    fclose(fp);

    // Calculate average temperature over all samples
    int total_temp = 0;
    for (i = 0; i < num_samples; i++) {
        total_temp += samples[i].temp;
    }
    float avg_temp = (float) total_temp / num_samples;

    // Print results
    printf("Average temperature: %.2f\n", avg_temp);

    return 0;
}