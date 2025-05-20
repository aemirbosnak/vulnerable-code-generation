//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_WEATHER_TYPES 10
#define MAX_CITY_SIZE 50

typedef struct {
    char name[MAX_CITY_SIZE];
    int temperature;
    int humidity;
    int windSpeed;
    int weatherType;
} City;

void generateWeather(City* city) {
    int weatherType = rand() % MAX_WEATHER_TYPES;
    switch(weatherType) {
        case 0:
            city->weatherType = "Sunny";
            break;
        case 1:
            city->weatherType = "Partly Cloudy";
            break;
        case 2:
            city->weatherType = "Rainy";
            break;
        case 3:
            city->weatherType = "Thunderstorm";
            break;
        case 4:
            city->weatherType = "Snowy";
            break;
        default:
            city->weatherType = "Unknown";
            break;
    }
}

int main() {
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    City* cities = (City*)malloc(numCities * sizeof(City));

    for(int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
        cities[i].temperature = rand() % 101;
        cities[i].humidity = rand() % 101;
        cities[i].windSpeed = rand() % 101;
        generateWeather(&cities[i]);
    }

    for(int i = 0; i < numCities; i++) {
        printf("City %d: %s\n", i+1, cities[i].name);
        printf("Temperature: %d\n", cities[i].temperature);
        printf("Humidity: %d\n", cities[i].humidity);
        printf("Wind Speed: %d\n", cities[i].windSpeed);
        printf("Weather Type: %s\n\n", cities[i].weatherType);
    }

    free(cities);
    return 0;
}