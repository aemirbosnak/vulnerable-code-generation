//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_YEAR 365

// Define weather types
typedef enum {
    SUNNY,
    CLOUDY,
    RAINY,
    STORMY
} Weather;

// Function to generate a random weather type
Weather generateRandomWeather() {
    return rand() % 4; // Randomly choose a number between 0 and 3
}

// Function to convert Weather enum to string for display
const char* weatherToString(Weather weather) {
    switch (weather) {
        case SUNNY: return "Sunny";
        case CLOUDY: return "Cloudy";
        case RAINY: return "Rainy";
        case STORMY: return "Stormy";
        default: return "Unknown";
    }
}

// Function to simulate the weather for a given number of days
void simulateWeather(int days) {
    printf("Weather Simulation for %d Days:\n", days);
    
    // Variables to count different weather occurrences
    int sunnyDays = 0, cloudyDays = 0, rainyDays = 0, stormyDays = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate and display weather for each day
    for (int day = 0; day < days; day++) {
        Weather todayWeather = generateRandomWeather();
        
        // Update counts based on today's weather
        switch (todayWeather) {
            case SUNNY: sunnyDays++; break;
            case CLOUDY: cloudyDays++; break;
            case RAINY: rainyDays++; break;
            case STORMY: stormyDays++; break;
        }

        // Display today's weather
        printf("Day %3d: %s\n", day + 1, weatherToString(todayWeather));
    }

    // Display summary
    printf("\n--- Weather Summary for %d Days ---\n", days);
    printf("Sunny Days: %d\n", sunnyDays);
    printf("Cloudy Days: %d\n", cloudyDays);
    printf("Rainy Days: %d\n", rainyDays);
    printf("Stormy Days: %d\n", stormyDays);
}

int main() {
    int days;

    // Prompt user for the number of days to simulate
    printf("Welcome to the Weather Simulation!\n");
    printf("How many days would you like to simulate? ");
    scanf("%d", &days);

    // Ensure the user enters a reasonable number of days
    if (days <= 0 || days > DAYS_IN_YEAR) {
        printf("Please enter a valid number of days (1 - %d).\n", DAYS_IN_YEAR);
        return 1;
    }

    // Start the weather simulation
    simulateWeather(days);

    printf("Thank you for using the Weather Simulation!\n");
    return 0;
}