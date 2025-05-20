//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct City {
    char name[20];
    int temperature[MAX_DAYS];
    int humidity[MAX_DAYS];
};

void generateWeather(struct City *cities, int numCities, int startDay, int endDay);
void printWeather(struct City *cities, int numCities, int day);

int main() {
    struct City cities[MAX_CITIES];
    int numCities, i;

    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    for (i = 0; i < numCities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
    }

    srand(time(NULL));
    generateWeather(cities, numCities, 1, MAX_DAYS);

    printf("\nWeather forecast for %d days:\n", MAX_DAYS);
    for (i = 1; i <= MAX_DAYS; i++) {
        printWeather(cities, numCities, i);
    }

    return 0;
}

void generateWeather(struct City *cities, int numCities, int startDay, int endDay) {
    int i, j;
    for (i = 0; i < numCities; i++) {
        for (j = startDay; j <= endDay; j++) {
            cities[i].temperature[j] = rand() % 41 - 20;
            cities[i].humidity[j] = rand() % 101;
        }
    }
}

void printWeather(struct City *cities, int numCities, int day) {
    int i;
    printf("\nDay %d:\n", day);
    for (i = 0; i < numCities; i++) {
        printf("%s: Temperature %d°C, Humidity %d%%\n", cities[i].name, cities[i].temperature[day], cities[i].humidity[day]);
    }
}