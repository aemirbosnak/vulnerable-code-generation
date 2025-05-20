//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Character graphics for weather symbols
const char* weather_symbols[] = {
    "   ",  // Clear
    "\u2601",  // Sunny
    "\u2603",  // Partly cloudy
    "\u2604",  // Cloudy
    "\u2612",  // Rainy
    "\u2602",  // Snowy
    "\u260B",  // Thunderstorm
};

// Probabilities for each weather type (in percent)
const int weather_probabilities[] = {
    20,  // Clear
    30,  // Sunny
    20,  // Partly cloudy
    15,  // Cloudy
    10,  // Rainy
    5,   // Snowy
    5,   // Thunderstorm
};

// Function to generate a random number in the range [0, 100]
int random_int(int max) {
    return rand() % (max + 1);
}

// Function to generate a random weather type
int random_weather() {
    int total_probability = 0;
    for (int i = 0; i < 7; i++) {
        total_probability += weather_probabilities[i];
    }

    int random_number = random_int(total_probability);
    int weather_type = 0;
    while (random_number >= weather_probabilities[weather_type]) {
        random_number -= weather_probabilities[weather_type];
        weather_type++;
    }

    return weather_type;
}

// Function to print a weather forecast for a given day
void print_weather_forecast(int day) {
    int weather_type = random_weather();
    printf("Day %d: %s\n", day, weather_symbols[weather_type]);
}

int main() {
    // Set the random seed using the current time
    srand(time(NULL));

    // Print a weather forecast for the next 7 days
    for (int day = 1; day <= 7; day++) {
        print_weather_forecast(day);
    }

    return 0;
}