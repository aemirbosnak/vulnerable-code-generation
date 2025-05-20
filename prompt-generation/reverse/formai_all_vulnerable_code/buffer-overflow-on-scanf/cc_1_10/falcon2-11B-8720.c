//Falcon2-11B DATASET v1.0 Category: Weather simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define WIND_SPEED_MAX 80
#define WIND_SPEED_MIN 0
#define WIND_DIRECTION_MAX 360
#define WIND_DIRECTION_MIN 0
#define TEMPERATURE_MAX 100
#define TEMPERATURE_MIN -50
#define HUMIDITY_MAX 100
#define HUMIDITY_MIN 0

void simulateWeather();
void displayWeather();
void displayForecast();

int main()
{
    char choice;
    int hour;

    do
    {
        printf("Welcome to Weather Simulator.\n");
        printf("Please select an option:\n");
        printf("1. Simulate Weather\n");
        printf("2. Display Weather\n");
        printf("3. Display Forecast\n");
        printf("4. Exit\n");
        printf("Enter your choice (1/2/3/4): ");
        scanf("%c", &choice);

        switch (choice)
        {
        case '1':
            simulateWeather();
            break;
        case '2':
            displayWeather();
            break;
        case '3':
            displayForecast();
            break;
        case '4':
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}

void simulateWeather()
{
    int temperature = rand() % (TEMPERATURE_MAX - TEMPERATURE_MIN) + TEMPERATURE_MIN;
    int humidity = rand() % (HUMIDITY_MAX - HUMIDITY_MIN) + HUMIDITY_MIN;
    int windSpeed = rand() % (WIND_SPEED_MAX - WIND_SPEED_MIN) + WIND_SPEED_MIN;
    int windDirection = rand() % (WIND_DIRECTION_MAX - WIND_DIRECTION_MIN) + WIND_DIRECTION_MIN;

    printf("Current weather:\n");
    printf("Temperature: %d C\n", temperature);
    printf("Humidity: %d %%\n", humidity);
    printf("Wind speed: %d m/s\n", windSpeed);
    printf("Wind direction: %d degrees\n\n", windDirection);
}

void displayWeather()
{
    int temperature = rand() % (TEMPERATURE_MAX - TEMPERATURE_MIN) + TEMPERATURE_MIN;
    int humidity = rand() % (HUMIDITY_MAX - HUMIDITY_MIN) + HUMIDITY_MIN;
    int windSpeed = rand() % (WIND_SPEED_MAX - WIND_SPEED_MIN) + WIND_SPEED_MIN;
    int windDirection = rand() % (WIND_DIRECTION_MAX - WIND_DIRECTION_MIN) + WIND_DIRECTION_MIN;

    printf("Current weather:\n");
    printf("Temperature: %d C\n", temperature);
    printf("Humidity: %d %%\n", humidity);
    printf("Wind speed: %d m/s\n", windSpeed);
    printf("Wind direction: %d degrees\n\n", windDirection);
}

void displayForecast()
{
    int hour = rand() % 24;

    printf("Forecast for the next 24 hours:\n");
    printf("Day %d:\n", hour + 1);
    printf("Temperature: %d C\n", rand() % (TEMPERATURE_MAX - TEMPERATURE_MIN) + TEMPERATURE_MIN);
    printf("Humidity: %d %%\n", rand() % (HUMIDITY_MAX - HUMIDITY_MIN) + HUMIDITY_MIN);
    printf("Wind speed: %d m/s\n", rand() % (WIND_SPEED_MAX - WIND_SPEED_MIN) + WIND_SPEED_MIN);
    printf("Wind direction: %d degrees\n\n", rand() % (WIND_DIRECTION_MAX - WIND_DIRECTION_MIN) + WIND_DIRECTION_MIN);

    for (int i = 1; i <= 23; i++)
    {
        if (i == hour + 1)
            continue;

        printf("Day %d:\n", i + 1);
        printf("Temperature: %d C\n", rand() % (TEMPERATURE_MAX - TEMPERATURE_MIN) + TEMPERATURE_MIN);
        printf("Humidity: %d %%\n", rand() % (HUMIDITY_MAX - HUMIDITY_MIN) + HUMIDITY_MIN);
        printf("Wind speed: %d m/s\n", rand() % (WIND_SPEED_MAX - WIND_SPEED_MIN) + WIND_SPEED_MIN);
        printf("Wind direction: %d degrees\n\n", rand() % (WIND_DIRECTION_MAX - WIND_DIRECTION_MIN) + WIND_DIRECTION_MIN);
    }
}