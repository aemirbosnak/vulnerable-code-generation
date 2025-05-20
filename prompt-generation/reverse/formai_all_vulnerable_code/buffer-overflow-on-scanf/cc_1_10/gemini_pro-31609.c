//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the player's stats
typedef struct {
    int health;
    int attack;
    int defense;
} Player;

// Define the game's world
typedef struct {
    char *name;
    char *description;
    Player *player;
} World;

// Create a new player
Player *create_player() {
    Player *player = malloc(sizeof(Player));
    player->health = 100;
    player->attack = 10;
    player->defense = 10;
    return player;
}

// Create a new world
World *create_world() {
    World *world = malloc(sizeof(World));
    world->name = "The Forest";
    world->description = "A dark and dangerous forest filled with creatures both friendly and hostile.";
    world->player = create_player();
    return world;
}

// Print the world's description
void print_world_description(World *world) {
    printf("%s\n", world->description);
}

// Print the player's stats
void print_player_stats(Player *player) {
    printf("Health: %d\n", player->health);
    printf("Attack: %d\n", player->attack);
    printf("Defense: %d\n", player->defense);
}

// Get the player's input
char *get_player_input() {
    char *input = malloc(100);
    scanf("%s", input);
    return input;
}

// Process the player's input
void process_player_input(World *world, char *input) {
    if (strcmp(input, "north") == 0) {
        printf("You travel north.\n");
    } else if (strcmp(input, "south") == 0) {
        printf("You travel south.\n");
    } else if (strcmp(input, "east") == 0) {
        printf("You travel east.\n");
    } else if (strcmp(input, "west") == 0) {
        printf("You travel west.\n");
    } else if (strcmp(input, "look") == 0) {
        print_world_description(world);
    } else if (strcmp(input, "stats") == 0) {
        print_player_stats(world->player);
    } else {
        printf("I don't understand that command.\n");
    }
}

// Main game loop
int main() {
    World *world = create_world();

    while (1) {
        print_world_description(world);
        char *input = get_player_input();
        process_player_input(world, input);
    }

    return 0;
}