//FormAI DATASET v1.0 Category: Weather simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Struct to hold weather conditions
typedef struct {
    float temperature;
    float humidity;
    float windSpeed;
    int pressure;
    bool isStormy;
} Weather;

// Function to generate random weather conditions
Weather generateWeather() {
    Weather weather;

    weather.temperature = (float)rand()/(float)(RAND_MAX/50) + 20.0;
    weather.humidity = (float)rand()/(float)(RAND_MAX/50) + 20.0;
    weather.windSpeed = (float)rand()/(float)(RAND_MAX/20) + 5.0;
    weather.pressure = rand()%20 + 1000;
    weather.isStormy = (rand()%2 == 1);

    return weather;
}

int main() {
    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Futuristic Weather Simulation!\n\n");

    int simulationDuration = 0;
    printf("How long would you like to simulate the weather for? (in days)\n");
    scanf("%d", &simulationDuration);

    printf("\nSimulating weather...\n\n");

    for (int i = 1; i <= simulationDuration; i++) {
        Weather currentWeather = generateWeather();

        printf("Day %d\n", i);
        printf("Temperature: %.1f C\n", currentWeather.temperature);
        printf("Humidity: %.1f%%\n", currentWeather.humidity);
        printf("Wind Speed: %.1f km/h\n", currentWeather.windSpeed);
        printf("Pressure: %d hPa\n", currentWeather.pressure);
        
        if (currentWeather.isStormy) {
            printf("Warning: Storm approaching!\n");
        }

        printf("\n");
    }

    printf("Weather simulation complete.\n");

    return 0;
}