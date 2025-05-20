//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP_SAMPLES 100

struct TempSample {
    time_t timestamp;
    double temperature;
};

double get_current_temperature() {
    // Implement code to get current temperature
    return 25.0;
}

int main() {
    struct TempSample temp_samples[MAX_TEMP_SAMPLES];
    int num_samples = 0;
    double average_temperature = 0.0;
    double min_temperature = 100.0;
    double max_temperature = 0.0;

    srand(time(NULL));

    while (1) {
        double temp = get_current_temperature();
        temp_samples[num_samples].timestamp = time(NULL);
        temp_samples[num_samples].temperature = temp;
        num_samples++;

        if (num_samples >= MAX_TEMP_SAMPLES) {
            num_samples = 0;
        }

        average_temperature = 0.0;
        min_temperature = 100.0;
        max_temperature = 0.0;

        for (int i = 0; i < MAX_TEMP_SAMPLES; i++) {
            if (temp_samples[i].temperature < min_temperature) {
                min_temperature = temp_samples[i].temperature;
            }
            if (temp_samples[i].temperature > max_temperature) {
                max_temperature = temp_samples[i].temperature;
            }
            average_temperature += temp_samples[i].temperature;
        }

        average_temperature /= MAX_TEMP_SAMPLES;

        printf("Current temperature: %.2f\n", temp);
        printf("Average temperature: %.2f\n", average_temperature);
        printf("Minimum temperature: %.2f\n", min_temperature);
        printf("Maximum temperature: %.2f\n", max_temperature);

        sleep(1);
    }

    return 0;
}