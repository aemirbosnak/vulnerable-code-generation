//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SECTORS 5
#define ENCOUNTERS 3

typedef struct {
    char name[30];
    int power;
    int health;
} Enemy;

typedef struct {
    char name[30];
    int resources;
} Sector;

void initialize_sectors(Sector* sectors) {
    const char* sector_names[SECTORS] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon"};
    for (int i = 0; i < SECTORS; i++) {
        snprintf(sectors[i].name, sizeof(sectors[i].name), "%s", sector_names[i]);
        sectors[i].resources = rand() % 100 + 1; // random resources between 1 and 100
    }
}

void initialize_enemies(Enemy* enemies) {
    const char* enemy_names[ENCOUNTERS] = {"Galactic Raider", "Space Pirate", "Asteroid Beast"};
    for (int i = 0; i < ENCOUNTERS; i++) {
        snprintf(enemies[i].name, sizeof(enemies[i].name), "%s", enemy_names[i]);
        enemies[i].power = rand() % 20 + 10; // random power between 10 and 30
        enemies[i].health = rand() % 50 + 50; // random health between 50 and 100
    }
}

void display_sector_info(Sector* sector) {
    printf("You entered sector: %s\n", sector->name);
    printf("Available resources: %d\n", sector->resources);
}

void encounter_enemy(Enemy* enemy) {
    printf("A wild %s(a) appeared!\n", enemy->name);
    printf("Enemy Power: %d, Enemy Health: %d\n", enemy->power, enemy->health);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    Sector sectors[SECTORS];
    Enemy enemies[ENCOUNTERS];
    int currentSector = 0;
    int totalResources = 0;

    initialize_sectors(sectors);
    initialize_enemies(enemies);

    printf("Welcome to the Space Adventure Game!\n");
    printf("You are the captain of a space ship navigating through unknown sectors.\n");
    
    while (1) {
        display_sector_info(&sectors[currentSector]);

        printf("Do you want to (C)ollect resources, (E)ngage in battle, or (M)ove to the next sector? (Q to quit): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'C' || choice == 'c') {
            totalResources += sectors[currentSector].resources;
            printf("You collected %d resources from sector %s!\n", sectors[currentSector].resources, sectors[currentSector].name);
            sectors[currentSector].resources = 0; // resources have been collected
        } else if (choice == 'E' || choice == 'e') {
            int enemyIndex = rand() % ENCOUNTERS;
            encounter_enemy(&enemies[enemyIndex]);
            printf("You engage in battle... \n");
            // Simulate a simple battle decision here
            printf("Do you want to fight (F) or flee (L)? ");
            char battle_choice;
            scanf(" %c", &battle_choice);
            if (battle_choice == 'F' || battle_choice == 'f') {
                printf("You fought bravely and defeated the %s!\n", enemies[enemyIndex].name);
            } else {
                printf("You fled from the battle.\n");
            }
        } else if (choice == 'M' || choice == 'm') {
            currentSector = (currentSector + 1) % SECTORS; // move to the next sector
            printf("Moving to the next sector...\n");
        } else if (choice == 'Q' || choice == 'q') {
            printf("You have gathered a total of %d resources in your adventure!\n", totalResources);
            printf("Thank you for playing!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}