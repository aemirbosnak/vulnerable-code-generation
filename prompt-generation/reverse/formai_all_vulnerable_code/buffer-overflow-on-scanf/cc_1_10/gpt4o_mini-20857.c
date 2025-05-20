//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_HEALTH 100
#define MAX_FUEL 100

typedef struct {
    char name[20];
    int distance;
    int hazard;
} Planet;

void initialize_planets(Planet planets[]) {
    snprintf(planets[0].name, 20, "Zeta-1");
    planets[0].distance = 50;
    planets[0].hazard = 10;

    snprintf(planets[1].name, 20, "Alpha-7");
    planets[1].distance = 120;
    planets[1].hazard = 30;

    snprintf(planets[2].name, 20, "Gamma-X");
    planets[2].distance = 200;
    planets[2].hazard = 20;

    snprintf(planets[3].name, 20, "Delta-4");
    planets[3].distance = 300;
    planets[3].hazard = 50;

    snprintf(planets[4].name, 20, "Beta-9");
    planets[4].distance = 150;
    planets[4].hazard = 25;
}

void print_planets(Planet planets[]) {
    printf("Available Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s (Distance: %d, Hazard Level: %d)\n", 
               i + 1, planets[i].name, planets[i].distance, planets[i].hazard);
    }
}

int explore_planet(Planet planet, int *health, int *fuel) {
    int encounter = rand() % 100;
    
    if (encounter < planet.hazard) {
        printf("You encountered a hazard on %s!\n", planet.name);
        int damage = (rand() % 20) + 10;
        *health -= damage;
        printf("You lost %d health! Current health: %d\n", damage, *health);
    } else {
        printf("Exploration of %s was successful!\n", planet.name);
    }

    *fuel -= planet.distance / 10;
    printf("Fuel used: %d. Remaining fuel: %d\n", planet.distance / 10, *fuel);
    
    if (*health <= 0) {
        printf("You have perished in space.\n");
        return 0; // Game over
    }
    if (*fuel < 0) {
        printf("You have run out of fuel!\n");
        return 0; // Game over
    }
    return 1; // Continue
}

int main() {
    Planet planets[MAX_PLANETS];
    int health = MAX_HEALTH;
    int fuel = MAX_FUEL;
    int is_alive = 1;
    
    srand(time(NULL));
    initialize_planets(planets);

    while (is_alive) {
        print_planets(planets);
        int choice;
        printf("Choose a planet to explore (1-%d): ", MAX_PLANETS);
        scanf("%d", &choice);

        if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice. Please choose a planet between 1 and %d.\n", MAX_PLANETS);
            continue;
        }

        is_alive = explore_planet(planets[choice - 1], &health, &fuel);
        
        if (is_alive) {
            printf("Health: %d | Fuel: %d\n", health, fuel);
            printf("Would you like to explore another planet? (1 for Yes, 0 for No): ");
            int continue_exploration;
            scanf("%d", &continue_exploration);
            if (continue_exploration == 0) {
                printf("Thank you for exploring the universe. Safe travels!\n");
                break;
            }
        }
    }
    
    return 0;
}