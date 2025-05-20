//FormAI DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature = 0;
    int chance_of_rain = 0;
    int weather_forecast = 0;

    srand(time(NULL)); // Set random seed for weather simulation

    printf("Welcome to the weather simulation program!\n");

    while (1) { // Continue simulation until user exits
        printf("\nPlease enter the current temperature in Fahrenheit: ");
        scanf("%d", &temperature);

        printf("Please enter the chance of rain (0-100): ");
        scanf("%d", &chance_of_rain);

        weather_forecast = rand() % 3; // Generate random weather forecast

        printf("\nSimulating weather...\n\n");

        switch (weather_forecast) {
            case 0:
                printf("The current weather is: Sunny\n");
                if (temperature > 80) {
                    printf("It's a hot day! Stay hydrated.\n");
                } else if (temperature < 60) {
                    printf("It's a bit chilly. Don't forget your jacket!\n");
                }
                break;
            case 1:
                printf("The current weather is: Cloudy\n");
                if (temperature > 70) {
                    printf("It's warm, but not too hot. Perfect weather for outdoor activities.\n");
                } else if (temperature < 50) {
                    printf("It's getting a bit cold. Make sure to wear warm clothing.\n");
                }
                break;
            case 2:
                printf("The current weather is: Rainy\n");
                if (chance_of_rain > 50) {
                    printf("It's a high chance of rain today. Make sure to bring an umbrella.\n");
                } else {
                    printf("It might rain today, so be prepared.\n");
                }
                break;
            default:
                printf("Oops, something went wrong with the simulation.\n");
                break;
        }

        printf("\nDo you want to simulate the weather again? (y/n): ");
        char user_input;
        scanf(" %c", &user_input);
        if (user_input == 'n' || user_input == 'N') {
            break;
        }
    }

    printf("\nThanks for using the weather simulation program! Goodbye.\n");
    return 0;
}