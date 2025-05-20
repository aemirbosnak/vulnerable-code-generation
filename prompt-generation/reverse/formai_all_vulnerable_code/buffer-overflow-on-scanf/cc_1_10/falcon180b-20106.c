//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the weather conditions
#define SUNNY 0
#define CLOUDY 1
#define RAINY 2
#define THUNDERSTORM 3

// Define the temperature range
#define MIN_TEMP -10
#define MAX_TEMP 40

// Define the wind speed range
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 20

// Define the humidity range
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100

typedef struct {
    int weather;
    int temperature;
    int windSpeed;
    int humidity;
} Weather;

// Function to generate random weather conditions
int generateWeather() {
    int weather = rand() % 4;
    return weather;
}

// Function to generate random temperature
int generateTemperature() {
    int temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    return temperature;
}

// Function to generate random wind speed
int generateWindSpeed() {
    int windSpeed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
    return windSpeed;
}

// Function to generate random humidity
int generateHumidity() {
    int humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
    return humidity;
}

// Function to print the weather conditions
void printWeather(Weather weather) {
    switch(weather.weather) {
        case SUNNY:
            printf("It's a beautiful, sunny day!\n");
            break;
        case CLOUDY:
            printf("The sky is cloudy and grey.\n");
            break;
        case RAINY:
            printf("It's raining outside.\n");
            break;
        case THUNDERSTORM:
            printf("There's a thunderstorm brewing.\n");
            break;
        default:
            printf("Invalid weather condition.\n");
            break;
    }
}

// Function to print the weather forecast
void forecast(int numDays) {
    srand(time(NULL));
    for(int i = 0; i < numDays; i++) {
        Weather weather = {generateWeather(), generateTemperature(), generateWindSpeed(), generateHumidity()};
        printWeather(weather);
        printf("The temperature is %d degrees Celsius.\n", weather.temperature);
        printf("The wind speed is %d km/h.\n", weather.windSpeed);
        printf("The humidity is %d%.\n\n", weather.humidity);
    }
}

int main() {
    int numDays;
    printf("Enter the number of days you want to forecast: ");
    scanf("%d", &numDays);
    forecast(numDays);
    return 0;
}