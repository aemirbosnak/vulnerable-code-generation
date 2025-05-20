//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define WEATHER_TYPES 5

// Structure to represent a city
typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int wind_speed;
    int precipitation;
} City;

// Function to generate random weather data for a city
void generate_weather(City* city) {
    srand(time(NULL));
    city->temperature = rand() % 40 + 1;
    city->humidity = rand() % 101;
    city->wind_speed = rand() % 21 + 1;
    city->precipitation = rand() % 101;
}

// Function to print weather data for a city
void print_weather(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d degrees Celsius\n", city.temperature);
    printf("Humidity: %d%%\n", city.humidity);
    printf("Wind Speed: %d km/h\n", city.wind_speed);
    printf("Precipitation: %d mm\n", city.precipitation);
    printf("\n");
}

// Function to simulate weather for all cities
void simulate_weather(City cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        generate_weather(&cities[i]);
        print_weather(cities[i]);
    }
}

int main() {
    // Initialize cities array
    City cities[MAX_CITIES];

    // Read city names from user
    printf("Enter city names (up to %d):\n", MAX_CITIES);
    for (int i = 0; i < MAX_CITIES; i++) {
        scanf("%s", cities[i].name);
    }

    // Simulate weather for all cities
    simulate_weather(cities, MAX_CITIES);

    return 0;
}