//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_TEMPERATURES 50

// Function to initialize weather data for a city
void init_weather(int city, int *temperatures, time_t start_time) {
    srand(start_time);
    for (int i = 0; i < MAX_TEMPERATURES; i++) {
        temperatures[i] = rand() % 41 - 20; // Random temperature between -20 and 40 degrees Celsius
    }
}

// Function to print weather data for a city
void print_weather(int city, int temperatures[], time_t current_time) {
    printf("City %d weather at %s:", city, ctime(&current_time));
    for (int i = 0; i < MAX_TEMPERATURES; i++) {
        printf(" %d", temperatures[i]);
    }
    printf("\n");
}

// Recursive function to simulate weather changes over time
void simulate_weather(int city, int temperatures[], time_t start_time, time_t end_time, time_t current_time) {
    if (current_time >= end_time) {
        return;
    }

    // Update weather data every hour
    time_t next_update = start_time + 3600;
    if (next_update <= current_time) {
        init_weather(city, temperatures, current_time);
        next_update = current_time + 3600;
    }

    // Print weather data every 6 hours
    if ((current_time - start_time) % 21600 == 0) {
        print_weather(city, temperatures, current_time);
    }

    simulate_weather(city, temperatures, start_time, end_time, next_update);
}

int main() {
    int cities[MAX_CITIES];
    int temperatures[MAX_CITIES][MAX_TEMPERATURES];
    time_t start_time = time(NULL);
    time_t end_time = start_time + 7 * 24 * 3600; // Simulate one week

    for (int i = 0; i < MAX_CITIES; i++) {
        cities[i] = i + 1;
        init_weather(i + 1, temperatures[i], start_time);
    }

    for (int i = 0; i < MAX_CITIES; i++) {
        simulate_weather(cities[i], temperatures[i], start_time, end_time, start_time);
    }

    return 0;
}