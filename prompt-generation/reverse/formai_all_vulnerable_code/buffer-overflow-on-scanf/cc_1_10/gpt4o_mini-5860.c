//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 100
#define MAX_STARS 1000

// Structure to hold planet data
typedef struct {
    char name[30];
    float distanceFromEarth; // in light-years
    int isInhabited; // 0 for no, 1 for yes
    float alienPresenceProbability; // Probability of alien presence on this planet
} Planet;

// Function to create a random planet
Planet createPlanet(int index) {
    Planet p;
    snprintf(p.name, sizeof(p.name), "Planet_%d", index + 1);
    p.distanceFromEarth = (rand() % 1000) + 1; // distance between 1 and 1000 light years
    p.isInhabited = rand() % 2; // 0 or 1
    p.alienPresenceProbability = ((float)(rand() % 100)) / 100.0f; // Probability between 0 and 1
    return p;
}

// Function to calculate total alien invasion probability
float calculateInvasionProbability(Planet planets[], int count) {
    float totalProbability = 0.0f;
    int inhabitedCount = 0;

    for (int i = 0; i < count; i++) {
        if (planets[i].isInhabited) {
            inhabitedCount++;
            totalProbability += planets[i].alienPresenceProbability;
        }
    }

    // Average of alien presence probabilities from inhabited planets
    return inhabitedCount > 0 ? totalProbability / inhabitedCount : 0.0f;
}

// Function to display planets
void displayPlanets(Planet planets[], int count) {
    printf("\n--- List of Planets ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Distance: %.2f light-years, Inhabited: %s, Alien Presence Probability: %.2f\n",
            planets[i].name,
            planets[i].distanceFromEarth,
            planets[i].isInhabited ? "Yes" : "No",
            planets[i].alienPresenceProbability);
    }
    printf("-----------------------\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int numPlanets;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many planets do you want to analyze (max %d)? ", MAX_PLANETS);
    scanf("%d", &numPlanets);

    if (numPlanets < 1 || numPlanets > MAX_PLANETS) {
        printf("Invalid number of planets! Must be between 1 and %d.\n", MAX_PLANETS);
        return 1; // Exit with error code
    }

    Planet planets[MAX_PLANETS];

    // Creating planets
    for (int i = 0; i < numPlanets; i++) {
        planets[i] = createPlanet(i);
    }

    // Display all planets
    displayPlanets(planets, numPlanets);

    // Calculate invasion probability
    float invasionProbability = calculateInvasionProbability(planets, numPlanets);
    printf("Calculated Alien Invasion Probability based on inhabited planets: %.2f\n", invasionProbability);

    // Conclusion
    if (invasionProbability > 0.75) {
        printf("Warning: High probability of alien invasion detected! Prepare for contact!\n");
    } else if (invasionProbability > 0.5) {
        printf("Caution: Moderate risk of alien presence. Stay vigilant!\n");
    } else if (invasionProbability > 0.25) {
        printf("Low risk of alien invasion. Enjoy your interstellar travels!\n");
    } else {
        printf("Nearly safe! No significant alien presence detected.\n");
    }

    return 0; // Successful execution
}