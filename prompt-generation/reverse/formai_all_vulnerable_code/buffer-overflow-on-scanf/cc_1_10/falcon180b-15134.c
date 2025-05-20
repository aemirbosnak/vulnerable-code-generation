//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define global variables
int temperature;
int humidity;
int windSpeed;
int cloudCoverage;
int precipitation;
int airPressure;

// Function to generate random weather conditions
void generateWeather() {
    srand(time(NULL));

    temperature = rand() % 30 + 1;
    humidity = rand() % 100 + 1;
    windSpeed = rand() % 20 + 1;
    cloudCoverage = rand() % 50 + 1;
    precipitation = rand() % 2;
    airPressure = rand() % 1013 + 1;

    printf("Current weather conditions:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind speed: %d km/h\n", windSpeed);
    printf("Cloud coverage: %d%%\n", cloudCoverage);
    if (precipitation == 1) {
        printf("Precipitation: Rain\n");
    } else {
        printf("Precipitation: None\n");
    }
    printf("Air pressure: %d hPa\n", airPressure);
}

int main() {
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Generate weather conditions\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateWeather();
                break;
            case 2:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 2);

    return 0;
}