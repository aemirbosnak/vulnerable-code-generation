//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int precipitation;
} City;

void generateRandomWeather(City* city, int minTemp, int maxTemp, int minHum, int maxHum, int minPrec, int maxPrec) {
    city->temperature = rand() % (maxTemp - minTemp + 1) + minTemp;
    city->humidity = rand() % (maxHum - minHum + 1) + minHum;
    city->precipitation = rand() % (maxPrec - minPrec + 1) + minPrec;
}

void printCityWeather(const City* city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d°C\n", city->temperature);
    printf("Humidity: %d%%\n", city->humidity);
    printf("Precipitation: %dmm\n\n", city->precipitation);
}

void simulateWeather(City cities[MAX_CITIES], int numCities, int numDays) {
    srand(time(NULL));

    for (int i = 0; i < numCities; i++) {
        generateRandomWeather(&cities[i], 0, 40, 20, 80, 0, 20);
    }

    for (int day = 1; day <= numDays; day++) {
        for (int i = 0; i < numCities; i++) {
            cities[i].temperature += rand() % 6 - 3;
            cities[i].humidity += rand() % 6 - 3;
            cities[i].precipitation += rand() % 6 - 3;
        }
    }

    for (int i = 0; i < numCities; i++) {
        printCityWeather(&cities[i]);
    }
}

int main() {
    City cities[MAX_CITIES];

    int numCities, numDays;

    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
    }

    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);

    simulateWeather(cities, numCities, numDays);

    return 0;
}