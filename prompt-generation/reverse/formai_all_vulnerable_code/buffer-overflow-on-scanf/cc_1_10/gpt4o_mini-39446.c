//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PLANETS 100
#define MAX_ALIENS 1000

typedef struct {
    double distance;
    double population_density;
    double technology_level;
    int alien_presence;
} Planet;

void initialize_planets(Planet *planets, int num_planets);
void calculate_probabilities(Planet *planets, int num_planets, double *probabilities);
void display_probabilities(Planet *planets, int num_planets, double *probabilities);
int random_alien_presence(void);

int main() {
    int num_planets;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    printf("Enter the number of planets (1 to %d): ", MAX_PLANETS);
    scanf("%d", &num_planets);
    
    if (num_planets < 1 || num_planets > MAX_PLANETS) {
        printf("Invalid number of planets. Exiting.\n");
        return 1;
    }
    
    Planet planets[MAX_PLANETS];
    double probabilities[MAX_PLANETS];
    
    initialize_planets(planets, num_planets);
    calculate_probabilities(planets, num_planets, probabilities);
    display_probabilities(planets, num_planets, probabilities);
    
    return 0;
}

void initialize_planets(Planet *planets, int num_planets) {
    srand(time(NULL));
    
    for (int i = 0; i < num_planets; i++) {
        planets[i].distance = (double)(rand() % 1000 + 1); // distance in light years
        planets[i].population_density = (double)(rand() % 100 + 1); // people per square km
        planets[i].technology_level = (double)(rand() % 10); // scale from 0 to 10
        planets[i].alien_presence = random_alien_presence();
    }
}

int random_alien_presence(void) {
    return rand() % 2; // 0 for no, 1 for yes
}

void calculate_probabilities(Planet *planets, int num_planets, double *probabilities) {
    for (int i = 0; i < num_planets; i++) {
        double base_probability = 0.1; // Starting chance of invasion

        // Modify probability based on distance (the further, the lesser the chance)
        double distance_factor = 1.0 / (1 + planets[i].distance / 500);
        
        // Modify probability based on population density
        double population_factor = planets[i].population_density / 100;
        
        // Modify probability based on technology
        double tech_factor = 1 + (planets[i].technology_level / 10);

        // Calculate final probability
        probabilities[i] = base_probability * distance_factor * population_factor * tech_factor;

        // Include existing alien presence
        if (planets[i].alien_presence) {
            probabilities[i] += 0.2; // Increase by 20% if aliens are already present
        }
        
        // Ensure probability does not exceed 1
        if (probabilities[i] > 1) {
            probabilities[i] = 1;
        }
    }
}

void display_probabilities(Planet *planets, int num_planets, double *probabilities) {
    printf("\nResults of Alien Invasion Probability:\n");
    printf("----------------------------------------------------\n");
    printf("| Planet | Distance (light years) | Probability (%) |\n");
    printf("----------------------------------------------------\n");
    
    for (int i = 0; i < num_planets; i++) {
        printf("|   %-5d |        %-18.2f |      %-9.2f    |\n", 
               i + 1, planets[i].distance, probabilities[i] * 100);
    }
    
    printf("----------------------------------------------------\n");
}