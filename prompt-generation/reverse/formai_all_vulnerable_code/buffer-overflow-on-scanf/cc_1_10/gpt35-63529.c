//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct player {
    char name[20];
    int health;
    int attack;
    int defense;
    int agility;
    int level;
    int experience;
    int gold;
};

struct enemy {
    char name[20];
    int health;
    int attack;
    int defense;
    int agility;
    int level;
    int experience;
    int gold;
};

void battle(struct player *player, struct enemy *enemy) {
    // Player attack loop
    while (player->health > 0 && enemy->health > 0) {
        int player_attack = player->attack * (rand() % 10 + 1) / 10;
        int enemy_defense = enemy->defense * (rand() % 10 + 1) / 10;
        int damage = player_attack - enemy_defense;
        if (damage <= 0) {
            printf("\n%s's attack missed %s!", player->name, enemy->name);
        } else {
            printf("\n%s dealt %d damage to %s!", player->name, damage, enemy->name);
            enemy->health -= damage;
        }
        
        if (enemy->health <= 0)
            break;
        
        // Enemy attack loop
        int enemy_attack = enemy->attack * (rand() % 10 + 1) / 10;
        int player_defense = player->defense * (rand() % 10 + 1) / 10;
        damage = enemy_attack - player_defense;
        if (damage <= 0) {
            printf("\n%s's attack missed %s!", enemy->name, player->name);
        } else {
            printf("\n%s dealt %d damage to %s!", enemy->name, damage, player->name);
            player->health -= damage;
        }
    }
    
    if (player->health <= 0) {
        printf("\n%s has been defeated...", player->name);
    } else if (enemy->health <= 0) {
        printf("\n%s has been defeated!", enemy->name);
        printf("\n%s gained %d experience and %d gold!", player->name, enemy->experience, enemy->gold);
        player->experience += enemy->experience;
        player->gold += enemy->gold;
    }
}

int main() {
    struct player player;
    player.health = 100;
    player.attack = 10;
    player.defense = 5;
    player.agility = 5;
    player.level = 1;
    player.experience = 0;
    player.gold = 0;
    
    struct enemy enemy;
    enemy.health = 50;
    enemy.attack = 8;
    enemy.defense = 3;
    enemy.agility = 3;
    enemy.level = 1;
    enemy.experience = 10;
    enemy.gold = 5;
    
    printf("Welcome to the dungeon explorer game!\n");
    printf("What is your name?\n");
    scanf("%s", player.name);
    printf("Hello, %s. Let's begin the adventure!\n", player.name);
    
    while (player.health > 0) {
        printf("\nYou are currently at level %d, with %d experience and %d gold.\n", player.level, player.experience, player.gold);
        printf("Would you like to:\n");
        printf("1. Explore the dungeon\n");
        printf("2. Rest\n");
        printf("3. View your status\n");
        printf("4. Quit\n");
        
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("You encounter a wild %s!\n", enemy.name);
                battle(&player, &enemy);
                break;
            case 2:
                printf("You find a room to rest and regain your health.\n");
                player.health = 100;
                break;
            case 3:
                printf("Your status:\n");
                printf("Name: %s\n", player.name);
                printf("Health: %d\n", player.health);
                printf("Attack: %d\n", player.attack);
                printf("Defense: %d\n", player.defense);
                printf("Agility: %d\n", player.agility);
                printf("Level: %d\n", player.level);
                printf("Experience: %d\n", player.experience);
                printf("Gold: %d\n", player.gold);
                break;
            case 4:
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    printf("Game over. %s was defeated at level %d with %d experience and %d gold.\n", player.name, player.level, player.experience, player.gold);
    return 0;
}