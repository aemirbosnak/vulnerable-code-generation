//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int health;
} Character;

void introduction() {
    printf("In fair Verona, where we lay our scene, \n");
    printf("Two star-crossed lovers must navigate their plight...\n\n");
    printf("Choose your character:\n");
    printf("1. Romeo\n");
    printf("2. Juliet\n");
}

void setCharacter(Character *character, int choice) {
    if (choice == 1) {
        strcpy(character->name, "Romeo");
        character->health = 100;
    } else {
        strcpy(character->name, "Juliet");
        character->health = 100;
    }
}

void choices(Character *character) {
    printf("\nYou are now playing as %s. What will you do?\n", character->name);
    printf("1. Sneak out to meet your love.\n");
    printf("2. Stay and confront the family feud.\n");
}

void meetLove(Character *character) {
    printf("\nYou sneaked out and met your love under the moonlight...\n");
    printf("1. Share a passionate kiss.\n");
    printf("2. Exchange vows of love.\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Your love deepens, and the night is filled with promises!\n");
    } else {
        printf("You vow to love each other until the end...\n");
    }
}

void confrontFeud(Character *character) {
    printf("\nYou confront the Capulet or Montague family...\n");
    printf("1. Stand your ground.\n");
    printf("2. Seek peace with words.\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("A duel ensues, and you lose some health!\n");
        character->health -= 30;
        printf("Remaining Health: %d\n", character->health);
    } else {
        printf("Your words soften their hearts, and they listen...\n");
    }
}

void ending(Character *character) {
    if (character->health > 0) {
        printf("\nLove conquers all! You and your lover found happiness together!\n");
    } else {
        printf("\nTragedy strikes as the feud takes its toll. But love was not in vain.\n");
    }
}

int main() {
    Character character;
    int choice;

    introduction();
    scanf("%d", &choice);
    setCharacter(&character, choice);

    choices(&character);
    scanf("%d", &choice);
    
    if (choice == 1) {
        meetLove(&character);
    } else {
        confrontFeud(&character);
    }

    ending(&character);
    return 0;
}