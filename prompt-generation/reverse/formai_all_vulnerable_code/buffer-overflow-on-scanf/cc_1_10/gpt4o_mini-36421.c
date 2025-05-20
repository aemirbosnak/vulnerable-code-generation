//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 7
#define MAX_TEMP 40
#define MIN_TEMP -10
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0

typedef struct Weather {
    char day[10];
    int temperature; // in Celsius
    int humidity;    // in percentage
    char description[50];
} Weather;

void generateWeather(Weather *forecast, const char *days[]) {
    for (int i = 0; i < DAYS; i++) {
        forecast[i].temperature = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
        forecast[i].humidity = (rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1)) + MIN_HUMIDITY;

        // Generate a simple weather description
        if (forecast[i].humidity < 30) {
            sprintf(forecast[i].description, "Sunny");
        } else if (forecast[i].humidity < 60) {
            sprintf(forecast[i].description, "Partly Cloudy");
        } else {
            sprintf(forecast[i].description, "Rainy");
        }

        sprintf(forecast[i].day, "%s", days[i]);
    }
}

void printForecast(const Weather *forecast) {
    printf("\nWeekly Weather Forecast:\n");
    printf("-------------------------------------------------------\n");
    printf("| Day        | Temperature (°C) | Humidity (%%) | Description          |\n");
    printf("-------------------------------------------------------\n");
    
    for (int i = 0; i < DAYS; i++) {
        printf("| %-10s | %-17d | %-13d | %-20s |\n",
               forecast[i].day, forecast[i].temperature, forecast[i].humidity, forecast[i].description);
    }
    printf("-------------------------------------------------------\n");
}

void displayMenu() {
    printf("Welcome to the Weather Simulation!\n");
    printf("1. View Weekly Forecast\n");
    printf("2. Exit\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Weather forecast[DAYS];
    const char *days[DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    generateWeather(forecast, days);

    int choice;
    do {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printForecast(forecast);
                break;
            case 2:
                printf("Thank you for using the Weather Simulation. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}