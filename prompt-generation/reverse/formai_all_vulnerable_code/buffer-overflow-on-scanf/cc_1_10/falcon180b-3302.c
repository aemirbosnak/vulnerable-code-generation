//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_WEATHER_TYPES 4
#define NUM_HOURS 24

enum {
    SUNNY = 0,
    CLOUDY,
    RAINY,
    THUNDERSTORM,
};

struct city {
    char name[20];
    int temperature[NUM_HOURS];
    int humidity[NUM_HOURS];
    int weather[NUM_HOURS];
};

void generate_weather(struct city *city, int hour) {
    int i;
    srand(time(NULL) + hour);
    for (i = 0; i < NUM_HOURS; i++) {
        city->temperature[i] = rand() % 40 + 10;
        city->humidity[i] = rand() % 100;
        city->weather[i] = rand() % NUM_WEATHER_TYPES;
    }
}

void print_weather(struct city *city, int hour) {
    printf("Hour %d weather in %s:\n", hour, city->name);
    printf("Temperature: %d°C\n", city->temperature[hour]);
    printf("Humidity: %d%%\n", city->humidity[hour]);
    switch (city->weather[hour]) {
        case SUNNY:
            printf("Weather: Sunny\n");
            break;
        case CLOUDY:
            printf("Weather: Cloudy\n");
            break;
        case RAINY:
            printf("Weather: Rainy\n");
            break;
        case THUNDERSTORM:
            printf("Weather: Thunderstorm\n");
            break;
    }
}

int main() {
    struct city cities[NUM_CITIES];
    int i, j;

    for (i = 0; i < NUM_CITIES; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generate_weather(&cities[i], 0);
    }

    for (i = 0; i < NUM_CITIES; i++) {
        printf("City: %s\n", cities[i].name);
        for (j = 0; j < NUM_HOURS; j++) {
            print_weather(&cities[i], j);
        }
    }

    return 0;
}