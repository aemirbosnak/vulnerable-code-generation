//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: random
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

City cities[MAX_CITIES];

void generateRandomCity(City *city) {
    city->temperature = rand() % 50 + 1;
    city->humidity = rand() % 100;
    city->windSpeed = rand() % 50 + 1;
}

void printCity(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d\n", city.temperature);
    printf("Humidity: %d%%\n", city.humidity);
    printf("Wind Speed: %d\n", city.windSpeed);
}

int main() {
    srand(time(NULL));

    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        generateRandomCity(&cities[i]);
    }

    int numDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);

    for (int day = 1; day <= numDays; day++) {
        for (int i = 0; i < numCities; i++) {
            City *city = &cities[i];
            city->temperature += rand() % 5 - 2;
            city->humidity += rand() % 10;
            city->windSpeed += rand() % 5 - 2;

            if (city->temperature < 0) {
                city->temperature = 0;
            } else if (city->temperature > 50) {
                city->temperature = 50;
            }

            if (city->humidity < 0) {
                city->humidity = 0;
            } else if (city->humidity > 100) {
                city->humidity = 100;
            }

            if (city->windSpeed < 0) {
                city->windSpeed = 0;
            } else if (city->windSpeed > 50) {
                city->windSpeed = 50;
            }
        }
    }

    printf("\nResults:\n");
    for (int i = 0; i < numCities; i++) {
        printCity(cities[i]);
    }

    return 0;
}