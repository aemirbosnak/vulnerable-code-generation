#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int health;
    char name[20];
} Character;

void attack(Character *target) {
    if (target != NULL) {
        target->health -= 10;
        printf("Attack! %s's health is now %d\n", target->name, target->health);
    } else {
        printf("Invalid target!\n");
    }
}

int main() {
    Character hero = {"Hero", 100};
    Character *villain = NULL;

    printf("Welcome to the Adventure Game!\n");

    // Simulate battle
    attack(&hero); // Valid attack
    attack(villain); // Invalid attack

    return 0;
}
