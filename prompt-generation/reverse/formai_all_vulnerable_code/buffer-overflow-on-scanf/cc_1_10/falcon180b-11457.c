//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

typedef struct {
    char name[20];
    int temperature[MAX_DAYS];
    int humidity[MAX_DAYS];
} City;

void generateWeather(City *city) {
    for (int i = 0; i < MAX_DAYS; i++) {
        city->temperature[i] = rand() % 31 - 15;
        city->humidity[i] = rand() % 101;
    }
}

void printWeather(City city) {
    printf("City: %s\n", city.name);
    printf("Weather forecast for the next 30 days:\n");
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("Day %d: Temperature - %d°C, Humidity - %d%%\n", i+1, city.temperature[i], city.humidity[i]);
    }
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];

    int numCities;
    printf("Enter the number of cities you want to simulate: ");
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
        generateWeather(&cities[i]);
    }

    int numDays;
    printf("Enter the number of days you want to forecast: ");
    scanf("%d", &numDays);

    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numDays; j++) {
            printf("%s - Day %d: Temperature - %d°C, Humidity - %d%%\n", cities[i].name, j+1, cities[i].temperature[j], cities[i].humidity[j]);
        }
        printf("\n");
    }

    return 0;
}