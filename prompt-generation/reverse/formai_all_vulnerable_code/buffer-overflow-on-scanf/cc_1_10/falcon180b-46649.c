//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define global variables
int temperature;
int humidity;
int windSpeed;
int cloudCoverage;
int precipitation;

// Function to generate random weather data
void generateWeather() {
    srand(time(NULL));
    temperature = rand() % 101;
    humidity = rand() % 101;
    windSpeed = rand() % 101;
    cloudCoverage = rand() % 101;
    precipitation = rand() % 101;
}

// Function to print weather data
void printWeather() {
    printf("Temperature: %d degrees\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d mph\n", windSpeed);
    printf("Cloud Coverage: %d%%\n", cloudCoverage);
    printf("Precipitation: %d inches\n", precipitation);
}

// Main function
int main() {
    int choice;
    do {
        // Print menu
        printf("\nWEATHER SIMULATION\n");
        printf("1. Generate Weather Data\n");
        printf("2. Print Weather Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch(choice) {
            case 1:
                generateWeather();
                break;
            case 2:
                printWeather();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}