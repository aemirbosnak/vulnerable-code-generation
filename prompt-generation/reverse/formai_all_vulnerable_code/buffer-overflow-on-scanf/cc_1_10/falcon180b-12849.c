//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_YEAR 365
#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60
#define MILLISECONDS_IN_SECOND 1000
#define MILLISECONDS_IN_MINUTE (MILLISECONDS_IN_SECOND * SECONDS_IN_MINUTE)
#define MILLISECONDS_IN_HOUR (MILLISECONDS_IN_MINUTE * MINUTES_IN_HOUR)
#define MILLISECONDS_IN_DAY (MILLISECONDS_IN_HOUR * HOURS_IN_DAY)
#define MILLISECONDS_IN_YEAR (MILLISECONDS_IN_DAY * DAYS_IN_YEAR)

typedef struct {
    int temperature;
    int humidity;
    int precipitation;
    int windSpeed;
} Weather;

void generateRandomWeather(Weather* weather) {
    srand(time(NULL));
    weather->temperature = rand() % 50 + 1;
    weather->humidity = rand() % 101;
    weather->precipitation = rand() % 3;
    weather->windSpeed = rand() % 11;
}

void printWeather(Weather weather) {
    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
    printf("Precipitation: %s\n", weather.precipitation == 0? "None" : weather.precipitation == 1? "Light" : "Heavy");
    printf("Wind Speed: %d mph\n", weather.windSpeed);
}

int main() {
    int days;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &days);

    for (int i = 0; i < days; i++) {
        Weather weather;
        generateRandomWeather(&weather);
        printWeather(weather);
        printf("\n");

        int hours = rand() % 24;
        int minutes = rand() % 60;
        int seconds = rand() % 60;
        int milliseconds = rand() % 1000;

        printf("Simulating %d:%02d:%02d.%03d...\n", hours, minutes, seconds, milliseconds);
        usleep(MILLISECONDS_IN_MINUTE);
    }

    return 0;
}