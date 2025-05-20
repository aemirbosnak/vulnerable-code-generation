//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SYSTEMS 5
#define MAX_EVENTS 3

typedef struct {
    char name[20];
    int resources;
} StarSystem;

typedef struct {
    char description[50];
    int resource_gain;
} Event;

void initializeStarSystems(StarSystem systems[]) {
    for (int i = 0; i < MAX_SYSTEMS; i++) {
        sprintf(systems[i].name, "System %d", i + 1);
        systems[i].resources = rand() % 100 + 50; // Random resources between 50-149
    }
}

void displayStarSystems(StarSystem systems[]) {
    printf("\n--- Available Star Systems ---\n");
    for (int i = 0; i < MAX_SYSTEMS; i++) {
        printf("%d: %s (Resources: %d)\n", i + 1, systems[i].name, systems[i].resources);
    }
}

Event generateEvent() {
    Event events[MAX_EVENTS] = {
        {"You found a hidden cache!", 30},
        {"A pirate ship attacks you!", -20},
        {"You discover a derelict spaceship!", 50}
    };
    return events[rand() % MAX_EVENTS];
}

void exploreSystem(StarSystem *system) {
    Event event = generateEvent();
    printf("Exploring %s...\n", system->name);
    printf("Event: %s\n", event.description);
    system->resources += event.resource_gain;

    if (event.resource_gain < 0) {
        printf("You lost resources. Current resources: %d\n", system->resources);
    } else {
        printf("You gained resources. Current resources: %d\n", system->resources);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    StarSystem starSystems[MAX_SYSTEMS];
    initializeStarSystems(starSystems);
    
    int choice;
    do {
        displayStarSystems(starSystems);
        printf("Select a star system to explore (1-%d) or 0 to exit: ", MAX_SYSTEMS);
        scanf("%d", &choice);

        if (choice > 0 && choice <= MAX_SYSTEMS) {
            exploreSystem(&starSystems[choice - 1]);
        } else if (choice != 0) {
            printf("Invalid choice, please try again.\n");
        }

    } while (choice != 0);

    printf("Thanks for playing the Space Adventure!\n");
    return 0;
}