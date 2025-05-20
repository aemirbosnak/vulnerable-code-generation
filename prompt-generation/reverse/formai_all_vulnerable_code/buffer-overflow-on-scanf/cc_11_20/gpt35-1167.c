//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_GALAXIES 30
#define MAX_PLANETS_PER_GALAXY 10
#define MAX_STARSHIPS 5

struct Galaxy {
    char name[20];
    int num_planets;
    char planets[MAX_PLANETS_PER_GALAXY][20];
};

struct Starship {
    char name[20];
    int speed;
    int fuel;
};

int main() {
    struct Galaxy galaxies[MAX_GALAXIES];
    struct Starship starships[MAX_STARSHIPS];
    int num_galaxies, num_starships, choice;
    
    printf("Welcome to the Space Adventure!\n");
    printf("Please enter the number of galaxies in your universe: ");
    scanf("%d", &num_galaxies);
    
    if (num_galaxies > MAX_GALAXIES) {
        printf("Error: The maximum number of galaxies allowed is %d.\n", MAX_GALAXIES);
        exit(1);
    }
    
    printf("Please enter the details of each galaxy:\n");
    for (int i = 0; i < num_galaxies; i++) {
        printf("Galaxy %d:\n", i+1);
        printf("Name: ");
        scanf("%s", galaxies[i].name);
        printf("Number of planets: ");
        scanf("%d", &galaxies[i].num_planets);
        if (galaxies[i].num_planets > MAX_PLANETS_PER_GALAXY) {
            printf("Error: The maximum number of planets allowed per galaxy is %d.\n", MAX_PLANETS_PER_GALAXY);
            exit(1);
        }
        printf("Enter the names of the planets:\n");
        for (int j = 0; j < galaxies[i].num_planets; j++) {
            printf("Planet %d: ", j+1);
            scanf("%s", galaxies[i].planets[j]);
        }
    }
    
    printf("Please enter the number of starships in your fleet: ");
    scanf("%d", &num_starships);
    
    if (num_starships > MAX_STARSHIPS) {
        printf("Error: The maximum number of starships allowed is %d.\n", MAX_STARSHIPS);
        exit(1);
    }
    
    printf("Please enter the details of each starship:\n");
    for (int i = 0; i < num_starships; i++) {
        printf("Starship %d:\n", i+1);
        printf("Name: ");
        scanf("%s", starships[i].name);
        printf("Speed: ");
        scanf("%d", &starships[i].speed);
        printf("Fuel: ");
        scanf("%d", &starships[i].fuel);
    }
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Travel to a planet\n");
        printf("2. Refuel a starship\n");
        printf("3. Quit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nSelect a galaxy and a planet to travel to:\n");
                printf("Galaxies:\n");
                for (int i = 0; i < num_galaxies; i++) {
                    printf("%d. %s\n", i+1, galaxies[i].name);
                }
                printf("Enter your choice: ");
                int galaxy_choice;
                scanf("%d", &galaxy_choice);
                if (galaxy_choice < 1 || galaxy_choice > num_galaxies) {
                    printf("Error: Invalid choice.\n");
                    break;
                }
                printf("Planets:\n");
                struct Galaxy galaxy = galaxies[galaxy_choice-1];
                for (int i = 0; i < galaxy.num_planets; i++) {
                    printf("%d. %s\n", i+1, galaxy.planets[i]);
                }
                printf("Enter your choice: ");
                int planet_choice;
                scanf("%d", &planet_choice);
                if (planet_choice < 1 || planet_choice > galaxy.num_planets) {
                    printf("Error: Invalid choice.\n");
                    break;
                }
                printf("You have successfully travelled to planet %s in galaxy %s!\n", galaxy.planets[planet_choice-1], galaxy.name);
                break;
            case 2:
                printf("\nSelect a starship to refuel:\n");
                for (int i = 0; i < num_starships; i++) {
                    printf("%d. %s (Fuel: %d)\n", i+1, starships[i].name, starships[i].fuel);
                }
                printf("Enter your choice: ");
                int starship_choice;
                scanf("%d", &starship_choice);
                if (starship_choice < 1 || starship_choice > num_starships) {
                    printf("Error: Invalid choice.\n");
                    break;
                }
                starships[starship_choice-1].fuel = 100;
                printf("%s has been refueled!\n", starships[starship_choice-1].name);
                break;
            case 3:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}