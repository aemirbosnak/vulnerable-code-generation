//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10
#define MAX_HP 100
#define MAX_WEAPON_DAMAGE 20
#define MAX_ARMOR_PROTECTION 10

typedef struct Player {
    char name[20];
    int hp;
    int weaponDamage;
    int armorProtection;
} Player;

typedef struct Enemy {
    char name[20];
    int hp;
    int damage;
} Enemy;

void initializePlayer(Player* player) {
    printf("Enter your name: ");
    scanf("%s", player->name);
    player->hp = MAX_HP;
    player->weaponDamage = rand() % MAX_WEAPON_DAMAGE + 1;
    player->armorProtection = rand() % MAX_ARMOR_PROTECTION + 1;
}

void initializeEnemies(Enemy enemies[MAX_ENEMIES], int numOfEnemies) {
    char names[MAX_ENEMIES][20] = {"Zombie", "Mutant", "Raider", "Ghoul", "Robot", "Bandit", "Cannibal", "Scavenger", "Slaver", "Survivor"};
    
    for(int i = 0; i < numOfEnemies; i++) {
        int randomIndex = rand() % MAX_ENEMIES;
        Enemy enemy = {names[randomIndex], rand() % MAX_HP + 1, rand() % MAX_WEAPON_DAMAGE + 1};
        enemies[i] = enemy;
    }
}

void displayPlayer(Player player) {
    printf("Name: %s\n", player.name);
    printf("HP: %d\n", player.hp);
    printf("Weapon damage: %d\n", player.weaponDamage);
    printf("Armor protection: %d\n", player.armorProtection);
}

void displayEnemies(Enemy enemies[MAX_ENEMIES], int numOfEnemies) {
    for(int i = 0; i < numOfEnemies; i++) {
        printf("Enemy %d:\n", i+1);
        printf("Name: %s\n", enemies[i].name);
        printf("HP: %d\n", enemies[i].hp);
        printf("Damage: %d\n\n", enemies[i].damage);
    }
}

int simulateBattle(Player* player, Enemy enemies[MAX_ENEMIES], int numOfEnemies) {
    int turn = 0;
    int playerDamageTaken = 0;
    printf("Battle begins!\n");
    
    while(numOfEnemies > 0 && player->hp > 0) {
        turn++;
        printf("Turn %d:\n", turn);
        printf("Player attacks %s for %d damage!\n", enemies[0].name, player->weaponDamage);
        enemies[0].hp -= player->weaponDamage;
        if(enemies[0].hp <= 0) {
            printf("%s is defeated!\n", enemies[0].name);
            for(int i = 0; i < numOfEnemies-1; i++) {
                enemies[i] = enemies[i+1];
            }
            numOfEnemies--;
            continue;
        }
        
        printf("%s attacks player for %d damage!\n", enemies[0].name, enemies[0].damage);
        playerDamageTaken = enemies[0].damage - player->armorProtection;
        if(playerDamageTaken < 0) {
            playerDamageTaken = 0;
        }
        player->hp -= playerDamageTaken;
        printf("Player takes %d damage!\n", playerDamageTaken);
    }
    
    if(player->hp <= 0) {
        printf("Player is defeated.\n");
        return 0;
    }
    
    printf("Player is victorious!\n");
    return 1;
}

int main() {
    srand(time(NULL));
    Player player;
    initializePlayer(&player);
    printf("\n");
    displayPlayer(player);
    printf("\n");
    Enemy enemies[MAX_ENEMIES];
    int numOfEnemies = rand() % MAX_ENEMIES + 1;
    initializeEnemies(enemies, numOfEnemies);
    displayEnemies(enemies, numOfEnemies);
    printf("\n");
    int result = simulateBattle(&player, enemies, numOfEnemies);
    return 0;
}