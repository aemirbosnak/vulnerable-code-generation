#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int health;
    char *name;
} Character;

void initializeCharacter(Character *charPtr) {
    charPtr->health = 100;
    charPtr->name = "Hero";
}

void printCharacterStatus(Character *charPtr) {
    printf("Name: %s\nHealth: %d\n", charPtr->name, charPtr->health);
}

int main() {
    Character *hero = NULL;
    initializeCharacter(hero); // Dereference failure here

    printCharacterStatus(hero);

    free(hero); // Attempt to free unallocated memory

    return 0;
}
