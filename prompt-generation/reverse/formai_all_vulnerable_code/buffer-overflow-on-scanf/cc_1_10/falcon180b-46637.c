//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Global variables
double temperature = 0;
double humidity = 0;
double pressure = 0;
double wind_speed = 0;
double wind_direction = 0;
char weather_condition[50];
char location[50];

// Function prototypes
void get_weather_data(char* api_key);
void display_weather_data();

int main() {
    char api_key[50];
    printf("Enter API Key: ");
    scanf("%s", api_key);

    get_weather_data(api_key);

    while(true) {
        display_weather_data();
        sleep(60); // Refresh every minute
    }

    return 0;
}

// Function to fetch weather data from API
void get_weather_data(char* api_key) {
    // TODO: Implement API call to fetch weather data and update global variables
}

// Function to display weather data on console
void display_weather_data() {
    printf("\n");
    printf("Current weather in %s:\n", location);
    printf("Temperature: %.2f *C\n", temperature);
    printf("Humidity: %.2f %%\n", humidity);
    printf("Pressure: %.2f hPa\n", pressure);
    printf("Wind Speed: %.2f m/s\n", wind_speed);
    printf("Wind Direction: %.2f degrees\n", wind_direction);
    printf("Weather Condition: %s\n", weather_condition);
}