//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WEATHER_TYPES 5
#define MAX_WEATHER_DURATION 7

typedef enum {
    SUNNY,
    CLOUDY,
    RAINY,
    SNOWY,
    FOGGY
} WeatherType;

typedef struct {
    WeatherType type;
    int duration;
} Weather;

void generateWeather(Weather *weather) {
    int randIndex = rand() % MAX_WEATHER_TYPES;
    weather->type = (WeatherType) randIndex;
    weather->duration = rand() % MAX_WEATHER_DURATION + 1;
}

void printWeather(Weather weather) {
    switch (weather.type) {
        case SUNNY:
            printf("The sun is shining brightly.\n");
            break;
        case CLOUDY:
            printf("The sky is covered with clouds.\n");
            break;
        case RAINY:
            printf("It's raining outside.\n");
            break;
        case SNOWY:
            printf("Snowflakes are falling gently.\n");
            break;
        case FOGGY:
            printf("A thick fog has settled in.\n");
            break;
    }
}

int main() {
    srand(time(NULL));

    Weather currentWeather;
    generateWeather(&currentWeather);
    printWeather(currentWeather);

    int userChoice;
    printf("Press 1 to check the weather again or any other key to exit:\n");
    scanf("%d", &userChoice);

    while (userChoice == 1) {
        generateWeather(&currentWeather);
        printWeather(currentWeather);

        printf("Press 1 to check the weather again or any other key to exit:\n");
        scanf("%d", &userChoice);
    }

    return 0;
}