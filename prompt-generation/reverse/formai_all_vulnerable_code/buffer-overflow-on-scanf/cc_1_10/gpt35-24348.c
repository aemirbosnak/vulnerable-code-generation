//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MAX_ENERGY 100

// Function prototypes
void print_game_info(int health, int energy, int score);
void heal(int *health);
void attack(int *health, int *energy, int *score);

int main()
{
    srand(time(0)); // Seed for the random number generator

    int player_health = MAX_HEALTH, player_energy = MAX_ENERGY, player_score = 0;
    char user_choice;

    printf("Welcome to CyberPunk Warzone!\n");
    printf("You are a hacker who has to fight against various enemies to earn points and survive.\n");
    printf("You have 100 health points and 100 energy points to start with.\n");
    printf("Press H to heal yourself or A to attack the enemy!\n");

    while (player_health > 0)
    {
        print_game_info(player_health, player_energy, player_score);

        printf("\nWhat do you want to do? (H/A): ");
        scanf(" %c", &user_choice);

        if (user_choice == 'H' || user_choice == 'h')
        {
            heal(&player_health);
            player_energy -= 10;
            printf("You healed yourself.\n");
        }
        else if (user_choice == 'A' || user_choice == 'a')
        {
            attack(&player_health, &player_energy, &player_score);
        }
        else
        {
            printf("Invalid choice!\n");
            continue;
        }

        // Enemy attack
        int enemy_damage = rand() % 21 + 10;
        player_health -= enemy_damage;

        printf("The enemy attacked you and dealt %d damage!\n", enemy_damage);

        // Energy regeneration
        player_energy += 10;
        if (player_energy > MAX_ENERGY)
        {
            player_energy = MAX_ENERGY;
        }
    }

    printf("\nGame over! You survived for %d rounds and earned %d points.\n", player_score, player_score*10);

    return 0;
}

void print_game_info(int health, int energy, int score)
{
    printf("\n-----------------------------------\n");
    printf("Health: %d/100 | Energy: %d/100 | Score: %d\n", health, energy, score);
    printf("-----------------------------------\n");
}

void heal(int *health)
{
    *health += 20;
    if (*health > MAX_HEALTH)
    {
        *health = MAX_HEALTH;
    }
}

void attack(int *health, int *energy, int *score)
{
    int attack_damage = rand() % 31 + 20;
    int crit_chance = rand() % 10 + 1;
    if (crit_chance == 1)
    {
        attack_damage *= 2;
        printf("Critical hit!\n");
    }
    *energy -= 20;
    *health -= attack_damage;
    *score += 1;
    printf("You attacked the enemy and dealt %d damage!\n", attack_damage);
}