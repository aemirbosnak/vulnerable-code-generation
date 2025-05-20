//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SAMPLES 1000
#define SAMPLE_INTERVAL 10
#define MIN_TEMP -20
#define MAX_TEMP 50

struct sample {
    time_t timestamp;
    double temperature;
};

int main() {
    struct sample samples[MAX_SAMPLES];
    int num_samples = 0;
    double avg_temp = 0;
    double min_temp = MAX_TEMP;
    double max_temp = MIN_TEMP;
    double temp_var = 0;
    double temp_std_dev = 0;
    char input[100];

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please enter the temperature in Celsius every %d seconds:\n", SAMPLE_INTERVAL);

    while (num_samples < MAX_SAMPLES) {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%lf", &samples[num_samples].temperature) == 1) {
            if (samples[num_samples].temperature >= MIN_TEMP && samples[num_samples].temperature <= MAX_TEMP) {
                samples[num_samples].timestamp = time(NULL);
                num_samples++;
            } else {
                printf("Invalid temperature value. Please enter a temperature between %d and %d degrees Celsius.\n", MIN_TEMP, MAX_TEMP);
            }
        } else {
            printf("Invalid input. Please enter the temperature in Celsius.\n");
        }
    }

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
    temp_var = 0;
    for (int i = 0; i < num_samples; i++) {
        temp_var += pow(samples[i].temperature - avg_temp, 2);
    }
    temp_std_dev = sqrt(temp_var / num_samples);

    printf("The average temperature is %.2lf degrees Celsius.\n", avg_temp);
    printf("The minimum temperature is %.2lf degrees Celsius.\n", min_temp);
    printf("The maximum temperature is %.2lf degrees Celsius.\n", max_temp);
    printf("The temperature standard deviation is %.2lf degrees Celsius.\n", temp_std_dev);

    return 0;
}