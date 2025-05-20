//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_A_YEAR 365
#define HOURS_IN_A_DAY 24
#define MINUTES_IN_AN_HOUR 60

// Structure for a single day's weather data
typedef struct {
    int temperature;
    int humidity;
    int windSpeed;
    int precipitation;
} WeatherData;

// Function to generate random weather data within certain ranges
WeatherData generateRandomWeather(int minTemp, int maxTemp, int minHumidity, int maxHumidity,
                                  int minWindSpeed, int maxWindSpeed, int minPrecipitation, int maxPrecipitation) {
    WeatherData weatherData;

    // Set temperature within range
    weatherData.temperature = rand() % (maxTemp - minTemp + 1) + minTemp;

    // Set humidity within range
    weatherData.humidity = rand() % (maxHumidity - minHumidity + 1) + minHumidity;

    // Set wind speed within range
    weatherData.windSpeed = rand() % (maxWindSpeed - minWindSpeed + 1) + minWindSpeed;

    // Set precipitation within range
    weatherData.precipitation = rand() % (maxPrecipitation - minPrecipitation + 1) + minPrecipitation;

    return weatherData;
}

// Function to print a single day's weather data
void printWeatherData(WeatherData weatherData) {
    printf("Temperature: %d degrees\n", weatherData.temperature);
    printf("Humidity: %d%%\n", weatherData.humidity);
    printf("Wind Speed: %d mph\n", weatherData.windSpeed);
    printf("Precipitation: %d inches\n\n", weatherData.precipitation);
}

// Function to simulate weather for a given number of days
void simulateWeather(int numDays) {
    srand(time(NULL));

    for (int i = 0; i < numDays; i++) {
        WeatherData weatherData = generateRandomWeather(50, 90, 30, 70, 5, 25, 0, 3);
        printWeatherData(weatherData);
    }
}

int main() {
    int numDays;

    printf("Enter the number of days to simulate weather for: ");
    scanf("%d", &numDays);

    simulateWeather(numDays);

    return 0;
}