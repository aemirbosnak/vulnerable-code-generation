//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SENSORS 5
#define TEMP_THRESHOLD 75.0 // Temperature threshold in Fahrenheit
#define LOG_FILE "temperature_log.txt"

void log_temperature(int sensor_id, float temperature) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }
    fprintf(file, "Sensor %d: %.2f°F\n", sensor_id, temperature);
    fclose(file);
}

float read_temperature(int sensor_id) {
    // Simulated temperature reading logic
    return (sensor_id * 10) + (float)(rand() % 30); // Random data for simulation
}

void check_temperature(float temperature, int sensor_id) {
    if (temperature > TEMP_THRESHOLD) {
        printf("Warning: Sensor %d exceeded threshold! Temperature: %.2f°F\n", sensor_id, temperature);
        log_temperature(sensor_id, temperature);
    } else {
        printf("Sensor %d is within the normal range. Temperature: %.2f°F\n", sensor_id, temperature);
    }
}

void display_timed_temperature(int interval_seconds) {
    int sensor_id;
    float temperature;

    for (sensor_id = 1; sensor_id <= MAX_SENSORS; sensor_id++) {
        temperature = read_temperature(sensor_id);
        check_temperature(temperature, sensor_id);
    }
}

void log_time() {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Error opening log file for time logging");
        return;
    }
    
    time_t now = time(NULL);
    fprintf(file, "Log Time: %s", ctime(&now));
    fclose(file);
}

void run_temperature_monitor(int interval_seconds) {
    while (1) {
        log_time();
        display_timed_temperature(interval_seconds);
        printf("Waiting for %d seconds before next check...\n", interval_seconds);
        sleep(interval_seconds);
    }
}

int main() {
    int interval_seconds;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Enter the interval between readings (in seconds): ");
    scanf("%d", &interval_seconds);

    if (interval_seconds <= 0) {
        fprintf(stderr, "Please use a positive interval.\n");
        return EXIT_FAILURE;
    }

    run_temperature_monitor(interval_seconds);

    return EXIT_SUCCESS;
}