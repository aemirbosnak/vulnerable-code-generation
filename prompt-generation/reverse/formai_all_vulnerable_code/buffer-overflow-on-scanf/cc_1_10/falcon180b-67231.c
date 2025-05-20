//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_DAYS 365
#define MIN_TEMP -20
#define MAX_TEMP 40
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 50

// Define structures
typedef struct {
    int day;
    int temperature;
    int humidity;
    int windSpeed;
} Weather;

// Function to generate random weather data
Weather generateWeather(int day) {
    Weather weather;
    weather.day = day;

    // Generate random temperature
    weather.temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;

    // Generate random humidity
    weather.humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;

    // Generate random wind speed
    weather.windSpeed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;

    return weather;
}

// Function to print weather data
void printWeather(Weather weather) {
    printf("Day %d: Temperature %dC, Humidity %d%, Wind Speed %d km/h\n", weather.day, weather.temperature, weather.humidity, weather.windSpeed);
}

// Function to simulate weather for a given number of days
void simulateWeather(int numDays) {
    srand(time(NULL));

    // Initialize array to store weather data
    Weather weatherData[MAX_DAYS];

    // Generate weather data for each day
    for (int i = 0; i < numDays; i++) {
        weatherData[i] = generateWeather(i + 1);
    }

    // Print weather data for each day
    for (int i = 0; i < numDays; i++) {
        printWeather(weatherData[i]);
    }
}

int main() {
    int numDays;

    // Get number of days to simulate from user
    printf("Enter number of days to simulate: ");
    scanf("%d", &numDays);

    // Simulate weather for given number of days
    simulateWeather(numDays);

    return 0;
}