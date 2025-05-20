//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DAYS_PER_YEAR 365.25
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60

#define MAX_CLOUD_COVER 100
#define MIN_CLOUD_COVER 0
#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE -10
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0
#define MAX_WIND_SPEED 20
#define MIN_WIND_SPEED 0

typedef struct {
    double temperature;
    double humidity;
    double wind_speed;
    double cloud_cover;
} Weather;

void generate_weather(Weather *weather) {
    weather->temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    weather->humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
    weather->wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
    weather->cloud_cover = rand() % (MAX_CLOUD_COVER - MIN_CLOUD_COVER + 1) + MIN_CLOUD_COVER;
}

void print_weather(Weather weather) {
    printf("Temperature: %.2f\n", weather.temperature);
    printf("Humidity: %.2f\n", weather.humidity);
    printf("Wind speed: %.2f\n", weather.wind_speed);
    printf("Cloud cover: %.2f\n", weather.cloud_cover);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int num_days;
    printf("Enter number of days to simulate: ");
    scanf("%d", &num_days);

    for (int i = 0; i < num_days; i++) {
        Weather weather;
        generate_weather(&weather);
        printf("Day %d:\n", i + 1);
        print_weather(weather);
        printf("\n");
    }

    return 0;
}