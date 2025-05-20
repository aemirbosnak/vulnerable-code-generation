//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITY 10
#define MAX_TEMP 100

// structure for city
typedef struct {
    char name[20];
    int temp;
} City;

// function to generate random temperature
int randTemp() {
    return rand() % MAX_TEMP;
}

// function to generate random city name
void randCityName(char *name) {
    int i;
    for (i = 0; i < strlen(name); i++) {
        name[i] = rand() % 26 + 'a';
    }
    name[strlen(name)] = '\0';
}

// function to display weather for all cities
void displayWeather(City cities[], int numCities) {
    int i;
    for (i = 0; i < numCities; i++) {
        printf("City: %s, Temperature: %d\n", cities[i].name, cities[i].temp);
    }
}

// main function
int main() {
    srand(time(NULL));
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    City cities[MAX_CITY];
    if (numCities > MAX_CITY) {
        printf("Error: Maximum number of cities is %d\n", MAX_CITY);
        return 1;
    }
    printf("Enter city names:\n");
    int i;
    for (i = 0; i < numCities; i++) {
        randCityName(cities[i].name);
        printf("City %d: %s\n", i + 1, cities[i].name);
    }
    printf("Enter temperatures for each city:\n");
    for (i = 0; i < numCities; i++) {
        cities[i].temp = randTemp();
        printf("City %d: %d\n", i + 1, cities[i].temp);
    }
    displayWeather(cities, numCities);
    return 0;
}