//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>

// Define the limits for the temperature readings
#define MIN_TEMP 0.0
#define MAX_TEMP 100.0
#define STEP 1.0

// Define the length of the temperature history buffer
#define HISTORY_SIZE 10

// Define the shape of the temperature monitor
#define SHAPE "*****"

// Initialize the temperature history buffer
float history[HISTORY_SIZE];
int history_index = 0;

// Get the current temperature reading
float get_temperature() {
    FILE *fp;
    char buf[100];
    float temp;

    // Open the temperature sensor file
    fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (fp == NULL) {
        perror("Error opening temperature sensor file");
        exit(1);
    }

    // Read the temperature from the file
    fgets(buf, sizeof(buf), fp);
    fclose(fp);

    // Convert the temperature to a float
    temp = atof(buf) / 1000.0;

    return temp;
}

// Update the temperature history buffer
void update_history(float temp) {
    // Add the new temperature to the buffer
    history[history_index] = temp;

    // Increment the history index
    history_index = (history_index + 1) % HISTORY_SIZE;
}

// Get the average temperature from the history buffer
float get_average_temp() {
    float avg_temp = 0.0;

    // Calculate the average temperature
    for (int i = 0; i < HISTORY_SIZE; i++) {
        avg_temp += history[i];
    }
    avg_temp /= HISTORY_SIZE;

    return avg_temp;
}

// Print the temperature monitor
void print_monitor() {
    float temp;
    float avg_temp;

    // Get the current temperature
    temp = get_temperature();

    // Update the temperature history buffer
    update_history(temp);

    // Get the average temperature
    avg_temp = get_average_temp();

    // Print the shape of the temperature monitor
    printf("%s\n", SHAPE);

    // Print the current temperature
    printf("Current temperature: %.1f°C\n", temp);

    // Print the average temperature
    printf("Average temperature: %.1f°C\n", avg_temp);

    // Print the shape of the temperature monitor
    printf("%s\n", SHAPE);
}

// Main function
int main() {
    // Print the temperature monitor
    print_monitor();

    // Loop forever, updating the temperature monitor every second
    while (1) {
        sleep(1);
        print_monitor();
    }

    return 0;
}