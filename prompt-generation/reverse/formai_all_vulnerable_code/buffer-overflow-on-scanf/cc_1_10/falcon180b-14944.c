//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100

struct City {
    char name[20];
    int temperature;
    int humidity;
};

int main() {
    int num_cities;
    int i;
    struct City cities[MAX_CITIES];
    char choice;

    // Get number of cities from user
    printf("Enter number of cities: ");
    scanf("%d", &num_cities);

    // Initialize random seed
    srand(time(NULL));

    // Populate cities with random names and weather conditions
    for (i = 0; i < num_cities; i++) {
        sprintf(cities[i].name, "City %d", i + 1);
        cities[i].temperature = rand() % 40 + 10;
        cities[i].humidity = rand() % 100;
    }

    // Display initial weather conditions for all cities
    printf("\nInitial weather conditions:\n");
    for (i = 0; i < num_cities; i++) {
        printf("City %s: Temperature %dC, Humidity %d%%\n", cities[i].name, cities[i].temperature, cities[i].humidity);
    }

    // Main simulation loop
    while (1) {
        // Display menu options
        printf("\nSelect an option:\n");
        printf("1. Display weather conditions\n");
        printf("2. Change weather conditions\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Process user choice
        switch (choice) {
        case '1':
            // Display weather conditions for all cities
            printf("\nCurrent weather conditions:\n");
            for (i = 0; i < num_cities; i++) {
                printf("City %s: Temperature %dC, Humidity %d%%\n", cities[i].name, cities[i].temperature, cities[i].humidity);
            }
            break;

        case '2':
            // Change weather conditions for selected city
            printf("\nEnter city name: ");
            scanf(" %s", cities[0].name);
            printf("Enter new temperature (10-50C): ");
            scanf("%d", &cities[0].temperature);
            printf("Enter new humidity (0-100%%): ");
            scanf("%d", &cities[0].humidity);
            printf("\nWeather conditions updated for City %s:\n", cities[0].name);
            printf("Temperature %dC, Humidity %d%%\n", cities[0].temperature, cities[0].humidity);
            break;

        case '3':
            // Exit program
            printf("\nExiting program...\n");
            exit(0);

        default:
            // Invalid choice
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}