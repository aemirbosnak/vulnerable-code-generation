//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>

/* Constants */
#define MAX_ENERGY 100
#define MAX_HEALTH 100
#define MAX_DISTANCE 1000

/* Player Struct */
struct Player {
    int energy;
    int health;
    int distance;
};

/* Function Prototypes */
void printStatus(struct Player p);
void travel(struct Player *p);

/* Main Function */
int main() {

    /* Initialize Player */
    struct Player player = {MAX_ENERGY, MAX_HEALTH, 0};

    /* Game Loop */
    while (player.health > 0 && player.distance < MAX_DISTANCE) {
        
        /* Print Player Status */
        printStatus(player);

        /* Travel Option */
        printf("\nTravel (1)\n");
        printf("Exit Game (2)\n");
        int option;
        printf("Select: ");
        scanf("%d", &option);

        /* Travel */
        if (option == 1) {
            travel(&player);
        }
        /* Exit */
        else if (option == 2) {
            printf("You have left the game.\n");
            return 0;
        }
        /* Invalid Option */
        else {
            printf("Invalid option.\n");
        }
    }

    /* Game Over */
    if (player.health <= 0) {
        printf("Your spaceship was destroyed.\n");
    }
    else if (player.distance >= MAX_DISTANCE) {
        printf("Congratulations! You have reached the nearest planet.\n");
    }

    return 0;
}

/* Print Player Status */
void printStatus(struct Player p) {
    printf("\n=== STATUS ===\n");
    printf("Energy: %d/%d\n", p.energy, MAX_ENERGY);
    printf("Health: %d/%d\n", p.health, MAX_HEALTH);
    printf("Distance: %d/%d\n", p.distance, MAX_DISTANCE);
}

/* Travel */
void travel(struct Player *p) {
    /* Random event */
    int event = rand() % 3;
    int energyCost;
    int healthCost;
    int distance;
    switch (event) {
        case 0:
            energyCost = 20;
            healthCost = 5;
            distance = 50;
            printf("You encountered a space anomaly.\n");
            break;
        case 1:
            energyCost = 40;
            healthCost = 10;
            distance = 100;
            printf("You encountered a swarm of space pirates.\n");
            break;
        case 2:
            energyCost = 60;
            healthCost = 15;
            distance = 200;
            printf("You encountered a black hole.\n");
            break;
    }

    /* Deduct Energy and Health */
    if (p->energy - energyCost < 0) {
        printf("You do not have enough energy to travel.\n");
        return;
    }
    if (p->health - healthCost < 0) {
        printf("You do not have enough health to travel.\n");
        return;
    }
    p->energy -= energyCost;
    p->health -= healthCost;
    p->distance += distance;

    /* Print Travel Results */
    printf("You traveled %d distance.\n", distance);
    printf("Energy: %d/%d\n", p->energy, MAX_ENERGY);
    printf("Health: %d/%d\n", p->health, MAX_HEALTH);
    printf("Distance: %d/%d\n", p->distance, MAX_DISTANCE);
}