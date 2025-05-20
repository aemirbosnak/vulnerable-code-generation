//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 365

struct City {
    char name[20];
    int temperature[MAX_DAYS];
    int precipitation[MAX_DAYS];
};

void generateWeather(struct City *city) {
    int i;
    srand(time(NULL));

    for (i = 0; i < MAX_DAYS; i++) {
        city->temperature[i] = rand() % 100;
        city->precipitation[i] = rand() % 10;
    }
}

void printCityWeather(struct City *city) {
    int i;

    printf("Weather in %s:\n", city->name);

    for (i = 0; i < MAX_DAYS; i++) {
        printf("Day %d: Temperature %d°C, Precipitation %d mm\n", i + 1, city->temperature[i], city->precipitation[i]);
    }
}

int main() {
    struct City cities[MAX_CITIES];
    int numCities, i;

    printf("Enter the number of cities (up to %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    printf("Enter the names of the cities:\n");
    for (i = 0; i < numCities; i++) {
        scanf("%s", cities[i].name);
        generateWeather(&cities[i]);
    }

    printf("Weather forecast for the next 365 days:\n");
    for (i = 0; i < numCities; i++) {
        printCityWeather(&cities[i]);
    }

    return 0;
}