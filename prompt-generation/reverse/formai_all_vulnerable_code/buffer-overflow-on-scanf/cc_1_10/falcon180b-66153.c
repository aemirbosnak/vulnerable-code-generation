//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_CITIES 100
#define MAX_HOURS 24
#define MAX_MINUTES 60

typedef struct {
    char name[20];
    int temperature;
    int humidity;
} City;

void generateRandomCity(City *city) {
    city->temperature = rand() % 101;
    city->humidity = rand() % 101;
}

void printCity(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d\n", city.temperature);
    printf("Humidity: %d\n", city.humidity);
}

int main() {
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    City cities[MAX_CITIES];
    for (int i = 0; i < numCities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generateRandomCity(&cities[i]);
    }

    int numHours;
    printf("Enter the number of hours to simulate: ");
    scanf("%d", &numHours);

    for (int i = 0; i < numHours; i++) {
        for (int j = 0; j < numCities; j++) {
            cities[j].temperature += rand() % 10 - 5;
            cities[j].humidity += rand() % 10 - 5;
        }
        for (int j = 0; j < numCities; j++) {
            printCity(cities[j]);
        }
        printf("\n");
    }

    return 0;
}