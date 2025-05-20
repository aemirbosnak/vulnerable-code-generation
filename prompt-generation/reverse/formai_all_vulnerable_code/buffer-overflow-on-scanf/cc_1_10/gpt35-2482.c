//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define SHIP_HEALTH 100
#define ALIEN_HEALTH 50

// Declare functions
void attack(int *attacker_health, int *defender_health);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize game variables
    int player_health = SHIP_HEALTH;
    int alien_health = ALIEN_HEALTH;
    int num_aliens_remaining = 5;

    // Game loop
    while (player_health > 0 && num_aliens_remaining > 0) {
        int choice;

        // Prompt user for choice
        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Flee\n");
        scanf("%d", &choice);

        // Handle user choice
        if (choice == 1) {
            // Player attacks alien
            attack(&player_health, &alien_health);

            // Check if player defeated alien
            if (alien_health <= 0) {
                num_aliens_remaining--;
                alien_health = ALIEN_HEALTH;
                printf("You defeated an alien! %d remaining\n", num_aliens_remaining);
            } else {
                // Alien counterattacks
                attack(&alien_health, &player_health);
            }
        } else if (choice == 2) {
            // Player chooses to flee
            printf("You flee from the alien invasion!\n");
            break;
        }
    }

    // End game
    if (num_aliens_remaining == 0) {
        printf("Congratulations! You saved the galaxy!\n");
    } else {
        printf("Game over. The aliens have conquered Earth...\n");
    }

    return 0;
}

void attack(int *attacker_health, int *defender_health) {
    // Calculate damage
    int damage = rand() % 10 + 1;

    // Subtract damage from defender's health
    *defender_health -= damage;

    // Check if defender is defeated
    if (*defender_health <= 0) {
        *defender_health = 0;
        printf("Defender defeated!\n");
    } else {
        printf("Attacker causes %d damage!\n", damage);
    }

    // Check if attacker is defeated
    if (*attacker_health <= 0) {
        *attacker_health = 0;
        printf("Attacker defeated!\n");
    }
}