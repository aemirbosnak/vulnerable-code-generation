//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define INITIAL_FUEL 50
#define FUEL_COST 10
#define PLANET_COUNT 5

typedef struct {
    char name[20];
    int fuel;
    int health;
    int resources;
} Spaceship;

typedef struct {
    char name[20];
    int dangerLevel;
} Planet;

Planet planets[PLANET_COUNT] = {
    {"Aridus", 2},
    {"Havoc-9", 5},
    {"Oasis Prime", 1},
    {"Terror-7", 4},
    {"Hope's End", 3}
};

void display_status(Spaceship *ship) {
    printf("\nSpaceship Status:\n");
    printf("Name: The Survivor\n");
    printf("Fuel: %d\n", ship->fuel);
    printf("Health: %d\n", ship->health);
    printf("Resources: %d\n", ship->resources);
}

void visit_planet(Spaceship *ship) {
    int planet_choice;
    printf("\nChoose a planet to visit:\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        printf("%d. %s (Danger Level: %d)\n", i + 1, planets[i].name, planets[i].dangerLevel);
    }
    printf("Enter your choice (1-%d): ", PLANET_COUNT);
    scanf("%d", &planet_choice);
    planet_choice -= 1; // Adjust for zero indexing

    if (planet_choice < 0 || planet_choice >= PLANET_COUNT) {
        printf("Invalid choice! Returning to main menu.\n");
        return;
    }
    
    printf("You have arrived at %s...\n", planets[planet_choice].name);
    
    // Random encounter based on planet's danger level
    int encounter_chance = rand() % (10 - planets[planet_choice].dangerLevel);
    if (encounter_chance < 2) { // 20% chance of a negative encounter
        printf("You faced a hostile environment! You lost 20 health.\n");
        ship->health -= 20;
        if (ship->health < 0) ship->health = 0;
    } else {
        printf("You found resources! Gained 10 resources.\n");
        ship->resources += 10;
    }
}

void refuel(Spaceship *ship) {
    if (ship->resources >= FUEL_COST) {
        ship->fuel += 20; // Refuel
        ship->resources -= FUEL_COST; // Pay fuel cost
        printf("Successfully refueled! You now have %d fuel.\n", ship->fuel);
    } else {
        printf("Not enough resources to refuel!\n");
    }
}

void game_over(Spaceship *ship) {
    printf("\n--- GAME OVER ---\n");
    printf("Your journey has ended. Final status:\n");
    display_status(ship);
    exit(0);
}

int main() {
    srand(time(0)); // Seed for random number generation

    Spaceship player_ship = {"The Survivor", INITIAL_FUEL, MAX_HEALTH, 0};

    printf("Welcome to the Post-Apocalyptic Space Adventure!\n");
    
    int choice;
    while (1) {
        display_status(&player_ship);
        printf("\nChoose an action:\n");
        printf("1. Visit a planet\n");
        printf("2. Refuel\n");
        printf("3. Check status\n");
        printf("4. Exit game\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (player_ship.fuel > 0) {
                    player_ship.fuel--;
                    visit_planet(&player_ship);
                } else {
                    printf("Out of fuel! You cannot visit a planet.\n");
                }
                break;
            case 2:
                refuel(&player_ship);
                break;
            case 3:
                display_status(&player_ship);
                break;
            case 4:
                printf("Exiting game. Farewell, traveler.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }

        // Check for game over conditions
        if (player_ship.health <= 0) {
            game_over(&player_ship);
        }

        if (player_ship.fuel < 0) {
            printf("You have drifted into the void... Fuel depleted.\n");
            game_over(&player_ship);
        }
    }
    
    return 0;
}