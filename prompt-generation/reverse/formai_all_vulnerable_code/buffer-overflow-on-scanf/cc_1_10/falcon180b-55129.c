//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_CITIES 10
#define DAYS_IN_WEEK 7

struct City {
    char name[20];
    int temp;
    int humidity;
};

void generateWeather(struct City* cities, int numCities) {
    srand(time(NULL));
    for (int i = 0; i < numCities; i++) {
        cities[i].temp = rand() % 101;
        cities[i].humidity = rand() % 101;
    }
}

void printWeather(struct City* cities, int numCities) {
    for (int i = 0; i < numCities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Temperature: %d\n", cities[i].temp);
        printf("Humidity: %d\n\n", cities[i].humidity);
    }
}

int main() {
    struct City cities[NUM_CITIES];
    char cityNames[NUM_CITIES][20];
    int i, j;

    // Get the names of the cities from the user
    printf("Enter the names of %d cities:\n", NUM_CITIES);
    for (i = 0; i < NUM_CITIES; i++) {
        scanf("%s", cityNames[i]);
        strcpy(cities[i].name, cityNames[i]);
    }

    // Generate weather for the cities
    generateWeather(cities, NUM_CITIES);

    // Print the weather for each city
    for (i = 0; i < DAYS_IN_WEEK; i++) {
        printf("Day %d:\n", i+1);
        printWeather(cities, NUM_CITIES);
        printf("\n");
    }

    return 0;
}