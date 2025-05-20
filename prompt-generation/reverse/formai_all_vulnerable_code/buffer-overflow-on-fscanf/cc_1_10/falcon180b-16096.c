//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Initialize variables
    char city[50];
    int temperature;
    int highest_temperature = -999;
    int lowest_temperature = 999;
    int average_temperature = 0;
    int count = 0;

    // Loop until user decides to quit
    while(1) {

        // Prompt user for city name
        printf("Enter city name (or type 'quit' to exit): ");
        scanf("%s", city);

        // Convert city name to uppercase
        for(int i = 0; i < strlen(city); i++) {
            city[i] = toupper(city[i]);
        }

        // Check if user wants to quit
        if(strcmp(city, "QUIT") == 0) {
            break;
        }

        // Open weather data file for city
        FILE *weather_data_file = fopen(city, "r");

        // Check if file exists
        if(weather_data_file == NULL) {
            printf("Weather data not available for %s.\n", city);
            continue;
        }

        // Read temperature data from file
        while(fscanf(weather_data_file, "%d", &temperature)!= EOF) {

            // Update highest and lowest temperatures
            if(temperature > highest_temperature) {
                highest_temperature = temperature;
            }

            if(temperature < lowest_temperature) {
                lowest_temperature = temperature;
            }

            // Update average temperature
            average_temperature += temperature;
            count++;
        }

        // Close weather data file
        fclose(weather_data_file);

        // Calculate average temperature
        if(count > 0) {
            average_temperature /= count;
        }

        // Display temperature data for city
        printf("Temperature data for %s:\n", city);
        printf("Highest temperature: %d\n", highest_temperature);
        printf("Lowest temperature: %d\n", lowest_temperature);
        printf("Average temperature: %d\n\n", average_temperature);
    }

    return 0;
}