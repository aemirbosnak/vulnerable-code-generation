//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 5
#define MAX_WEATHER_TYPES 5

typedef struct {
    char name[50];
    float temperature; // in Celsius
    float humidity;    // in percentage
    float windSpeed;   // in km/h
} CityWeather;

const char *weatherTypes[MAX_WEATHER_TYPES] = {
    "Sunny",
    "Rainy",
    "Cloudy",
    "Stormy",
    "Snowy"
};

// Function prototypes
void generateWeather(CityWeather *city);
void displayWeather(const CityWeather *city);
void simulateWeatherForAllCities(CityWeather cities[], int numCities);

int main() {
    srand(time(NULL)); // Seed random number generator

    CityWeather cities[MAX_CITIES] = {
        {"New York", 0, 0, 0},
        {"Los Angeles", 0, 0, 0},
        {"Chicago", 0, 0, 0},
        {"Houston", 0, 0, 0},
        {"Miami", 0, 0, 0},
    };

    while (1) {
        printf("\nWeather Simulation Menu:\n");
        printf("1. Generate Weather\n");
        printf("2. Display Weather\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                simulateWeatherForAllCities(cities, MAX_CITIES);
                break;
            case 2:
                for (int i = 0; i < MAX_CITIES; i++) {
                    displayWeather(&cities[i]);
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void generateWeather(CityWeather *city) {
    city->temperature = (float)(rand() % 41) - 5; // Temperature between -5 to 35 degrees Celsius
    city->humidity = (float)(rand() % 101); // Humidity between 0% to 100%
    city->windSpeed = (float)(rand() % 51); // Wind speed between 0 to 50 km/h
}

void displayWeather(const CityWeather *city) {
    printf("\nWeather Report for %s:\n", city->name);
    printf("Temperature: %.2f °C\n", city->temperature);
    printf("Humidity: %.2f%%\n", city->humidity);
    printf("Wind Speed: %.2f km/h\n", city->windSpeed);
    printf("Weather Condition: %s\n", weatherTypes[rand() % MAX_WEATHER_TYPES]);
}

void simulateWeatherForAllCities(CityWeather cities[], int numCities) {
    for (int i = 0; i < numCities; i++) {
        generateWeather(&cities[i]);
        printf("Weather generated for %s.\n", cities[i].name);
    }
}