//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 7

typedef struct {
    char name[20];
    int temperature[NUM_DAYS];
    int humidity[NUM_DAYS];
    int precipitation[NUM_DAYS];
} City;

void generateRandomWeather(City* city) {
    srand(time(NULL));

    for (int i = 0; i < NUM_DAYS; i++) {
        city->temperature[i] = rand() % 31 + 1;
        city->humidity[i] = rand() % 101;
        city->precipitation[i] = rand() % 11;
    }
}

void printCityWeather(City* city) {
    printf("City: %s\n", city->name);
    printf("Weather Forecast for the next 7 days:\n");

    for (int i = 0; i < NUM_DAYS; i++) {
        printf("Day %d: Temperature - %d°C, Humidity - %d%, Precipitation - %dmm\n",
               i + 1, city->temperature[i], city->humidity[i], city->precipitation[i]);
    }
}

int main() {
    City cities[NUM_CITIES];

    printf("Enter the names of %d cities:\n", NUM_CITIES);

    for (int i = 0; i < NUM_CITIES; i++) {
        scanf("%s", cities[i].name);
        generateRandomWeather(&cities[i]);
    }

    printf("\nWeather forecast for the next 7 days:\n");

    for (int i = 0; i < NUM_CITIES; i++) {
        printCityWeather(&cities[i]);
    }

    return 0;
}