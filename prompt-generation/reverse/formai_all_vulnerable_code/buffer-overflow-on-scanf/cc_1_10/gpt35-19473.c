//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYER_NAME_SIZE 20

typedef struct {
    char name[MAX_PLAYER_NAME_SIZE];
    int health;
    int armor;
    int weapon_power;
} Player;

typedef struct {
    char type[20];
    int damage;
} Weapon;

typedef struct {
    char name[30];
    char description[100];
    int enemy_health;
    Weapon enemy_weapon;
} Enemy;

void print_player_status(Player player) {
    printf("Name: %s\nHealth: %d\nArmor: %d\nWeapon Power: %d\n",
           player.name, player.health, player.armor, player.weapon_power);
}

void print_enemy_status(Enemy enemy) {
    printf("Name: %s\nDescription: %s\nHealth: %d\n",
           enemy.name, enemy.description, enemy.enemy_health);
}

void attack_enemy(Player *player, Enemy *enemy) {
    int damage = player->weapon_power - enemy->enemy_weapon.damage;
    if (damage < 0) {
        damage = 0;
    }
    enemy->enemy_health -= damage;
    printf("%s attacked %s with a damage of %d!\n", player->name, enemy->name, damage);
}

int main() {
    printf("Welcome to the Procedural Space Adventure game!\n");
    Player player;
    printf("Please enter your name (up to %d characters): ", MAX_PLAYER_NAME_SIZE);
    scanf("%s", player.name);
    player.health = 100;
    player.armor = 50;
    player.weapon_power = 25;
    printf("Welcome, %s!\n", player.name);
    printf("Your mission is to explore the galaxy and defeat the evil aliens.\n");

    Enemy enemy1 = {"Krogan", "A fierce warrior alien from the planet Tuchanka.", 50, {"Shotgun", 15}};
    Enemy enemy2 = {"Reaper", "A highly advanced sentient machine from beyond the galaxy.", 100, {"Laser Beam", 30}};
    Enemy enemy3 = {"Zerg", "A swarm of insectoid-like aliens that consume all in their path.", 75, {"Acid Spray", 20}};
    Enemy *enemies[] = {&enemy1, &enemy2, &enemy3};
    int num_enemies = 3;

    while (num_enemies > 0) {
        // Player chooses which enemy to attack
        printf("Choose an enemy to attack:\n");
        for (int i = 0; i < num_enemies; i++) {
            printf("%d. %s\n", i+1, enemies[i]->name);
        }
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > num_enemies) {
            printf("Invalid choice!\n");
            continue;
        }
        choice--;
        printf("You have chosen to attack %s!\n", enemies[choice]->name);
        printf("Your current status:\n");
        print_player_status(player);
        printf("The enemy status:\n");
        print_enemy_status(*enemies[choice]);

        // Player attacks the chosen enemy
        attack_enemy(&player, enemies[choice]);
        if (enemies[choice]->enemy_health <= 0) {
            printf("You have defeated %s!\n", enemies[choice]->name);
            num_enemies--;
            for (int i = choice; i < num_enemies; i++) {
                enemies[i] = enemies[i+1];
            }
        }
        else {
            // Enemy attacks the player
            printf("%s attacked with a damage of %d!\n", enemies[choice]->name, enemies[choice]->enemy_weapon.damage);
            int damage = enemies[choice]->enemy_weapon.damage - player.armor;
            if (damage < 0) {
                damage = 0;
            }
            player.health -= damage;
            printf("You received %d damage! Your current health is %d.\n", damage, player.health);
            if (player.health <= 0) {
                printf("You have been defeated!\n");
                exit(0);
            }
        }
    }

    printf("Congratulations, you have saved the galaxy!\n");
    return 0;
}