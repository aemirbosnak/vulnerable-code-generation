//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100

typedef struct character {
    char name[20];
    int health;
    int attack;
    int defense;
} character;

character createCharacter() {
    character newCharacter;
    printf("Enter character name: ");
    scanf("%s", newCharacter.name);
    newCharacter.health = MAX_HEALTH;
    newCharacter.attack = rand() % 10 + 1;
    newCharacter.defense = rand() % 5 + 1;
    return newCharacter;
}

void battle(character player, character enemy) {
    int playerTurn = 1;
    while (player.health > 0 && enemy.health > 0) {
        if (playerTurn) {
            int damage = player.attack - enemy.defense;
            enemy.health -= damage;
            printf("%s attacks %s for %d damage!\n", player.name, enemy.name, damage);
        } else {
            int damage = enemy.attack - player.defense;
            player.health -= damage;
            printf("%s attacks %s for %d damage!\n", enemy.name, player.name, damage);
        }
        playerTurn = !playerTurn;
    }
}

int main() {
    character player = createCharacter();
    character enemy = createCharacter();
    battle(player, enemy);

    if (player.health > enemy.health) {
        printf("%s won the battle!\n", player.name);
    } else {
        printf("%s won the battle!\n", enemy.name);
    }

    return 0;
}