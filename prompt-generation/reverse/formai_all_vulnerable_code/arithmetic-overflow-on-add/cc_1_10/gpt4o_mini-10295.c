//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of simulation days
#define MAX_DAYS 30

// Structure to hold weather information
typedef struct {
    char date[11];           // Date in YYYY-MM-DD format
    char condition[20];      // Weather condition
    float temperature;       // Temperature in Celsius
    float humidity;          // Humidity in percentage
} Weather;

// Function to generate a random weather condition
const char* generateWeatherCondition() {
    const char* conditions[] = {"Sunny", "Cloudy", "Rainy", "Stormy", "Snowy", "Foggy"};
    return conditions[rand() % 6];
}

// Function to simulate daily weather
void simulateWeather(Weather* weather, int day) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Set the date for the current day's weather
    sprintf(weather[day].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, day + 1);
    
    // Generate random weather condition
    strcpy(weather[day].condition, generateWeatherCondition());

    // Randomly generate temperature and humidity based on conditions
    if (strcmp(weather[day].condition, "Sunny") == 0) {
        weather[day].temperature = (rand() % 31) + 15; // 15 to 45 degrees
        weather[day].humidity = (rand() % 21) + 40;    // 40% to 60%
    } else if (strcmp(weather[day].condition, "Cloudy") == 0) {
        weather[day].temperature = (rand() % 11) + 10; // 10 to 20 degrees
        weather[day].humidity = (rand() % 21) + 60;    // 60% to 80%
    } else if (strcmp(weather[day].condition, "Rainy") == 0) {
        weather[day].temperature = (rand() % 16) + 5;  // 5 to 20 degrees
        weather[day].humidity = (rand() % 21) + 80;    // 80% to 100%
    } else if (strcmp(weather[day].condition, "Stormy") == 0) {
        weather[day].temperature = (rand() % 21) + 0;   // 0 to 20 degrees
        weather[day].humidity = (rand() % 21) + 70;     // 70% to 90%
    } else if (strcmp(weather[day].condition, "Snowy") == 0) {
        weather[day].temperature = (rand() % 6) - 5;    // -5 to 1 degree
        weather[day].humidity = (rand() % 21) + 60;     // 60% to 80%
    } else {
        weather[day].temperature = (rand() % 11) + 5;   // 5 to 15 degrees
        weather[day].humidity = (rand() % 41) + 30;     // 30% to 70%
    }
}

// Function to display the weather data
void displayWeather(Weather* weather, int days) {
    printf("Weather Simulation for the Month:\n");
    printf("--------------------------------------------------\n");
    printf("%-12s  %-10s  %-15s  %-10s\n", "Date", "Condition", "Temperature (°C)", "Humidity (%)");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < days; i++) {
        printf("%-12s  %-10s  %-15.2f  %-10.2f\n",
               weather[i].date,
               weather[i].condition,
               weather[i].temperature,
               weather[i].humidity);
    }
    printf("--------------------------------------------------\n");
}

// The main entry point of the program
int main() {
    Weather weather[MAX_DAYS];
    srand(time(NULL)); // Seed for random number generation

    // Simulate weather for MAX_DAYS
    for (int i = 0; i < MAX_DAYS; i++) {
        simulateWeather(weather, i);
    }

    // Display the simulated weather
    displayWeather(weather, MAX_DAYS);
    
    return 0;
}