//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_EVENTS 3

typedef struct {
    char name[20];
    int resources;
} Planet;

typedef struct {
    char description[50];
} Event;

void initializePlanets(Planet planets[]);
void displayPlanet(Planet planet);
Event generateRandomEvent();
void explore(Planet planet);

int main() {
    Planet planets[MAX_PLANETS];
    initializePlanets(planets);
    
    printf("Welcome, brave astronaut! Prepare for an adventure among the stars!\n");
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("\nYou have arrived at %s!\n", planets[i].name);
        displayPlanet(planets[i]);
        explore(planets[i]);
    }

    printf("\nCongratulations! Your adventure has come to an end. Safe travels!\n");
    return 0;
}

void initializePlanets(Planet planets[]) {
    // Initialize planets with fictional names and resource values
    const char *names[MAX_PLANETS] = {"Zyphor", "Crystara", "Gorrath", "Elvion", "Nexulon"};
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", names[i]);
        planets[i].resources = rand() % 100 + 1;  // random resources between 1 and 100
    }
}

void displayPlanet(Planet planet) {
    printf("Planet Name: %s\n", planet.name);
    printf("Available Resources: %d\n", planet.resources);
}

Event generateRandomEvent() {
    Event events[MAX_EVENTS] = {
        {"You discovered alien ruins!"},
        {"A meteor shower approaches! Brace for impact!"},
        {"You encountered friendly aliens who share their technology!"}
    };
    return events[rand() % MAX_EVENTS];
}

void explore(Planet planet) {
    srand(time(NULL));
    int action;
    
    printf("What would you like to do?\n");
    printf("1. Gather Resources\n");
    printf("2. Explore Mysterious Areas\n");
    printf("Please enter the action number: ");
    scanf("%d", &action);

    if (action == 1) {
        printf("Gathering resources... You have collected %d resources!\n", planet.resources);
    } else if (action == 2) {
        Event randomEvent = generateRandomEvent();
        printf("Exploring... %s\n", randomEvent.description);
        
        // Handle different events
        if (randomEvent.description[0] == 'Y') {
            printf("You gained additional resources!\n");
            planet.resources += (rand() % 50 + 1); // gain more resources
            printf("Total Resources now: %d\n", planet.resources);
        } else {
            printf("Hold on tight! It's going to be a bumpy ride!\n");
            planet.resources = (planet.resources > 10) ? (planet.resources - 10) : 0; // lose some resources
            printf("Total Resources after the event: %d\n", planet.resources);
        }
    } else {
        printf("Invalid action! You wasted your turn exploring in null space!\n");
    }
}