//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 7

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int pressure;
} City;

void generateRandomWeather(City *city) {
    city->temperature = rand() % 30 + 1;
    city->humidity = rand() % 101;
    city->pressure = rand() % 101;
}

void printCityWeather(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d°C\n", city.temperature);
    printf("Humidity: %d%%\n", city.humidity);
    printf("Pressure: %d hPa\n\n", city.pressure);
}

void simulateWeather(City cities[NUM_CITIES], int days) {
    srand(time(NULL));

    for (int i = 0; i < NUM_CITIES; i++) {
        generateRandomWeather(&cities[i]);
    }

    for (int day = 1; day <= days; day++) {
        printf("Day %d:\n", day);

        for (int i = 0; i < NUM_CITIES; i++) {
            printCityWeather(cities[i]);
        }

        printf("\n");
    }
}

int main() {
    City cities[NUM_CITIES] = {{"New York", 0, 0, 0}, {"Los Angeles", 0, 0, 0}, {"Chicago", 0, 0, 0}, {"Houston", 0, 0, 0}, {"Miami", 0, 0, 0}};

    int numDays;

    printf("Welcome to the Weather Simulation!\n\n");
    printf("Enter the number of days you want to simulate (between 1 and 7): ");
    scanf("%d", &numDays);

    if (numDays < 1 || numDays > 7) {
        printf("Invalid number of days. Exiting program.\n");
        return 1;
    }

    simulateWeather(cities, numDays);

    return 0;
}