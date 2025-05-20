//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS 7
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60

// Structure to hold temperature and humidity data for a given day
typedef struct {
    int temperature;
    int humidity;
} WeatherData;

// Function to generate random weather data for a given day
void generateWeatherData(WeatherData *data, int day) {
    data->temperature = rand() % 100; // Generate random temperature between 0 and 99
    data->humidity = rand() % 101; // Generate random humidity between 0 and 100
}

// Function to print the weather forecast for a given day
void printWeatherForecast(const WeatherData *data, int day) {
    printf("Day %d: Temperature %d°C, Humidity %d%%\n", day, data->temperature, data->humidity);
}

// Function to simulate a week's worth of weather
void simulateWeather(int startDay, int numDays) {
    time_t startTime = time(NULL) - (startDay * HOURS_PER_DAY * MINUTES_PER_HOUR);
    srand(startTime);

    for (int i = 0; i < numDays; i++) {
        WeatherData data;
        generateWeatherData(&data, i + startDay);
        printWeatherForecast(&data, i + startDay);
    }
}

int main() {
    int startDay, numDays;

    // Prompt the user for the starting day and number of days to simulate
    printf("Enter the starting day (0-6): ");
    scanf("%d", &startDay);
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);

    // Simulate the weather for the given number of days
    simulateWeather(startDay, numDays);

    return 0;
}