//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 5
#define MAX_DAYS 10

typedef struct {
    char name[20];
    int temperature;
    int humidity;
} City;

void generateRandomWeather(City city) {
    city.temperature = rand() % 50 + 10;
    city.humidity = rand() % 101;
}

void printCity(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d\n", city.temperature);
    printf("Humidity: %d\n", city.humidity);
    printf("\n");
}

int main() {
    srand(time(0));

    City cities[MAX_CITIES];
    int numCities;

    printf("Enter number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generateRandomWeather(cities[i]);
    }

    int numDays;

    printf("Enter number of days (max %d): ", MAX_DAYS);
    scanf("%d", &numDays);

    for (int i = 0; i < numDays; i++) {
        for (int j = 0; j < numCities; j++) {
            generateRandomWeather(cities[j]);
            printCity(cities[j]);
        }
    }

    return 0;
}