//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 10
#define NUM_CONDITIONS 3

// Weather conditions
const char *conditions[] = {
    "Sunny",
    "Rainy",
    "Cloudy"
};

// Function to simulate weather for a given day
void simulateWeather(int day) {
    if (day >= DAYS) {
        return; // Base case: stop after simulating DAYS
    }

    // Generate a random index to pick a weather condition
    int randomIndex = rand() % NUM_CONDITIONS;
    printf("Day %d: %s\n", day + 1, conditions[randomIndex]);

    // Recursive call for the next day
    simulateWeather(day + 1);
}

// Function to prompt user for weather simulation
void weatherSimulationMenu() {
    int choice;

    printf("Weather Simulation Menu:\n");
    printf("1. Simulate weather for next 10 days\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    // Process user's choice
    switch (choice) {
        case 1:
            // Call weather simulation starting from day 0
            printf("Simulating weather...\n");
            simulateWeather(0);
            weatherSimulationMenu(); // show menu again after simulation
            break;
        case 2:
            printf("Exiting program. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid option, please try again.\n");
            weatherSimulationMenu(); // show menu again
            break;
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Start the weather simulation menu
    weatherSimulationMenu();

    return 0;
}