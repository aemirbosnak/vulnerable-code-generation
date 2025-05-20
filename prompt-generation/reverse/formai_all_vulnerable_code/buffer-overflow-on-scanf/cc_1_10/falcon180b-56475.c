//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define DAYS_IN_YEAR 365

struct City {
    char name[50];
    int temperature;
    int humidity;
};

void generateRandomWeather(struct City *city) {
    city->temperature = rand() % 41 - 20;
    city->humidity = rand() % 101;
}

void printWeatherReport(struct City *city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d°C\n", city->temperature);
    printf("Humidity: %d%%\n\n", city->humidity);
}

int main() {
    srand(time(NULL));

    struct City cities[MAX_CITIES];

    int numCities;
    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        generateRandomWeather(&cities[i]);
    }

    int numDays;
    printf("Enter the number of days to simulate (max %d): ", DAYS_IN_YEAR);
    scanf("%d", &numDays);

    for (int day = 1; day <= numDays; day++) {
        printf("Day %d\n", day);
        for (int i = 0; i < numCities; i++) {
            printWeatherReport(&cities[i]);
        }
    }

    return 0;
}