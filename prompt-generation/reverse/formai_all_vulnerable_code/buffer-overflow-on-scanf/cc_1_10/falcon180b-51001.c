//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 7

struct City {
    char name[30];
    int temperature[MAX_DAYS];
};

struct City cities[MAX_CITIES];

void generateRandomWeather(int cityIndex) {
    srand(time(NULL));
    for (int i = 0; i < MAX_DAYS; i++) {
        cities[cityIndex].temperature[i] = rand() % 41 - 20;
    }
}

void printCityWeather(int cityIndex) {
    printf("City: %s\n", cities[cityIndex].name);
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("Day %d: %dC\n", i + 1, cities[cityIndex].temperature[i]);
    }
}

int main() {
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generateRandomWeather(i);
    }

    int numDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);

    for (int i = 0; i < numDays; i++) {
        for (int j = 0; j < numCities; j++) {
            printCityWeather(j);
        }
    }

    return 0;
}