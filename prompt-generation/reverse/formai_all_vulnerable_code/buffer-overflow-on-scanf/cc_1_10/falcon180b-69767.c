//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 14

struct City {
    char name[20];
    int temperature[MAX_DAYS];
    int humidity[MAX_DAYS];
    int precipitation[MAX_DAYS];
};

void generateWeather(struct City *cities, int numCities, int numDays) {
    srand(time(NULL));
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numDays; j++) {
            cities[i].temperature[j] = rand() % 41 + 5;
            cities[i].humidity[j] = rand() % 101;
            cities[i].precipitation[j] = rand() % 4;
        }
    }
}

void printWeather(struct City *cities, int numCities, int numDays) {
    for (int i = 0; i < numCities; i++) {
        printf("Weather forecast for %s:\n", cities[i].name);
        for (int j = 0; j < numDays; j++) {
            printf("Day %d: Temperature %d°C, Humidity %d%, Precipitation %d\n", j + 1, cities[i].temperature[j], cities[i].humidity[j], cities[i].precipitation[j]);
        }
        printf("\n");
    }
}

int main() {
    struct City cities[MAX_CITIES];
    int numCities, numDays;

    printf("Enter the number of cities (up to %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    printf("Enter the number of days to forecast (up to %d): ", MAX_DAYS);
    scanf("%d", &numDays);

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    generateWeather(cities, numCities, numDays);
    printWeather(cities, numCities, numDays);

    return 0;
}