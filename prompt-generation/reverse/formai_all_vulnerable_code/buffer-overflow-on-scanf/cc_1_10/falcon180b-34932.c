//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Alan Turing
// This is a weather simulation program written in C, inspired by the great Alan Turing.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the constants
#define SUNNY 1
#define RAINY 2
#define CLOUDY 3
#define THUNDERSTORM 4
#define SNOWY 5

// Define the structure for weather data
struct WeatherData {
    int temperature;
    int humidity;
    int windSpeed;
    int weatherType;
};

// Function to generate random weather data
struct WeatherData generateWeatherData() {
    struct WeatherData weather;
    weather.temperature = rand() % 40 + 1;
    weather.humidity = rand() % 100;
    weather.windSpeed = rand() % 11;
    weather.weatherType = rand() % 6;
    return weather;
}

// Function to print weather data
void printWeatherData(struct WeatherData weather) {
    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
    printf("Wind Speed: %d km/h\n", weather.windSpeed);
    printf("Weather Type: ");
    switch(weather.weatherType) {
        case SUNNY:
            printf("Sunny\n");
            break;
        case RAINY:
            printf("Rainy\n");
            break;
        case CLOUDY:
            printf("Cloudy\n");
            break;
        case THUNDERSTORM:
            printf("Thunderstorm\n");
            break;
        case SNOWY:
            printf("Snowy\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

// Function to simulate weather for a given number of days
void simulateWeather(int days) {
    srand(time(NULL));
    for(int i=0; i<days; i++) {
        struct WeatherData weather = generateWeatherData();
        printWeatherData(weather);
    }
}

int main() {
    int numDays;
    printf("Enter the number of days to simulate weather: ");
    scanf("%d", &numDays);
    simulateWeather(numDays);
    return 0;
}