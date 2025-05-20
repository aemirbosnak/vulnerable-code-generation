//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum distance of each planet from the spaceship (in light years)
#define MAX_PLANET_DISTANCE 30

// Define the maximum number of aliens that can be encountered on each planet
#define MAX_ALIENS 10

// Define the possible outcomes of a battle with an alien
typedef enum {
    ALIEN_DEFEAT,
    SPACESHIP_DEFEAT,
    NEUTRAL
} BattleOutcome;

// Define a struct for each planet in the game
typedef struct {
    char name[20];
    int distance;
    int num_aliens;
    int alien_strength[MAX_ALIENS];
} Planet;

// Define a function to calculate the strength of a group of aliens
int calculate_alien_strength(int* alien_strength, int num_aliens) {
    int total_strength = 0;
    for (int i = 0; i < num_aliens; i++) {
        total_strength += alien_strength[i];
    }
    return total_strength;
}

// Define a function to simulate a battle between the spaceship and a group of aliens
BattleOutcome simulate_battle(int spaceship_strength, int* alien_strength, int num_aliens) {
    int alien_total_strength = calculate_alien_strength(alien_strength, num_aliens);
    if (spaceship_strength > alien_total_strength) {
        return ALIEN_DEFEAT;
    } else if (spaceship_strength < alien_total_strength) {
        return SPACESHIP_DEFEAT;
    } else {
        return NEUTRAL;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create an array of planets
    Planet planets[5] = {
        {"Alderaan", rand() % MAX_PLANET_DISTANCE + 1, rand() % MAX_ALIENS + 1, {1, 2, 3}},
        {"Tatooine", rand() % MAX_PLANET_DISTANCE + 1, rand() % MAX_ALIENS + 1, {2, 3, 4}},
        {"Naboo", rand() % MAX_PLANET_DISTANCE + 1, rand() % MAX_ALIENS + 1, {3, 4, 5}},
        {"Coruscant", rand() % MAX_PLANET_DISTANCE + 1, rand() % MAX_ALIENS + 1, {4, 5, 6}},
        {"Bespin", rand() % MAX_PLANET_DISTANCE + 1, rand() % MAX_ALIENS + 1, {5, 6, 7}}
    };
    
    // Set the strength of the spaceship
    int spaceship_strength = 10;
    
    // Print out the list of planets and their properties
    printf("Welcome to the Procedural Space Adventure!\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s (Distance: %d light years, Aliens: %d)\n", i + 1, planets[i].name, planets[i].distance, planets[i].num_aliens);
    }
    
    // Prompt the user to select a planet
    int selection = 0;
    while (selection < 1 || selection > 5) {
        printf("Please select a planet: ");
        scanf("%d", &selection);
    }
    
    // Calculate the strength of the aliens on the selected planet
    int planet_strength = calculate_alien_strength(planets[selection - 1].alien_strength, planets[selection - 1].num_aliens);
    
    // Simulate a battle with the aliens, and print the outcome
    printf("You have encountered %d aliens with a total strength of %d.\n", planets[selection - 1].num_aliens, planet_strength);
    BattleOutcome outcome = simulate_battle(spaceship_strength, planets[selection - 1].alien_strength, planets[selection - 1].num_aliens);
    if (outcome == ALIEN_DEFEAT) {
        printf("You have successfully defeated the aliens and can continue your space adventure!\n");
    } else if (outcome == SPACESHIP_DEFEAT) {
        printf("The aliens have defeated your spaceship and your space adventure has come to an end.\n");
    } else {
        printf("The battle was a draw and you must retreat to your spaceship to try again.\n");
    }
    
    return 0;
}