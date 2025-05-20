//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 7

struct City {
    char name[20];
    int temperature;
    int humidity;
};

void generateRandomWeather(struct City *cities, int numCities, int numDays) {
    srand(time(0));

    for (int i = 0; i < numCities; i++) {
        cities[i].temperature = rand() % 30 + 1;
        cities[i].humidity = rand() % 100;
    }

    for (int i = 0; i < numDays; i++) {
        for (int j = 0; j < numCities; j++) {
            cities[j].temperature += rand() % 3 - 1;
            cities[j].humidity += rand() % 5;
        }
    }
}

void printWeatherReport(struct City *cities, int numCities, int numDays) {
    printf("Weather Report for %d days:\n", numDays);

    for (int i = 0; i < numCities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Average Temperature: %.2f\n", cities[i].temperature / numDays);
        printf("Average Humidity: %.2f\n\n", cities[i].humidity / numDays);
    }
}

int main() {
    struct City cities[NUM_CITIES];

    printf("Enter the names of %d cities:\n", NUM_CITIES);

    for (int i = 0; i < NUM_CITIES; i++) {
        scanf("%s", cities[i].name);
    }

    generateRandomWeather(cities, NUM_CITIES, NUM_DAYS);
    printWeatherReport(cities, NUM_CITIES, NUM_DAYS);

    return 0;
}