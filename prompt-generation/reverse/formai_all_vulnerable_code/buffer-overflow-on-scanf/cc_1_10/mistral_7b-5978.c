//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CITY_COUNT 5
#define WEATHER_TYPES 4
#define MIN_TEMP -10
#define MAX_TEMP 50

typedef struct {
    char city[20];
    int temperature;
} City;

typedef enum { SUNNY, CLOUDS, RAIN, SNOW } Weather;

void print_city_weather(City cities[], int index) {
    printf("\nCity: %s", cities[index].city);
    Weather weather = (rand() % WEATHER_TYPES);
    switch (weather) {
        case SUNNY:
            printf(" \nWeather: Sunny\nTemperature: %d degrees Celsius\n", cities[index].temperature + rand() % 11 + 10);
            break;
        case CLOUDS:
            printf(" \nWeather: Clouds\nTemperature: %d degrees Celsius\n", cities[index].temperature + rand() % 6 + 5);
            break;
        case RAIN:
            printf(" \nWeather: Rain\nTemperature: %d degrees Celsius\n", cities[index].temperature + rand() % 4 + 2);
            break;
        case SNOW:
            printf(" \nWeather: Snow\nTemperature: %d degrees Celsius\n", cities[index].temperature);
            break;
    }
}

int main() {
    srand(time(NULL));
    City cities[CITY_COUNT];

    for (int i = 0; i < CITY_COUNT; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].city);
        cities[i].temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    }

    for (int i = 0; i < CITY_COUNT; i++) {
        print_city_weather(cities, i);
    }

    return 0;
}