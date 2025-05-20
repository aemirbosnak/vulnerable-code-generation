//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define TEMP_MIN -10
#define TEMP_MAX 30
#define HUMIDITY_MIN 0
#define HUMIDITY_MAX 100
#define WIND_SPEED_MIN 0
#define WIND_SPEED_MAX 20
#define PRESSURE_MIN 800
#define PRESSURE_MAX 1200
#define RAIN_MIN 0
#define RAIN_MAX 100
#define CLOUD_COVER_MIN 0
#define CLOUD_COVER_MAX 100

typedef struct {
    int temperature;
    int humidity;
    int wind_speed;
    int pressure;
    int rain;
    int cloud_cover;
} Weather;

void generate_weather(Weather *weather) {
    weather->temperature = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    weather->humidity = rand() % (HUMIDITY_MAX - HUMIDITY_MIN + 1) + HUMIDITY_MIN;
    weather->wind_speed = rand() % (WIND_SPEED_MAX - WIND_SPEED_MIN + 1) + WIND_SPEED_MIN;
    weather->pressure = rand() % (PRESSURE_MAX - PRESSURE_MIN + 1) + PRESSURE_MIN;
    weather->rain = rand() % (RAIN_MAX - RAIN_MIN + 1) + RAIN_MIN;
    weather->cloud_cover = rand() % (CLOUD_COVER_MAX - CLOUD_COVER_MIN + 1) + CLOUD_COVER_MIN;
}

void print_weather(Weather weather) {
    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
    printf("Wind Speed: %d km/h\n", weather.wind_speed);
    printf("Pressure: %d hPa\n", weather.pressure);
    printf("Rain: %d%%\n", weather.rain);
    printf("Cloud Cover: %d%%\n\n", weather.cloud_cover);
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Weather Simulator!\n\n");

    Weather current_weather;
    generate_weather(&current_weather);
    print_weather(current_weather);

    int choice;
    do {
        printf("What would you like to do?\n");
        printf("1. Check weather\n");
        printf("2. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_weather(&current_weather);
                print_weather(current_weather);
                break;

            case 2:
                printf("Thank you for using the Weather Simulator!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 2);

    return 0;
}