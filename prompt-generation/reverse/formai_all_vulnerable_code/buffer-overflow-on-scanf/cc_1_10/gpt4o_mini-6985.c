//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_WEEK 7
#define MAX_TEMP 35
#define MIN_TEMP -10

const char *weather_conditions[] = {
    "Sunny",
    "Rainy",
    "Cloudy",
    "Snowy"
};

typedef struct {
    char condition[10];
    int temperature;
    int humidity;
} Weather;

void generate_weather(Weather *w) {
    int condition_index = rand() % 4;
    int temperature = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    int humidity = rand() % 101; // Humidity from 0 to 100

    strcpy(w->condition, weather_conditions[condition_index]);
    w->temperature = temperature;
    w->humidity = humidity;
}

void print_weather(Weather w, int day) {
    printf("Day %d: %s\n", day + 1, w.condition);
    printf("Temperature: %d°C\n", w.temperature);
    printf("Humidity: %d%%\n", w.humidity);
    printf("------------------------------\n");
}

void display_weather_forecast(Weather week_weather[DAYS_IN_WEEK]) {
    printf("Weekly Weather Forecast:\n");
    printf("=========================\n");
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        print_weather(week_weather[i], i);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Weather week_weather[DAYS_IN_WEEK];

    printf("Welcome to the Weekly Weather Simulator!\n");
    printf("Generating weather conditions for the week...\n");

    // Generate random weather for each day of the week
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        generate_weather(&week_weather[i]);
    }

    // Display the generated weather forecast
    display_weather_forecast(week_weather);

    // Allow user to query a specific day
    int query_day;
    printf("Enter a day number (1-7) to get detailed weather: ");
    scanf("%d", &query_day);

    if (query_day < 1 || query_day > DAYS_IN_WEEK) {
        printf("Invalid day! Please enter a number between 1 and 7.\n");
    } else {
        printf("Detailed weather for Day %d:\n", query_day);
        print_weather(week_weather[query_day - 1], query_day - 1);
    }

    printf("Thank you for using the Weekly Weather Simulator!\n");
    return 0;
}