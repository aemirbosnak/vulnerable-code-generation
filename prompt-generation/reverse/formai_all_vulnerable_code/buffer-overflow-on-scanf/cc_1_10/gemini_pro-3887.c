//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the weather conditions
typedef enum {
    SUNNY,
    CLOUDY,
    RAINY,
    STORMY
} weather_condition;

// Define the weather simulation parameters
#define DAYS_IN_SIMULATION 365
#define CHANCE_OF_RAIN 0.3
#define CHANCE_OF_STORM 0.1

// Generate a random weather condition
weather_condition generate_weather() {
    double r = (double)rand() / RAND_MAX;
    if (r < CHANCE_OF_STORM) {
        return STORMY;
    } else if (r < CHANCE_OF_RAIN) {
        return RAINY;
    } else if (r < 0.5) {
        return CLOUDY;
    } else {
        return SUNNY;
    }
}

// Simulate the weather for a given number of days
void simulate_weather(int days) {
    int sunny_days = 0;
    int cloudy_days = 0;
    int rainy_days = 0;
    int stormy_days = 0;

    for (int i = 0; i < days; i++) {
        weather_condition weather = generate_weather();
        switch (weather) {
            case SUNNY:
                sunny_days++;
                break;
            case CLOUDY:
                cloudy_days++;
                break;
            case RAINY:
                rainy_days++;
                break;
            case STORMY:
                stormy_days++;
                break;
        }
    }

    // Print the results of the simulation
    printf("Weather simulation results:\n");
    printf("    Sunny days: %d\n", sunny_days);
    printf("    Cloudy days: %d\n", cloudy_days);
    printf("    Rainy days: %d\n", rainy_days);
    printf("    Stormy days: %d\n", stormy_days);
}

// Greet the user
void greet_user() {
    printf("Welcome to the Weather Simulation Extravaganza!\n");
    printf("Get ready for a whirlwind of weather patterns!\n");
}

// Get the number of days to simulate from the user
int get_num_days() {
    int days;
    printf("How many days do you want to simulate? (1-365): ");
    scanf("%d", &days);
    return days;
}

// Main function
int main() {
    // Greet the user
    greet_user();

    // Get the number of days to simulate
    int days = get_num_days();

    // Simulate the weather
    simulate_weather(days);

    // Say goodbye to the user
    printf("Thanks for playing the Weather Simulation Extravaganza!\n");
    return 0;
}