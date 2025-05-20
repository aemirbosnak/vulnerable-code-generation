//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMP_SAMPLES 1000
#define TEMP_SAMPLE_INTERVAL 500000 // 500ms

typedef struct {
    double temp;
    time_t timestamp;
} TempSample;

int main() {
    int i;
    TempSample tempSamples[MAX_TEMP_SAMPLES];
    double avgTemp = 0.0;
    double minTemp = 1000.0;
    double maxTemp = -1000.0;
    double tempRange = 0.0;
    time_t startTime;
    time_t endTime;
    double totalTime = 0.0;

    // Initialize random seed
    srand(time(NULL));

    // Get current time
    time(&startTime);

    // Loop and take temperature samples
    for (i = 0; i < MAX_TEMP_SAMPLES; i++) {
        // Generate random temperature between 20 and 30 degrees Celsius
        tempSamples[i].temp = 20.0 + (double)rand() / RAND_MAX * 10.0;

        // Set timestamp for this sample
        tempSamples[i].timestamp = startTime + i * TEMP_SAMPLE_INTERVAL;

        // Update min/max temperature
        if (tempSamples[i].temp < minTemp) {
            minTemp = tempSamples[i].temp;
        }

        if (tempSamples[i].temp > maxTemp) {
            maxTemp = tempSamples[i].temp;
        }
    }

    // Loop through samples and calculate average temperature
    for (i = 0; i < MAX_TEMP_SAMPLES; i++) {
        avgTemp += tempSamples[i].temp;
    }

    avgTemp /= MAX_TEMP_SAMPLES;

    // Calculate temperature range
    tempRange = maxTemp - minTemp;

    // Calculate total time
    time(&endTime);
    totalTime = difftime(endTime, startTime);

    // Print results
    printf("Average temperature: %.2f degrees Celsius\n", avgTemp);
    printf("Minimum temperature: %.2f degrees Celsius\n", minTemp);
    printf("Maximum temperature: %.2f degrees Celsius\n", maxTemp);
    printf("Temperature range: %.2f degrees Celsius\n", tempRange);
    printf("Total time: %.2f seconds\n", totalTime);

    return 0;
}