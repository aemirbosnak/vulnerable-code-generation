//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_WEATHER_TYPES 10

typedef struct {
    char name[50];
    int temperature;
    int humidity;
    int wind;
    int precipitation;
    int pressure;
} Weather;

typedef struct {
    int x;
    int y;
    Weather weather;
} City;

City cities[MAX_CITIES];
int numCities = 0;

void generateRandomWeather(Weather *weather) {
    weather->temperature = rand() % 101;
    weather->humidity = rand() % 101;
    weather->wind = rand() % 101;
    weather->precipitation = rand() % 101;
    weather->pressure = rand() % 101;
}

void generateRandomCity(City *city) {
    city->x = rand() % 1001;
    city->y = rand() % 1001;
    generateRandomWeather(&city->weather);
}

void generateRandomCities(int numCities) {
    srand(time(NULL));
    for (int i = 0; i < numCities; i++) {
        City city;
        generateRandomCity(&city);
        cities[i] = city;
    }
}

void printCity(City city) {
    printf("City: %s\n", city.weather.name);
    printf("Temperature: %d\n", city.weather.temperature);
    printf("Humidity: %d\n", city.weather.humidity);
    printf("Wind: %d\n", city.weather.wind);
    printf("Precipitation: %d\n", city.weather.precipitation);
    printf("Pressure: %d\n", city.weather.pressure);
}

void printCities() {
    printf("Number of cities: %d\n", numCities);
    for (int i = 0; i < numCities; i++) {
        printCity(cities[i]);
    }
}

int main() {
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    generateRandomCities(numCities);
    printCities();
    return 0;
}