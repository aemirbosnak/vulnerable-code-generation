//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10

typedef struct Enemy {
    char name[20];
    int health;
    int armor;
    int attack_power;
} Enemy;

void battle(Enemy *enemy) {
    printf("You are battling %s.\n", enemy->name);
    printf("Their health is %d.\n", enemy->health);
    printf("Their armor is %d.\n", enemy->armor);
    printf("Enter your attack command (attack, defend, flee): ");

    char command;
    scanf("%c", &command);

    switch (command) {
        case 'a':
            enemy->health -= 20;
            printf("You attacked successfully!\n");
            break;
        case 'd':
            enemy->armor -= 10;
            printf("You defended successfully!\n");
            break;
        case 'f':
            printf("You fled successfully!\n");
            break;
        default:
            printf("Invalid command.\n");
            break;
    }

    if (enemy->health <= 0) {
        printf("You have defeated %s!\n", enemy->name);
    } else if (enemy->armor <= 0) {
        printf("You have broken %s's armor!\n", enemy->name);
    } else {
        battle(enemy);
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Enemy enemies[MAX_ENEMIES];
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].name[0] = 'E' + i;
        enemies[i].health = rand() % 100 + 10;
        enemies[i].armor = rand() % 20 + 1;
        enemies[i].attack_power = rand() % 20 + 1;
    }

    battle(&enemies[0]);

    return 0;
}