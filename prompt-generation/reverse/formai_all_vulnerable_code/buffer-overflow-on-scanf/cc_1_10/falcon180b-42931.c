//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for temperature data
typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureData;

// Function to log temperature data
void logTemperatureData(TemperatureData *data) {
    FILE *logFile = fopen("temperature.log", "a");
    if (logFile!= NULL) {
        fprintf(logFile, "%ld,%.2f\n", data->timestamp, data->temperature);
        fclose(logFile);
    } else {
        printf("Error: Unable to open log file.\n");
    }
}

// Function to get current temperature
float getTemperature() {
    return rand() % 101; // Simulate random temperature between 0 and 100 degrees
}

// Function to monitor temperature
void monitorTemperature(int interval, int duration) {
    srand(time(NULL)); // Seed random number generator with current time
    TemperatureData data;
    data.timestamp = time(NULL);
    data.temperature = getTemperature();
    logTemperatureData(&data);

    while (duration > 0) {
        sleep(interval); // Pause for specified interval
        data.timestamp = time(NULL);
        data.temperature = getTemperature();
        logTemperatureData(&data);
        duration--;
    }
}

int main() {
    int interval, duration;

    // Prompt user for monitoring interval and duration
    printf("Enter monitoring interval (in seconds): ");
    scanf("%d", &interval);
    printf("Enter monitoring duration (in seconds): ");
    scanf("%d", &duration);

    // Convert seconds to medieval time units for display purposes
    float intervalHours = interval / 3600.0;
    float durationHours = duration / 3600.0;

    printf("Monitoring temperature every %dh %2.2fm for %dh %2.2fm...\n",
           intervalHours, (intervalHours > 1)? "ours" : "our",
           durationHours, (durationHours > 1)? "ours" : "our");

    // Monitor temperature
    monitorTemperature(interval, duration);

    return 0;
}