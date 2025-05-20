//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game world
#define WORLD_WIDTH 10
#define WORLD_HEIGHT 10
char world[WORLD_HEIGHT][WORLD_WIDTH];

// Define the player
struct Player {
    int x;
    int y;
    int health;
    int attack;
    int defense;
};

// Initialize the game world
void init_world() {
    for (int i = 0; i < WORLD_HEIGHT; i++) {
        for (int j = 0; j < WORLD_WIDTH; j++) {
            world[i][j] = '.';
        }
    }
}

// Initialize the player
void init_player(struct Player *player) {
    player->x = 0;
    player->y = 0;
    player->health = 100;
    player->attack = 10;
    player->defense = 5;
}

// Print the game world
void print_world(struct Player *player) {
    for (int i = 0; i < WORLD_HEIGHT; i++) {
        for (int j = 0; j < WORLD_WIDTH; j++) {
            if (player->x == j && player->y == i) {
                printf("@");
            } else {
                printf("%c", world[i][j]);
            }
        }
        printf("\n");
    }
}

// Handle player movement
void handle_movement(struct Player *player) {
    char input;

    printf("Enter a direction to move: (w, a, s, d)\n");
    scanf(" %c", &input);

    switch (input) {
        case 'w':
            if (player->y > 0) {
                player->y--;
            }
            break;
        case 'a':
            if (player->x > 0) {
                player->x--;
            }
            break;
        case 's':
            if (player->y < WORLD_HEIGHT - 1) {
                player->y++;
            }
            break;
        case 'd':
            if (player->x < WORLD_WIDTH - 1) {
                player->x++;
            }
            break;
    }
}

// Handle player combat
void handle_combat(struct Player *player) {
    // Check if the player is in combat
    if (world[player->y][player->x] == 'm') {
        // Create a monster
        struct Monster {
            int health;
            int attack;
            int defense;
        };

        struct Monster monster;
        monster.health = 100;
        monster.attack = 5;
        monster.defense = 2;

        // Battle the monster
        while (player->health > 0 && monster.health > 0) {
            // Player attacks
            int damage = player->attack - monster.defense;
            if (damage < 0) {
                damage = 0;
            }
            monster.health -= damage;

            // Monster attacks
            damage = monster.attack - player->defense;
            if (damage < 0) {
                damage = 0;
            }
            player->health -= damage;
        }

        // If the player wins, remove the monster from the world
        if (player->health > 0) {
            world[player->y][player->x] = '.';
        }
    }
}

// Main game loop
int main() {
    // Initialize the game world and player
    init_world();
    struct Player player;
    init_player(&player);

    // Game loop
    while (player.health > 0) {
        // Print the game world
        print_world(&player);

        // Handle player movement
        handle_movement(&player);

        // Handle player combat
        handle_combat(&player);
    }

    // Game over
    printf("You died!\n");

    return 0;
}