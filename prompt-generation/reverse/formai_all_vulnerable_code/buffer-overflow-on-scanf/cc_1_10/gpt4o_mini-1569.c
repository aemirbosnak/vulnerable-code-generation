//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5
#define MAX_TREASURES 3

typedef struct {
    int health;
    int damage;
    char name[20];
} Starship;

typedef struct {
    int health;
    int damage;
    char name[20];
} Alien;

typedef struct {
    int value;
    char name[20];
} Treasure;

void initializeStarship(Starship *ship) {
    ship->health = 100;
    ship->damage = 20;
    snprintf(ship->name, sizeof(ship->name), "Galactic Cruiser");
    printf("Starship %s initialized with %d health and %d damage!\n", ship->name, ship->health, ship->damage);
}

void initializeAliens(Alien aliens[], int numAliens) {
    for (int i = 0; i < numAliens; i++) {
        aliens[i].health = rand() % 50 + 50;
        aliens[i].damage = rand() % 10 + 5;
        snprintf(aliens[i].name, sizeof(aliens[i].name), "Alien #%d", i + 1);
        printf("Encountered %s with %d health and %d damage!\n", aliens[i].name, aliens[i].health, aliens[i].damage);
    }
}

void initializeTreasures(Treasure treasures[], int numTreasures) {
    for (int i = 0; i < numTreasures; i++) {
        treasures[i].value = rand() % 100 + 50;
        snprintf(treasures[i].name, sizeof(treasures[i].name), "Treasure #%d", i + 1);
        printf("Found %s worth %d galactic credits!\n", treasures[i].name, treasures[i].value);
    }
}

void battle(Starship *ship, Alien *alien) {
    printf("\nBattling %s!\n", alien->name);
    while (ship->health > 0 && alien->health > 0) {
        alien->health -= ship->damage;
        printf("Your ship attacks! %s's health is now %d.\n", alien->name, alien->health);
        if (alien->health > 0) {
            ship->health -= alien->damage;
            printf("%s attacks back! Your health is now %d.\n", alien->name, ship->health);
        }
    }

    if (ship->health > 0) {
        printf("You defeated %s! Your remaining health is %d.\n", alien->name, ship->health);
    } else {
        printf("Your ship was destroyed by %s. Game Over!\n", alien->name);
        exit(0);
    }
}

void explore(Starship *ship, Alien aliens[], int numAliens, Treasure treasures[], int numTreasures) {
    int choice;
    printf("\n1. Explore for treasures\n2. Battle alien ships\n3. Exit\n");
    printf("What would you like to do? ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (int i = 0; i < numTreasures; i++) {
                printf("Collecting %s...\n", treasures[i].name);
                printf("You gained %d galactic credits!\n", treasures[i].value);
            }
            break;
        case 2:
            for (int i = 0; i < numAliens; i++) {
                battle(ship, &aliens[i]);
            }
            break;
        case 3:
            printf("Exiting the adventure. Until next time, space traveler!\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    Starship ship;
    Alien aliens[MAX_ENEMIES];
    Treasure treasures[MAX_TREASURES];

    initializeStarship(&ship);
    initializeAliens(aliens, MAX_ENEMIES);
    initializeTreasures(treasures, MAX_TREASURES);

    while (1) {
        explore(&ship, aliens, MAX_ENEMIES, treasures, MAX_TREASURES);
    }

    return 0;
}