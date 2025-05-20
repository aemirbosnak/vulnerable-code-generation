//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_NAME_LENGTH 20
#define MAX_ENEMY_DESCRIPTION_LENGTH 50
#define MAX_HIT_POINTS 100
#define MAX_ENEMIES 10
#define MAX_ROUNDS 20
#define ATTACK_CHANCE 70

// Structs
typedef struct {
    char name[MAX_NAME_LENGTH];
    int hit_points;
    int attack_power;
} player_t;

typedef struct {
    char description[MAX_ENEMY_DESCRIPTION_LENGTH];
    int hit_points;
    int attack_power;
} enemy_t;

// Function Declarations
void print_intro();
void create_player(player_t *player);
void generate_enemies(enemy_t enemies[MAX_ENEMIES]);
int battle(player_t *player, enemy_t *enemy);
void print_results(int player_hit_points);

// Function Definitions
void print_intro() {
    printf("-----------------------------\n");
    printf("|  SPACE ADVENTURE: APOCALYPSE EDITION  |\n");
    printf("-----------------------------\n");
    printf("Welcome to the post-apocalyptic world of space adventure!\n");
    printf("You are the last surviving space ranger, sent on a mission to save the universe\n");
    printf("and defeat the evil aliens who have taken over.\n");
    printf("\n");
}

void create_player(player_t *player) {
    printf("Enter your name: ");
    scanf("%s", player->name);
    player->hit_points = MAX_HIT_POINTS;
    player->attack_power = rand() % 21 + 10; // Attack power between 10 and 30
}

void generate_enemies(enemy_t enemies[MAX_ENEMIES]) {
    char descriptions[MAX_ENEMIES][MAX_ENEMY_DESCRIPTION_LENGTH] = {"Huge Mutant Monster", "Cyborg Pirate", "Giant Space Squid", "Alien Overlord", "Robot Assassin", "Venomous Space Serpent", "Fire-breathing Dragon", "Zombie Astronaut", "Vampire Bat", "Galactic Ghost"};
    int hit_points_range = (MAX_HIT_POINTS / 2) + 1; // Max hit points for enemies is half of player's max hit points

    for(int i = 0; i < MAX_ENEMIES; i++) {
        strncpy(enemies[i].description, descriptions[i], MAX_ENEMY_DESCRIPTION_LENGTH);
        enemies[i].hit_points = rand() % hit_points_range + 1;
        enemies[i].attack_power = rand() % 16 + 5; // Attack power between 5 and 20
    }
}

int battle(player_t *player, enemy_t *enemy) {
    int player_attack_chance = rand() % 101; // Random number between 0 and 100
    int enemy_attack_chance = rand() % 101; // Random number between 0 and 100
    int player_damage = 0;
    int enemy_damage = 0;

    // Player attacks first
    if(player_attack_chance <= ATTACK_CHANCE) {
        player_damage = player->attack_power;
        enemy->hit_points -= player_damage;
        printf("%s attacks the %s and deals %d damage!\n", player->name, enemy->description, player_damage);
    }
    else
        printf("%s misses the attack!\n", player->name);

    // Check if enemy is still alive
    if(enemy->hit_points <= 0)
        return 1; // Player wins

    // Enemy attacks next
    if(enemy_attack_chance <= ATTACK_CHANCE) {
        enemy_damage = enemy->attack_power;
        player->hit_points -= enemy_damage;
        printf("The %s attacks %s and deals %d damage!\n", enemy->description, player->name, enemy_damage);
    }
    else
        printf("The %s misses the attack!\n", enemy->description);

    // Check if player is still alive
    if(player->hit_points <= 0)
        return -1; // Enemy wins

    return 0; // Neither wins
}

void print_results(int player_hit_points) {
    if(player_hit_points > 0)
        printf("Congratulations! You have defeated all the enemies and saved the universe!\n");
    else
        printf("Game over! You have been defeated by the enemy aliens.\n");
}

// Main Function
int main() {
    srand(time(NULL)); // Initialize random number generator
    player_t player;
    enemy_t enemies[MAX_ENEMIES];
    int player_wins = 0;
    int current_round = 1;

    print_intro();
    create_player(&player);
    generate_enemies(enemies);

    while(current_round <= MAX_ROUNDS && player_wins == 0) {
        printf("\nRound %d: You have %d hit points remaining...\n", current_round, player.hit_points);
        printf("Choose your enemy to fight: \n");

        for(int i = 0; i < MAX_ENEMIES; i++)
            printf("%d. %s\n", i+1, enemies[i].description);

        int enemy_choice = 0;
        scanf("%d", &enemy_choice);

        player_wins = battle(&player, &enemies[enemy_choice - 1]);
        current_round++;
    }

    print_results(player.hit_points);

    return 0;
}