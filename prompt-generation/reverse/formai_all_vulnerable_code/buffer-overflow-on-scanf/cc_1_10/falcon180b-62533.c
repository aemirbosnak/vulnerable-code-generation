//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DAY 86400 // seconds in a day
#define YEAR 31536000 // seconds in a year

// struct to hold weather data
typedef struct {
    int temperature; // in Celsius
    int humidity; // in percentage
    int wind_speed; // in meters per second
} Weather;

// function to generate random weather data
Weather generate_weather() {
    Weather w;
    w.temperature = rand() % 41 - 20; // range from -20 to 20 degrees Celsius
    w.humidity = rand() % 101; // range from 0 to 100%
    w.wind_speed = rand() % 21; // range from 0 to 20 m/s
    return w;
}

// function to print weather data
void print_weather(Weather w) {
    printf("Temperature: %d degrees Celsius\n", w.temperature);
    printf("Humidity: %d%%\n", w.humidity);
    printf("Wind speed: %d m/s\n", w.wind_speed);
}

// function to simulate weather for a given number of days
void simulate_weather(int days, int seed) {
    srand(seed); // set seed for random number generator
    int i;
    for (i = 0; i < days; i++) {
        Weather w = generate_weather();
        print_weather(w);
        printf("\n");
        sleep(1); // pause for 1 second to simulate passage of time
    }
}

int main() {
    int days, seed;
    printf("Enter number of days to simulate weather: ");
    scanf("%d", &days);
    printf("Enter seed for random number generator: ");
    scanf("%d", &seed);
    simulate_weather(days, seed);
    return 0;
}