//GEMINI-pro DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the player's struct
typedef struct {
    char name[32];
    int health;
    int attack;
    int defense;
} player_t;

// Define the monster's struct
typedef struct {
    char name[32];
    int health;
    int attack;
    int defense;
} monster_t;

// Define the game's state
typedef enum {
    GAME_STATE_RUNNING,
    GAME_STATE_WON,
    GAME_STATE_LOST
} game_state_t;

// Define the game's functions
void create_player(player_t *player);
void create_monster(monster_t *monster);
void print_player_stats(player_t *player);
void print_monster_stats(monster_t *monster);
void combat(player_t *player, monster_t *monster);
game_state_t check_game_state(player_t *player, monster_t *monster);

// Main function
int main() {
    // Create the player and monster
    player_t player;
    monster_t monster;
    create_player(&player);
    create_monster(&monster);

    // Print the player and monster stats
    printf("Player stats:\n");
    print_player_stats(&player);
    printf("\nMonster stats:\n");
    print_monster_stats(&monster);

    // Start the game loop
    game_state_t game_state = GAME_STATE_RUNNING;
    while (game_state == GAME_STATE_RUNNING) {
        // Combat
        combat(&player, &monster);

        // Check the game state
        game_state = check_game_state(&player, &monster);
    }

    // Print the game over message
    if (game_state == GAME_STATE_WON) {
        printf("You won!\n");
    } else if (game_state == GAME_STATE_LOST) {
        printf("You lost!\n");
    }

    return 0;
}

// Create the player
void create_player(player_t *player) {
    printf("What is your name? ");
    scanf("%s", player->name);
    player->health = 100;
    player->attack = 10;
    player->defense = 5;
}

// Create the monster
void create_monster(monster_t *monster) {
    strcpy(monster->name, "Goblin");
    monster->health = 50;
    monster->attack = 5;
    monster->defense = 2;
}

// Print the player stats
void print_player_stats(player_t *player) {
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Attack: %d\n", player->attack);
    printf("Defense: %d\n", player->defense);
}

// Print the monster stats
void print_monster_stats(monster_t *monster) {
    printf("Name: %s\n", monster->name);
    printf("Health: %d\n", monster->health);
    printf("Attack: %d\n", monster->attack);
    printf("Defense: %d\n", monster->defense);
}

// Combat
void combat(player_t *player, monster_t *monster) {
    // Player attacks first
    int damage_dealt = player->attack - monster->defense;
    if (damage_dealt < 0) {
        damage_dealt = 0;
    }
    monster->health -= damage_dealt;
    printf("%s attacks %s for %d damage!\n", player->name, monster->name, damage_dealt);

    // Monster attacks second
    damage_dealt = monster->attack - player->defense;
    if (damage_dealt < 0) {
        damage_dealt = 0;
    }
    player->health -= damage_dealt;
    printf("%s attacks %s for %d damage!\n", monster->name, player->name, damage_dealt);
}

// Check the game state
game_state_t check_game_state(player_t *player, monster_t *monster) {
    if (player->health <= 0) {
        return GAME_STATE_LOST;
    } else if (monster->health <= 0) {
        return GAME_STATE_WON;
    } else {
        return GAME_STATE_RUNNING;
    }
}