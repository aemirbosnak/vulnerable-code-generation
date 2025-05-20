//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 10

typedef struct {
    char name[20];
    float intelligenceLevel; // scale from 0.0 (not intelligent) to 1.0 (highly intelligent)
    float technologicalAdvancement; // scale from 0.0 (primitive) to 1.0 (advanced)
    float opennessToContact; // scale from 0.0 (hostile) to 1.0 (friendly)
} Planet;

float calculateInvasionProbability(Planet p) {
    float probability = (p.intelligenceLevel * p.technologicalAdvancement * p.opennessToContact);
    return probability * 100; // converting to percentage
}

void simulateInvasion(int num_simulations, Planet planets[], int num_planets) {
    int successful_invasions = 0;

    for (int i = 0; i < num_simulations; i++) {
        int planetIndex = rand() % num_planets;
        float invasion_chance = calculateInvasionProbability(planets[planetIndex]);

        // Using a random float to decide if the invasion succeeds
        float random_value = (float)rand() / (float)(RAND_MAX) * 100;
        if (random_value <= invasion_chance) {
            successful_invasions++;
            printf("Invasion successful on planet: %s\n", planets[planetIndex].name);
        } else {
            printf("Invasion failed on planet: %s\n", planets[planetIndex].name);
        }
    }

    printf("Total simulations: %d\n", num_simulations);
    printf("Successful invasions: %d (%.2f%%)\n", successful_invasions, 
           (float)successful_invasions / num_simulations * 100);
}

void initializePlanets(Planet planets[]) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "Planet_%d", i + 1);
        planets[i].intelligenceLevel = ((float)rand() / RAND_MAX) * 1.0; 
        planets[i].technologicalAdvancement = ((float)rand() / RAND_MAX) * 1.0; 
        planets[i].opennessToContact = ((float)rand() / RAND_MAX) * 1.0; 
    }
}

void displayPlanetInfo(Planet planets[], int num_planets) {
    printf("Planet Information:\n");
    printf("Name\t\tIntelligence\tTech Adv.\tOpenness\n");
    for (int i = 0; i < num_planets; i++) {
        printf("%s\t%.2f\t\t%.2f\t\t%.2f\n", planets[i].name, 
               planets[i].intelligenceLevel, 
               planets[i].technologicalAdvancement, 
               planets[i].opennessToContact);
    }
}

int main() {
    srand(time(NULL));
    Planet planets[NUM_PLANETS];
    initializePlanets(planets);

    displayPlanetInfo(planets, NUM_PLANETS);

    int num_simulations;
    printf("Enter the number of invasion simulations to run: ");
    scanf("%d", &num_simulations);

    if (num_simulations <= 0) {
        printf("Number of simulations must be a positive integer!\n");
        return 1;
    }

    simulateInvasion(num_simulations, planets, NUM_PLANETS);
    
    return 0;
}