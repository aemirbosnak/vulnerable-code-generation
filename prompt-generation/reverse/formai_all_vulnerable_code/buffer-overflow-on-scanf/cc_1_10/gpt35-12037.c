//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the player character struct
struct Player {
    char name[20];
    int health;
    int strength;
    int gold;
    int keys;
};

// Define the room struct
struct Room {
    char name[20];
    char description[100];
    int gold;
    int keys;
    int monster_health;
    int monster_strength;
    int boss;
};

// Define the function to initialize a player character
struct Player initialize_player() {
    struct Player player;
    printf("What is your name, adventurer?\n");
    scanf("%s", player.name);
    player.health = 100;
    player.strength = 10;
    player.gold = 0;
    player.keys = 0;
    return player;
}

// Define the function to initialize a room
struct Room initialize_room(char* name, char* description, int gold, int keys, int monster_health, int monster_strength, int boss) {
    struct Room room;
    strcpy(room.name, name);
    strcpy(room.description, description);
    room.gold = gold;
    room.keys = keys;
    room.monster_health = monster_health;
    room.monster_strength = monster_strength;
    room.boss = boss;
    return room;
}

int main() {
    // Initialize the player character and starting room
    struct Player player = initialize_player();
    struct Room current_room = initialize_room("Starting Room", "You are in a dark room. There is a door to the north.", 0, 0, 0, 0, 0);
    
    // Initialize the game loop
    int playing = 1;
    while (playing) {
        // Print the current room description and options
        printf("%s\n", current_room.name);
        printf("%s\n", current_room.description);
        printf("What do you want to do?\n");
        if (current_room.gold > 0) {
            printf("- Loot the room (1 gold)\n");
        }
        if (current_room.keys > 0) {
            printf("- Pick up the key (%d key(s))\n", current_room.keys);
        }
        if (current_room.monster_health > 0) {
            printf("- Fight the monster (%d health, %d strength)\n", current_room.monster_health, current_room.monster_strength);
        }
        if (current_room.boss) {
            printf("- Fight the boss (%d health, %d strength)\n", current_room.monster_health * 2, current_room.monster_strength * 2);
        }
        printf("- Move north (1 key required)\n");
        printf("- Exit game\n");
        
        // Get the player's choice
        char choice[20];
        scanf("%s", choice);
        
        // Handle the player's choice
        if (strcmp(choice, "loot") == 0) {
            printf("You find %d gold!\n", current_room.gold);
            player.gold += current_room.gold;
            current_room.gold = 0;
        }
        else if (strcmp(choice, "pick") == 0) {
            printf("You pick up the key.\n");
            player.keys += current_room.keys;
            current_room.keys = 0;
        }
        else if (strcmp(choice, "fight") == 0) {
            int monster_health = current_room.monster_health;
            int monster_strength = current_room.monster_strength;
            printf("You enter the battle with the monster!\n");
            while (player.health > 0 && monster_health > 0) {
                printf("You attack the monster!\n");
                monster_health -= player.strength;
                if (monster_health <= 0) {
                    printf("The monster is defeated!\n");
                    player.gold += current_room.gold;
                    current_room.gold = 0;
                }
                else {
                    printf("The monster attacks you!\n");
                    player.health -= monster_strength;
                    if (player.health <= 0) {
                        printf("You have been defeated...\n");
                        playing = 0;
                    }
                }
            }
        }
        else if (strcmp(choice, "boss") == 0) {
            int boss_health = current_room.monster_health * 2;
            int boss_strength = current_room.monster_strength * 2;
            printf("You enter the battle with the boss!\n");
            while (player.health > 0 && boss_health > 0) {
                printf("You attack the boss!\n");
                boss_health -= player.strength;
                if (boss_health <= 0) {
                    printf("The boss is defeated! Congratulations, you have won the game!\n");
                    playing = 0;
                }
                else {
                    printf("The boss attacks you!\n");
                    player.health -= boss_strength;
                    if (player.health <= 0) {
                        printf("You have been defeated...\n");
                        playing = 0;
                    }
                }
            }
        }
        else if (strcmp(choice, "move") == 0) {
            if (player.keys >= 1) {
                printf("You use a key to unlock the door and move north.\n");
                player.keys -= 1;
                current_room = initialize_room("Boss Room", "You are in the final room. The boss is waiting for you.", 100, 0, 50, 20, 1);
            }
            else {
                printf("The door is locked. You need a key to open it.\n");
            }
        }
        else if (strcmp(choice, "exit") == 0) {
            printf("Goodbye, adventurer!\n");
            playing = 0;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
        
        // Print the player's current status
        printf("Name: %s\n", player.name);
        printf("Health: %d\n", player.health);
        printf("Strength: %d\n", player.strength);
        printf("Gold: %d\n", player.gold);
        printf("Keys: %d\n", player.keys);
        printf("\n");
    }
    return 0;
}