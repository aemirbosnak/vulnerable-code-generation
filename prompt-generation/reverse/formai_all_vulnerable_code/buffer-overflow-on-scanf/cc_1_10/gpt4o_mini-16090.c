//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WEATHER_TYPES 4
#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE -10
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0

typedef enum {
    SUNNY,
    RAINY,
    CLOUDY,
    WINDY
} WeatherType;

typedef struct {
    WeatherType type;
    int temperature; // in Celsius
    int humidity;    // in percentage
} Weather;

void printWeather(Weather weather) {
    const char *weatherTypes[NUM_WEATHER_TYPES] = {"Sunny", "Rainy", "Cloudy", "Windy"};
    
    printf("Weather Type: %s\n", weatherTypes[weather.type]);
    printf("Temperature: %d°C\n", weather.temperature);
    printf("Humidity: %d%%\n\n", weather.humidity);
}

Weather generateRandomWeather() {
    Weather weather;
    
    weather.type = rand() % NUM_WEATHER_TYPES;
    weather.temperature = MIN_TEMPERATURE + rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1);
    weather.humidity = MIN_HUMIDITY + rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1);
    
    return weather;
}

void simulateWeather(int days) {
    for (int i = 0; i < days; i++) {
        printf("Day %d:\n", i + 1);
        Weather weather = generateRandomWeather();
        printWeather(weather);
    }
}

int main() {
    srand(time(0)); // Seed random number generator with current time
    int daysToSimulate;

    printf("Enter the number of days to simulate weather: ");
    scanf("%d", &daysToSimulate);

    if (daysToSimulate <= 0) {
        printf("Please enter a valid number of days.\n");
        return 1;
    }

    printf("\nWeather Simulation for %d days:\n", daysToSimulate);
    simulateWeather(daysToSimulate);

    return 0;
}