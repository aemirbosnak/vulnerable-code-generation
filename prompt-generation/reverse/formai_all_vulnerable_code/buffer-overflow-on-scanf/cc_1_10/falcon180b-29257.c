//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct City {
    char name[20];
    int population;
    int temperature;
    int humidity;
};

void generateCities(struct City cities[], int numCities) {
    for (int i = 0; i < numCities; i++) {
        sprintf(cities[i].name, "City %d", i + 1);
        cities[i].population = rand() % 1000000;
        cities[i].temperature = rand() % 50 - 25;
        cities[i].humidity = rand() % 100;
    }
}

void printCity(struct City city) {
    printf("Name: %s\n", city.name);
    printf("Population: %d\n", city.population);
    printf("Temperature: %d°C\n", city.temperature);
    printf("Humidity: %d%%\n\n", city.humidity);
}

void simulateWeather(struct City cities[], int numCities, int days) {
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < days; j++) {
            cities[i].temperature += rand() % 10 - 5;
            cities[i].humidity += rand() % 10 - 5;
        }
    }
}

int main() {
    srand(time(NULL));

    int numCities;
    printf("Enter the number of cities (1 to %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    struct City cities[numCities];
    generateCities(cities, numCities);

    int days;
    printf("Enter the number of days to simulate (1 to %d): ", MAX_DAYS);
    scanf("%d", &days);

    simulateWeather(cities, numCities, days);

    printf("Weather simulation results:\n");
    for (int i = 0; i < numCities; i++) {
        printCity(cities[i]);
    }

    return 0;
}