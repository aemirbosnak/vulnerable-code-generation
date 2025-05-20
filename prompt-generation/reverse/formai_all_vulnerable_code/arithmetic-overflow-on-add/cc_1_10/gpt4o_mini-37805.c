//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants
#define MAX_DAYS 7
#define MAX_WEATHER_TYPES 4

// Enum for weather types
typedef enum {
    SUNNY,
    CLOUDY,
    RAINY,
    SNOWY
} WeatherType;

// Struct to hold daily weather data
typedef struct {
    char date[11]; // e.g., "YYYY-MM-DD"
    WeatherType weather;
    float temperature; // in Celsius
    float windSpeed; // in km/h
    float humidity; // in percentage
} DailyWeather;

// Function prototypes
void generateWeatherForecast(DailyWeather* forecast, int days);
void printWeatherForecast(DailyWeather* forecast, int days);
const char* weatherToString(WeatherType weather);

int main() {
    DailyWeather weeklyForecast[MAX_DAYS];
    srand(time(NULL)); // Seed random number generator

    // Generate weather forecast for the week
    generateWeatherForecast(weeklyForecast, MAX_DAYS);

    // Print the weather forecast
    printWeatherForecast(weeklyForecast, MAX_DAYS);

    return 0;
}

// Function to generate weather data for a specified number of days
void generateWeatherForecast(DailyWeather* forecast, int days) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    for (int i = 0; i < days; i++) {
        // Set the date
        snprintf(forecast[i].date, sizeof(forecast[i].date), "%04d-%02d-%02d",
                 tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday + i);

        // Generate random weather type
        forecast[i].weather = rand() % MAX_WEATHER_TYPES;

        // Generate random temperature (in a reasonable range)
        forecast[i].temperature = (rand() % 301 - 100) / 10.0; // -10.0 to 30.0

        // Generate random wind speed (0 to 150 km/h)
        forecast[i].windSpeed = rand() % 151;

        // Generate random humidity (30% to 100%)
        forecast[i].humidity = (rand() % 71 + 30); // 30% to 100%
    }
}

// Function to print the weather forecast
void printWeatherForecast(DailyWeather* forecast, int days) {
    printf("Weather Forecast for the Next %d Days:\n", days);
    printf("---------------------------------------------------------\n");
    printf("| Date       | Weather    | Temp (°C) | Wind (km/h) | Humidity (%) |\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < days; i++) {
        printf("| %-10s | %-10s | %-10.1f | %-11.1f | %-12.1f |\n",
               forecast[i].date,
               weatherToString(forecast[i].weather),
               forecast[i].temperature,
               forecast[i].windSpeed,
               forecast[i].humidity);
    }

    printf("---------------------------------------------------------\n");
}

// Function to convert weather type to string
const char* weatherToString(WeatherType weather) {
    switch (weather) {
        case SUNNY: return "Sunny";
        case CLOUDY: return "Cloudy";
        case RAINY: return "Rainy";
        case SNOWY: return "Snowy";
        default: return "Unknown";
    }
}