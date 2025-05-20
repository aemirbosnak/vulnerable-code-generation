//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STARS 10
#define MAX_ACTIONS 5
#define PARADOX_CHANCE 30

typedef struct {
    char name[20];
    int health;
    int energy;
} Spaceship;

typedef struct {
    char name[20];
    int power;
    int quantum_riddle;
} CosmicEntity;

void initialize_spaceship(Spaceship *ship) {
    printf("Enter your spaceship name: ");
    scanf("%s", ship->name);
    ship->health = 100;
    ship->energy = 100;
}

void generate_cosmic_entities(CosmicEntity *entities) {
    char *entity_names[] = {"Zylox", "Quantum Worm", "Nebula Phantom", "Hypernova Beast", "Eclipse Specter"};
    srand(time(NULL));

    for (int i = 0; i < MAX_STARS; i++) {
        int index = rand() % 5; // Randomly select an entity from the names
        sprintf(entities[i].name, "%s", entity_names[index]);
        entities[i].power = (rand() % 40) + 10; // Power between 10 and 50
        entities[i].quantum_riddle = rand() % 10; // Riddle for the entity
    }
}

void encounter_entity(Spaceship *ship, CosmicEntity entity) {
    printf("You encounter a cosmic entity: %s!\n", entity.name);
    printf("It has a power level of %d.\n", entity.power);
    
    if (rand() % 100 < PARADOX_CHANCE) {
        printf("A paradox unfolds! You feel your reality shift...\n");
        ship->health -= (rand() % 50); // Random reduction in health
        ship->energy += (rand() % 30); // Gain some energy
        printf("You lost some health, but gained energy!\n");
    } else {
        printf("Prepare for a confrontation!\n");
        int choice;
        printf("Choose your action!\n1. Attack\n2. Negotiate\n3. Retreat\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            ship->health -= entity.power;
            printf("You attacked and lost %d health!\n", entity.power);
        } else if (choice == 2) {
            printf("You attempt to negotiate...\n");
            if (entity.quantum_riddle > 5) {
                printf("Success! The entity agrees to a truce!\n");
            } else {
                printf("The entity is not pleased!\n");
                ship->health -= entity.power;
                printf("You lost %d health in its wrath!\n", entity.power);
            }
        } else if (choice == 3) {
            printf("You decided to retreat safely.\n");
        } else {
            printf("Invalid choice! The universe spins unpredictably...\n");
        }
    }

    if (ship->health <= 0) {
        printf("Your spaceship has been destroyed!\n");
        exit(0);
    } else {
        printf("Your spaceship's current health: %d\n", ship->health);
        printf("Your spaceship's current energy: %d\n", ship->energy);
    }
}

int main() {
    Spaceship playerShip;
    CosmicEntity cosmic_entities[MAX_STARS];
    int travelCount = 0;

    initialize_spaceship(&playerShip);
    generate_cosmic_entities(cosmic_entities);

    printf("Welcome to the Paradoxical Space Adventure, Captain %s!\n", playerShip.name);

    while (playerShip.health > 0) {
        printf("\n--- Traveling through the cosmic void ... ---\n");
        sleep(1); // Simulate time passing
        travelCount++;

        if (travelCount % 2 == 0) {
            encounter_entity(&playerShip, cosmic_entities[travelCount % MAX_STARS]);
        }

        if (playerShip.energy <= 0) {
            printf("You've run out of energy and were lost in the void.\n");
            break;
        }
    }

    return 0;
}