//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 7

const char *weatherConditions[] = {"Sunny", "Rainy", "Cloudy", "Windy", "Stormy"};

typedef struct {
    int temperature; // in degrees Celsius
    int humidity;    // in percentage
    const char *condition;
} Weather;

void generateWeather(Weather *w) {
    w->temperature = rand() % 31 - 10; // Random temperature between -10 and 30
    w->humidity = rand() % 101;         // Random humidity between 0% and 100%
    w->condition = weatherConditions[rand() % 5]; // Random weather condition
}

void displayWeather(Weather *w, int day) {
    printf("Day %d: Weather Condition: %s, Temperature: %d°C, Humidity: %d%%\n",
           day + 1, w->condition, w->temperature, w->humidity);
}

void simulateWeather(int days) {
    Weather weekWeather[MAX_DAYS];

    printf("Weather Simulation for the Week:\n");
    printf("====================================\n");

    for (int i = 0; i < days; i++) {
        generateWeather(&weekWeather[i]);
        displayWeather(&weekWeather[i], i);
    }

    printf("====================================\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int days;
    printf("Enter the number of days to simulate (up to %d): ", MAX_DAYS);
    scanf("%d", &days);

    if (days < 1 || days > MAX_DAYS) {
        printf("Please enter a valid number of days between 1 and %d.\n", MAX_DAYS);
        return 1;
    }

    simulateWeather(days);

    return 0;
}