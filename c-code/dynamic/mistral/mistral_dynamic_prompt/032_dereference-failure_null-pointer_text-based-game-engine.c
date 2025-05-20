#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int health;
    char* attacks[3];
} Character;

void attack(Character* opponent, Character* attacker, int attackIndex) {
    printf("%s uses %s on %s!\n", attacker->name, attacker->attacks[attackIndex], opponent->name);
    opponent->health -= 10 * (opponent->health / attacker->health);
}

int main() {
    Character player = {"Player", 100, {"Slash", "Bite", "Fist"}};
    Character monster = {"Goblin", 50, NULL};

    int choice;
    scanf("%d", &choice);

    attack(&monster, &player, choice);
    printf("The goblin has %d health remaining.\n", monster.health);

    return 0;
}
