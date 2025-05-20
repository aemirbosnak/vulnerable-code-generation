//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOCATIONS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float temperature; // in Celsius
    float humidity;    // percentage
} WeatherLocation;

void generateRandomWeather(WeatherLocation* location) {
    location->temperature = (rand() % 401 - 200) / 10.0; // Generate temp between -20.0 to 20.0
    location->humidity = rand() % 101; // Generate humidity between 0 and 100%
}

void displayWeather(const WeatherLocation* location) {
    printf("Location: %s\n", location->name);
    printf("Temperature: %.1f °C\n", location->temperature);
    printf("Humidity: %.1f%%\n", location->humidity);
}

void displayAllWeather(WeatherLocation locations[], int count) {
    printf("\nWeather Report\n");
    for (int i = 0; i < count; i++) {
        displayWeather(&locations[i]);
        printf("-------------------------\n");
    }
}

void sortLocationsByTemperature(WeatherLocation locations[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (locations[j].temperature > locations[j + 1].temperature) {
                WeatherLocation temp = locations[j];
                locations[j] = locations[j + 1];
                locations[j + 1] = temp;
            }
        }
    }
}

void getUserInput(WeatherLocation* location) {
    printf("Enter location name (max %d characters): ", MAX_NAME_LENGTH - 1);
    fgets(location->name, MAX_NAME_LENGTH, stdin);
    location->name[strcspn(location->name, "\n")] = '\0'; // Remove newline character
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    WeatherLocation locations[MAX_LOCATIONS];
    int count = 0;
    char choice;

    do {
        if (count >= MAX_LOCATIONS) {
            printf("Maximum number of locations reached. Cannot add more.\n");
            break;
        }
        
        getUserInput(&locations[count]);
        generateRandomWeather(&locations[count]);
        count++;

        printf("Do you want to add another location? (y/n): ");
        scanf(" %c", &choice);
        while(getchar() != '\n'); // Clear input buffer
    } while (choice == 'y' || choice == 'Y');

    displayAllWeather(locations, count);

    printf("Sorting locations by temperature...\n");
    sortLocationsByTemperature(locations, count);
    displayAllWeather(locations, count);

    return 0;
}