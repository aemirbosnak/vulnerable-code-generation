//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAY 86400 // number of seconds in a day

// structure to hold weather data for a location
typedef struct {
    double temperature;
    double humidity;
    double windSpeed;
    double precipitation;
} WeatherData;

// function to generate random weather data for a location
void generateWeatherData(WeatherData *weather) {
    srand(time(NULL));
    weather->temperature = rand() % 50 + 10; // temperature in Celsius
    weather->humidity = rand() % 101; // humidity in percentage
    weather->windSpeed = rand() % 21 + 1; // wind speed in km/h
    weather->precipitation = rand() % 101; // precipitation in mm
}

// function to print weather data for a location
void printWeatherData(WeatherData weather) {
    printf("Temperature: %.2f°C\n", weather.temperature);
    printf("Humidity: %.2f%%\n", weather.humidity);
    printf("Wind Speed: %.2f km/h\n", weather.windSpeed);
    printf("Precipitation: %.2f mm\n", weather.precipitation);
}

// function to simulate weather for a location over a period of time
void simulateWeather(WeatherData *weather, int days) {
    for (int i = 0; i < days; i++) {
        generateWeatherData(weather);
        printf("Day %d:\n", i+1);
        printWeatherData(*weather);
        printf("\n");
    }
}

// main function
int main() {
    WeatherData weather;
    int numDays;

    // get number of days to simulate weather for
    printf("Enter number of days to simulate weather for: ");
    scanf("%d", &numDays);

    // simulate weather for the specified number of days
    simulateWeather(&weather, numDays);

    return 0;
}