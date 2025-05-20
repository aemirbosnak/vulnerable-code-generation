//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the probability of an alien invasion
double alienInvasionProbability(int numStars, double avgPlanetsPerStar, double probLifePerPlanet, double probIntelligentLifePerPlanet, double probInvasionPerIntelligentSpecies) {
    // Calculate the number of planets in the universe
    double numPlanets = numStars * avgPlanetsPerStar;

    // Calculate the number of planets with life
    double numPlanetsWithLife = numPlanets * probLifePerPlanet;

    // Calculate the number of planets with intelligent life
    double numPlanetsWithIntelligentLife = numPlanetsWithLife * probIntelligentLifePerPlanet;

    // Calculate the probability of an alien invasion
    double probInvasion = numPlanetsWithIntelligentLife * probInvasionPerIntelligentSpecies;

    return probInvasion;
}

int main() {
    // Get the number of stars in the universe
    int numStars;
    printf("Enter the number of stars in the universe: ");
    scanf("%d", &numStars);

    // Get the average number of planets per star
    double avgPlanetsPerStar;
    printf("Enter the average number of planets per star: ");
    scanf("%lf", &avgPlanetsPerStar);

    // Get the probability of life per planet
    double probLifePerPlanet;
    printf("Enter the probability of life per planet: ");
    scanf("%lf", &probLifePerPlanet);

    // Get the probability of intelligent life per planet
    double probIntelligentLifePerPlanet;
    printf("Enter the probability of intelligent life per planet: ");
    scanf("%lf", &probIntelligentLifePerPlanet);

    // Get the probability of an invasion per intelligent species
    double probInvasionPerIntelligentSpecies;
    printf("Enter the probability of an invasion per intelligent species: ");
    scanf("%lf", &probInvasionPerIntelligentSpecies);

    // Calculate the probability of an alien invasion
    double probInvasion = alienInvasionProbability(numStars, avgPlanetsPerStar, probLifePerPlanet, probIntelligentLifePerPlanet, probInvasionPerIntelligentSpecies);

    // Print the probability of an alien invasion
    printf("The probability of an alien invasion is: %lf\n", probInvasion);

    return 0;
}