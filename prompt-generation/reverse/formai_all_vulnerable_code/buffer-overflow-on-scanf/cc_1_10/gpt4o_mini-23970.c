//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define PROBABILITY_THRESHOLD 0.5

// Structure to hold city data
typedef struct {
    char name[50];
    double alien_invasion_probability; // Probability of an alien invasion in this city
} City;

// Function to initialize a city with a name and a random probability
void initialize_city(City *city, const char *name) {
    strcpy(city->name, name);
    city->alien_invasion_probability = ((double) rand() / RAND_MAX) * 1.0; // Random probability between 0 and 1
}

// Function to simulate alien invasion based on probability
int simulate_invasion(double probability) {
    return (rand() / (double)RAND_MAX) < probability; // Returns 1 for invasion, 0 otherwise
}

// Function to display invasion results
void display_invasion_results(City cities[], int num_cities) {
    printf("\n---- Alien Invasion Results ----\n");
    for (int i = 0; i < num_cities; i++) {
        if (simulate_invasion(cities[i].alien_invasion_probability)) {
            printf("Invasion occurred in %s (Probability: %.2f)\n", cities[i].name, cities[i].alien_invasion_probability);
        } else {
            printf("No invasion in %s (Probability: %.2f)\n", cities[i].name, cities[i].alien_invasion_probability);
        }
    }
    printf("---------------------------------\n");
}

// Function to rank cities by invasion probability
void rank_cities(City cities[], int num_cities) {
    for (int i = 0; i < num_cities - 1; i++) {
        for (int j = 0; j < num_cities - i - 1; j++) {
            if (cities[j].alien_invasion_probability < cities[j + 1].alien_invasion_probability) {
                // Swap cities
                City temp = cities[j];
                cities[j] = cities[j + 1];
                cities[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed RNG with current time
    int num_cities;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of cities to simulate (1-%d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    // Input validation
    if (num_cities < 1 || num_cities > MAX_CITIES) {
        printf("Invalid number of cities. Please restart the program with a valid input.\n");
        return 1;
    }

    City cities[MAX_CITIES];

    // Initialize cities with random invasion probabilities
    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        char name[50];
        scanf("%s", name);
        initialize_city(&cities[i], name);
    }

    // Display initial probabilities
    printf("\n---- Initial Alien Invasion Probabilities ----\n");
    for (int i = 0; i < num_cities; i++) {
        printf("%s: Probability %.2f\n", cities[i].name, cities[i].alien_invasion_probability);
    }
    printf("-----------------------------------------------\n");

    // Simulate invasions
    display_invasion_results(cities, num_cities);

    // Rank and display cities by invasion probabilities
    rank_cities(cities, num_cities);
    printf("\n---- Ranked Cities by Invasion Probability ----\n");
    for (int i = 0; i < num_cities; i++) {
        printf("%d. %s: Probability %.2f\n", i + 1, cities[i].name, cities[i].alien_invasion_probability);
    }
    printf("-----------------------------------------------\n");

    return 0;
}