//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
int exploreSpace(int fuel, int food, int water);
void attackAlien(int* health, int* ammo, int* aliensKilled);

// Main function
int main() {

    int fuel = 100;
    int food = 50;
    int water = 50;
    int health = 100;
    int ammo = 50;
    int aliensKilled = 0;
    int choice;

    printf("Welcome to the Procedural Space Adventure!\n");

    while (health > 0) {
        printf("\nWhat do you want to do?\n");
        printf("1. Explore Space\n");
        printf("2. Attack Alien\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fuel -= 20;
                food -= 10;
                water -= 10;
                printf("Exploring space...\n");
                health = exploreSpace(fuel, food, water);
                break;

            case 2:
                if (ammo > 0) {
                    printf("Attacking alien...\n");
                    attackAlien(&health, &ammo, &aliensKilled);
                }
                else {
                    printf("You don't have enough ammo to attack!\n");
                }
                break;

            case 3:
                printf("Thanks for playing!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("Fuel: %d\n", fuel);
        printf("Food: %d\n", food);
        printf("Water: %d\n", water);
        printf("Health: %d\n", health);
        printf("Ammo: %d\n", ammo);
        printf("Aliens Killed: %d\n", aliensKilled);
    }

    printf("Game over!\n");

    return 0;
}

// Function to explore space
int exploreSpace(int fuel, int food, int water) {

    srand(time(NULL)); // Seed random number generator

    int chance = rand() % 10 + 1; // Generate random number between 1 and 10

    if (chance <= 5) {
        fuel -= 10;
        food -= 5;
        water -= 5;
        return 100;
    }
    else if (chance <= 8) {
        fuel -= 20;
        food -= 10;
        water -= 10;
        return 50;
    }
    else {
        fuel -= 30;
        food -= 15;
        water -= 15;
        return 0;
    }

}

// Function to attack alien
void attackAlien(int* health, int* ammo, int* aliensKilled) {

    srand(time(NULL)); // Seed random number generator

    int chance = rand() % 10 + 1; // Generate random number between 1 and 10

    if (chance <= 7) {
        *health -= 20;
        printf("You were attacked by the alien and lost 20 health!\n");
    }
    else {
        printf("You killed the alien!\n");
        *ammo -= 10;
        *aliensKilled += 1;
    }

}