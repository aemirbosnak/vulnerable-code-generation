//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float temperature;
    time_t timestamp;
} TemperatureReading;

// Create a new temperature reading
TemperatureReading* create_reading(float temperature) {
    TemperatureReading* reading = malloc(sizeof(TemperatureReading));
    reading->temperature = temperature;
    reading->timestamp = time(NULL);
    return reading;
}

// Free a temperature reading
void free_reading(TemperatureReading* reading) {
    free(reading);
}

// Store a temperature reading in a file
void store_reading(TemperatureReading* reading, char* filename) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%f,%ld\n", reading->temperature, reading->timestamp);
    fclose(file);
}

// Read temperature readings from a file
TemperatureReading** read_readings(char* filename, int* num_readings) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int max_readings = 100;
    TemperatureReading** readings = malloc(max_readings * sizeof(TemperatureReading*));
    int num_readings_read = 0;

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        float temperature;
        time_t timestamp;

        sscanf(line, "%f,%ld", &temperature, &timestamp);

        readings[num_readings_read] = create_reading(temperature);

        num_readings_read++;

        if (num_readings_read == max_readings) {
            max_readings *= 2;
            readings = realloc(readings, max_readings * sizeof(TemperatureReading*));
        }
    }

    fclose(file);

    *num_readings = num_readings_read;

    return readings;
}

// Free an array of temperature readings
void free_readings(TemperatureReading** readings, int num_readings) {
    for (int i = 0; i < num_readings; i++) {
        free_reading(readings[i]);
    }
    free(readings);
}

// Get the average temperature from an array of readings
float get_average_temperature(TemperatureReading** readings, int num_readings) {
    float total_temperature = 0;
    for (int i = 0; i < num_readings; i++) {
        total_temperature += readings[i]->temperature;
    }
    return total_temperature / num_readings;
}

// Get the maximum temperature from an array of readings
float get_max_temperature(TemperatureReading** readings, int num_readings) {
    float max_temperature = readings[0]->temperature;
    for (int i = 1; i < num_readings; i++) {
        if (readings[i]->temperature > max_temperature) {
            max_temperature = readings[i]->temperature;
        }
    }
    return max_temperature;
}

// Get the minimum temperature from an array of readings
float get_min_temperature(TemperatureReading** readings, int num_readings) {
    float min_temperature = readings[0]->temperature;
    for (int i = 1; i < num_readings; i++) {
        if (readings[i]->temperature < min_temperature) {
            min_temperature = readings[i]->temperature;
        }
    }
    return min_temperature;
}

// Print a summary of the temperature readings
void print_summary(TemperatureReading** readings, int num_readings) {
    printf("Average temperature: %.2f degrees Celsius\n", get_average_temperature(readings, num_readings));
    printf("Maximum temperature: %.2f degrees Celsius\n", get_max_temperature(readings, num_readings));
    printf("Minimum temperature: %.2f degrees Celsius\n", get_min_temperature(readings, num_readings));
}

int main() {
    // Create a new temperature reading
    TemperatureReading* reading = create_reading(25.0);

    // Store the temperature reading in a file
    store_reading(reading, "temperatures.txt");

    // Free the temperature reading
    free_reading(reading);

    // Read temperature readings from a file
    TemperatureReading** readings;
    int num_readings;
    readings = read_readings("temperatures.txt", &num_readings);

    // Print a summary of the temperature readings
    print_summary(readings, num_readings);

    // Free the temperature readings
    free_readings(readings, num_readings);

    return 0;
}