//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 5
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int distance; // Distance from the starting point
} Planet;

void initializePlanets(Planet planets[], int count) {
    const char *planetNames[] = { "Zog", "Trex", "Alpha", "Beta", "Gamma" };
    srand(time(NULL));
    
    for (int i = 0; i < count; i++) {
        strcpy(planets[i].name, planetNames[i]);
        planets[i].distance = rand() % 1000 + 100; // Random distance between 100 and 1099
    }
}

void displayMenu() {
    printf("\nWelcome to the Space Adventure!\n");
    printf("1. View Planets\n");
    printf("2. Travel to a Planet\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void displayPlanets(Planet planets[], int count) {
    printf("\nAvailable Planets:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Distance: %d light years\n", i + 1, planets[i].name, planets[i].distance);
    }
}

void travelToPlanet(Planet planets[], int count) {
    int choice;
    printf("Enter the number of the planet you want to travel to: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > count) {
        printf("Invalid selection.\n");
        return;
    }
    printf("Travelling to %s...\n", planets[choice - 1].name);
    int travelTime = planets[choice - 1].distance / 20; // Speed of 20 light years per year
    printf("It will take %d years to reach %s.\n", travelTime, planets[choice - 1].name);
}

int main() {
    Planet planets[MAX_PLANETS];
    initializePlanets(planets, MAX_PLANETS);

    int running = 1;
    while (running) {
        displayMenu();
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                displayPlanets(planets, MAX_PLANETS);
                break;
            case 2:
                travelToPlanet(planets, MAX_PLANETS);
                break;
            case 3:
                printf("Exiting the Space Adventure. Safe travels!\n");
                running = 0;
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}