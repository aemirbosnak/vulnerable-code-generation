//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int health = 100;
int strength = 10;
int agility = 10;
int gold = 0;
int level = 1;

void battle() {
    int enemy_health = 50;
    int enemy_strength = 5;
    while (health > 0 && enemy_health > 0) {
        printf("Enemy Health: %d\n", enemy_health);
        printf("Your Health: %d\n", health);
        int attack_type;
        printf("Select Attack Type (1: normal, 2: special)\n");
        scanf("%d", &attack_type);
        if (attack_type == 1) {
            int damage = strength - enemy_strength;
            enemy_health = enemy_health - damage;
            printf("You did %d damage to the enemy!\n", damage);
        } else if (attack_type == 2) {
            if (agility >= 5) {
                int damage = strength + 5 - enemy_strength;
                enemy_health = enemy_health - damage;
                agility = agility - 5;
                printf("You did %d damage to the enemy!\n", damage);
            } else {
                printf("Not enough agility to use special attack!\n");
            }
        } else {
            printf("Invalid attack type! Try again.\n");
        }
        if (enemy_health > 0) {
            int enemy_attack = enemy_strength - agility;
            health = health - enemy_attack;
            printf("The enemy did %d damage to you!\n", enemy_attack);
        }
    }
    if (health > 0) {
        printf("You defeated the enemy! You gained 10 gold and 1 level!\n");
        gold = gold + 10;
        level = level + 1;
    } else {
        printf("You were defeated by the enemy! Game over.\n");
        exit(0);
    }
}

void shop() {
    printf("Welcome to the shop!\n");
    printf("You have %d gold.\n", gold);
    int item_choice;
    printf("Select Item (1: health potion, 2: strength potion, 3: agility potion)\n");
    scanf("%d", &item_choice);
    if (item_choice == 1) {
        if (gold >= 10) {
            gold = gold - 10;
            health = health + 50;
            printf("You bought a health potion! Your health is now %d.\n", health);
        } else {
            printf("Not enough gold to buy health potion!\n");
        }
    } else if (item_choice == 2) {
        if (gold >= 20) {
            gold = gold - 20;
            strength = strength + 10;
            printf("You bought a strength potion! Your strength is now %d.\n", strength);
        } else {
            printf("Not enough gold to buy strength potion!\n");
        }
    } else if (item_choice == 3) {
        if (gold >= 50) {
            gold = gold - 50;
            agility = agility + 5;
            printf("You bought an agility potion! Your agility is now %d.\n", agility);
        } else {
            printf("Not enough gold to buy agility potion!\n");
        }
    } else {
        printf("Invalid item choice! Try again.\n");
    }
}

int main() {
    while (1) {
        int choice;
        printf("Select Option (1: battle, 2: shop, 3: quit)\n");
        scanf("%d", &choice);
        if (choice == 1) {
            battle();
        } else if (choice == 2) {
            shop();
        } else if (choice == 3) {
            printf("Thanks for playing!\n");
            exit(0);
        } else {
            printf("Invalid option! Try again.\n");
        }
    }
    return 0;
}