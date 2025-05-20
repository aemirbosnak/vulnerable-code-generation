//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CITIES 10
#define MAX_DAYS 365

struct City {
    char name[50];
    int temperature[MAX_DAYS];
    int precipitation[MAX_DAYS];
    int humidity[MAX_DAYS];
};

void generateWeather(struct City *city, int day) {
    int temperature = rand() % 30 + 1;
    int precipitation = rand() % 101;
    int humidity = rand() % 101;
    city->temperature[day] = temperature;
    city->precipitation[day] = precipitation;
    city->humidity[day] = humidity;
}

void printWeather(struct City *city, int day) {
    printf("On day %d in %s:\n", day, city->name);
    printf("Temperature: %d degrees Celsius\n", city->temperature[day]);
    printf("Precipitation: %d mm\n", city->precipitation[day]);
    printf("Humidity: %d%%\n\n", city->humidity[day]);
}

int main() {
    srand(time(0));
    struct City cities[MAX_CITIES];
    int numCities;
    printf("How many cities do you want to simulate? ");
    scanf("%d", &numCities);
    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
    }
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < MAX_DAYS; j++) {
            generateWeather(&cities[i], j);
        }
    }
    int day;
    printf("Enter the day you want to see the weather for each city (1-%d): ", MAX_DAYS);
    scanf("%d", &day);
    for (int i = 0; i < numCities; i++) {
        printWeather(&cities[i], day);
    }
    return 0;
}