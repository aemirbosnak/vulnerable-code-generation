//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void travel();
void battle();
int randInt(int min, int max);

int main()
{
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship traversing through the galaxy.\n");
    printf("Your mission is to explore new planets and defeat enemy spaceships.\n");
    printf("Let's get started!\n\n");

    travel();

    return 0;
}

void travel()
{
    printf("You are currently flying through space.\n");
    printf("What would you like to do?\n");
    printf("1. Explore nearby planet\n");
    printf("2. Battle enemy spaceship\n");
    printf("3. Keep flying\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEntering the orbit of a nearby planet...\n");
            // Generate a random terrain for the planet and display it
            printf("You have discovered a %s planet with %d moons.\n", randInt(1, 2) == 1 ? "barren" : "lush", randInt(0, 4));
            // Random chance of finding resources or encountering hostile aliens
            if (randInt(1, 10) >= 8) {
                printf("You have found a cache of valuable resources!\n\n");
            } else {
                printf("You have encountered hostile aliens! Prepare for battle!\n\n");
                battle();
            }
            travel();
            break;

        case 2:
            printf("\nScanning for enemy spaceships...\n");
            // Random chance of encountering an enemy spaceship
            if (randInt(1, 10) >= 7) {
                printf("You have encountered an enemy spaceship! Prepare for battle!\n\n");
                battle();
            } else {
                printf("No enemy spaceships detected.\n\n");
            }
            travel();
            break;

        case 3:
            printf("\nContinuing to fly through space...\n\n");
            travel();
            break;

        default:
            printf("\nInvalid choice. Please try again.\n\n");
            travel();
            break;
    }
}

void battle()
{
    // Generate a random strength level for the enemy spaceship
    int enemyStrength = randInt(1, 10);
    printf("Enemy spaceship detected! Strength level: %d\n", enemyStrength);
    printf("Preparing to engage in battle...\n");

    // Random chance of winning or losing the battle
    if (randInt(1, 10) <= enemyStrength) {
        printf("Your spaceship has been defeated.\n");
        printf("GAME OVER.\n");
        exit(0);
    } else {
        printf("You have won the battle!\n");
        printf("Gaining valuable experience points...\n");
    }
}

int randInt(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}