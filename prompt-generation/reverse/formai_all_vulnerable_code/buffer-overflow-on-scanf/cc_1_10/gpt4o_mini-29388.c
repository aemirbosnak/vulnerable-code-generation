//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WEATHER_TYPES 5

// Weather types enumeration
const char *weather_types[MAX_WEATHER_TYPES] = {
    "Sunny",
    "Cloudy",
    "Rainy",
    "Stormy",
    "Snowy"
};

// Structure to hold Weather data
typedef struct {
    char type[20];
    float temperature;
    int humidity;
} Weather;

// Function to update weather
void update_weather(Weather *current_weather) {
    // Randomly pick a new weather type
    int weather_index = rand() % MAX_WEATHER_TYPES;
    strcpy(current_weather->type, weather_types[weather_index]);
    
    // Update temperature and humidity based on the weather type
    switch (weather_index) {
        case 0: // Sunny
            current_weather->temperature = (rand() % (35 - 20 + 1)) + 20;
            current_weather->humidity = rand() % 41 + 20; // 20-60%
            break;
        case 1: // Cloudy
            current_weather->temperature = (rand() % (25 - 15 + 1)) + 15;
            current_weather->humidity = rand() % 41 + 30; // 30-70%
            break;
        case 2: // Rainy
            current_weather->temperature = (rand() % (20 - 10 + 1)) + 10;
            current_weather->humidity = rand() % 31 + 60; // 60-90%
            break;
        case 3: // Stormy
            current_weather->temperature = (rand() % (18 - 5 + 1)) + 5;
            current_weather->humidity = rand() % 51 + 70; // 70-120%
            break;
        case 4: // Snowy
            current_weather->temperature = (rand() % (5 - (-10) + 1)) - 10;
            current_weather->humidity = rand() % 41 + 60; // 60-100%
            break;
    }
}

// Function to display the current weather
void display_weather(Weather *current_weather) {
    printf("Current Weather:\n");
    printf("Type: %s\n", current_weather->type);
    printf("Temperature: %.2f°C\n", current_weather->temperature);
    printf("Humidity: %d%%\n", current_weather->humidity);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Weather current_weather;
    strcpy(current_weather.type, "Sunny");
    current_weather.temperature = 25.0;
    current_weather.humidity = 50;

    int choice;

    printf("Weather Simulation Program\n");
    printf("--------------------------\n");

    do {
        printf("\nOptions:\n");
        printf("1. View Current Weather\n");
        printf("2. Change Weather\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_weather(&current_weather);
                break;
            case 2:
                update_weather(&current_weather);
                printf("Weather updated!\n");
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}