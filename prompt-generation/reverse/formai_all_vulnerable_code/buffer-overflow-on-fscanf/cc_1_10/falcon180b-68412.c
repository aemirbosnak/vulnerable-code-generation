//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURES 100

struct temperature {
    time_t timestamp;
    float value;
};

int main() {
    FILE *data_file;
    struct temperature temperatures[MAX_TEMPERATURES];
    int num_temperatures = 0;
    float avg_temperature = 0;
    float min_temperature = 1000;
    float max_temperature = -1000;
    int min_index = -1;
    int max_index = -1;
    int i;

    // Open the data file
    data_file = fopen("temperatures.dat", "r");

    if (data_file == NULL) {
        printf("Error: Could not open data file.\n");
        exit(1);
    }

    // Read in the temperatures
    while (num_temperatures < MAX_TEMPERATURES && fscanf(data_file, "%ld %f\n", &temperatures[num_temperatures].timestamp, &temperatures[num_temperatures].value) == 2) {
        num_temperatures++;
    }

    // Close the data file
    fclose(data_file);

    // Sort the temperatures by timestamp
    for (i = 0; i < num_temperatures - 1; i++) {
        if (temperatures[i].timestamp > temperatures[i+1].timestamp) {
            struct temperature temp = temperatures[i];
            temperatures[i] = temperatures[i+1];
            temperatures[i+1] = temp;
        }
    }

    // Calculate the average temperature
    for (i = 0; i < num_temperatures; i++) {
        avg_temperature += temperatures[i].value;
    }
    avg_temperature /= num_temperatures;

    // Find the minimum and maximum temperatures
    for (i = 0; i < num_temperatures; i++) {
        if (temperatures[i].value < min_temperature) {
            min_temperature = temperatures[i].value;
            min_index = i;
        }
        if (temperatures[i].value > max_temperature) {
            max_temperature = temperatures[i].value;
            max_index = i;
        }
    }

    // Print the results
    printf("Average temperature: %.2f\n", avg_temperature);
    printf("Minimum temperature: %.2f at %s", min_temperature, ctime(&temperatures[min_index].timestamp));
    printf("Maximum temperature: %.2f at %s\n", max_temperature, ctime(&temperatures[max_index].timestamp));

    return 0;
}