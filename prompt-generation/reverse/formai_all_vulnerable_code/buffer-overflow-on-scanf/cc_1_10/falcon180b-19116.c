//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define DAY_HOURS 24

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int windSpeed;
} City;

void generateRandomWeather(City *city) {
    city->temperature = rand() % 40 + 10;
    city->humidity = rand() % 100;
    city->windSpeed = rand() % 20 + 1;
}

void printWeather(City *city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d°C\n", city->temperature);
    printf("Humidity: %d%%\n", city->humidity);
    printf("Wind Speed: %d m/s\n\n", city->windSpeed);
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];
    int numCities = 0;

    while (numCities < MAX_CITIES) {
        printf("Enter the name of a city (or type 'done' to finish): ");
        scanf("%s", cities[numCities].name);

        if (strcmp(cities[numCities].name, "done") == 0) {
            break;
        }

        numCities++;
    }

    printf("\nWeather Forecast for the Next %d Hours:\n", DAY_HOURS);

    for (int i = 0; i < DAY_HOURS; i++) {
        for (int j = 0; j < numCities; j++) {
            generateRandomWeather(&cities[j]);
            printWeather(&cities[j]);
        }
    }

    return 0;
}