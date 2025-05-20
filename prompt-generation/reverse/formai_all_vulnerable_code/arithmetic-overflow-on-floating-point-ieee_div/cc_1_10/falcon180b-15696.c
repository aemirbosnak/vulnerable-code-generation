//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_SAMPLES 100
#define SAMPLE_INTERVAL 1
#define MAX_TEMP_CHANGE_RATE 10
#define MIN_TEMP_CHANGE_RATE -10

struct sample {
    time_t timestamp;
    double temperature;
};

double calculate_temp_change_rate(double current_temp, double previous_temp, time_t current_time, time_t previous_time) {
    double temp_change = current_temp - previous_temp;
    double time_diff = difftime(current_time, previous_time);
    if (time_diff == 0) {
        return 0;
    }
    return temp_change / time_diff;
}

void print_sample(struct sample sample) {
    printf("Timestamp: %s\n", ctime(&sample.timestamp));
    printf("Temperature: %.2f\n", sample.temperature);
    printf("Temperature change rate: %.2f\n", calculate_temp_change_rate(sample.temperature, 0, sample.timestamp, 0));
}

int main() {
    int i;
    struct sample samples[MAX_SAMPLES];
    double previous_temp = 0;

    srand(time(NULL));

    for (i = 0; i < MAX_SAMPLES; i++) {
        samples[i].timestamp = time(NULL);
        samples[i].temperature = rand() % 101;
        if (i > 0) {
            double temp_change_rate = calculate_temp_change_rate(samples[i].temperature, previous_temp, samples[i].timestamp, samples[i-1].timestamp);
            if (temp_change_rate > MAX_TEMP_CHANGE_RATE || temp_change_rate < MIN_TEMP_CHANGE_RATE) {
                printf("Warning: Temperature change rate out of range (%.2f)\n", temp_change_rate);
            }
        }
        previous_temp = samples[i].temperature;
    }

    for (i = 0; i < MAX_SAMPLES; i++) {
        print_sample(samples[i]);
    }

    return 0;
}