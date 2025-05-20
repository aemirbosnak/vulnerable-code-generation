//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define THRESHOLD 75.0  // Set the temperature threshold
#define MAX_SENSORS 5   // Maximum number of sensors
#define MONITOR_INTERVAL 2  // Interval between temperature checks (in seconds)

void check_temperature(float temperature) {
    printf("Checking temperature... ");

    if (temperature > THRESHOLD) {
        printf("WARNING: Temperature is too high! %.2f°F\n", temperature);
        printf("** Alert! ** Immediate action required!\n");
    } else {
        printf("Temperature is normal: %.2f°F\n", temperature);
    }
}

float simulate_sensor_reading(int sensor_id) {
    // Simulate a temperature reading
    srand(time(NULL) + sensor_id);  // Seed based on sensor ID
    return (float)(rand() % 100);  // Random temperature between 0 and 99
}

void display_temperature_readings(float temperatures[], int count) {
    printf("\n=== Current Temperature Readings ===\n");
    for (int i = 0; i < count; i++) {
        printf("Sensor %d: %.2f°F\n", i + 1, temperatures[i]);
    }
    printf("====================================\n");
}

int main() {
    float temperatures[MAX_SENSORS];

    printf("Temperature Monitoring System Initiated!\n");
    printf("Monitoring temperature from %d sensors...\n", MAX_SENSORS);

    while (1) {
        printf("\n--- New Monitoring Cycle ---\n");
        for (int i = 0; i < MAX_SENSORS; i++) {
            temperatures[i] = simulate_sensor_reading(i);
            check_temperature(temperatures[i]);
        }
        display_temperature_readings(temperatures, MAX_SENSORS);
        
        printf("Waiting for the next monitoring cycle...\n");
        sleep(MONITOR_INTERVAL);  // Wait before the next reading
    }

    return 0;  // End of program
}