//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMY_NUMBER 10
#define MAX_ENEMY_HP 150
#define MAX_PLAYER_HP 200

struct enemy {
    int hp;
    int damage;
    int speed;
};

int main() {
    srand((unsigned)time(NULL));
    
    int player_hp = MAX_PLAYER_HP;
    int enemy_count = 0;
    struct enemy enemies[MAX_ENEMY_NUMBER];

    printf("Welcome to Procedural Space Adventure!\n");

    while (player_hp > 0 && enemy_count < MAX_ENEMY_NUMBER) {
        printf("Player HP: %d\n", player_hp);
        printf("Number of Enemies: %d\n", enemy_count);

        struct enemy new_enemy;
        new_enemy.hp = rand() % MAX_ENEMY_HP + 50;
        new_enemy.damage = rand() % 25 + 25;
        new_enemy.speed = rand() % 10 + 1;

        printf("A new enemy has appeared! HP: %d, Damage: %d, Speed: %d\n", 
                new_enemy.hp, new_enemy.damage, new_enemy.speed);

        int choice = 0;
        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Flee\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You attack the enemy!\n");
            new_enemy.hp -= rand() % 50 + 25;
            if (new_enemy.hp <= 0) {
                printf("The enemy has been defeated!\n");
                enemy_count++;
                continue;
            }

            printf("The enemy attacks you!\n");
            player_hp -= new_enemy.damage;
            if (player_hp <= 0) {
                printf("You have been defeated...\n");
                break;
            }
        } else if (choice == 2) {
            printf("You flee the battle...\n");
            continue;
        } else {
            printf("Invalid choice!\n");
            continue;
        }
    }

    if (enemy_count == MAX_ENEMY_NUMBER) {
        printf("Congratulations! You have defeated all the enemies!\n");
    }

    printf("Thanks for playing Procedural Space Adventure!\n");
    return 0;
}