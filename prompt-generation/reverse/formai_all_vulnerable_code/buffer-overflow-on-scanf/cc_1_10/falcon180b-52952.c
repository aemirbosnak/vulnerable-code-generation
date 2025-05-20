//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

struct City {
    char name[50];
    int temperature;
    int humidity;
};

void generateRandomWeather(struct City* city, int minTemp, int maxTemp, int minHum, int maxHum) {
    city->temperature = rand() % (maxTemp - minTemp + 1) + minTemp;
    city->humidity = rand() % (maxHum - minHum + 1) + minHum;
}

void printCityWeather(struct City* city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d degrees Celsius\n", city->temperature);
    printf("Humidity: %d%%\n\n", city->humidity);
}

int main() {
    srand(time(0));

    struct City cities[MAX_CITIES];
    int numCities;

    printf("Welcome to the Weather Simulator!\n");
    printf("How many cities would you like to simulate? (Maximum %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    printf("Enter city names:\n");
    for (int i = 0; i < numCities; i++) {
        scanf("%s", cities[i].name);
        generateRandomWeather(&cities[i], 0, 40, 20, 80);
    }

    int numDays;

    printf("\nHow many days would you like to simulate? (Maximum %d): ", MAX_DAYS);
    scanf("%d", &numDays);

    for (int day = 1; day <= numDays; day++) {
        printf("\nDay %d:\n", day);
        for (int i = 0; i < numCities; i++) {
            printCityWeather(&cities[i]);
        }
    }

    return 0;
}