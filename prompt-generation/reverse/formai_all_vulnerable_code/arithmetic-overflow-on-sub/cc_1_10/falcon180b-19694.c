//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main() {
    // Initialize variables
    int num_readings = 0;
    int max_readings = 10;
    double temperatures[max_readings];
    double average_temp = 0.0;
    double max_temp = -1000.0;
    double min_temp = 1000.0;
    time_t start_time = time(NULL);
    char input_buffer[50];

    // Prompt user for input
    printf("Enter temperature readings (type 'done' when finished):\n");

    // Read in temperature values
    while (num_readings < max_readings) {
        fgets(input_buffer, sizeof(input_buffer), stdin);
        if (strcmp(input_buffer, "done") == 0) {
            break;
        }
        temperatures[num_readings] = atof(input_buffer);
        num_readings++;
    }

    // Calculate average temperature
    for (int i = 0; i < num_readings; i++) {
        average_temp += temperatures[i];
    }
    average_temp /= num_readings;

    // Find maximum and minimum temperatures
    for (int i = 0; i < num_readings; i++) {
        if (temperatures[i] > max_temp) {
            max_temp = temperatures[i];
        }
        if (temperatures[i] < min_temp) {
            min_temp = temperatures[i];
        }
    }

    // Print results
    printf("Average temperature: %.2f\n", average_temp);
    printf("Maximum temperature: %.2f\n", max_temp);
    printf("Minimum temperature: %.2f\n", min_temp);
    printf("Elapsed time: %ld seconds\n", time(NULL) - start_time);

    return 0;
}