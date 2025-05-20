//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 10
#define MAX_TEMP 100
#define MIN_TEMP -50

typedef struct {
    char name[20];
    int temp[NUM_DAYS];
    int humidity[NUM_DAYS];
    int windSpeed[NUM_DAYS];
} City;

void generateWeather(City *cities) {
    for (int i = 0; i < NUM_CITIES; i++) {
        for (int j = 0; j < NUM_DAYS; j++) {
            int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            int humidity = rand() % 101;
            int windSpeed = rand() % 51;

            cities[i].temp[j] = temp;
            cities[i].humidity[j] = humidity;
            cities[i].windSpeed[j] = windSpeed;
        }
    }
}

void printWeather(City *cities) {
    for (int i = 0; i < NUM_CITIES; i++) {
        printf("City: %s\n", cities[i].name);
        for (int j = 0; j < NUM_DAYS; j++) {
            printf("Day %d: Temperature: %d, Humidity: %d, Wind Speed: %d\n", j + 1, cities[i].temp[j], cities[i].humidity[j], cities[i].windSpeed[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    City cities[NUM_CITIES];

    for (int i = 0; i < NUM_CITIES; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
    }

    generateWeather(cities);
    printWeather(cities);

    return 0;
}