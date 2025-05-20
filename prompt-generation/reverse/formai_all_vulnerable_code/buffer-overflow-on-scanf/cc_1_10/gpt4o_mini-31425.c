//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hasLife;
    float distanceFromEarth; // in light-years
} Planet;

typedef struct {
    Planet planets[MAX_PLANETS];
    int planetCount;
} Galaxy;

// Function prototypes
void initializeGalaxy(Galaxy *galaxy);
void explorePlanet(Planet *planet);
void displayGalacticMap(Galaxy *galaxy);

int main() {
    Galaxy milkyWay;
    initializeGalaxy(&milkyWay);

    // Display the galactic map
    printf("Welcome to the Galactic Explorer!\n");
    printf("You are about to embark on an interstellar journey.\n");

    displayGalacticMap(&milkyWay);

    // Loop through the planets for exploration
    char choice;
    do {
        int planetIndex;
        printf("Enter the number of the planet you want to explore (0 to exit): ");
        scanf("%d", &planetIndex);

        if(planetIndex == 0) {
            break;
        } else if (planetIndex < 1 || planetIndex > milkyWay.planetCount) {
            printf("Invalid planet number. Please try again.\n");
            continue;
        }

        explorePlanet(&milkyWay.planets[planetIndex - 1]);

        printf("Do you want to explore another planet? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for visiting the Galactic Explorer! Safe travels!\n");
    return 0;
}

void initializeGalaxy(Galaxy *galaxy) {
    galaxy->planetCount = 5;

    strcpy(galaxy->planets[0].name, "Zyphor");
    galaxy->planets[0].hasLife = 1;
    galaxy->planets[0].distanceFromEarth = 4.2;

    strcpy(galaxy->planets[1].name, "Vemoria");
    galaxy->planets[1].hasLife = 0;
    galaxy->planets[1].distanceFromEarth = 7.1;

    strcpy(galaxy->planets[2].name, "Trionis");
    galaxy->planets[2].hasLife = 1;
    galaxy->planets[2].distanceFromEarth = 2.9;

    strcpy(galaxy->planets[3].name, "Xylor");
    galaxy->planets[3].hasLife = 0;
    galaxy->planets[3].distanceFromEarth = 5.0;

    strcpy(galaxy->planets[4].name, "Lunitra");
    galaxy->planets[4].hasLife = 1;
    galaxy->planets[4].distanceFromEarth = 3.5;

    printf("Galaxy initialized with %d planets!\n", galaxy->planetCount);
}

void explorePlanet(Planet *planet) {
    printf("You have arrived at %s.\n", planet->name);
    printf("Distance from Earth: %.2f light-years\n", planet->distanceFromEarth);
    
    if (planet->hasLife) {
        printf("This planet has life! Let's discover its secrets...\n");
        srand(time(NULL));
        int discovery = rand() % 3;
        
        switch (discovery) {
            case 0:
                printf("You found an alien civilization! They are friendly and welcome you.\n");
                break;
            case 1:
                printf("You discovered ancient ruins with artifacts of advanced technology.\n");
                break;
            case 2:
                printf("You encountered a beautiful landscape with unique flora and fauna.\n");
                break;
        }
    } else {
        printf("This planet is barren and hostile. Better luck next time!\n");
    }
}

void displayGalacticMap(Galaxy *galaxy) {
    printf("Galactic map of the Milky Way:\n");
    for (int i = 0; i < galaxy->planetCount; i++) {
        printf("%d. %s (Distance: %.2f light-years) %s\n", 
                i + 1, 
                galaxy->planets[i].name, 
                galaxy->planets[i].distanceFromEarth, 
                galaxy->planets[i].hasLife ? "[Life detected]" : "[No life]");
    }
}