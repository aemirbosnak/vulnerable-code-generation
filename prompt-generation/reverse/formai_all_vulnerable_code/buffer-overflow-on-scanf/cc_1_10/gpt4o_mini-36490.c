//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLANET_COUNT 5
#define RESOURCE_COUNT 3

const char* planets[PLANET_COUNT] = {
    "Mars",
    "Venus",
    "Jupiter",
    "Saturn",
    "Pluto"
};

const char* resources[RESOURCE_COUNT] = {
    "Water",
    "Gold",
    "Minerals"
};

void displayIntro() {
    printf("Welcome to the Space Adventure Game!\n");
    printf("Embark on a journey across the universe and gather valuable resources!\n\n");
}

void displayPlanets() {
    printf("You can explore the following planets:\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        printf("%d. %s\n", i + 1, planets[i]);
    }
}

int randomEvent() {
    int event = rand() % 100;
    if (event < 10) return -1; // Encounter a space pirate
    if (event < 30) return 1;  // Find a treasure
    return 0; // Nothing happens
}

void explorePlanet(int choice, int* resourcesCollected) {
    int event = randomEvent();
    printf("You have landed on %s!\n", planets[choice - 1]);
    
    if (event == -1) {
        printf("Oh no! You've encountered space pirates!\n");
        printf("You lost some resources...\n");
        *resourcesCollected -= 1;
    } else if (event == 1) {
        int resourceFound = rand() % RESOURCE_COUNT;
        printf("Congratulations! You found %s!\n", resources[resourceFound]);
        *resourcesCollected += 1;
    } else {
        printf("It's a quiet planet. Nothing happens.\n");
    }
}

void displayResources(int resourcesCollected) {
    printf("Total resources collected: %d\n\n", resourcesCollected);
}

int main() {
    srand(time(0));
    int resourcesCollected = 0;
    int choice;

    displayIntro();

    while (1) {
        displayPlanets();
        printf("Choose a planet to explore (1 - %d) or enter 0 to exit: ", PLANET_COUNT);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for playing! You collected a total of %d resources.\n", resourcesCollected);
            break;
        } else if (choice < 1 || choice > PLANET_COUNT) {
            printf("Invalid choice! Please select a valid planet.\n\n");
            continue;
        }
        
        explorePlanet(choice, &resourcesCollected);
        displayResources(resourcesCollected);
    }

    return 0;
}