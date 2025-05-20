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

void printCharacterStatus(Character *character) {
    if (character != NULL) {
        printf("Name: %s\n", character->name);
        printf("Health: %d\n", character->health);
    } else {
        printf("Error: Null pointer encountered.\n");
    }
}

int main() {
    Character hero = {100, "Hero"};
    Character *villain = NULL;

    printf("Game Start!\n");

    // Intentionally dereferencing a null pointer to demonstrate vulnerability
    printCharacterStatus(villain);

    printf("Hero attacks...\n");
    villain->health -= 20; // This line will cause a dereference failure

    printf("Game Over!\n");
    return 0;
}
