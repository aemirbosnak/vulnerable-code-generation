//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CITIES 10
#define MAX_WEATHER_REPORTS 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char cityName[MAX_NAME_LENGTH];
    float temperature;    // in degrees Celsius
    int humidity;         // in percentage
    float windSpeed;      // in km/h
    char description[100]; // weather condition description
} WeatherReport;

typedef struct {
    char name[MAX_NAME_LENGTH];
    WeatherReport reports[MAX_WEATHER_REPORTS];
    int reportCount;
} City;

void generateWeatherReport(City* city) {
    for (int i = 0; i < MAX_WEATHER_REPORTS; i++) {
        city->reports[i].temperature = (rand() % 351) / 10.0 - 20; // -20.0 to 30.0 degrees
        city->reports[i].humidity = rand() % 101; // 0 to 100 %
        city->reports[i].windSpeed = rand() % 151; // 0 to 150 km/h

        const char* conditions[] = {"Sunny", "Cloudy", "Rainy", "Stormy", "Snowy", "Foggy"};
        strcpy(city->reports[i].description, conditions[rand() % 6]);
    }
    city->reportCount = MAX_WEATHER_REPORTS;
}

void displayWeatherReport(const City* city) {
    printf("Weather Report for %s:\n", city->name);
    for (int i = 0; i < city->reportCount; i++) {
        printf("  Report %d:\n", i + 1);
        printf("    Temperature: %.1f °C\n", city->reports[i].temperature);
        printf("    Humidity: %d%%\n", city->reports[i].humidity);
        printf("    Wind Speed: %.1f km/h\n", city->reports[i].windSpeed);
        printf("    Condition: %s\n", city->reports[i].description);
    }
}

void simulateWeather(int cityCount) {
    City cities[MAX_CITIES];

    for (int i = 0; i < cityCount; i++) {
        printf("Enter name for city %d: ", i + 1);
        fgets(cities[i].name, MAX_NAME_LENGTH, stdin);
        size_t len = strlen(cities[i].name);
        if (len > 0 && cities[i].name[len - 1] == '\n') {
            cities[i].name[len - 1] = '\0'; // remove newline character
        }
        generateWeatherReport(&cities[i]);
    }

    printf("\nWeather Simulation Results:\n");
    for (int i = 0; i < cityCount; i++) {
        displayWeatherReport(&cities[i]);
    }
}

int main() {
    srand(time(NULL));

    int cityCount;
    printf("Enter number of cities to simulate weather for (max %d): ", MAX_CITIES);
    scanf("%d", &cityCount);
    getchar(); // consume newline

    if (cityCount < 1 || cityCount > MAX_CITIES) {
        printf("Invalid number of cities. Please enter a number between 1 and %d.\n", MAX_CITIES);
        return 1;
    }

    simulateWeather(cityCount);

    return 0;
}