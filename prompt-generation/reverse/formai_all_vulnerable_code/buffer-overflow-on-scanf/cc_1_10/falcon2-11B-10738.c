//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int health;
    int strength;
    int agility;
    int intelligence;
    int max_health;
} Player;

typedef struct {
    char name[100];
    int health;
    int strength;
    int agility;
    int intelligence;
    int max_health;
} Enemy;

void create_player(Player *player) {
    player->name[0] = 'C';
    strcpy(player->name + 1, "yberpunk");
    player->health = 100;
    player->strength = 10;
    player->agility = 10;
    player->intelligence = 10;
    player->max_health = 200;
}

void create_enemy(Enemy *enemy) {
    enemy->name[0] = 'A';
    strcpy(enemy->name + 1, "I");
    enemy->health = 100;
    enemy->strength = 10;
    enemy->agility = 10;
    enemy->intelligence = 10;
    enemy->max_health = 200;
}

void battle(Player *player, Enemy *enemy) {
    printf("BATTLE!\n");
    printf("CYBERPUNK VS A.I. \n");
    printf("Player's health: %d\n", player->health);
    printf("Enemy's health: %d\n", enemy->health);
    
    while (player->health > 0 && enemy->health > 0) {
        printf("What do you do? (1 - Attack, 2 - Defend)\n");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            player->health -= enemy->strength;
            printf("Player's health: %d\n", player->health);
        } else if (choice == 2) {
            player->health -= enemy->agility;
            printf("Player's health: %d\n", player->health);
        }
    }
    
    if (player->health > 0) {
        printf("Player wins!\n");
    } else {
        printf("Player loses!\n");
    }
}

int main() {
    Player player;
    Enemy enemy;
    
    create_player(&player);
    create_enemy(&enemy);
    
    battle(&player, &enemy);
    
    return 0;
}