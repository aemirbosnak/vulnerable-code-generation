//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void simulateWeather(int numDays);
void printWeather(int temperature, int humidity, int windSpeed);

int main() {
    int numDays;

    printf("Enter the number of days to simulate the weather: ");
    scanf("%d", &numDays);

    simulateWeather(numDays);

    return 0;
}

void simulateWeather(int numDays) {
    int i;
    int temperature = 0;
    int humidity = 0;
    int windSpeed = 0;
    int random = 0;

    srand(time(0)); // Seed the random number generator

    for (i = 0; i < numDays; i++) {
        // Simulate temperature changes
        random = rand() % 10;
        if (random < 5) {
            temperature++;
        } else {
            temperature--;
        }

        // Simulate humidity changes
        random = rand() % 10;
        if (random < 5) {
            humidity++;
        } else {
            humidity--;
        }

        // Simulate wind speed changes
        random = rand() % 10;
        if (random < 5) {
            windSpeed++;
        } else {
            windSpeed--;
        }

        // Print the weather conditions for the day
        printWeather(temperature, humidity, windSpeed);
    }
}

void printWeather(int temperature, int humidity, int windSpeed) {
    printf("\nToday's weather:\n");
    printf("Temperature: %d degrees\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind speed: %d mph\n", windSpeed);
}