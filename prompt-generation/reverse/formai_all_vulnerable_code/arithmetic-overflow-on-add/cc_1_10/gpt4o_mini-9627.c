//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 7

typedef struct {
    char *day;
    int temperature; // in degrees Celsius
    int windSpeed; // in km/h
    int humidity; // in percentage
} WeatherDay;

void generateWeather(WeatherDay *weather, int baseTemp, int baseWind, int baseHumidity) {
    for (int i = 0; i < DAYS; i++) {
        weather[i].temperature = baseTemp + (rand() % 11) - 5; // Variance of -5 to +5 degrees
        weather[i].windSpeed = baseWind + (rand() % 21) - 10; // Variance of -10 to +10 km/h
        weather[i].humidity = baseHumidity + (rand() % 21) - 10; // Variance of -10 to +10%
        
        // Ensure values remain within plausible ranges
        if (weather[i].temperature < -30) weather[i].temperature = -30;
        if (weather[i].temperature > 50) weather[i].temperature = 50;
        if (weather[i].windSpeed < 0) weather[i].windSpeed = 0;
        if (weather[i].humidity < 0) weather[i].humidity = 0;
        if (weather[i].humidity > 100) weather[i].humidity = 100;
    }
}

void displayWeather(WeatherDay *weather) {
    printf("\nWeekly Weather Forecast:\n");
    printf("---------------------------\n");
    for (int i = 0; i < DAYS; i++) {
        printf("%s: Temperature: %d°C, Wind Speed: %dkm/h, Humidity: %d%%\n",
               weather[i].day, weather[i].temperature, weather[i].windSpeed, weather[i].humidity);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    WeatherDay weather[DAYS];
    char *daysOfWeek[DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    for (int i = 0; i < DAYS; i++) {
        weather[i].day = daysOfWeek[i];
    }

    int baseTemp, baseWind, baseHumidity;
    printf("Enter the base temperature (°C): ");
    scanf("%d", &baseTemp);
    printf("Enter the base wind speed (km/h): ");
    scanf("%d", &baseWind);
    printf("Enter the base humidity (%%): ");
    scanf("%d", &baseHumidity);

    generateWeather(weather, baseTemp, baseWind, baseHumidity);
    displayWeather(weather);

    return 0;
}