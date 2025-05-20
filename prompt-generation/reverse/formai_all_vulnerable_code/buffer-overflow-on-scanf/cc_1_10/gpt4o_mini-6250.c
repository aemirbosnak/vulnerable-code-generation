//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 30
#define MAX_CITY 5

const char *cities[MAX_CITY] = { "New York", "Los Angeles", "Chicago", "Houston", "Phoenix" };
const char *weatherPatterns[] = { "Sunny", "Rainy", "Cloudy", "Snowy" };

void simulateWeather(int days);
void printWeather(int day, const char *city, const char *weather);
const char* getRandomCity();
const char* getRandomWeather();

int main() {
    srand(time(NULL));  // Seed for randomness
    int daysToSimulate;

    printf("Welcome to the Weather Simulation Program!\n");
    printf("How many days of weather would you like to simulate (max %d days)? ", MAX_DAYS);
    scanf("%d", &daysToSimulate);
    
    if (daysToSimulate < 1 || daysToSimulate > MAX_DAYS) {
        printf("Please enter a valid number of days (1-%d)\n", MAX_DAYS);
        return 1;
    }

    simulateWeather(daysToSimulate);
    
    printf("Simulation completed!\n");
    return 0;
}

void simulateWeather(int days) {
    printf("\nWeather Simulation Results:\n");
    for (int i = 0; i < days; i++) {
        const char *city = getRandomCity();
        const char *weather = getRandomWeather();
        printWeather(i + 1, city, weather);
    }
}

void printWeather(int day, const char *city, const char *weather) {
    printf("Day %2d: %s - %s\n", day, city, weather);
}

const char* getRandomCity() {
    return cities[rand() % MAX_CITY];
}

const char* getRandomWeather() {
    return weatherPatterns[rand() % (sizeof(weatherPatterns) / sizeof(weatherPatterns[0]))];
}