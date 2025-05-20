//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365
#define MAX_HOURS 24

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int windSpeed;
    int precipitation;
} City;

int main() {
    City cities[MAX_CITIES];
    int numCities;
    char input[100];
    int i, j;

    //Get number of cities from user
    printf("Enter number of cities: ");
    scanf("%d", &numCities);

    //Get city information from user
    for(i=0; i<numCities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);

        printf("Enter temperature: ");
        scanf("%d", &cities[i].temperature);

        printf("Enter humidity: ");
        scanf("%d", &cities[i].humidity);

        printf("Enter wind speed: ");
        scanf("%d", &cities[i].windSpeed);

        printf("Enter precipitation: ");
        scanf("%d", &cities[i].precipitation);
    }

    //Simulate weather for each city
    for(i=0; i<numCities; i++) {
        printf("Weather for %s:\n", cities[i].name);

        //Simulate temperature
        for(j=0; j<MAX_DAYS; j++) {
            printf("Day %d: %d\n", j+1, cities[i].temperature);
        }

        //Simulate humidity
        for(j=0; j<MAX_HOURS; j++) {
            printf("Hour %d: %d\n", j+1, cities[i].humidity);
        }

        //Simulate wind speed
        for(j=0; j<MAX_HOURS; j++) {
            printf("Hour %d: %d\n", j+1, cities[i].windSpeed);
        }

        //Simulate precipitation
        for(j=0; j<MAX_DAYS; j++) {
            printf("Day %d: %d\n", j+1, cities[i].precipitation);
        }
    }

    return 0;
}