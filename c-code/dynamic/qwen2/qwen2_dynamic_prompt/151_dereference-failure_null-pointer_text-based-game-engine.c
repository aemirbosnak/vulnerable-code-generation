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
        printf("Error: Character is null.\n");
    }
}

int main() {
    Character hero = {100, "Hero"};
    Character *villain = NULL;

    printf("Game Start:\n");
    printCharacterStatus(&hero);

    // Intentional dereference failure
    printf("\nAttempting to access villain's status...\n");
    printCharacterStatus(villain);

    return 0;
}
