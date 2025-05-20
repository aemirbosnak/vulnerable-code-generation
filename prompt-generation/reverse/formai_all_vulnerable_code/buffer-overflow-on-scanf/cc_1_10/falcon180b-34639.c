//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITY 10
#define DAY_IN_YEAR 365
#define HOUR_IN_DAY 24

typedef struct {
    char name[20];
    int temperature;
    int humidity;
} City;

void initCity(City *city) {
    strcpy(city->name, "Unknown");
    city->temperature = 0;
    city->humidity = 0;
}

void printCity(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d\n", city.temperature);
    printf("Humidity: %d\n\n", city.humidity);
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITY];
    int numCities = 0;

    while (numCities < MAX_CITY) {
        char input[50];
        printf("Enter a city name (or type 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        strcpy(cities[numCities].name, input);
        initCity(&cities[numCities]);
        numCities++;
    }

    int day = 0;

    while (day < DAY_IN_YEAR) {
        for (int i = 0; i < numCities; i++) {
            cities[i].temperature = rand() % 101 - 50;
            cities[i].humidity = rand() % 101;
        }

        printf("Day %d\n", day + 1);

        for (int hour = 0; hour < HOUR_IN_DAY; hour++) {
            for (int i = 0; i < numCities; i++) {
                printf("City: %s - ", cities[i].name);
                printCity(cities[i]);
            }
        }

        day++;
        printf("\n");
    }

    return 0;
}