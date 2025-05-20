//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 80
#define TEMP_MIN -20
#define TEMP_MAX 40
#define TEMP_STEP 1
#define HUMIDITY_MIN 0
#define HUMIDITY_MAX 100
#define HUMIDITY_STEP 1
#define WIND_SPEED_MIN 0
#define WIND_SPEED_MAX 20
#define WIND_SPEED_STEP 1

typedef struct {
    int temperature;
    int humidity;
    int windSpeed;
} Weather;

void initWeather(Weather *weather) {
    weather->temperature = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    weather->humidity = rand() % (HUMIDITY_MAX - HUMIDITY_MIN + 1) + HUMIDITY_MIN;
    weather->windSpeed = rand() % (WIND_SPEED_MAX - WIND_SPEED_MIN + 1) + WIND_SPEED_MIN;
}

void printWeather(Weather weather) {
    printf("Temperature: %d°C\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
    printf("Wind Speed: %d m/s\n", weather.windSpeed);
}

int main() {
    srand(time(NULL));

    Weather currentWeather, forecast[5];

    initWeather(&currentWeather);

    for (int i = 0; i < 5; i++) {
        initWeather(&forecast[i]);
    }

    int choice;
    do {
        system("clear");
        printf("Current Weather:\n");
        printWeather(currentWeather);

        printf("\n5-Day Forecast:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d-Day Forecast: ", i + 1);
            printWeather(forecast[i]);
        }

        printf("\nEnter your choice:\n");
        printf("1. Update current weather\n");
        printf("2. Update 5-day forecast\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initWeather(&currentWeather);
                break;
            case 2:
                for (int i = 0; i < 5; i++) {
                    initWeather(&forecast[i]);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}