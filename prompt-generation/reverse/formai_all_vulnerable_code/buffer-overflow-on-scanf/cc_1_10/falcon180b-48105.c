//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define DAYS_PER_WEEK 7
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60

struct City {
    char name[20];
    int temperature;
    int humidity;
};

void generateRandomWeather(struct City *city) {
    city->temperature = rand() % 41 - 20;
    city->humidity = rand() % 101;
}

void printWeather(struct City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d degrees Celsius\n", city.temperature);
    printf("Humidity: %d%%\n\n", city.humidity);
}

int main() {
    srand(time(NULL));

    struct City cities[MAX_CITIES];

    int numCities;
    printf("Enter the number of cities (maximum %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        generateRandomWeather(&cities[i]);
    }

    int numDays;
    printf("Enter the number of days to simulate (maximum %d): ", DAYS_PER_WEEK);
    scanf("%d", &numDays);

    for (int day = 1; day <= numDays; day++) {
        for (int hour = 0; hour < HOURS_PER_DAY; hour++) {
            for (int cityIndex = 0; cityIndex < numCities; cityIndex++) {
                struct City *city = &cities[cityIndex];
                printWeather(*city);
            }
        }
        printf("\n");
    }

    return 0;
}