//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Player {
    char name[50];
    int health;
    int level;
};

struct Monster {
    char name[50];
    int health;
    int attack_damage;
};

struct Room {
    char description[200];
    int monsters_in_room;
};

int main() {
    // Define the game world
    int num_rooms = 10;
    int num_players = 4;
    int num_monsters = 5;
    srand(time(0));

    // Create the game world
    struct Room rooms[num_rooms];
    struct Player players[num_players];
    struct Monster monsters[num_monsters];

    // Generate the game world
    for (int i = 0; i < num_rooms; i++) {
        int num_monsters = rand() % 10 + 1;
        int monsters_in_room = rand() % num_monsters;
        for (int j = 0; j < monsters_in_room; j++) {
            monsters[i * num_monsters + j].name[0] = 'M';
            monsters[i * num_monsters + j].health = rand() % 50 + 1;
            monsters[i * num_monsters + j].attack_damage = rand() % 5 + 1;
        }
        rooms[i].description[0] = 'R';
        rooms[i].monsters_in_room = num_monsters;
    }

    // Initialize the game world
    int current_room = 0;
    int current_player = 0;

    // Main game loop
    while (1) {
        // Print the current room description
        printf("%s\n", rooms[current_room].description);

        // Print the current players
        for (int i = 0; i < num_players; i++) {
            printf("Player %d: %s\n", i + 1, players[i].name);
        }

        // Print the current monsters
        for (int i = 0; i < num_monsters; i++) {
            printf("Monster %d: %s\n", i + 1, monsters[i].name);
        }

        // Check for player input
        int command;
        printf("What would you like to do? (1-4)\n");
        scanf("%d", &command);
        if (command == 1) {
            // Move to the next room
            current_room++;
            if (current_room == num_rooms) {
                current_room = 0;
            }
        } else if (command == 2) {
            // Attack a monster
            int monster_index = rand() % num_monsters;
            if (monsters[monster_index].health > 0) {
                int damage = rand() % monsters[monster_index].attack_damage;
                monsters[monster_index].health -= damage;
                printf("You attacked Monster %d and dealt %d damage.\n", monster_index + 1, damage);
            } else {
                printf("Monster %d is already dead.\n", monster_index + 1);
            }
        } else if (command == 3) {
            // Heal a player
            if (players[current_player].health < 100) {
                int healing = rand() % 10 + 1;
                players[current_player].health += healing;
                printf("Player %d healed for %d health.\n", current_player + 1, healing);
            } else {
                printf("Player %d is already at full health.\n", current_player + 1);
            }
        } else if (command == 4) {
            // Quit the game
            break;
        }
    }

    return 0;
}