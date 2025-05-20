//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEMP 1000
#define MIN_TEMP -1000
#define MAX_NUM_TEMPERATURES 100

typedef struct {
    int temperature;
    time_t timestamp;
} Temperature;

int main() {
    int num_temperatures = 0;
    Temperature temperatures[MAX_NUM_TEMPERATURES];
    char input[100];
    double average_temperature = 0.0;
    double variance = 0.0;
    double standard_deviation = 0.0;
    int max_temperature_index = 0;
    int min_temperature_index = 0;
    int max_temperature = MIN_TEMP;
    int min_temperature = MAX_TEMP;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please enter the number of temperatures you would like to record:\n");
    scanf("%d", &num_temperatures);

    for (int i = 0; i < num_temperatures; i++) {
        printf("Please enter temperature #%d:\n", i+1);
        scanf("%s", input);

        if (isdigit(input[0])) {
            // Convert input string to integer
            temperatures[i].temperature = atoi(input);

            // Update max and min temperatures
            if (temperatures[i].temperature > max_temperature) {
                max_temperature = temperatures[i].temperature;
                max_temperature_index = i;
            } else if (temperatures[i].temperature < min_temperature) {
                min_temperature = temperatures[i].temperature;
                min_temperature_index = i;
            }
        } else {
            // Invalid input
            printf("Invalid input.\n");
            exit(1);
        }

        // Get timestamp for this temperature
        time(&temperatures[i].timestamp);
    }

    // Calculate average temperature
    for (int i = 0; i < num_temperatures; i++) {
        average_temperature += temperatures[i].temperature;
    }
    average_temperature /= num_temperatures;

    // Calculate variance and standard deviation
    for (int i = 0; i < num_temperatures; i++) {
        variance += pow((temperatures[i].temperature - average_temperature), 2);
    }
    variance /= num_temperatures;
    standard_deviation = sqrt(variance);

    // Print results
    printf("Average temperature: %.2f\n", average_temperature);
    printf("Standard deviation: %.2f\n", standard_deviation);
    printf("Maximum temperature: %d at %s\n", max_temperature, ctime(&temperatures[max_temperature_index].timestamp));
    printf("Minimum temperature: %d at %s\n", min_temperature, ctime(&temperatures[min_temperature_index].timestamp));

    return 0;
}