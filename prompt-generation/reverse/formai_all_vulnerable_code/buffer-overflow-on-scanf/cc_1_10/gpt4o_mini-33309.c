//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_DAYS 30

typedef struct Weather {
    int day;
    char condition[20];
    int temperature; // in Fahrenheit
} Weather;

void generateWeather(Weather *weatherData, int days);
void displayWeather(Weather *weatherData, int days);
void displayWeatherReport(Weather *weatherData, int days);
void clearScreen();

int main() {
    Weather weatherData[MAX_DAYS];
    int days = 0;
    
    printf("Welcome to the Retro Weather Simulator!\n");
    printf("How many days of weather would you like to simulate (1 - 30)? ");
    
    // Input the number of days for the simulation
    while (1) {
        scanf("%d", &days);
        if (days >= 1 && days <= MAX_DAYS) {
            break;
        } else {
            printf("Please enter a valid number of days (1 - 30): ");
        }
    }

    // Generate weather data
    generateWeather(weatherData, days);

    // Display generated weather data
    clearScreen();
    printf("Weather Simulation Report\n");
    printf("-------------------------\n");
    displayWeatherReport(weatherData, days);

    return 0;
}

void generateWeather(Weather *weatherData, int days) {
    const char *conditions[] = {
        "Sunny", "Cloudy", "Rainy", "Stormy", "Snowy", "Windy"
    };
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < days; i++) {
        weatherData[i].day = i + 1;
        // Randomly select a weather condition
        int condIndex = rand() % 6;
        snprintf(weatherData[i].condition, sizeof(weatherData[i].condition), "%s", conditions[condIndex]);
        // Random temperature between 30 and 100
        weatherData[i].temperature = rand() % 71 + 30; 
    }
}

void displayWeather(Weather *weatherData, int days) {
    for (int i = 0; i < days; i++) {
        printf("Day %02d: %s, %d°F\n", weatherData[i].day, weatherData[i].condition, weatherData[i].temperature);
    }
}

void displayWeatherReport(Weather *weatherData, int days) {
    displayWeather(weatherData, days);
    printf("-------------------------\n");
    printf("Thank you for using the Weather Simulator!\n");
}

void clearScreen() {
    // System call for clearing screen
    printf("\033[H\033[J");
    usleep(500000); // Pause for half a second
}