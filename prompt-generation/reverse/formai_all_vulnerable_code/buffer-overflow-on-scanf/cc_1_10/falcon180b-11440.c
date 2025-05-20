//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 30
#define MIN_TEMP 0
#define MAX_TEMP 100
#define TEMP_RANGE (MAX_TEMP - MIN_TEMP)
#define HUMIDITY_RANGE 100
#define WIND_SPEED_RANGE 50

typedef struct {
    int day;
    int temperature;
    int humidity;
    int windSpeed;
} WeatherData;

void generateWeatherData(WeatherData* weatherData, int numDays) {
    srand(time(NULL));
    for (int i = 0; i < numDays; i++) {
        weatherData[i].day = i + 1;
        weatherData[i].temperature = rand() % TEMP_RANGE + MIN_TEMP;
        weatherData[i].humidity = rand() % HUMIDITY_RANGE;
        weatherData[i].windSpeed = rand() % WIND_SPEED_RANGE;
    }
}

void printWeatherData(WeatherData* weatherData, int numDays) {
    printf("Weather Data:\n");
    for (int i = 0; i < numDays; i++) {
        printf("Day %d: Temperature %d, Humidity %d, Wind Speed %d\n", weatherData[i].day, weatherData[i].temperature, weatherData[i].humidity, weatherData[i].windSpeed);
    }
}

int main() {
    int numDays;
    printf("Enter number of days to simulate (max %d): ", MAX_DAYS);
    scanf("%d", &numDays);

    if (numDays <= 0 || numDays > MAX_DAYS) {
        printf("Invalid number of days.\n");
        return 1;
    }

    WeatherData weatherData[MAX_DAYS];
    generateWeatherData(weatherData, numDays);
    printWeatherData(weatherData, numDays);

    return 0;
}