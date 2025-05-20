//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a temperature structure
typedef struct {
    float temperature; // Temperature in Celsius
    time_t timestamp;  // Timestamp of the reading
} TemperatureReading;

// Function to generate a random temperature
float generateRandomTemperature(float min, float max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

// Function to log the temperature readings
void logTemperatureReadings(TemperatureReading *readings, int count) {
    printf("Timestamp                     | Temperature (°C)\n");
    printf("------------------------------------------------------\n");
    for(int i = 0; i < count; i++) {
        struct tm *tm_info = localtime(&readings[i].timestamp);
        char buffer[26];
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%s | %.2f\n", buffer, readings[i].temperature);
    }
}

// Function to monitor temperature over a period
void monitorTemperature(int duration, int interval, int count) {
    TemperatureReading *readings = malloc(count * sizeof(TemperatureReading));
    
    for(int i = 0; i < count; i++) {
        readings[i].temperature = generateRandomTemperature(-10.0f, 40.0f); // Random temperatures between -10 and 40 °C
        readings[i].timestamp = time(NULL);
        sleep(interval); // Wait for the interval to pass
    }

    logTemperatureReadings(readings, count);
    free(readings);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int duration;  // Duration for the monitoring session
    int interval;  // Time between temperature readings
    int count;     // Total observations to take

    printf("Enter the total duration for monitoring (in seconds): ");
    scanf("%d", &duration);
    
    printf("Enter the interval between readings (in seconds): ");
    scanf("%d", &interval);

    // Calculate how many readings to take
    count = duration / interval;

    // Ensure count is at least 1
    if (count < 1) {
        printf("Interval must be less than or equal to duration.\n");
        return 1;
    }

    printf("Starting temperature monitoring...\n");
    monitorTemperature(duration, interval, count);
    printf("Monitoring completed.\n");
    
    return 0;
}