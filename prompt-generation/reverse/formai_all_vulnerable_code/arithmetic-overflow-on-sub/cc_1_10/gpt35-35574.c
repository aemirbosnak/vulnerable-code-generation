//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function declarations
void intro();
void generateGalaxy();
void generatePlanets(int galaxyNum);
void explorePlanet(int planetNum);
void randomEvent();

// global variables
const int GALAXY_COUNT = 5;
const int PLANET_COUNT = 10;
char galaxyNames[5][20] = {"Andromeda", "Milky Way", "Triangulum", "Pinwheel", "Whirlpool"};
char planetNames[10][20] = {"Mars", "Venus", "Jupiter", "Saturn", "Uranus", "Neptune", "Mercury", "Pluto", "Kepler-438b", "HD 209458 b"};
char resources[10][20] = {"Iron", "Gold", "Silver", "Platinum", "Copper", "Aluminum", "Titanium", "Uranium", "Diamonds", "Emeralds"};
int resourceAmt[10];

int main() {
    srand(time(NULL));
    intro();
    generateGalaxy();
    return 0;
}

void intro() {
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You have been selected to explore the depths of space. Your mission is to travel to different galaxies and explore new planets in search of valuable resources.\n");
    printf("Your ship is fully equipped with everything you need to survive, but be careful - space is a dangerous place, and you never know what you might encounter.\n");
    printf("Enjoy your adventure!\n\n");
}

void generateGalaxy() {
    printf("Generating galaxies...\n");
    for (int i = 0; i < GALAXY_COUNT; i++) {
        printf("%d. %s\n", i+1, galaxyNames[i]);
    }
    printf("Please select a galaxy to explore: ");
    int galaxyChoice;
    scanf("%d", &galaxyChoice);
    printf("\nExploring %s...\n\n", galaxyNames[galaxyChoice-1]);
    generatePlanets(galaxyChoice);
}

void generatePlanets(int galaxyNum) {
    for (int i = 0; i < PLANET_COUNT; i++) {
        // generate random resources for planet
        for (int j = 0; j < 10; j++) {
            resourceAmt[j] = rand() % 10000; 
        }
        printf("%d. %s - Resources: ", i+1, planetNames[i]);
        for (int j = 0; j < 10; j++) {
            printf("%d %s, ", resourceAmt[j], resources[j]);
        }
        printf("\n");
    }
    printf("Please select a planet to explore (or enter 0 to return to galaxy selection): ");
    int planetChoice;
    scanf("%d", &planetChoice);
    if (planetChoice == 0) {
        generateGalaxy();
    } else {
        explorePlanet(planetChoice);
    }
}

void explorePlanet(int planetNum) {
    printf("\nExploring %s...\n", planetNames[planetNum-1]);
    printf("You have found the following resources: ");
    for (int j = 0; j < 10; j++) {
        printf("%d %s, ", resourceAmt[j], resources[j]);
    }
    printf("\n");
    randomEvent();
}

void randomEvent() {
    int eventChance = rand() % 10;
    switch (eventChance) {
        case 0:
            printf("You have encountered a hostile alien race! Prepare for battle!\n");
            break;
        case 1:
            printf("Your ship is malfunctioning. Time to make some repairs.\n");
            break;
        case 2:
            printf("A strange anomaly has appeared on your radar. Investigate?\n");
            break;
        default:
            printf("Nothing eventful happens on this planet.\n");
            break;
    }
}