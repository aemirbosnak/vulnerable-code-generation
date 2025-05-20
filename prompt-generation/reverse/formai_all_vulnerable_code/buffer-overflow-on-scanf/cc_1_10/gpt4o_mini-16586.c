//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DAYS_IN_YEAR 365
#define MAX_WEATHER_TYPES 5
#define MAX_NAME_LENGTH 50

// Weather struct to hold individual weather day information
typedef struct {
    char type[MAX_NAME_LENGTH];
    float temperature; // in Celsius
    float humidity;    // in percentage
} Weather;

// Function prototypes
void generateWeather(Weather *weather);
void displayWeather(const Weather *weather, int days);
const char* getWeatherType(int index);
void simulateWeather(int days);

int main() {
    int days;

    printf("Enter the number of days to simulate weather (up to %d): ", DAYS_IN_YEAR);
    scanf("%d", &days);

    if (days <= 0 || days > DAYS_IN_YEAR) {
        printf("Please enter a valid number of days.\n");
        return 1;
    }

    simulateWeather(days);

    return 0;
}

// Function to get weather type based on index
const char* getWeatherType(int index) {
    const char* weatherTypes[MAX_WEATHER_TYPES] = {
        "Sunny",
        "Rainy",
        "Cloudy",
        "Windy",
        "Snowy"
    };
    return weatherTypes[index];
}

// Function to generate random weather data
void generateWeather(Weather *weather) {
    int weatherIndex = rand() % MAX_WEATHER_TYPES;

    strcpy(weather->type, getWeatherType(weatherIndex));
    weather->temperature = (rand() % 41) - 10; // Random temperature between -10 to 30
    weather->humidity = rand() % 101; // Random humidity between 0% to 100%
}

// Function to display weather data
void displayWeather(const Weather *weather, int days) {
    printf("\nWeather simulation for %d days:\n", days);
    printf("%-10s %-15s %-15s %-15s\n", "Day", "Weather Type", "Temp (°C)", "Humidity (%)");
    
    for (int i = 0; i < days; i++) {
        printf("%-10d %-15s %-15.2f %-15.2f\n", i + 1, weather[i].type, weather[i].temperature, weather[i].humidity);
    }
}

// Function to simulate weather for a specified number of days
void simulateWeather(int days) {
    Weather *weatherData = malloc(days * sizeof(Weather));
    
    if (weatherData == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    srand(time(NULL)); // Seed for random number generation

    for (int i = 0; i < days; i++) {
        generateWeather(&weatherData[i]);
    }

    displayWeather(weatherData, days);

    free(weatherData); // Clean up allocated memory
}