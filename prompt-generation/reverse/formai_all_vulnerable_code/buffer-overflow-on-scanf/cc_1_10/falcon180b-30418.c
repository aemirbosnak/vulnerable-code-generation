//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_TYPES 5
#define WEATHER_TYPES_STRINGS { "Sunny", "Rainy", "Cloudy", "Stormy", "Snowy" }

#define MIN_TEMPERATURE -10
#define MAX_TEMPERATURE 40
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 100

typedef struct {
    int temperature;
    int humidity;
    int wind_speed;
    char weather_type[20];
} Weather;

void init_weather(Weather *weather) {
    srand(time(NULL));
    weather->temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    weather->humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
    weather->wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
    weather->weather_type[0] = '\0';
}

void print_weather(Weather weather) {
    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
    printf("Wind Speed: %d km/h\n", weather.wind_speed);
    printf("Weather Type: %s\n", weather.weather_type);
}

int main() {
    int num_weathers, i;
    printf("Enter the number of weather simulations: ");
    scanf("%d", &num_weathers);

    for (i = 0; i < num_weathers; i++) {
        Weather weather;
        init_weather(&weather);
        printf("Weather Simulation %d:\n", i + 1);
        print_weather(weather);
    }

    return 0;
}