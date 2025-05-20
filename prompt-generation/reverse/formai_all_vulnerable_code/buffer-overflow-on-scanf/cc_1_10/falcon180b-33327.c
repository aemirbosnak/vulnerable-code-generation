//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_A_WEEK 7
#define HOURS_IN_A_DAY 24
#define MINUTES_IN_AN_HOUR 60

typedef enum {
    SUNNY = 0,
    CLOUDY = 1,
    RAINY = 2,
    THUNDERSTORM = 3,
    SNOWY = 4
} WeatherType;

typedef struct {
    WeatherType type;
    int temperature;
} Weather;

void generateWeather(Weather* weather) {
    int random = rand() % 5;

    switch (random) {
        case 0:
            weather->type = SUNNY;
            weather->temperature = rand() % 30 + 20;
            break;
        case 1:
            weather->type = CLOUDY;
            weather->temperature = rand() % 20 + 10;
            break;
        case 2:
            weather->type = RAINY;
            weather->temperature = rand() % 15 + 5;
            break;
        case 3:
            weather->type = THUNDERSTORM;
            weather->temperature = rand() % 25 + 15;
            break;
        case 4:
            weather->type = SNOWY;
            weather->temperature = rand() % -10 - 5;
            break;
    }
}

void printWeather(Weather weather) {
    switch (weather.type) {
        case SUNNY:
            printf("The weather is sunny with a temperature of %d degrees Celsius.\n", weather.temperature);
            break;
        case CLOUDY:
            printf("The weather is cloudy with a temperature of %d degrees Celsius.\n", weather.temperature);
            break;
        case RAINY:
            printf("The weather is rainy with a temperature of %d degrees Celsius.\n", weather.temperature);
            break;
        case THUNDERSTORM:
            printf("The weather is thunderstormy with a temperature of %d degrees Celsius.\n", weather.temperature);
            break;
        case SNOWY:
            printf("The weather is snowy with a temperature of %d degrees Celsius.\n", weather.temperature);
            break;
    }
}

int main() {
    srand(time(NULL));

    Weather weather;
    generateWeather(&weather);

    int choice;
    do {
        printf("Current weather: ");
        printWeather(weather);

        printf("Do you want to check the weather again? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            generateWeather(&weather);
        }
    } while (choice == 'y' || choice == 'Y');

    return 0;
}