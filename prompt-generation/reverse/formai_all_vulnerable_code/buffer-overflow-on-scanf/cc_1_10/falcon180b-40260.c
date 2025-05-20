//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100

typedef struct {
    char name[20];
    int temperature;
    int windSpeed;
    int humidity;
} City;

void generateWeather(City *cities, int numCities) {
    for (int i = 0; i < numCities; i++) {
        cities[i].temperature = rand() % 50 + 1;
        cities[i].windSpeed = rand() % 20 + 1;
        cities[i].humidity = rand() % 100;
    }
}

void printWeather(City *cities, int numCities) {
    for (int i = 0; i < numCities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Temperature: %d degrees Celsius\n", cities[i].temperature);
        printf("Wind Speed: %d km/h\n", cities[i].windSpeed);
        printf("Humidity: %d%%\n\n", cities[i].humidity);
    }
}

int main() {
    srand(time(NULL));
    City cities[MAX_CITIES];
    int numCities;

    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    if (numCities > MAX_CITIES) {
        printf("Error: Maximum number of cities is %d.\n", MAX_CITIES);
        return 1;
    }

    printf("Enter the names of the cities:\n");
    for (int i = 0; i < numCities; i++) {
        scanf("%s", cities[i].name);
    }

    generateWeather(cities, numCities);
    printWeather(cities, numCities);

    return 0;
}