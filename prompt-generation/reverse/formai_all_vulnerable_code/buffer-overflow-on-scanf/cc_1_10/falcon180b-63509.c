//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 50
#define MAX_WEATHER_TYPES 5

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int windSpeed;
    int weatherType;
} City;

void generateWeather(City *city, int weatherType) {
    switch (weatherType) {
        case 0: // Sunny
            city->temperature = rand() % 30 + 70;
            city->humidity = rand() % 41 + 20;
            city->windSpeed = rand() % 11 + 1;
            city->weatherType = 0;
            break;
        case 1: // Cloudy
            city->temperature = rand() % 20 + 60;
            city->humidity = rand() % 71 + 30;
            city->windSpeed = rand() % 21 + 1;
            city->weatherType = 1;
            break;
        case 2: // Rainy
            city->temperature = rand() % 10 + 50;
            city->humidity = rand() % 81 + 40;
            city->windSpeed = rand() % 31 + 1;
            city->weatherType = 2;
            break;
        case 3: // Thunderstorm
            city->temperature = rand() % 20 + 60;
            city->humidity = rand() % 71 + 30;
            city->windSpeed = rand() % 41 + 1;
            city->weatherType = 3;
            break;
        case 4: // Snowy
            city->temperature = rand() % 10 + 30;
            city->humidity = rand() % 61 + 20;
            city->windSpeed = rand() % 11 + 1;
            city->weatherType = 4;
            break;
    }
}

void printCity(City *city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d\n", city->temperature);
    printf("Humidity: %d\n", city->humidity);
    printf("Wind Speed: %d\n", city->windSpeed);
    printf("Weather Type: %s\n", (city->weatherType == 0)? "Sunny" : (city->weatherType == 1)? "Cloudy" : (city->weatherType == 2)? "Rainy" : (city->weatherType == 3)? "Thunderstorm" : "Snowy");
    printf("\n");
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    City cities[numCities];

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    for (int i = 0; i < numCities; i++) {
        generateWeather(&cities[i], rand() % MAX_WEATHER_TYPES);
    }

    printf("Weather Simulation\n");
    for (int i = 0; i < numCities; i++) {
        printCity(&cities[i]);
    }

    return 0;
}