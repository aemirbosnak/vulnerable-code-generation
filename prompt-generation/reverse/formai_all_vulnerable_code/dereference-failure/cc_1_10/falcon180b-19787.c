//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_CITIES 5
#define NUM_DAYS 30

struct City {
    char name[20];
    int temperature;
    int humidity;
};

void generateRandomWeather(struct City* city, int minTemp, int maxTemp, int minHum, int maxHum) {
    city->temperature = rand() % (maxTemp - minTemp + 1) + minTemp;
    city->humidity = rand() % (maxHum - minHum + 1) + minHum;
}

void printWeatherReport(struct City* cities, int numCities) {
    printf("Weather Report for %d Days:\n", NUM_DAYS);
    for (int i = 0; i < numCities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Temperature: %d\n", cities[i].temperature);
        printf("Humidity: %d\n\n", cities[i].humidity);
    }
}

int main() {
    srand(time(NULL));

    struct City cities[NUM_CITIES];

    for (int i = 0; i < NUM_CITIES; i++) {
        strcpy(cities[i].name, "City ");
        char numStr[3];
        sprintf(numStr, "%d", i + 1);
        strcat(cities[i].name, numStr);
    }

    for (int i = 0; i < NUM_CITIES; i++) {
        generateRandomWeather(&cities[i], 50, 90, 20, 80);
    }

    for (int day = 1; day <= NUM_DAYS; day++) {
        printf("Day %d:\n", day);
        printWeatherReport(cities, NUM_CITIES);
        printf("\n");
    }

    return 0;
}