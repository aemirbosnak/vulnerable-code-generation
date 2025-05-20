//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_MIN -30
#define TEMP_MAX 40

#define PRESSURE_MIN 900
#define PRESSURE_MAX 1100

#define HUMIDITY_MIN 0
#define HUMIDITY_MAX 100

#define WIND_SPEED_MIN 0
#define WIND_SPEED_MAX 30

#define CLOUDINESS_MIN 0
#define CLOUDINESS_MAX 100

#define RAINFALL_MIN 0
#define RAINFALL_MAX 100

typedef struct {
    int temperature;
    int pressure;
    int humidity;
    int windSpeed;
    int cloudiness;
    int rainfall;
} Weather;

void generateRandomWeather(Weather *weather) {
    srand(time(NULL));

    weather->temperature = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    weather->pressure = rand() % (PRESSURE_MAX - PRESSURE_MIN + 1) + PRESSURE_MIN;
    weather->humidity = rand() % (HUMIDITY_MAX - HUMIDITY_MIN + 1) + HUMIDITY_MIN;
    weather->windSpeed = rand() % (WIND_SPEED_MAX - WIND_SPEED_MIN + 1) + WIND_SPEED_MIN;
    weather->cloudiness = rand() % (CLOUDINESS_MAX - CLOUDINESS_MIN + 1) + CLOUDINESS_MIN;
    weather->rainfall = rand() % (RAINFALL_MAX - RAINFALL_MIN + 1) + RAINFALL_MIN;
}

void printWeather(Weather weather) {
    printf("Temperature: %d\n", weather.temperature);
    printf("Pressure: %d\n", weather.pressure);
    printf("Humidity: %d\n", weather.humidity);
    printf("Wind Speed: %d\n", weather.windSpeed);
    printf("Cloudiness: %d\n", weather.cloudiness);
    printf("Rainfall: %d\n", weather.rainfall);
}

int main() {
    int numWeeks;
    printf("Enter the number of weeks to simulate: ");
    scanf("%d", &numWeeks);

    Weather weather;
    for (int i = 0; i < numWeeks; i++) {
        generateRandomWeather(&weather);
        printWeather(weather);
        printf("\n");
    }

    return 0;
}