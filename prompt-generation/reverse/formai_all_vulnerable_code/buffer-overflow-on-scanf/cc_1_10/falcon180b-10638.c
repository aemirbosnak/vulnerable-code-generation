//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[50];
    float temp[MAX_DAYS];
    float humidity[MAX_DAYS];
} City;

void generateWeather(City* city, int day) {
    float avgTemp = 0, avgHumidity = 0;
    int count = 0;

    // Generate weather for the current day
    city->temp[day] = rand() % 41 + 1; // Temperature in Celsius
    city->humidity[day] = rand() % 101; // Humidity in percentage

    // Generate weather for the previous days
    for (int i = 0; i < day; i++) {
        city->temp[i] = city->temp[i + 1] - (rand() % 6) + 1;
        city->humidity[i] = city->humidity[i + 1] - (rand() % 6);

        avgTemp += city->temp[i];
        avgHumidity += city->humidity[i];
        count++;
    }

    city->temp[0] = avgTemp / count;
    city->humidity[0] = avgHumidity / count;
}

void printWeather(City* city, int day) {
    printf("Weather in %s on day %d:\n", city->name, day);
    printf("Temperature: %.2f°C\n", city->temp[day]);
    printf("Humidity: %.2f%%\n", city->humidity[day]);
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];
    int numCities;

    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);

        for (int j = 0; j < MAX_DAYS; j++) {
            generateWeather(&cities[i], j);
        }
    }

    int startDay, endDay;
    printf("Enter the start day: ");
    scanf("%d", &startDay);
    printf("Enter the end day: ");
    scanf("%d", &endDay);

    for (int i = 0; i < numCities; i++) {
        for (int j = startDay; j <= endDay; j++) {
            printWeather(&cities[i], j);
        }
    }

    return 0;
}