//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Weather simulation constants
#define MIN_TEMP -10
#define MAX_TEMP 40
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 50

// Weather data structure
typedef struct {
    int temperature;
    int humidity;
    int windSpeed;
} WeatherData;

// Function to generate random weather data
WeatherData generateWeatherData() {
    WeatherData data;

    // Set temperature within range
    data.temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;

    // Set humidity within range
    data.humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;

    // Set wind speed within range
    data.windSpeed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;

    return data;
}

// Function to print weather data
void printWeatherData(WeatherData data) {
    printf("Temperature: %d\n", data.temperature);
    printf("Humidity: %d%%\n", data.humidity);
    printf("Wind Speed: %d km/h\n", data.windSpeed);
}

// Main function to simulate weather
int main() {
    srand(time(NULL)); // Seed random number generator with current time

    int numDays;
    printf("Enter the number of days to simulate weather: ");
    scanf("%d", &numDays);

    for (int i = 0; i < numDays; i++) {
        WeatherData data = generateWeatherData();
        printWeatherData(data);
        printf("\n");
    }

    return 0;
}