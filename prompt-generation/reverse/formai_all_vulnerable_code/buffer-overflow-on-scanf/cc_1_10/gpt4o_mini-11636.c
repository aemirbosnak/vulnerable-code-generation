//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WEATHER_TYPES 5
#define CITY_NAME "Wonderland"

const char *weather_types[MAX_WEATHER_TYPES] = {
    "Sunny",
    "Rainy",
    "Cloudy",
    "Stormy",
    "Snowy"
};

typedef struct {
    int temperature; // in Celsius
    int humidity;    // as a percentage
    int wind_speed;  // in km/h
    const char *weather_type;
} Weather;

void generate_weather(Weather *w) {
    w->temperature = (rand() % 41) - 10; // Range: -10 to 30 degrees Celsius
    w->humidity = rand() % 101;          // Range: 0 to 100%
    w->wind_speed = rand() % 91;         // Range: 0 to 90 km/h
    w->weather_type = weather_types[rand() % MAX_WEATHER_TYPES];
}

void display_weather(const Weather *w) {
    printf("Weather Report for %s:\n", CITY_NAME);
    printf("Temperature: %d°C\n", w->temperature);
    printf("Humidity: %d%%\n", w->humidity);
    printf("Wind Speed: %d km/h\n", w->wind_speed);
    printf("Weather Type: %s\n", w->weather_type);
}

void ask_for_continue() {
    char answer;
    printf("Do you want to generate another weather report? (y/n): ");
    scanf(" %c", &answer);
    if (answer == 'y' || answer == 'Y') {
        // Proceed to generate new weather
    } else {
        printf("Thank you for using the weather simulation program!\n");
        exit(0);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    Weather current_weather;

    printf("Welcome to the Weather Simulation Program for %s!\n", CITY_NAME);

    while (1) {
        generate_weather(&current_weather);
        display_weather(&current_weather);
        ask_for_continue();
    }

    return 0;
}