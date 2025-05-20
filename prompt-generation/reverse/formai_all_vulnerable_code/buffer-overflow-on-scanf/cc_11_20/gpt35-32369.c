//FormAI DATASET v1.0 Category: Weather simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {

    // Welcome message
    printf("Welcome to Brave Weather Simulation!\n");

    // Get user input for number of days to simulate
    int daysToSimulate;
    printf("How many days would you like to simulate?\n");
    scanf("%d", &daysToSimulate);

    // Prompt user for confirmation
    printf("You have requested to simulate %d days of weather. Proceed? (Y/N)\n", daysToSimulate);

    char confirmation;
    scanf(" %c", &confirmation);

    // If user confirms, proceed
    if (confirmation == 'Y' || confirmation == 'y') {

        srand(time(NULL)); // Seed random number generator with current time

        // Initialize variables for weather conditions and forecasts
        int temperature, windSpeed, humidity;
        bool isRaining;
        char forecast[20];

        // Display table header
        printf("Day\tTemperature\tWind Speed\tHumidity\tForecast\n");

        // Loop through each simulated day
        for (int day = 1; day <= daysToSimulate; day++) {

            // Generate random weather conditions for each variable
            temperature = rand() % 41 - 20; // Temperatures from -20°C to +20°C
            windSpeed = rand() % 51; // Wind speeds from 0 m/s to 50 m/s
            humidity = rand() % 101; // Humidity from 0% to 100%
            isRaining = (rand() % 2 == 0); // 50% chance of rain

            // Determine forecast based on weather conditions
            if (isRaining) {
                if (temperature > 0) {
                    sprintf(forecast, "Rain and %d°C", temperature);
                } else if (temperature == 0) {
                    sprintf(forecast, "Rain and 0°C");
                } else {
                    sprintf(forecast, "Snow and %d°C", temperature);
                }
            } else {
                if (windSpeed > 40) {
                    sprintf(forecast, "Windy and %d°C", temperature);
                } else if (temperature > 30) {
                    sprintf(forecast, "Hot and %d°C", temperature);
                } else if (temperature > 20) {
                    sprintf(forecast, "Warm and %d°C", temperature);
                } else if (temperature > 10) {
                    sprintf(forecast, "Cool and %d°C", temperature);
                } else {
                    sprintf(forecast, "Cold and %d°C", temperature);
                }
            }

            // Display weather conditions and forecast for current day
            printf("%d\t%d°C\t\t%d m/s\t\t%d%%\t\t%s\n", day, temperature, windSpeed, humidity, forecast);
        }

        // End program
        printf("Simulation complete. Thank you for using Brave Weather Simulation!\n");

        return 0;

    } else {
        // If user cancels, end program
        printf("Simulation cancelled. Thank you for using Brave Weather Simulation!\n");

        return 0;
    }
}