//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TEMP_FILE "temperature_readings.txt"
#define MAX_TEMP 75
#define MIN_TEMP 10

void log_temperature(float temperature) {
    FILE *log_file = fopen("temperature_log.txt", "a");
    if (log_file == NULL) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }
    time_t now = time(NULL);
    fprintf(log_file, "Temperature: %.2f°C at %s", temperature, ctime(&now));
    fclose(log_file);
}

float read_temperature() {
    FILE *temp_file = fopen(TEMP_FILE, "r");
    if (temp_file == NULL) {
        perror("Could not open temperature file");
        exit(EXIT_FAILURE);
    }

    float temperature;
    if (fscanf(temp_file, "%f", &temperature) != 1) {
        perror("Failed to read temperature");
        fclose(temp_file);
        exit(EXIT_FAILURE);
    }
    fclose(temp_file);
    return temperature;
}

void check_temperature(float temperature) {
    if (temperature > MAX_TEMP) {
        printf("Warning: Temperature too high! (%.2f°C)\n", temperature);
        log_temperature(temperature);
    } else if (temperature < MIN_TEMP) {
        printf("Warning: Temperature too low! (%.2f°C)\n", temperature);
        log_temperature(temperature);
    } else {
        printf("Temperature is normal: %.2f°C\n", temperature);
    }
}

void generate_temperature_file() {
    FILE *temp_file = fopen(TEMP_FILE, "w");
    if (temp_file == NULL) {
        perror("Could not create temperature file");
        exit(EXIT_FAILURE);
    }

    // Generate a random temperature between 5°C and 85°C
    float temperature = (rand() % 81) + 5; // Result will be between 5 and 85
    fprintf(temp_file, "%.2f\n", temperature);
    fclose(temp_file);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    while (1) {
        printf("Generating new temperature reading...\n");
        generate_temperature_file(); // Simulating new temperature reading
        float temperature = read_temperature(); // Read the temperature
        check_temperature(temperature); // Check and log as necessary
        sleep(5); // Wait for 5 seconds before generating next reading
    }

    return 0;
}