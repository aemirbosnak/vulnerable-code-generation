//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    int temperature[MAX_DAYS];
    int humidity[MAX_DAYS];
    int precipitation[MAX_DAYS];
} City;

void generateRandomWeather(City *city) {
    int i;
    for (i = 0; i < MAX_DAYS; i++) {
        city->temperature[i] = rand() % 50 + 1;
        city->humidity[i] = rand() % 101;
        city->precipitation[i] = rand() % 101;
    }
}

void printWeatherReport(City *city) {
    int i;
    printf("Weather report for %s:\n", city->name);
    for (i = 0; i < MAX_DAYS; i++) {
        printf("Day %d: Temperature %d°C, Humidity %d%, Precipitation %dmm\n", i + 1, city->temperature[i], city->humidity[i], city->precipitation[i]);
    }
}

int main() {
    int numCities, i;
    City cities[MAX_CITIES];

    srand(time(NULL));

    printf("Enter the number of cities (up to %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    printf("Enter the names of the cities:\n");
    for (i = 0; i < numCities; i++) {
        scanf("%s", cities[i].name);
        generateRandomWeather(&cities[i]);
    }

    printf("Weather reports:\n");
    for (i = 0; i < numCities; i++) {
        printWeatherReport(&cities[i]);
    }

    return 0;
}