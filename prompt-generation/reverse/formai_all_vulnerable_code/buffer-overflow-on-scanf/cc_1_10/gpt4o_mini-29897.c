//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WEATHER_TYPES 5

// Enumeration for various weather types
typedef enum {
    SUNNY,
    RAINY,
    CLOUDY,
    SNOWY,
    WINDY
} WeatherType;

// Function prototypes
const char* getWeatherType(WeatherType type);
WeatherType getRandomWeather();
void simulateWeather();

int main() {
    char choice;
    
    printf("Welcome to the C Weather Simulation Program!\n");
    
    do {
        printf("\nWould you like to simulate the weather? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'y' || choice == 'Y') {
            simulateWeather();
        } else if (choice == 'n' || choice == 'N') {
            printf("Thank you for using the weather simulator. Goodbye!\n");
        } else {
            printf("Invalid choice. Please enter 'y' or 'n'.\n");
        }
    } while (choice != 'n' && choice != 'N');

    return 0;
}

// Function to get a string representation of the weather type
const char* getWeatherType(WeatherType type) {
    switch (type) {
        case SUNNY: return "Sunny";
        case RAINY: return "Rainy";
        case CLOUDY: return "Cloudy";
        case SNOWY: return "Snowy";
        case WINDY: return "Windy";
        default: return "Unknown";
    }
}

// Function to generate a random weather type
WeatherType getRandomWeather() {
    return rand() % MAX_WEATHER_TYPES;
}

// Function to simulate and display the weather
void simulateWeather() {
    srand(time(NULL));
    WeatherType currentWeather = getRandomWeather();
    
    printf("\nCurrent weather is: %s\n", getWeatherType(currentWeather));
    printf("Would you like to see the forecast for the next 5 days? (y/n): ");
    
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("\n5-Day Weather Forecast:\n");
        for (int i = 1; i <= 5; i++) {
            WeatherType forecast = getRandomWeather();
            printf("Day %d: %s\n", i, getWeatherType(forecast));
        }
    } else {
        printf("Perhaps some other time! You can always check back.\n");
    }
    
    printf("Would you like to learn about different weather phenomena? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("\nHere are some interesting weather facts:\n");
        printf("1. Sunny weather is generally considered the best for outdoor activities!\n");
        printf("2. Rainy days can contribute to the growth of plants!\n");
        printf("3. Clouds are made of tiny water droplets or ice crystals, depending on their altitude.\n");
        printf("4. Snowflakes can have unique formations with six sides!\n");
        printf("5. Wind can greatly influence the weather, transporting heat and moisture!\n");
    } else {
        printf("No worries! Maybe another time.\n");
    }
}