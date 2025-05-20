//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the RNG
#define INIT_RAND() srand(time(NULL))

// Get a random integer in the range [a, b]
#define RAND_RANGE(a, b) (a + rand() % (b - a + 1))

// Define the cosmic constants
#define LIGHTYEARS_PER_GALAXY 100000
#define GALAXIES_IN_UNIVERSE 1000000000
#define STARS_PER_GALAXY 1000000000
#define PLANETS_PER_STAR 10
#define CIVILIZATIONS_PER_PLANET 0.1

// Calculate the probability of an alien invasion
double alien_invasion_probability() {
    // Initialize the RNG
    INIT_RAND();

    // The probability of an alien invasion is equal to the probability
    // of finding a habitable planet times the probability of that planet
    // being inhabited by an intelligent civilization times the probability
    // of that civilization being hostile.

    // The probability of finding a habitable planet is equal to the
    // number of habitable planets in the universe divided by the total
    // number of planets in the universe.
    double num_habitable_planets = PLANETS_PER_STAR * STARS_PER_GALAXY * GALAXIES_IN_UNIVERSE;
    double num_planets = num_habitable_planets / 10;
    double habitable_planet_probability = num_habitable_planets / num_planets;

    // The probability of a planet being inhabited by an intelligent
    // civilization is equal to the probability of life arising on that
    // planet times the probability of that life evolving into an
    // intelligent civilization.
    double life_probability = 0.1;
    double intelligent_life_probability = 0.01;
    double inhabited_planet_probability = life_probability * intelligent_life_probability;

    // The probability of an intelligent civilization being hostile is
    // equal to the probability of that civilization being warlike times
    // the probability of that civilization having the technology to reach
    // Earth.
    double warlike_probability = 0.1;
    double technology_probability = 0.01;
    double hostile_civilization_probability = warlike_probability * technology_probability;

    // The overall probability of an alien invasion is equal to the
    // product of these three probabilities.
    double invasion_probability = habitable_planet_probability * inhabited_planet_probability * hostile_civilization_probability;

    return invasion_probability;
}

int main() {
    // Calculate the probability of an alien invasion
    double invasion_probability = alien_invasion_probability();

    // Print the result
    printf("The probability of an alien invasion is %f%%\n", invasion_probability * 100);

    return 0;
}