//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 20
#define MAX_TRAVEL_DISTANCE 100
#define MAX_ATTACKS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char type[MAX_NAME_LENGTH];
    int distance;
    int resources;
} Planet;

void initializePlanets(Planet planets[], int count) {
    const char *types[] = {"Rocky", "Gas Giant", "Water World", "Ice Planet"};
    for (int i = 0; i < count; i++) {
        snprintf(planets[i].name, MAX_NAME_LENGTH, "Planet-%d", i + 1);
        strcpy(planets[i].type, types[rand() % 4]);
        planets[i].distance = (rand() % MAX_TRAVEL_DISTANCE) + 1;
        planets[i].resources = (rand() % 1000) + 1;
    }
}

void encounterAlien() {
    int choice;
    printf("You've encountered an alien! What do you want to do?\n");
    printf("1. Diplomacy\n");
    printf("2. Attack\n");
    printf("3. Run away screaming\n");
    printf("Choose your action: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You tried diplomacy. The alien laughed and offered you a banana. You got a banana!\n");
            break;
        case 2:
            printf("You attacked the alien with a rubber chicken! The alien was confused and left. You win!\n");
            break;
        case 3:
            printf("You ran away screaming! The alien was so confused, it forgot you existed. You win by default!\n");
            break;
        default:
            printf("Invalid choice! The alien eats your lunch in retaliation. Great job!\n");
    }
}

void explorePlanet(Planet *planet) {
    printf("Exploring %s, the %s...\n", planet->name, planet->type);
    printf("Resources available: %d\n", planet->resources);
    encounterAlien();
}

void travelToPlanet(Planet *planet) {
    printf("Setting course for %s...\n", planet->name);
    printf("Traveling distance: %d light-years!\n", planet->distance);
    for (int i = 0; i < planet->distance; i += 10) {
        printf("Traveling... %d light-years completed!\n", i);
        if (i % 20 == 0) {
            encounterAlien();
        }
        sleep(1); // pause for the dramatics!
    }
    printf("Arrived at %s!\n", planet->name);
    explorePlanet(planet);
}

int main(void) {
    srand(time(NULL)); // Seed randomness
    Planet planets[MAX_PLANETS];
    initializePlanets(planets, MAX_PLANETS);

    printf("Welcome to the Great Interstellar Space Adventure!\n");
    printf("You are the captain of the starship 'S.S. Quirky'.\n");

    int choice;
    while (1) {
        printf("Which planet would you like to visit?\n");
        for (int i = 0; i < MAX_PLANETS; i++) {
            printf("%d: %s (Type: %s, Distance: %d, Resources: %d)\n", 
                    i + 1, planets[i].name, planets[i].type, planets[i].distance, planets[i].resources);
        }
        printf("Enter the planet number (1-%d) or 0 to exit: ", MAX_PLANETS);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for playing! Remember, always take a snack on your space adventures!\n");
            break;
        }

        if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice! You just lost 10 space credibility points.\n");
            continue;
        }

        travelToPlanet(&planets[choice - 1]);
    }

    return 0;
}