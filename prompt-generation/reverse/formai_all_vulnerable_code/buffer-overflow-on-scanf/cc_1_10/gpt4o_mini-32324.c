//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DAYS 30
#define MAX_TEMP 40
#define MIN_TEMP -10

typedef struct {
    int day;
    int month;
    int year;
    float temperature;
    float humidity;
    char *condition;
} WeatherDay;

const char *conditions[] = {"Sunny", "Cloudy", "Rainy", "Snowy", "Windy"};

WeatherDay generateWeather(int day, int month, int year) {
    WeatherDay wd;
    wd.day = day;
    wd.month = month;
    wd.year = year;
    
    wd.temperature = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    wd.humidity = (rand() % 100) + 1;  
    wd.condition = (char *)conditions[rand() % 5];

    return wd;
}

void displayWeather(WeatherDay wd) {
    printf("Date: %02d/%02d/%04d\n", wd.day, wd.month, wd.year);
    printf("Temperature: %.1f °C\n", wd.temperature);
    printf("Humidity: %.1f%%\n", wd.humidity);
    printf("Condition: %s\n", wd.condition);
    printf("-----------------------------------------\n");
}

void simulateMonthWeather(int month, int year) {
    srand(time(NULL));
    printf("Weather Simulation for %02d/%04d\n", month, year);
    printf("=========================================\n");

    for (int day = 1; day <= DAYS; ++day) {
        WeatherDay wd = generateWeather(day, month, year);
        displayWeather(wd);
        sleep(1); // Simulate delay for user reading
    }
}

void getUserInput(int *month, int *year) {
    printf("Enter the month (1-12): ");
    scanf("%d", month);
    printf("Enter the year (e.g., 2023): ");
    scanf("%d", year);
}

int main() {
    int month, year;
    getUserInput(&month, &year);
    if (month < 1 || month > 12 || year < 1900) {
        printf("Invalid input. Please enter a valid month (1-12) and year (>= 1900).\n");
        return 1;
    }
    
    simulateMonthWeather(month, year);

    return 0;
}