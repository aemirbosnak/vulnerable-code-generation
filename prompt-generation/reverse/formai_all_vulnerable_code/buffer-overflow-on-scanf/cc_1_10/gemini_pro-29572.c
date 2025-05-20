//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
    int health;
    int attack;
    int defense;
} Character;

Character player;
Character enemy;

void init_game() {
    // Initialize the player
    strcpy(player.name, "Player");
    player.health = 100;
    player.attack = 10;
    player.defense = 5;

    // Initialize the enemy
    strcpy(enemy.name, "Enemy");
    enemy.health = 100;
    enemy.attack = 10;
    enemy.defense = 5;
}

void print_stats() {
    printf("Player: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Attack: %d\n", player.attack);
    printf("Defense: %d\n\n", player.defense);

    printf("Enemy: %s\n", enemy.name);
    printf("Health: %d\n", enemy.health);
    printf("Attack: %d\n", enemy.attack);
    printf("Defense: %d\n\n", enemy.defense);
}

int get_action() {
    int action;
    printf("What do you want to do?\n");
    printf("1. Attack\n");
    printf("2. Defend\n");
    printf("3. Heal\n");
    scanf("%d", &action);
    return action;
}

void do_action(int action) {
    switch (action) {
        case 1: // Attack
            enemy.health -= player.attack - enemy.defense;
            printf("You attacked the enemy for %d damage.\n", player.attack - enemy.defense);
            break;
        case 2: // Defend
            player.defense += 2;
            printf("You increased your defense by 2.\n");
            break;
        case 3: // Heal
            player.health += 10;
            printf("You healed yourself for 10 health.\n");
            break;
    }
}

int main() {
    // Initialize the game
    init_game();

    // Print the stats
    print_stats();

    // Get the player's action
    int action = get_action();

    // Do the action
    do_action(action);

    // Print the stats
    print_stats();

    return 0;
}