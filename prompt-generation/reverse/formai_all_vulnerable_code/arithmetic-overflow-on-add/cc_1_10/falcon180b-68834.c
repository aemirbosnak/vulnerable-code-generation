//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 365
#define MIN_TEMP -100
#define MAX_TEMP 100
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100

typedef struct {
    char name[50];
    int temp;
    int humidity;
} City;

int main() {
    int numCities, numDays;
    City cities[MAX_CITIES];
    time_t startTime, endTime;
    int i, j;

    // Initialize random seed
    srand(time(NULL));

    // Get number of cities from user
    printf("Enter number of cities (1 to %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    // Get city names from user
    for(i = 0; i < numCities; i++) {
        printf("Enter city name %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    // Get number of days from user
    printf("Enter number of days to simulate (1 to %d): ", MAX_DAYS);
    scanf("%d", &numDays);

    // Initialize start and end times
    startTime = time(NULL) - (numDays * 24 * 60 * 60);
    endTime = startTime + (numDays * 24 * 60 * 60);

    // Simulate weather for each city
    for(i = 0; i < numCities; i++) {
        for(j = 0; j < numDays; j++) {
            // Generate random temperature and humidity
            int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            int humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;

            // Update city weather data
            cities[i].temp = temp;
            cities[i].humidity = humidity;

            // Print weather report for current day
            time_t currentTime = startTime + (j * 24 * 60 * 60);
            struct tm *t = localtime(&currentTime);
            printf("Weather report for %s on %d-%02d-%02d:\n", cities[i].name, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
            printf("Temperature: %d\n", temp);
            printf("Humidity: %d\n\n", humidity);
        }
    }

    return 0;
}