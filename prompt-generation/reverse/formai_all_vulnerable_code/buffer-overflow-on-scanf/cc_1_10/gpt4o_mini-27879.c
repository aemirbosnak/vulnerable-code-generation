//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 100
#define MAX_LIFE_FORMS 1000
#define ALIEN_PROBABILITY_MULTIPLIER 0.05 // Base probability factor for life forming aliens.

typedef struct {
    char name[20];
    int distance_from_earth; // in light years
    int number_of_life_forms;
    float alien_invasion_probability;
} Planet;

void initialize_planets(Planet planets[], int count) {
    const char *planet_names[] = {
        "Mars", "Venus", "Jupiter", "Saturn", "Mercury", "Uranus", "Neptune", "Pluto", 
        "Proxima Centauri b", "Kepler-186f", "HD 40307g", "Gliese 581g", "TRAPPIST-1e", 
        "K2-18b", "LHS 1140 b", "Teegarden's Star b", "Ross 128 b", "GJ 357 d", "Luyten b",
        "YZ Ceti b"
    };

    for (int i = 0; i < count; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", 
                planet_names[rand() % (sizeof(planet_names)/sizeof(planet_names[0]))]);
        planets[i].distance_from_earth = rand() % 1001 + 1; // Distance range from 1 to 1000 light years.
        planets[i].number_of_life_forms = rand() % MAX_LIFE_FORMS;
        planets[i].alien_invasion_probability = 0.0f; // Initial probability.
    }
}

void calculate_alien_invasion_probabilities(Planet planets[], int count) {
    for (int i = 0; i < count; i++) {
        // Probability based on distance and number of life forms.
        planets[i].alien_invasion_probability = 
            ALIEN_PROBABILITY_MULTIPLIER * planets[i].number_of_life_forms / (float)planets[i].distance_from_earth;
    }
}

void display_planets(const Planet planets[], int count) {
    printf("%-20s %-18s %-20s %-30s\n", "Planet Name", "Distance (ly)", "Life Forms", "Invasion Probability");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-18d %-20d %-30.6f\n", 
            planets[i].name, 
            planets[i].distance_from_earth, 
            planets[i].number_of_life_forms, 
            planets[i].alien_invasion_probability);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation.
    
    int num_planets;
    printf("Enter the number of planets to analyze (up to %d): ", MAX_PLANETS);
    scanf("%d", &num_planets);
    
    if (num_planets > MAX_PLANETS || num_planets < 1) {
        printf("Invalid number of planets. Please enter a number between 1 and %d.\n", MAX_PLANETS);
        return 1;
    }
    
    Planet planets[MAX_PLANETS];
    initialize_planets(planets, num_planets);
    calculate_alien_invasion_probabilities(planets, num_planets);
    display_planets(planets, num_planets);
    
    return 0;
}