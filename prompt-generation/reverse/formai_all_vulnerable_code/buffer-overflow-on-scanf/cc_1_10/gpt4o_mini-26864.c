//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LOCATIONS 5
#define TEMP_MIN -10
#define TEMP_MAX 35
#define HUMIDITY_MIN 0
#define HUMIDITY_MAX 100

typedef struct {
    char name[30];
    int temperature;
    int humidity;
    char condition[20];
} Weather;

const char* conditions[] = {
    "Sunny", "Cloudy", "Rainy", "Stormy", "Snowy"
};

void simulateWeather(Weather *weather) {
    weather->temperature = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    weather->humidity = rand() % (HUMIDITY_MAX - HUMIDITY_MIN + 1) + HUMIDITY_MIN;
    strcpy(weather->condition, conditions[rand() % (sizeof(conditions) / sizeof(conditions[0]))]);
}

void displayWeather(const Weather *weather) {
    printf("Weather in %s:\n", weather->name);
    printf("Temperature: %d°C\n", weather->temperature);
    printf("Humidity: %d%%\n", weather->humidity);
    printf("Condition: %s\n", weather->condition);
}

void displayMenu() {
    printf("Choose a location:\n");
    printf("1. New York\n");
    printf("2. Tokyo\n");
    printf("3. London\n");
    printf("4. Sydney\n");
    printf("5. Cape Town\n");
    printf("0. Exit\n");
}

int main() {
    srand(time(0));

    Weather locations[NUM_LOCATIONS] = {
        {"New York", 0, 0, ""},
        {"Tokyo", 0, 0, ""},
        {"London", 0, 0, ""},
        {"Sydney", 0, 0, ""},
        {"Cape Town", 0, 0, ""}
    };

    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the weather simulation. Have a great day!\n");
            break;
        } else if (choice < 1 || choice > NUM_LOCATIONS) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        // Simulate the weather for the chosen location
        simulateWeather(&locations[choice - 1]);
        // Display the weather
        displayWeather(&locations[choice - 1]);
        printf("\n");
    }

    return 0;
}