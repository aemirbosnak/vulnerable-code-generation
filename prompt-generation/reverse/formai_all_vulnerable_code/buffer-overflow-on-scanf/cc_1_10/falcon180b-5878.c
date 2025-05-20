//Falcon-180B DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int health;
    int attack;
} Character;

void print_character(Character c) {
    printf("Name: %s\n", c.name);
    printf("Health: %d\n", c.health);
    printf("Attack: %d\n", c.attack);
}

void generate_character(Character* c) {
    strcpy(c->name, "Survivor");
    c->health = rand() % 101;
    c->attack = rand() % 101;
}

int fight(Character attacker, Character defender) {
    int attack_power = attacker.attack;
    int defense_power = defender.health;

    if (attack_power > defense_power) {
        defender.health -= attack_power - defense_power;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    Character player;
    generate_character(&player);
    print_character(player);

    Character enemy;
    generate_character(&enemy);
    print_character(enemy);

    int choice;
    while (1) {
        printf("What do you want to do?\n");
        printf("1. Attack\n2. Defend\n");
        scanf("%d", &choice);

        if (choice == 1 && player.health > 0 && enemy.health > 0) {
            if (fight(player, enemy)) {
                printf("You dealt %d damage to the enemy!\n", player.attack - enemy.health);
                enemy.health = 0;
            } else {
                printf("You missed the enemy.\n");
            }
        } else if (choice == 2 && player.health > 0 && enemy.health > 0) {
            if (fight(enemy, player)) {
                printf("The enemy dealt %d damage to you!\n", enemy.attack - player.health);
                player.health = 0;
            } else {
                printf("The enemy missed you.\n");
            }
        } else {
            printf("Invalid choice.\n");
        }

        if (player.health <= 0) {
            printf("You died. Game over.\n");
            break;
        } else if (enemy.health <= 0) {
            printf("You killed the enemy. Congratulations!\n");
            break;
        }
    }

    return 0;
}