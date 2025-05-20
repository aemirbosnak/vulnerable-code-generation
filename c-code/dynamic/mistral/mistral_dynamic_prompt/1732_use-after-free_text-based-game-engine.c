#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int health, attack;
} Character;

Character *createCharacter(char *name, int health, int attack) {
    Character *newCharacter = (Character *)malloc(sizeof(Character));
    newCharacter->name = strdup(name);
    newCharacter->health = health;
    newCharacter->attack = attack;
    return newCharacter;
}

void freeCharacter(Character *character) {
    free(character->name);
    free(character);
}

int main() {
    Character *hero = createCharacter("Hero", 100, 20);
    Character *enemy = createCharacter("Goblin", 30, 5);

    while (hero->health > 0 && enemy->health > 0) {
        printf("Hero's HP: %d\n", hero->health);
        printf("Goblin's HP: %d\n", enemy->health);

        hero->health -= enemy->attack;
        enemy->health -= hero->attack;
    }

    if (enemy->health > 0) {
        printf("Goblin has won!\n");
    } else {
        printf("Hero has won!\n");
    }

    free(hero); // Free the memory allocated for the hero, but reuse 'hero' pointer
    printf("Fight again!\n");

    return 0;
}
