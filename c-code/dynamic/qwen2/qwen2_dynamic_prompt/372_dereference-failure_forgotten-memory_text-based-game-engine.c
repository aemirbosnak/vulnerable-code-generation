#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int health;
} Character;

void loadCharacter(Character *charPtr) {
    FILE *file = fopen("character.dat", "rb");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }
    fread(charPtr, sizeof(Character), 1, file);
    fclose(file);
}

int main() {
    Character *player = NULL;
    player->health = 100; // Dereference failure: using uninitialized pointer

    printf("Welcome to the Adventure Game!\n");

    while (1) {
        printf("Your current health is %d\n", player->health);

        printf("Enter 's' to save your progress or 'q' to quit: ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        } else if (choice == 's') {
            loadCharacter(player); // Load character data from file
        } else {
            printf("Invalid choice.\n");
        }
    }

    free(player); // Free allocated memory
    return 0;
}
