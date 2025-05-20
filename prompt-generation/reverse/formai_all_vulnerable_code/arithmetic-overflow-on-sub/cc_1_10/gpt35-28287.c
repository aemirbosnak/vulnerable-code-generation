//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int player_health = 100;
    int ghost_health = 50;
    int player_attack, ghost_attack;
    int player_defense = 0;
    int ghost_defense = 0;
    int turn_count = 1;

    // Set up random seed
    srand(time(NULL));

    // Introduction
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a creepy old mansion...\n");
    printf("Suddenly, a ghost appears!\n");
    printf("You must defeat the ghost to leave the mansion alive!\n");
    printf("\n");

    while (1) {
        printf("TURN %d\n", turn_count);
        printf("Player Health: %d\n", player_health);
        printf("Ghost Health: %d\n", ghost_health);
        printf("\n");

        // Get player attack and defense values
        printf("Enter your attack value (0-10): ");
        scanf("%d", &player_attack);
        printf("Enter your defense value (0-5): ");
        scanf("%d", &player_defense);

        // Determine ghost attack and defense values randomly
        ghost_attack = rand() % 11;
        ghost_defense = rand() % 6;

        // Calculate damage dealt and taken
        int player_damage = player_attack - ghost_defense;
        int ghost_damage = ghost_attack - player_defense;

        // Make sure damage values are non-negative
        if (player_damage < 0) {
            player_damage = 0;
        }
        if (ghost_damage < 0) {
            ghost_damage = 0;
        }

        // Update health values
        player_health -= ghost_damage;
        ghost_health -= player_damage;

        // Check for game over conditions
        if (player_health <= 0) {
            printf("You have been defeated by the ghost!\n");
            break;
        }
        if (ghost_health <= 0) {
            printf("Congratulations! You have defeated the ghost!\n");
            break;
        }

        turn_count++;
        printf("\n");
    }

    printf("Thanks for playing the Haunted House Simulator!\n");

    return 0;
}