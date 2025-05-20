//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_TEMP_SENSORS 4

// Function to read temperature from sensor
float read_temperature(int sensor_index) {
    float temperature;
    // Code to read temperature from sensor
    return temperature;
}

// Function to calculate average temperature
float calculate_average_temperature(float temperatures[], int num_sensors) {
    float sum = 0.0;
    for (int i = 0; i < num_sensors; i++) {
        sum += temperatures[i];
    }
    float average_temperature = sum / num_sensors;
    return average_temperature;
}

// Function to print temperature data
void print_temperature_data(float temperatures[], int num_sensors) {
    printf("Temperature data:\n");
    for (int i = 0; i < num_sensors; i++) {
        printf("Sensor %d: %.2f°C\n", i + 1, temperatures[i]);
    }
}

int main() {
    int num_sensors = 0;
    float temperatures[MAX_TEMP_SENSORS] = {0.0};

    // Code to detect and initialize temperature sensors
    for (int i = 0; i < MAX_TEMP_SENSORS; i++) {
        if (read_temperature(i)!= -1) {
            num_sensors++;
            temperatures[num_sensors - 1] = read_temperature(i);
        }
    }

    // Calculate and print average temperature
    float average_temperature = calculate_average_temperature(temperatures, num_sensors);
    printf("Average temperature: %.2f°C\n", average_temperature);

    // Print temperature data
    print_temperature_data(temperatures, num_sensors);

    return 0;
}