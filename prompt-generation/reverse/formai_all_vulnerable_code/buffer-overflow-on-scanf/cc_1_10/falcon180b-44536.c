//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MAX_HOURS 24
#define MAX_MINUTES 60
#define MAX_SECONDS 60

typedef struct {
    int temperature;
    int humidity;
    int precipitation;
} Weather;

void generateWeather(Weather *weather, int day, int hour, int minute, int second) {
    if (day >= 0 && day < MAX_DAYS && hour >= 0 && hour < MAX_HOURS && minute >= 0 && minute < MAX_MINUTES && second >= 0 && second < MAX_SECONDS) {
        weather->temperature = rand() % 50 + 10;
        weather->humidity = rand() % 100;
        weather->precipitation = rand() % 4;
    } else {
        printf("Invalid weather data.\n");
    }
}

void printWeather(Weather weather) {
    printf("Temperature: %d°C\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
    if (weather.precipitation == 0) {
        printf("Precipitation: None\n");
    } else if (weather.precipitation == 1) {
        printf("Precipitation: Light rain\n");
    } else if (weather.precipitation == 2) {
        printf("Precipitation: Moderate rain\n");
    } else {
        printf("Precipitation: Heavy rain\n");
    }
}

int main(void) {
    srand(time(NULL));

    Weather weather;
    int day, hour, minute, second;

    printf("Enter day (0-364): ");
    scanf("%d", &day);

    printf("Enter hour (0-23): ");
    scanf("%d", &hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &minute);

    printf("Enter second (0-59): ");
    scanf("%d", &second);

    generateWeather(&weather, day, hour, minute, second);
    printWeather(weather);

    return 0;
}