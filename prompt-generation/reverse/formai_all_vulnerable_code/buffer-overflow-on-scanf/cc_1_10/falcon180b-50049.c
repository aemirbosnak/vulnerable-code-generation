//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    int temperature;
    int precipitation;
} City;

void generateRandomWeather(City* city, int minTemp, int maxTemp, int minPrecip, int maxPrecip) {
    city->temperature = rand() % (maxTemp - minTemp + 1) + minTemp;
    city->precipitation = rand() % (maxPrecip - minPrecip + 1) + minPrecip;
}

void printCityWeather(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d degrees\n", city.temperature);
    printf("Precipitation: %d mm\n\n", city.precipitation);
}

void printWeatherReport(City* cities, int numCities, int day) {
    printf("Weather report for day %d:\n", day);
    for (int i = 0; i < numCities; i++) {
        printCityWeather(cities[i]);
    }
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];
    int numCities = 0;

    printf("Enter city names (up to %d cities):\n", MAX_CITIES - 1);
    while (numCities < MAX_CITIES && scanf("%s", cities[numCities].name)!= EOF) {
        numCities++;
    }

    printf("Enter minimum and maximum temperatures (in degrees Celsius):\n");
    scanf("%d %d", &cities[0].temperature, &cities[0].temperature);

    printf("Enter minimum and maximum precipitation (in mm):\n");
    scanf("%d %d", &cities[0].precipitation, &cities[0].precipitation);

    for (int i = 1; i < numCities; i++) {
        generateRandomWeather(&cities[i], cities[0].temperature, cities[0].temperature, cities[0].precipitation, cities[0].precipitation);
    }

    int numDays;
    printf("Enter number of days to simulate (up to %d days):\n", MAX_DAYS);
    scanf("%d", &numDays);

    for (int day = 1; day <= numDays; day++) {
        printWeatherReport(cities, numCities, day);
    }

    return 0;
}