//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the global variables
int temperature = 0;
int humidity = 0;
int wind_speed = 0;
int wind_direction = 0;
int pressure = 0;
int uv_index = 0;

// Define the function to get the current weather data
void get_weather_data() {
    printf("Getting weather data...\n");
    // Simulate waiting for weather data
    sleep(2);
    printf("Weather data received!\n");
    temperature = rand() % 100;
    humidity = rand() % 100;
    wind_speed = rand() % 100;
    wind_direction = rand() % 360;
    pressure = rand() % 1000;
    uv_index = rand() % 11;
}

// Define the function to display the weather data
void display_weather_data() {
    printf("Current weather data:\n");
    printf("Temperature: %d\n", temperature);
    printf("Humidity: %d\n", humidity);
    printf("Wind speed: %d\n", wind_speed);
    printf("Wind direction: %d\n", wind_direction);
    printf("Pressure: %d\n", pressure);
    printf("UV index: %d\n", uv_index);
}

// Define the main function
int main() {
    int choice;
    while(1) {
        printf("\n");
        printf("1. Get weather data\n");
        printf("2. Display weather data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                get_weather_data();
                break;
            case 2:
                display_weather_data();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}