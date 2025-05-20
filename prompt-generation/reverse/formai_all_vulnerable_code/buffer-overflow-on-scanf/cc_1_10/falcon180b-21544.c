//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[50];
    int temperature;
    int humidity;
    int windSpeed;
} City;

void generateRandomCity(City *city) {
    city->temperature = rand() % 100;
    city->humidity = rand() % 100;
    city->windSpeed = rand() % 100;
}

void printCity(City city) {
    printf("%s: Temperature %dC, Humidity %d%%\n", city.name, city.temperature, city.humidity);
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];
    int numCities;

    printf("Enter number of cities: ");
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generateRandomCity(&cities[i]);
    }

    int numDays;

    printf("Enter number of days to simulate: ");
    scanf("%d", &numDays);

    for (int day = 1; day <= numDays; day++) {
        for (int i = 0; i < numCities; i++) {
            cities[i].temperature += rand() % 10 - 5;
            cities[i].humidity += rand() % 10;
            cities[i].windSpeed += rand() % 10;

            if (cities[i].temperature > 40) {
                cities[i].temperature = 40;
            } else if (cities[i].temperature < 0) {
                cities[i].temperature = 0;
            }

            if (cities[i].humidity > 100) {
                cities[i].humidity = 100;
            } else if (cities[i].humidity < 0) {
                cities[i].humidity = 0;
            }

            if (cities[i].windSpeed > 50) {
                cities[i].windSpeed = 50;
            } else if (cities[i].windSpeed < 0) {
                cities[i].windSpeed = 0;
            }
        }

        printf("\nDay %d\n", day);
        for (int i = 0; i < numCities; i++) {
            printCity(cities[i]);
        }
    }

    return 0;
}