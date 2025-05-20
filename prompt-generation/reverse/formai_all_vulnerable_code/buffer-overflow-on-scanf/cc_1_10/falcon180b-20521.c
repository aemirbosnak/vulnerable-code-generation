//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define WEATHER_TYPES 5

enum {
    SUNNY,
    CLOUDY,
    RAINY,
    SNOWY,
    STORMY
};

struct Weather {
    int type;
    int temperature;
    int humidity;
};

void generate_weather(struct Weather* weather) {
    weather->type = rand() % WEATHER_TYPES;
    weather->temperature = rand() % 101;
    weather->humidity = rand() % 101;
}

void print_weather(struct Weather weather) {
    switch (weather.type) {
        case SUNNY:
            printf("Sunny day with %d degrees and %d%% humidity.\n", weather.temperature, weather.humidity);
            break;
        case CLOUDY:
            printf("Cloudy day with %d degrees and %d%% humidity.\n", weather.temperature, weather.humidity);
            break;
        case RAINY:
            printf("Rainy day with %d degrees and %d%% humidity.\n", weather.temperature, weather.humidity);
            break;
        case SNOWY:
            printf("Snowy day with %d degrees and %d%% humidity.\n", weather.temperature, weather.humidity);
            break;
        case STORMY:
            printf("Stormy day with %d degrees and %d%% humidity.\n", weather.temperature, weather.humidity);
            break;
    }
}

int main() {
    srand(time(NULL));

    int num_days;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    struct Weather weather;
    for (int i = 1; i <= num_days; i++) {
        generate_weather(&weather);
        print_weather(weather);
    }

    return 0;
}