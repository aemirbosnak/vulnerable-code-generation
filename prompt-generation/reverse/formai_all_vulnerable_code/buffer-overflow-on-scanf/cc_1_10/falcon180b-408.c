//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100

// Define the structure of a city
typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int windSpeed;
} City;

// Function to generate a random city name
void generateCityName(char *cityName) {
    char *adjectives[] = {"Sunny", "Rainy", "Cloudy", "Windy"};
    char *nouns[] = {"Island", "Mountain", "Valley", "Forest"};

    int randIndex = rand() % 4;
    strcpy(cityName, adjectives[randIndex]);
    strcat(cityName, " ");
    randIndex = rand() % 4;
    strcat(cityName, nouns[randIndex]);
}

// Function to get user input for the number of cities
int getNumCities() {
    int numCities = 0;

    while (numCities <= 0 || numCities > MAX_CITIES) {
        printf("Enter the number of cities (1-100): ");
        scanf("%d", &numCities);
    }

    return numCities;
}

// Function to generate random weather conditions for each city
void generateWeather(City *cities, int numCities) {
    for (int i = 0; i < numCities; i++) {
        cities[i].temperature = rand() % 40 + 1;
        cities[i].humidity = rand() % 100;
        cities[i].windSpeed = rand() % 20 + 1;
    }
}

// Function to print the weather conditions for each city
void printWeather(City *cities, int numCities) {
    printf("City\tTemperature\tHumidity\tWind Speed\n");
    for (int i = 0; i < numCities; i++) {
        printf("%s\t%d\t\t%d\t\t%d\n", cities[i].name, cities[i].temperature, cities[i].humidity, cities[i].windSpeed);
    }
}

int main() {
    srand(time(NULL));

    int numCities = getNumCities();
    City cities[MAX_CITIES];

    for (int i = 0; i < numCities; i++) {
        generateCityName(cities[i].name);
    }

    generateWeather(cities, numCities);
    printWeather(cities, numCities);

    return 0;
}