//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: visionary
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
    int pressure;
} City;

City cities[MAX_CITIES];
int numCities;

void generateRandomCity(City *city) {
    city->temperature = rand() % 50 + 1;
    city->humidity = rand() % 100;
    city->windSpeed = rand() % 20 + 1;
    city->pressure = rand() % 30 + 1;
}

void generateRandomCities(int numCities) {
    srand(time(NULL));
    for (int i = 0; i < numCities; i++) {
        generateRandomCity(&cities[i]);
        strcpy(cities[i].name, "City ");
        cities[i].name[6] = '0' + i;
    }
}

void printCityInfo(City *city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d\n", city->temperature);
    printf("Humidity: %d%%\n", city->humidity);
    printf("Wind Speed: %d km/h\n", city->windSpeed);
    printf("Air Pressure: %d hPa\n", city->pressure);
    printf("\n");
}

void printWeatherForecast(int numDays, int interval) {
    for (int i = 0; i < numDays; i += interval) {
        printf("Day %d:\n", i + 1);
        for (int j = 0; j < numCities; j++) {
            printCityInfo(&cities[j]);
        }
    }
}

int main() {
    int numCities, numDays, interval;

    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    printf("Enter the number of days for the weather forecast: ");
    scanf("%d", &numDays);

    printf("Enter the interval between weather updates (in days): ");
    scanf("%d", &interval);

    generateRandomCities(numCities);

    printf("Weather forecast for the next %d days:\n", numDays);
    printWeatherForecast(numDays, interval);

    return 0;
}