//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_EVENTS 3

typedef struct {
    char name[20];
    int resources; // Resources found on the planet
    int risk;      // The risk level of the planet
} Planet;

typedef struct {
    char description[50];
    int resource_gain;
} Event;

void initialize_planets(Planet *planets) {
    const char *planet_names[MAX_PLANETS] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon"};
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", planet_names[i]);
        planets[i].resources = rand() % 100 + 1; // Resources between 1 and 100
        planets[i].risk = rand() % 10 + 1;       // Risk between 1 and 10
    }
}

void initialize_events(Event *events) {
    snprintf(events[0].description, sizeof(events[0].description), "You found rare minerals!");
    events[0].resource_gain = 20;

    snprintf(events[1].description, sizeof(events[1].description), "You encountered space pirates!");
    events[1].resource_gain = -30;

    snprintf(events[2].description, sizeof(events[2].description), "You discovered ancient artifacts!");
    events[2].resource_gain = 50;
}

void explore_planet(Planet planet, Event *events) {
    printf("\nExploring Planet %s...\n", planet.name);
    printf("Resources available: %d\n", planet.resources);
    printf("Risk level: %d\n", planet.risk);
    
    if (rand() % 10 < planet.risk) { // Encounter event based on risk
        int event_index = rand() % MAX_EVENTS;
        printf("%s\n", events[event_index].description);
        planet.resources += events[event_index].resource_gain;

        if (events[event_index].resource_gain < 0) {
            printf("You lost some resources! New resources: %d\n", planet.resources);
        } else {
            printf("You gained resources! New resources: %d\n", planet.resources);
        }
    } else {
        printf("The exploration was successful! You collected %d resources.\n", planet.resources);
    }
}

int main() {
    srand(time(NULL));

    Planet planets[MAX_PLANETS];
    initialize_planets(planets);
    
    Event events[MAX_EVENTS];
    initialize_events(events);

    int total_resources = 0;
    char choice;

    printf("Welcome to the Space Explorer Game!\n\n");

    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("Planet %s - Resources: %d, Risk: %d\n", planets[i].name, planets[i].resources, planets[i].risk);
    }

    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("\nDo you want to explore planet %s? (y/n): ", planets[i].name);
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            explore_planet(planets[i], events);
            total_resources += planets[i].resources;
        } else {
            printf("Skipping planet %s...\n", planets[i].name);
        }
    }

    printf("\nGame Over! You collected a total of %d resources.\n", total_resources);
    return 0;
}