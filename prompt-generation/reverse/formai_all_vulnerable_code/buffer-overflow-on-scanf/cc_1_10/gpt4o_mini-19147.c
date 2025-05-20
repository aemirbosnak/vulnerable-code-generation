//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_HEALTH 100
#define MAX_INVENTORY 5
#define TREASURE_COUNT 3
#define MAX_MONSTERS 5

typedef struct {
    char name[50];
    int health;
    int attack;
    int defense;
} Player;

typedef struct {
    char name[50];
    int health;
    int attack;
} Monster;

typedef struct {
    char name[50];
    int value;
    int rarity;
} Treasure;

void display_status(Player player) {
    printf("\n--- Player Status ---\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d/%d\n", player.health, MAX_HEALTH);
    printf("---------------------\n");
}

void initialize_player(Player* player) {
    printf("Enter your name, brave adventurer: ");
    scanf("%s", player->name);
    player->health = MAX_HEALTH;
    player->attack = 20;
    player->defense = 5;
}

void initialize_monsters(Monster monsters[]) {
    strcpy(monsters[0].name, "Goblin");
    monsters[0].health = 30;
    monsters[0].attack = 10;

    strcpy(monsters[1].name, "Orc");
    monsters[1].health = 40;
    monsters[1].attack = 15;

    strcpy(monsters[2].name, "Dragon");
    monsters[2].health = 80;
    monsters[2].attack = 25;

    strcpy(monsters[3].name, "Phantom");
    monsters[3].health = 50;
    monsters[3].attack = 20;

    strcpy(monsters[4].name, "Vampire");
    monsters[4].health = 60;
    monsters[4].attack = 18;
}

void initialize_treasures(Treasure treasures[]) {
    strcpy(treasures[0].name, "Golden Crown");
    treasures[0].value = 100;
    treasures[0].rarity = 5;

    strcpy(treasures[1].name, "Ancient Relic");
    treasures[1].value = 200;
    treasures[1].rarity = 3;

    strcpy(treasures[2].name, "Wizard's Staff");
    treasures[2].value = 150;
    treasures[2].rarity = 4;
}

void attack(Player* player, Monster* monster) {
    printf("%s attacks %s!\n", player->name, monster->name);
    monster->health -= (player->attack - monster->attack / 2);
    printf("%s takes damage! Remaining Health: %d\n", monster->name, monster->health);
}

int battle(Player* player, Monster* monster) {
    while (player->health > 0 && monster->health > 0) {
        attack(player, monster);
        if (monster->health > 0) {
            player->health -= (monster->attack - player->defense);
            printf("%s takes damage! Remaining Health: %d\n", player->name, player->health);
        }
    }
    return player->health > 0;
}

void loot(Player* player, Treasure treasure) {
    printf("Congratulations! You've found the %s worth %d gold!\n", treasure.name, treasure.value);
}

void adventure(Player* player, Monster monsters[], Treasure treasures[]) {
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        printf("\n--- A wild monster appears! ---\n");
        int monster_index = rand() % MAX_MONSTERS;
        Monster current_monster = monsters[monster_index];
        printf("You encounter a %s!\n", current_monster.name);

        int fight_result = battle(player, &current_monster);
        if (fight_result) {
            printf("You've defeated the %s!\n", current_monster.name);
            int loot_chance = rand() % 10;
            if (loot_chance < 5) {
                int treasure_index = rand() % TREASURE_COUNT;
                loot(player, treasures[treasure_index]);
            }
        } else {
            printf("You've been defeated by the %s! Game Over.\n", current_monster.name);
            exit(0);
        }
    }
}

int main() {
    Player player;
    Monster monsters[MAX_MONSTERS];
    Treasure treasures[TREASURE_COUNT];

    initialize_player(&player);
    initialize_monsters(monsters);
    initialize_treasures(treasures);
    
    printf("Welcome to the Quest for the Lost Treasure, %s!\n", player.name);
    printf("Your adventure awaits...\n");

    display_status(player);
    
    adventure(&player, monsters, treasures);
    
    printf("You've triumphed in your quest! Your journey has just begun!\n");
    return 0;
}