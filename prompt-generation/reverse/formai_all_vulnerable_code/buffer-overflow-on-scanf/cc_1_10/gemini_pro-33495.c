//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} creature;

creature player;
creature enemies[10];
int num_enemies;
int current_enemy;

void create_player() {
    printf("What is your name?\n");
    scanf("%s", player.name);
    player.health = 100;
    player.attack = 10;
    player.defense = 10;
}

void create_enemies() {
    srand(time(NULL));
    num_enemies = rand() % 10 + 1;
    for (int i = 0; i < num_enemies; i++) {
        enemies[i].name = malloc(10);
        enemies[i].health = rand() % 100 + 1;
        enemies[i].attack = rand() % 20 + 1;
        enemies[i].defense = rand() % 20 + 1;
    }
}

void print_stats() {
    printf("Player:\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Attack: %d\n", player.attack);
    printf("Defense: %d\n\n", player.defense);

    for (int i = 0; i < num_enemies; i++) {
        printf("Enemy %d:\n", i + 1);
        printf("Name: %s\n", enemies[i].name);
        printf("Health: %d\n", enemies[i].health);
        printf("Attack: %d\n", enemies[i].attack);
        printf("Defense: %d\n\n", enemies[i].defense);
    }
}

void attack(creature *attacker, creature *defender) {
    int damage = attacker->attack - defender->defense;
    if (damage < 0) {
        damage = 0;
    }
    defender->health -= damage;
    printf("%s attacks %s for %d damage!\n", attacker->name, defender->name, damage);
}

void battle() {
    while (player.health > 0 && current_enemy < num_enemies) {
        print_stats();

        int choice;
        printf("What do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                attack(&player, &enemies[current_enemy]);
                if (enemies[current_enemy].health <= 0) {
                    printf("%s has been defeated!\n", enemies[current_enemy].name);
                    current_enemy++;
                }
                break;
            case 2:
                // TODO: Implement defend
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        if (player.health <= 0) {
            printf("You have been defeated!\n");
            break;
        }

        attack(&enemies[current_enemy], &player);
    }
}

void cleanup() {
    for (int i = 0; i < num_enemies; i++) {
        free(enemies[i].name);
    }
}

int main() {
    create_player();
    create_enemies();
    battle();
    cleanup();
    return 0;
}