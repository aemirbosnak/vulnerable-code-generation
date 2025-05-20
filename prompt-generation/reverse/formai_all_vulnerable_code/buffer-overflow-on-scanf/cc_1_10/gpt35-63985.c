//FormAI DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int current_temperature = 70;
    int target_temperature;
    int humidity;
    char weather_conditions[20];
    int simulation_time = 30;
    int time_elapsed = 0;

    srand(time(0));  // Seed random number generator

    printf("Welcome to the Weather Simulation Program!\n\n");
    printf("Please enter the desired target temperature (in degrees Fahrenheit): ");
    scanf("%d", &target_temperature);
    printf("Please enter the current humidity (as a percentage): ");
    scanf("%d", &humidity);
    printf("Please enter the current weather conditions (e.g. sunny, cloudy, rainy): ");
    scanf("%s", weather_conditions);

    printf("\nBeginning simulation...\n\n");

    while (time_elapsed < simulation_time) {
        printf("Time: %d minutes\n", time_elapsed);

        // Check if temperature needs to increase or decrease
        if (current_temperature < target_temperature) {
            current_temperature += rand() % 5 + 1;  // Increase temperature by 1-5 degrees Fahrenheit
        } else {
            current_temperature -= rand() % 5 + 1;  // Decrease temperature by 1-5 degrees Fahrenheit
        }

        // Print current weather conditions
        printf("Weather: %s\n", weather_conditions);

        // Print current humidity
        printf("Humidity: %d%%\n", humidity);

        // Print current temperature
        printf("Temperature: %dF\n", current_temperature);

        printf("\n");

        time_elapsed += 5;  // Increment time by 5 minutes
    }

    printf("Simulation complete.\n");

    return 0;
}