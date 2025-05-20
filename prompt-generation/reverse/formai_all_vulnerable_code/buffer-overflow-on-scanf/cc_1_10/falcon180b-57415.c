//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_TEMPERATURES 100

struct city {
    char name[20];
    int temperature;
};

void generate_random_city(struct city *city) {
    city->temperature = rand() % 40 + 1; // Random temperature between 1 and 40 degrees Celsius
    sprintf(city->name, "City %d", rand() % MAX_CITIES + 1); // Random city name
}

int main() {
    struct city cities[MAX_CITIES];
    int i, j;
    char choice;

    srand(time(NULL)); // Seed the random number generator with the current time

    // Initialize the cities with random temperatures and names
    for (i = 0; i < MAX_CITIES; i++) {
        generate_random_city(&cities[i]);
    }

    // Print the initial weather conditions
    printf("Initial weather conditions:\n");
    for (i = 0; i < MAX_CITIES; i++) {
        printf("%s: %d degrees Celsius\n", cities[i].name, cities[i].temperature);
    }

    do {
        // Simulate weather changes
        for (i = 0; i < MAX_CITIES; i++) {
            cities[i].temperature += rand() % 5 - 2; // Random temperature change between -2 and 2 degrees Celsius
        }

        // Print the updated weather conditions
        printf("\nWeather conditions after 1 hour:\n");
        for (i = 0; i < MAX_CITIES; i++) {
            printf("%s: %d degrees Celsius\n", cities[i].name, cities[i].temperature);
        }

        // Ask the user if they want to continue the simulation
        printf("\nDo you want to continue the simulation? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}