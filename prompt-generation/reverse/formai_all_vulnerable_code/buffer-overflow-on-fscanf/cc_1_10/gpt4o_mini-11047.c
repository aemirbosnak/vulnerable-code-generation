//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void read_temperature_data(const char *filename, double *temperatures, int *count);
void display_temperatures(const double *temperatures, int count);
double calculate_average(const double *temperatures, int count);
double find_minimum(const double *temperatures, int count);
double find_maximum(const double *temperatures, int count);

int main(void) {
    // Declare variables
    const char *filename = "temperatures.txt"; // File with temperature data
    double temperatures[100]; // Array to hold temperature values
    int count = 0; // Number of temperatures read

    // Read temperature data
    read_temperature_data(filename, temperatures, &count);

    // Display the read temperatures
    printf("Read %d temperature values:\n", count);
    display_temperatures(temperatures, count);

    // Calculate and display statistics
    double average = calculate_average(temperatures, count);
    double minimum = find_minimum(temperatures, count);
    double maximum = find_maximum(temperatures, count);

    // Print statistics
    printf("Average Temperature: %.2f\n", average);
    printf("Minimum Temperature: %.2f\n", minimum);
    printf("Maximum Temperature: %.2f\n", maximum);

    return 0; // Indicate successful termination
}

// Function to read temperature data from a file
void read_temperature_data(const char *filename, double *temperatures, int *count) {
    FILE *file = fopen(filename, "r"); // Open the file for reading
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE); // Exit if file can't be opened
    }

    while (fscanf(file, "%lf", &temperatures[*count]) == 1) {
        (*count)++;
        if (*count >= 100) break; // Prevent overflow
    }

    fclose(file); // Close the file
}

// Function to display temperatures
void display_temperatures(const double *temperatures, int count) {
    for (int i = 0; i < count; i++) {
        printf("Temperature[%d]: %.2f\n", i, temperatures[i]);
    }
}

// Function to calculate the average temperature
double calculate_average(const double *temperatures, int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += temperatures[i]; // Summing up all temperature values
    }
    return sum / count; // Return average
}

// Function to find the minimum temperature
double find_minimum(const double *temperatures, int count) {
    double min = temperatures[0]; // Start with the first temperature
    for (int i = 1; i < count; i++) {
        if (temperatures[i] < min) {
            min = temperatures[i]; // Update minimum temperature
        }
    }
    return min; // Return minimum temperature
}

// Function to find the maximum temperature
double find_maximum(const double *temperatures, int count) {
    double max = temperatures[0]; // Start with the first temperature
    for (int i = 1; i < count; i++) {
        if (temperatures[i] > max) {
            max = temperatures[i]; // Update maximum temperature
        }
    }
    return max; // Return maximum temperature
}