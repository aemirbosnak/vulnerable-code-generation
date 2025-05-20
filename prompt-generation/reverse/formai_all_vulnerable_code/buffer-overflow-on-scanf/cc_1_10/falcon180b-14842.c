//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_CITIES 100
#define MAX_DAYS 30

struct City {
    char name[20];
    double latitude;
    double longitude;
};

struct Day {
    int temperature[MAX_CITIES];
    int humidity[MAX_CITIES];
    int windSpeed[MAX_CITIES];
};

void generateRandomCity(struct City *city) {
    city->latitude = (double)rand() / RAND_MAX * 180 - 90;
    city->longitude = (double)rand() / RAND_MAX * 360 - 180;
}

void generateWeather(struct Day *day, int cityIndex) {
    double temperature = rand() % 40 + 1;
    double humidity = rand() % 101;
    double windSpeed = rand() % 51 + 1;

    day->temperature[cityIndex] = (int)temperature;
    day->humidity[cityIndex] = humidity;
    day->windSpeed[cityIndex] = windSpeed;
}

void printCity(struct City *city) {
    printf("City: %s\n", city->name);
    printf("Latitude: %.2f\n", city->latitude);
    printf("Longitude: %.2f\n", city->longitude);
}

void printDay(struct Day *day, int cityIndex) {
    printf("Day %d in %s:\n", day->temperature[cityIndex], day->humidity[cityIndex]);
    printf("Temperature: %d degrees Celsius\n", day->temperature[cityIndex]);
    printf("Humidity: %d%%\n", day->humidity[cityIndex]);
    printf("Wind speed: %d km/h\n\n", day->windSpeed[cityIndex]);
}

int main() {
    srand(time(NULL));

    struct City cities[MAX_CITIES];
    int numCities = 0;

    printf("Enter city names (up to %d):\n", MAX_CITIES);
    while (numCities < MAX_CITIES && scanf("%s", cities[numCities].name) == 1) {
        generateRandomCity(&cities[numCities]);
        numCities++;
    }

    struct Day days[MAX_DAYS];
    int numDays = 0;

    printf("Enter number of days to simulate (up to %d):\n", MAX_DAYS);
    scanf("%d", &numDays);

    for (int i = 0; i < numDays; i++) {
        printf("Day %d:\n", i + 1);
        for (int j = 0; j < numCities; j++) {
            generateWeather(&days[i], j);
            printDay(&days[i], j);
        }
    }

    return 0;
}