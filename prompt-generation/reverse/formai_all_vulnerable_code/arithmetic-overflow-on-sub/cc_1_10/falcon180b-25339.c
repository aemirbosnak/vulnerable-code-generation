//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_TEMP_SAMPLES 1000

typedef struct {
    int temp;
    time_t timestamp;
} TempSample;

int main(int argc, char *argv[]) {
    int num_samples = 0;
    TempSample samples[MAX_TEMP_SAMPLES];
    time_t current_time;
    double avg_temp = 0;
    double max_temp = 0;
    double min_temp = 1000;

    printf("Starting temperature monitor...\n");

    while (num_samples < MAX_TEMP_SAMPLES) {
        current_time = time(NULL);
        if (current_time - samples[num_samples].timestamp > 60) {
            printf("Reading temperature...\n");
            samples[num_samples].temp = rand() % 101; // Simulate random temperature between 0 and 100 degrees Celsius
            samples[num_samples].timestamp = current_time;
            num_samples++;
        }
        sleep(1);
    }

    printf("Stopping temperature monitor...\n");

    for (int i = 0; i < num_samples; i++) {
        avg_temp += samples[i].temp;
        if (samples[i].temp > max_temp) {
            max_temp = samples[i].temp;
        }
        if (samples[i].temp < min_temp) {
            min_temp = samples[i].temp;
        }
    }

    avg_temp /= num_samples;

    printf("Average temperature: %.2f degrees Celsius\n", avg_temp);
    printf("Maximum temperature: %.2f degrees Celsius\n", max_temp);
    printf("Minimum temperature: %.2f degrees Celsius\n", min_temp);

    return 0;
}