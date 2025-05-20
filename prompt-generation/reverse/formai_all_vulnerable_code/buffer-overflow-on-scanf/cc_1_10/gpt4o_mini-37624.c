//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100
#define NAME_LENGTH 50

// Structure to hold information about each city
typedef struct {
    char name[NAME_LENGTH];
    int population;
} City;

// Function to compare two cities for sorting purposes
int compare(const void *a, const void *b) {
    City *cityA = (City *)a;
    City *cityB = (City *)b;
    return cityA->population - cityB->population; // Sort by population
}

// Function to display city information
void displayCities(City cities[], int count) {
    printf("Cities in the Wasteland:\n");
    printf("----------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("City Name: %s, Population: %d\n", cities[i].name, cities[i].population);
    }
}

int main() {
    City cities[MAX_CITIES];
    int cityCount = 0;

    // In a post-apocalyptic world, gathering information about surviving cities is crucial.
    printf("Welcome to the Wasteland City Recorder\n");
    printf("Prepare to enter the names and populations of the cities you have encountered.\n");
    printf("To stop entering, type 'END' as the city name.\n");

    while (cityCount < MAX_CITIES) {
        printf("Enter city name (or 'END' to finish): ");
        scanf("%s", cities[cityCount].name);

        // Check for termination condition
        if (strcmp(cities[cityCount].name, "END") == 0) {
            break;
        }

        printf("Enter the population of %s: ", cities[cityCount].name);
        scanf("%d", &cities[cityCount].population);
        cityCount++;
    }

    // Check if we have any cities to sort
    if (cityCount == 0) {
        printf("No cities recorded. The Wasteland remains a mystery.\n");
        return 0;
    }

    // Log the details of the cities to be sorted
    printf("\nYou have entered %d cities. Sorting the data...\n", cityCount);

    // Sort the cities by their population
    qsort(cities, cityCount, sizeof(City), compare);

    // Display the sorted cities
    displayCities(cities, cityCount);

    // Finally, the notes of the ruins to ensure the future generations have a glimpse of the past.
    printf("\nThe survivors of tomorrow will learn from the remnants of today.\n");
    printf("May these records stand the test of time in the Wasteland.\n");

    return 0;
}