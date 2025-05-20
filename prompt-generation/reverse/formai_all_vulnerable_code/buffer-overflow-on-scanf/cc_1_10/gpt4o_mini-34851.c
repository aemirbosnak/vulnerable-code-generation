//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DAYS 7
#define MAX_CONDITIONS 5

// Weather conditions
const char* conditions[MAX_CONDITIONS] = {
    "Sunny",
    "Cloudy",
    "Rainy",
    "Windy",
    "Stormy"
};

// Day structure
typedef struct {
    int day;
    char condition[20];
    int high_temp;
    int low_temp;
} WeatherDay;

// Function to generate random weather data
void generateWeather(WeatherDay* forecast) {
    for (int i = 0; i < MAX_DAYS; i++) {
        forecast[i].day = i + 1;
        strcpy(forecast[i].condition, conditions[rand() % MAX_CONDITIONS]);
        forecast[i].high_temp = rand() % 21 + 15; // Random high temp between 15 and 35
        forecast[i].low_temp = rand() % 11 + 5;   // Random low temp between 5 and 15
    }
}

// Function to display the weather forecast
void displayForecast(const WeatherDay* forecast) {
    printf("Weather Forecast for the Week:\n");
    printf("Day\tCondition\tHigh Temp\tLow Temp\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("%d\t%s\t\t%d°C\t\t%d°C\n", 
                forecast[i].day, 
                forecast[i].condition, 
                forecast[i].high_temp, 
                forecast[i].low_temp);
    }
    printf("--------------------------------------------------\n");
}

// Function to display the weather for a specific day
void displayDailyForecast(const WeatherDay* forecast, int day) {
    if (day < 1 || day > MAX_DAYS) {
        printf("Invalid day number. Please enter a number between 1 and %d.\n", MAX_DAYS);
        return;
    }

    printf("Weather Forecast for Day %d:\n", day);
    printf("Condition: %s\n", forecast[day - 1].condition);
    printf("High Temperature: %d°C\n", forecast[day - 1].high_temp);
    printf("Low Temperature: %d°C\n", forecast[day - 1].low_temp);
}

// Main function
int main() {
    srand(time(NULL));  // Seed for random number generation

    WeatherDay forecast[MAX_DAYS];
    generateWeather(forecast);

    int choice;
    while (1) {
        printf("1. View Weekly Forecast\n");
        printf("2. View Specific Day Forecast\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayForecast(forecast);
                break;
            case 2:
                {
                    int day;
                    printf("Enter day number (1 to %d): ", MAX_DAYS);
                    scanf("%d", &day);
                    displayDailyForecast(forecast, day);
                }
                break;
            case 3:
                printf("Exiting the program. Have a nice day!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}