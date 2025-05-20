//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 7

typedef struct {
    float temperature; // in Celsius
    float humidity;    // in percentage
    float windSpeed;   // in km/h
} Weather;

void generateWeather(Weather *weather) {
    // Generates random weather parameters
    weather->temperature = (rand() % 41) - 10; // Temperature from -10 to 30
    weather->humidity = rand() % 101;           // Humidity from 0% to 100%
    weather->windSpeed = (rand() % 101);        // Wind speed from 0 to 100 km/h
}

void displayWeather(Weather weather, int day) {
    // Displays the weather information for a given day
    printf("Day %d:\n", day + 1);
    printf("Temperature: %.2f °C\n", weather.temperature);
    printf("Humidity: %.2f%%\n", weather.humidity);
    printf("Wind Speed: %.2f km/h\n\n", weather.windSpeed);
}

void simulateWeather(int days) {
    Weather weather[MAX_DAYS];

    for(int i = 0; i < days; i++) {
        generateWeather(&weather[i]);
    }

    printf("Weather forecast for the next %d days:\n\n", days);
    for(int i = 0; i < days; i++) {
        displayWeather(weather[i], i);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int days;

    printf("Welcome to the Weather Simulation Program!\n");
    printf("Enter the number of days you want to simulate (1 - %d): ", MAX_DAYS);
    scanf("%d", &days);

    // Input validation
    if (days < 1 || days > MAX_DAYS) {
        printf("Invalid number of days. Please run the program again.\n");
        return 1; // Exit with error
    }

    simulateWeather(days); // Run the weather simulation

    printf("Simulation complete. Thank you for using the Weather Simulation Program!\n");
    return 0;
}