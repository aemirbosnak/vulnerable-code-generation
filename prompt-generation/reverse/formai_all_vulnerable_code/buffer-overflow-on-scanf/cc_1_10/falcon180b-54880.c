//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_TYPES 5
#define WEATHER_TYPE_SUNNY 0
#define WEATHER_TYPE_CLOUDY 1
#define WEATHER_TYPE_RAINY 2
#define WEATHER_TYPE_STORMY 3
#define WEATHER_TYPE_SNOWY 4

typedef struct {
    int temperature;
    int humidity;
    int wind;
    int weatherType;
} Weather;

int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int getRandomWeatherType() {
    return getRandomInt(0, WEATHER_TYPES - 1);
}

void generateWeather(Weather* weather) {
    weather->temperature = getRandomInt(0, 100);
    weather->humidity = getRandomInt(0, 100);
    weather->wind = getRandomInt(0, 10);
    weather->weatherType = getRandomWeatherType();
}

void printWeather(Weather weather) {
    switch (weather.weatherType) {
        case WEATHER_TYPE_SUNNY:
            printf("The weather is sunny with a temperature of %d degrees.\n", weather.temperature);
            break;
        case WEATHER_TYPE_CLOUDY:
            printf("The weather is cloudy with a temperature of %d degrees.\n", weather.temperature);
            break;
        case WEATHER_TYPE_RAINY:
            printf("The weather is rainy with a temperature of %d degrees.\n", weather.temperature);
            break;
        case WEATHER_TYPE_STORMY:
            printf("The weather is stormy with a temperature of %d degrees.\n", weather.temperature);
            break;
        case WEATHER_TYPE_SNOWY:
            printf("The weather is snowy with a temperature of %d degrees.\n", weather.temperature);
            break;
    }
}

int main() {
    srand(time(NULL));

    int numDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);

    Weather weather;
    for (int i = 0; i < numDays; i++) {
        generateWeather(&weather);
        printWeather(weather);
    }

    return 0;
}