//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMP_SAMPLES 1000

struct temperature_sample {
    time_t timestamp;
    double temperature;
};

int main() {
    int num_samples = 0;
    struct temperature_sample samples[MAX_TEMP_SAMPLES];
    FILE *file;
    char line[1024];
    double current_temp = 0.0;
    double max_temp = 0.0;
    double min_temp = 0.0;
    double avg_temp = 0.0;

    // Open the temperature log file
    file = fopen("temperature.log", "r");
    if (file == NULL) {
        printf("Error opening temperature log file.\n");
        exit(1);
    }

    // Read in the temperature samples
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (sscanf(line, "%ld %lf\n", &samples[num_samples].timestamp, &samples[num_samples].temperature)!= 2) {
            printf("Error parsing temperature sample: %s\n", line);
            exit(1);
        }
        num_samples++;
        if (num_samples >= MAX_TEMP_SAMPLES) {
            printf("Maximum number of temperature samples reached.\n");
            break;
        }
    }

    // Close the temperature log file
    fclose(file);

    // Calculate the maximum, minimum, and average temperature
    for (int i = 0; i < num_samples; i++) {
        current_temp = samples[i].temperature;
        if (current_temp > max_temp) {
            max_temp = current_temp;
        }
        if (current_temp < min_temp) {
            min_temp = current_temp;
        }
        avg_temp += current_temp;
    }
    avg_temp /= num_samples;

    // Print the temperature statistics
    printf("Maximum temperature: %.2lf\n", max_temp);
    printf("Minimum temperature: %.2lf\n", min_temp);
    printf("Average temperature: %.2lf\n", avg_temp);

    return 0;
}