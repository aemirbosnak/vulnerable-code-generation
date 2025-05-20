//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLANETS 9

typedef struct {
    char name[20];
    float distance_from_sun; // in millions of leagues
    float size;               // in leagues
    int moons;                // number of moons
} Planet;

void createPlanets(Planet *solSystem) {
    // Define the celestial bodies of the realm
    char *names[NUM_PLANETS] = {
        "Mercury", "Venus", "Earth", "Mars", "Jupiter", 
        "Saturn", "Uranus", "Neptune", "Pluto"
    };
  
    float distances[NUM_PLANETS] = {
        36.0, 67.0, 93.0, 142.0, 483.0, 
        886.0, 1783.0, 2793.0, 3670.0
    };
   
    float sizes[NUM_PLANETS] = {
        1.5, 3.5, 4.0, 2.5, 11.0, 
        9.0, 4.0, 3.5, 1.0
    };
    
    int moonsCount[NUM_PLANETS] = {
        0, 0, 1, 2, 79, 
        83, 27, 14, 5
    };
  
    for(int i = 0; i < NUM_PLANETS; i++) {
        snprintf(solSystem[i].name, sizeof(solSystem[i].name), "%s", names[i]);
        solSystem[i].distance_from_sun = distances[i];
        solSystem[i].size = sizes[i];
        solSystem[i].moons = moonsCount[i];
    }
}

void displaySolarSystem(Planet *solSystem) {
    printf("Behold the Celestial Bodies of the Solar System:\n");
    printf("---------------------------------------------------\n");
    printf("| Name       | Distance (millions of leagues) | Size (leagues) | Moons |\n");
    printf("---------------------------------------------------\n");
    for(int i = 0; i < NUM_PLANETS; i++) {
        printf("| %-10s | %-30.2f | %-15.2f | %-5d |\n",
               solSystem[i].name,
               solSystem[i].distance_from_sun,
               solSystem[i].size,
               solSystem[i].moons);
    }
    printf("---------------------------------------------------\n");
}

void celestialDance(int steps) {
    printf("Let us now witness the celestial dance of the planets:\n");
    for(int step = 1; step <= steps; step++) {
        printf("Step %d:\n", step);
        for(int i = 0; i < NUM_PLANETS; i++) {
            // Just a fanciful display of their movement
            printf(" - The beautiful %s circles around the Sun, journeying in the vastness of the cosmos!\n", 
                  ((Planet*)&(i))->name);
        }
        printf("And thus ends the step, as the tapestry of the night sky keeps weaving.\n");
    }
}

int main() {
    printf("Greetings, noble traveler! Welcome to the realm of the Solar System simulation.\n");
   
    // The grand celestial system
    Planet solSystem[NUM_PLANETS];
    createPlanets(solSystem);
    
    // Display its majesty
    displaySolarSystem(solSystem);
    
    printf("\nPrepare thine mind for the celestial dance!\n");
    int dance_steps;
    printf("Enter the number of steps to witness the dance: ");
    scanf("%d", &dance_steps);
   
    celestialDance(dance_steps);
    
    printf("\nThus concludes our journey through the Solar System.\n");
    printf("May your days be filled with starlight and wonder!\n");

    return 0;
}