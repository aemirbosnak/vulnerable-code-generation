//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int health = 100;
int ammo = 50;

void displayStats() {
    printf("\nYour current health is %d and you have %d ammo left.\n", health, ammo);
}

void attack() {
    if (ammo > 0) {
        int hitChance = rand() % 2;
        if (hitChance == 0) {
            int damageDealt = rand() % 10 + 5;
            printf("\nYou hit the alien for %d damage!\n", damageDealt);
            ammo--;
        } else {
            printf("\nYou missed the alien!\n");
            ammo--;
        }
    } else {
        printf("\nYou are out of ammo! Retreat and grab some more.\n");
    }
}

void runAway() {
    int escapeChance = rand() % 2;
    if (escapeChance == 0) {
        printf("\nYou successfully escaped!\n");
        health -= 10;
    } else {
        printf("\nYou couldn't escape. The alien attacks you!\n");
        int damageTaken = rand() % 5 + 1;
        health -= damageTaken;
    }
}

void fightAliens() {
    printf("\nYou have entered a room filled with aliens! You need to fight your way through to escape.\n");
    displayStats();
    while (1) {
        int choice;
        printf("\nWhat do you want to do? 1. Attack 2. Run Away\n");
        scanf("%d", &choice);
        if (choice == 1) {
            attack();
        } else if (choice == 2) {
            runAway();
        } else {
            printf("\nInvalid choice. Try again.\n");
        }
        displayStats();
        if (health <= 0) {
            printf("\nYou have been defeated by the aliens! Game Over.\n");
            break;
        }
        if (ammo <= 0) {
            printf("\nYou are out of ammo! Game Over.\n");
            break;
        }
        int alienCount = rand() % 5 + 1;
        printf("\nYou encounter %d more aliens. Prepare to fight!\n", alienCount);
        for (int i = 0; i < alienCount; i++) {
            int alienHitChance = rand() % 2;
            if (alienHitChance == 0) {
                int damageTaken = rand() % 5 + 1;
                health -= damageTaken;
                printf("\nThe alien hits you for %d damage!\n", damageTaken);
            } else {
                printf("\nThe alien misses you!\n");
            }
        }
        if (health <= 0) {
            printf("\nYou have been defeated by the aliens! Game Over.\n");
            break;
        }
    }
}

int main() {
    srand(time(0));
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship, and you and your crew have just landed on an unknown planet. You need to explore the planet to find the resources your ship needs to continue its journey.\n");
    while (1) {
        printf("\nWhat do you want to do? 1. Explore the planet 2. Leave the planet\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            int eventChance = rand() % 2;
            if (eventChance == 0) {
                printf("\nYou discover a cave. Do you want to explore it? 1. Yes 2. No\n");
                int caveChoice;
                scanf("%d", &caveChoice);
                if (caveChoice == 1) {
                    printf("\nYou enter the cave and are attacked by aliens!\n");
                    fightAliens();
                    if (health <= 0 || ammo <= 0) {
                        break;
                    }
                } else {
                    printf("\nYou decide not to explore the cave.\n");
                }
            } else {
                printf("\nYou find a resource deposit and collect the resources your ship needs. Well done!\n");
            }
        } else if (choice == 2) {
            printf("\nYou leave the planet and continue your journey in space. Congratulations!\n");
            break;
        } else {
            printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}