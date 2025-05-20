//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int i, j;
    double avg_temp = 0.0, max_temp = 0.0, min_temp = 0.0;
    double temp_array[100];
    char *temp_file = "temp_data.txt";
    FILE *fp;
    time_t current_time;
    struct tm *tm_struct;

    // Initialize temperature array with zeros
    for (i = 0; i < 100; i++) {
        temp_array[i] = 0.0;
    }

    // Open temperature data file for reading
    fp = fopen(temp_file, "r");
    if (fp == NULL) {
        printf("Error: Could not open temperature data file.\n");
        exit(1);
    }

    // Read temperature data from file
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%lf", &temp_array[i]);
    }

    // Calculate average temperature
    for (i = 0; i < 100; i++) {
        avg_temp += temp_array[i];
    }
    avg_temp = avg_temp / 100;

    // Calculate maximum temperature
    max_temp = temp_array[0];
    for (i = 1; i < 100; i++) {
        if (temp_array[i] > max_temp) {
            max_temp = temp_array[i];
        }
    }

    // Calculate minimum temperature
    min_temp = temp_array[0];
    for (i = 1; i < 100; i++) {
        if (temp_array[i] < min_temp) {
            min_temp = temp_array[i];
        }
    }

    // Close temperature data file
    fclose(fp);

    // Get current time
    time(&current_time);
    tm_struct = localtime(&current_time);

    // Print temperature data
    printf("Temperature data for %s\n", asctime(tm_struct));
    printf("Average temperature: %.2lf\n", avg_temp);
    printf("Maximum temperature: %.2lf\n", max_temp);
    printf("Minimum temperature: %.2lf\n", min_temp);

    return 0;
}