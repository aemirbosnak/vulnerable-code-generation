//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_MONTH 30
#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE -10

typedef struct {
    char *date; 
    int temperature; 
    int humidity; 
    int precipitation; 
} WeatherDay;

void generateRandomWeather(WeatherDay *day) {
    day->temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    day->humidity = rand() % 101;  // Humidity percentage from 0 to 100
    day->precipitation = rand() % 101; // Precipitation percentage from 0 to 100
}

void displayWeather(WeatherDay *day) {
    printf("Date: %s\n", day->date);
    printf("Temperature: %d°C\n", day->temperature);
    printf("Humidity: %d%%\n", day->humidity);
    printf("Chance of Precipitation: %d%%\n", day->precipitation);
    printf("--------------------------------\n");
}

void simulateWeather(int days) {
    WeatherDay weatherForecast[DAYS_IN_MONTH];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    for (int i = 0; i < days; ++i) {
        char date[11]; // Format: YYYY-MM-DD
        strftime(date, sizeof(date), "%Y-%m-%d", t);
        weatherForecast[i].date = strdup(date);
        generateRandomWeather(&weatherForecast[i]);

        // Increment the date
        t->tm_mday += 1;
        mktime(t); // Normalize the structure
    }
    
    printf("Weather Simulation for Next %d Days:\n", days);
    printf("--------------------------------\n");
    for (int i = 0; i < days; ++i) {
        displayWeather(&weatherForecast[i]);
        free(weatherForecast[i].date); // Free allocated memory for date
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int daysToSimulate = DAYS_IN_MONTH;

    printf("Welcome to the Weather Simulation Program!\n");
    printf("Simulating weather for the next %d days...\n", daysToSimulate);
    simulateWeather(daysToSimulate);
    
    printf("Weather simulation completed. Thank you for using the program!\n");
    return 0;
}