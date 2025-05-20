//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CITIES 100
#define CITY_NAME_LENGTH 50
#define MAX_WEATHER_TYPES 5

// Weather type enum
typedef enum {
    SUNNY,
    RAINY,
    CLOUDY,
    SNOWY,
    WINDY
} WeatherType;

// Weather forecast structure
typedef struct {
    WeatherType type;
    float temperature;  // in degrees Celsius
    int humidity;       // percentage
} WeatherForecast;

// City structure
typedef struct {
    char name[CITY_NAME_LENGTH];
    WeatherForecast forecast;
} City;

// Function prototypes
void generateRandomCityWeather(City *city);
void displayCityWeather(const City *city);
const char* weatherTypeToString(WeatherType type);
void simulateWeatherForCities(City cities[], int cityCount);
void displayWeatherForAllCities(const City cities[], int cityCount);

int main() {
    srand(time(NULL)); // Seed random number generator

    City cities[MAX_CITIES];
    int cityCount;

    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &cityCount);

    if (cityCount < 1 || cityCount > MAX_CITIES) {
        printf("Invalid number of cities. Exiting.\n");
        return 1;
    }

    // Input city names
    for (int i = 0; i < cityCount; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    // Simulate weather for each city
    simulateWeatherForCities(cities, cityCount);

    // Display the weather
    displayWeatherForAllCities(cities, cityCount);

    return 0;
}

void generateRandomCityWeather(City *city) {
    city->forecast.type = rand() % MAX_WEATHER_TYPES; // Random weather type
    city->forecast.temperature = (rand() % 41) - 10;  // Random temperature between -10 and +30
    city->forecast.humidity = rand() % 101;            // Random humidity between 0 and 100
}

void displayCityWeather(const City *city) {
    printf("City: %s\n", city->name);
    printf("Weather: %s\n", weatherTypeToString(city->forecast.type));
    printf("Temperature: %.1f °C\n", city->forecast.temperature);
    printf("Humidity: %d%%\n", city->forecast.humidity);
    printf("-------------------------------\n");
}

const char* weatherTypeToString(WeatherType type) {
    switch (type) {
        case SUNNY: return "Sunny";
        case RAINY: return "Rainy";
        case CLOUDY: return "Cloudy";
        case SNOWY: return "Snowy";
        case WINDY: return "Windy";
        default: return "Unknown";
    }
}

void simulateWeatherForCities(City cities[], int cityCount) {
    for (int i = 0; i < cityCount; i++) {
        generateRandomCityWeather(&cities[i]);
    }
}

void displayWeatherForAllCities(const City cities[], int cityCount) {
    printf("Weather forecast for all cities:\n");
    printf("===============================\n");
    for (int i = 0; i < cityCount; i++) {
        displayCityWeather(&cities[i]);
    }
}