//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_VELOCITY 10000  // in km/h
#define EARTH_RADIUS 6371   // in km

typedef struct {
    char name[50];
    double distance_from_earth; // in km
    double population;           // in billions
    double average_velocity;     // in km/h
} Planet;

double calculate_probability(Planet planet) {
    double risk_factor = planet.distance_from_earth / EARTH_RADIUS;
    double population_factor = planet.population * 0.1;  // Convert billions to % scale
    double velocity_factor = MAX_VELOCITY / planet.average_velocity;

    double probability = (risk_factor + population_factor - velocity_factor) * 10;
    if(probability < 0) probability = 0;
    if(probability > 100) probability = 100;

    return probability;
}

void display_planet_info(Planet planet) {
    printf("Planet Name: %s\n", planet.name);
    printf("Distance from Earth: %.2f km\n", planet.distance_from_earth);
    printf("Population (in billions): %.2f\n", planet.population);
    printf("Average Velocity of Alien Ships: %.2f km/h\n", planet.average_velocity);
    printf("\nAlien Invasion Probability: %.2f%%\n", calculate_probability(planet));
}

int main() {
    srand(time(NULL));
    Planet planets[MAX_PLANETS];
    int count = 0;

    printf("Alien Invasion Probability Calculator\n");
    printf("======================================\n");

    for (int i = 0; i < MAX_PLANETS; ++i) {
        printf("Enter details for Planet %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", planets[i].name);
        
        planets[i].distance_from_earth = (rand() % 20000) + 1000; // Distance between 1,000 km and 20,000 km
        planets[i].population = (rand() % 10) + 1; // Population between 1 and 10 billion
        planets[i].average_velocity = (rand() % MAX_VELOCITY) + 100; // Minimum velocity 100 km/h
        
        display_planet_info(planets[i]);
        printf("--------------------------------------\n");
        count++;
        
        printf("Process another planet? (1 for Yes, 0 for No): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 0) break;
    }

    printf("\nAdventure concludes with a total of %d planets processed!\n", count);
    printf("Best of luck in your interstellar endeavors!\n");
    return 0;
}