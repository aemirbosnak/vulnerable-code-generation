//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MIN_TEMP -30
#define MAX_TEMP 40
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100

typedef struct {
    char name[20];
    int days;
    int temperature[MAX_DAYS];
    int humidity[MAX_DAYS];
} WeatherData;

void generateWeather(WeatherData *data) {
    srand(time(NULL));
    for (int i = 0; i < data->days; i++) {
        data->temperature[i] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        data->humidity[i] = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
    }
}

void printWeather(WeatherData *data) {
    printf("Weather Data for %s:\n", data->name);
    printf("Days: %d\n", data->days);
    printf("Temperature:\n");
    for (int i = 0; i < data->days; i++) {
        printf("%d: %d\n", i + 1, data->temperature[i]);
    }
    printf("Humidity:\n");
    for (int i = 0; i < data->days; i++) {
        printf("%d: %d\n", i + 1, data->humidity[i]);
    }
}

int main() {
    WeatherData data;
    printf("Enter location name: ");
    scanf("%s", data.name);
    printf("Enter number of days to simulate: ");
    scanf("%d", &data.days);

    generateWeather(&data);
    printWeather(&data);

    return 0;
}