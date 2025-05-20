//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 7

typedef struct {
    char *description;
    int temperature; // in Celsius
    int precipitation; // in mm
} Weather;

Weather generateWeather() {
    Weather weather;

    // Different weather descriptions
    const char *descriptions[] = {
        "Sunny",
        "Partly Cloudy",
        "Cloudy",
        "Rainy",
        "Thunderstorms",
        "Snowy",
        "Foggy"
    };

    // Randomly select a weather description
    int descIndex = rand() % 7;
    weather.description = (char *)descriptions[descIndex];

    // Random temperature between -10 and 35
    weather.temperature = (rand() % 46) - 10;

    // Random precipitation between 0 and 20 mm, only for certain weather types
    if (descIndex == 3 || descIndex == 4 || descIndex == 5) { // Rainy, Thunderstorms, Snowy
        weather.precipitation = rand() % 21;
    } else {
        weather.precipitation = 0; // No rain for other conditions
    }

    return weather;
}

void printWeatherReport(Weather weather, int day) {
    printf("Day %d:\n", day + 1);
    printf("Description: %s\n", weather.description);
    printf("Temperature: %d°C\n", weather.temperature);
    if (weather.precipitation > 0) {
        printf("Precipitation: %d mm\n", weather.precipitation);
    } else {
        printf("Precipitation: None\n");
    }
    printf("\n");
}

int main() {
    srand(time(0)); // Seed random number generator

    printf("Welcome to Sunnydale Weather Simulator!\n");
    printf("Get the weather forecast for the week ahead.\n\n");

    int quit = 0;
    while (!quit) {
        Weather weekWeather[MAX_DAYS];

        // Generate weather for a week
        for (int i = 0; i < MAX_DAYS; ++i) {
            weekWeather[i] = generateWeather();
        }

        // Print the weather report
        printf("Weekly Weather Forecast:\n");
        printf("------------------------------\n");
        for (int i = 0; i < MAX_DAYS; ++i) {
            printWeatherReport(weekWeather[i], i);
        }

        // Ask user if they want a new forecast or to quit
        char choice;
        printf("Would you like to generate a new forecast? (Y/N): ");
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n') {
            quit = 1;
        }
        printf("\n");
    }

    printf("Thank you for using Sunnydale Weather Simulator!\n");
    return 0;
}