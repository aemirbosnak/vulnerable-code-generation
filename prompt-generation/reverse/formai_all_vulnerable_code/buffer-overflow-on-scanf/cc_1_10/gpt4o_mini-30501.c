//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

#define MAX_LOCATIONS 10
#define MAX_WEATHER_TYPES 5

typedef struct {
    char name[30];
    float temperature; // in Celsius
    float humidity; // in percentage
    char weatherType[15];
} WeatherReport;

const char *weatherTypes[MAX_WEATHER_TYPES] = {
    "Sunny",
    "Cloudy",
    "Rainy",
    "Stormy",
    "Snowy"
};

void generateWeather(WeatherReport *report) {
    report->temperature = rand() % 40 - 10; // Random temperature between -10 and 30
    report->humidity = rand() % 101; // Random humidity between 0 to 100%
    strcpy(report->weatherType, weatherTypes[rand() % MAX_WEATHER_TYPES]);
}

void displayWeatherReport(WeatherReport *report) {
    printf("Location: %s\n", report->name);
    printf("Temperature: %.1f°C\n", report->temperature);
    printf("Humidity: %.1f%%\n", report->humidity);
    printf("Weather Type: %s\n", report->weatherType);
    printf("----------------------------\n");
}

void simulateWeather(int numberOfLocations) {
    WeatherReport reports[MAX_LOCATIONS];
    
    // Seed random number generator
    srand(time(NULL));

    for (int i = 0; i < numberOfLocations; i++) {
        sprintf(reports[i].name, "Location %d", i + 1);
        generateWeather(&reports[i]);
    }

    printf("---- Weather Simulation Report ----\n");
    for (int i = 0; i < numberOfLocations; i++) {
        displayWeatherReport(&reports[i]);
    }
}

int main() {
    int numberOfLocations;

    printf("Enter the number of locations to simulate weather for (max %d): ", MAX_LOCATIONS);
    scanf("%d", &numberOfLocations);

    if (numberOfLocations < 1 || numberOfLocations > MAX_LOCATIONS) {
        printf("Invalid number of locations. Please enter a number between 1 and %d.\n", MAX_LOCATIONS);
        return 1;
    }

    simulateWeather(numberOfLocations);
    return 0;
}