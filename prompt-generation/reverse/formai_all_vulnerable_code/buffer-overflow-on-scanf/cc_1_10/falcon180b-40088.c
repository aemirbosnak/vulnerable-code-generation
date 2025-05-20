//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 365

typedef struct {
    char name[50];
    int temperature;
    int humidity;
    int windSpeed;
} City;

void generateRandomWeather(City *city) {
    city->temperature = rand() % 101; // Random temperature between 0 and 100
    city->humidity = rand() % 101; // Random humidity between 0 and 100
    city->windSpeed = rand() % 101; // Random wind speed between 0 and 100
}

void printCityWeather(City *city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d\n", city->temperature);
    printf("Humidity: %d\n", city->humidity);
    printf("Wind Speed: %d\n\n", city->windSpeed);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    City cities[MAX_CITIES];
    int numCities;

    printf("Enter the number of cities (maximum %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf(" %[^\n]", cities[i].name);
    }

    int days;
    printf("Enter the number of days to simulate (maximum %d): ", MAX_DAYS);
    scanf("%d", &days);

    printf("\n");

    for (int day = 1; day <= days; day++) {
        for (int i = 0; i < numCities; i++) {
            generateRandomWeather(&cities[i]);
            printCityWeather(&cities[i]);
        }
    }

    return 0;
}