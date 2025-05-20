//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MAX_HOURS 24
#define MIN_TEMP -20
#define MAX_TEMP 50
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 50
#define MIN_AIR_PRESSURE 950
#define MAX_AIR_PRESSURE 1050

struct WeatherData {
    int day;
    int hour;
    int temperature;
    int humidity;
    int windSpeed;
    int airPressure;
};

void generateRandomWeather(struct WeatherData *weatherData) {
    srand(time(NULL));
    weatherData->day = rand() % MAX_DAYS;
    weatherData->hour = rand() % MAX_HOURS;
    weatherData->temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    weatherData->humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
    weatherData->windSpeed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
    weatherData->airPressure = rand() % (MAX_AIR_PRESSURE - MIN_AIR_PRESSURE + 1) + MIN_AIR_PRESSURE;
}

void printWeatherData(struct WeatherData weatherData) {
    printf("Day: %d\n", weatherData.day);
    printf("Hour: %d\n", weatherData.hour);
    printf("Temperature: %d°C\n", weatherData.temperature);
    printf("Humidity: %d%%\n", weatherData.humidity);
    printf("Wind Speed: %d km/h\n", weatherData.windSpeed);
    printf("Air Pressure: %d hPa\n", weatherData.airPressure);
}

int main() {
    int numDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);

    struct WeatherData weatherData;
    for (int i = 0; i < numDays; i++) {
        generateRandomWeather(&weatherData);
        printWeatherData(weatherData);
    }

    return 0;
}