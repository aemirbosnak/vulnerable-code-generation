//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Character;

void generateCharacter(Character* c) {
    sprintf(c->name, "Character %d", rand() % 1000);
    c->health = rand() % 100 + 1;
    c->attack = rand() % 50 + 1;
    c->defense = rand() % 50 + 1;
}

int fight(Character attacker, Character defender) {
    int damage = attacker.attack - defender.defense;
    if (damage > 0) {
        defender.health -= damage;
        if (defender.health <= 0) {
            printf("You have defeated %s!\n", defender.name);
            return 1;
        } else {
            printf("You dealt %d damage to %s.\n", damage, defender.name);
        }
    } else {
        printf("Your attack was blocked by %s.\n", defender.name);
    }
    return 0;
}

int main() {
    srand(time(NULL));
    Character player;
    generateCharacter(&player);

    while (player.health > 0) {
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Fight an enemy\n");
        printf("2. Check your stats\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                Character enemy;
                generateCharacter(&enemy);
                int result = fight(player, enemy);
                if (!result) {
                    enemy.health = 0;
                }
            }
            break;
        case 2:
            printf("Name: %s\n", player.name);
            printf("Health: %d\n", player.health);
            printf("Attack: %d\n", player.attack);
            printf("Defense: %d\n", player.defense);
            break;
        case 3:
            printf("Thanks for playing!\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}