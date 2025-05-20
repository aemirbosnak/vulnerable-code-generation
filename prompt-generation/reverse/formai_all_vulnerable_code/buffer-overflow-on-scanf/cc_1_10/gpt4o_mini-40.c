//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    char resource[30];
    char creature[30];
} Planet;

void print_intro();
void display_planets(Planet *planets, int count);
void explore_planet(Planet *planet);
void gather_resources(Planet *planet);

int main() {
    Planet planets[5] = {
        {"AquaTerra", "Water Crystals", "Friendly Aquans"},
        {"Florae", "Healing Herbs", "Gentle Floraes"},
        {"Lumia", "Light Stones", "Shining Lumins"},
        {"Solara", "Sun Energy", "Radiant Solarites"},
        {"Gaia", "Earth Gems", "Wise Geonites"}
    };

    int choice, running = 1;

    print_intro();

    while (running) {
        printf("\nExplore the Universes of Peaceful Planets\n");
        printf("1. List Planets\n");
        printf("2. Explore a Planet\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_planets(planets, 5);
                break;
            case 2:
                printf("Enter the number of the planet to explore (1-5): ");
                int planet_number;
                scanf("%d", &planet_number);
                if (planet_number >= 1 && planet_number <= 5) {
                    explore_planet(&planets[planet_number - 1]);
                } else {
                    printf("Invalid selection. Please choose a number between 1 and 5.\n");
                }
                break;
            case 3:
                printf("Thank you for exploring the peaceful universe. Safe travels!\n");
                running = 0;
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    
    return 0;
}

void print_intro() {
    printf("Welcome to the Peaceful Space Adventure!\n");
    printf("Where harmony and exploration unite in the cosmos.\n\n");
}

void display_planets(Planet *planets, int count) {
    printf("List of Planets to Explore:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, planets[i].name);
    }
}

void explore_planet(Planet *planet) {
    printf("\nExploring %s...\n", planet->name);
    printf("You are met by the inhabitants: %s.\n", planet->creature);
    gather_resources(planet);
}

void gather_resources(Planet *planet) {
    char choice;
    printf("Would you like to gather %s from %s? (y/n): ", planet->resource, planet->name);
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("You gather valuable %s. The friendly %s appreciate your kindness!\n", planet->resource, planet->creature);
    } else {
        printf("You choose not to gather resources. The %s respect your decision.\n", planet->creature);
    }
}