//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of locations
#define MAX_LOCATIONS 10

// Define the structure for each location
typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int windSpeed;
} Location;

// Define the global variables
int numLocations = 0;
Location locations[MAX_LOCATIONS];

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Prompt the user for the number of locations
    printf("Enter the number of locations (1-10): ");
    scanf("%d", &numLocations);

    // Loop through each location and initialize its properties
    for (int i = 0; i < numLocations; i++) {
        locations[i].temperature = rand() % 50 + 1;
        locations[i].humidity = rand() % 100;
        locations[i].windSpeed = rand() % 20 + 1;
    }

    // Print the initial weather conditions for each location
    printf("\nInitial weather conditions:\n");
    for (int i = 0; i < numLocations; i++) {
        printf("Location %d: Temperature %d degrees, Humidity %d%, Wind Speed %d mph\n", i+1, locations[i].temperature, locations[i].humidity, locations[i].windSpeed);
    }

    // Simulate the weather changes over time
    for (int i = 0; i < 100; i++) {
        // Loop through each location and update its properties
        for (int j = 0; j < numLocations; j++) {
            locations[j].temperature += rand() % 3 - 1;
            locations[j].humidity += rand() % 10;
            locations[j].windSpeed += rand() % 5 - 2;

            // Check if the temperature is too high or too low
            if (locations[j].temperature > 100) {
                locations[j].temperature = 100;
            } else if (locations[j].temperature < 0) {
                locations[j].temperature = 0;
            }
        }

        // Print the updated weather conditions for each location
        printf("\nWeather conditions after %d minutes:\n", i+1);
        for (int j = 0; j < numLocations; j++) {
            printf("Location %d: Temperature %d degrees, Humidity %d%, Wind Speed %d mph\n", j+1, locations[j].temperature, locations[j].humidity, locations[j].windSpeed);
        }
    }

    return 0;
}