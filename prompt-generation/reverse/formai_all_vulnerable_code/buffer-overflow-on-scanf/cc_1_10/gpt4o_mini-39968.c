//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256
#define MAX_CHAPTERS 5

typedef struct {
    char name[50];
    char love_interest[50];
    char spaceship[50];
    int fate;  // 0: tragedy, 1: happy ending
} Character;

void start_adventure(Character *character) {
    printf("Welcome to the celestial saga of %s and %s.\n", character->name, character->love_interest);
    printf("You both are star-crossed lovers in a galaxy full of rival factions.\n\n");
}

void choose_spaceship(Character *character) {
    printf("Choose a spaceship for your thrilling journey:\n");
    printf("1. The StarFire\n");
    printf("2. The Celestial Voyager\n");
    printf("Enter the name of your spaceship: ");
    fgets(character->spaceship, sizeof(character->spaceship), stdin);
    character->spaceship[strcspn(character->spaceship, "\n")] = '\0'; // Remove newline
}

void chapter_one(Character *character) {
    printf("Chapter 1: The Forbidden Love\n");
    printf("%s, a rebelling astronaut, has fallen in love with %s, a member of a rival faction.\n", character->name, character->love_interest);
    printf("They meet secretly on the asteroid of Verona-9.\n");
    printf("Do you choose to keep their love a secret or announce it to the factions?\n");
    printf("1. Keep it a secret\n");
    printf("2. Boldly announce it\n");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // To consume the newline character
    if (choice == 1) {
        printf("They decided to cherish their love in the shadows.\n");
    } else {
        printf("They announced their love, causing unrest among the factions.\n");
    }
}

void chapter_two(Character *character) {
    printf("Chapter 2: The Galactic Challenge\n");
    printf("A race is set by both factions to declare the strongest. %s and %s must enter the race aboard the %s.\n", character->name, character->love_interest, character->spaceship);
    printf("Will they risk everything for victory?\n");
    printf("1. Enter the race\n");
    printf("2. Withdraw to protect their love\n");

    int choice;
    scanf("%d", &choice);
    getchar(); // To consume the newline character
    if (choice == 1) {
        printf("They entered the race, their hearts pounding with excitement.\n");
    } else {
        printf("They chose love over glory, hiding in the shadows of space.\n");
    }
}

void chapter_three(Character *character) {
    printf("Chapter 3: The Clash of Factions\n");
    printf("Enemies target them due to their defiance. A battle ensues in the cosmos.\n");
    printf("1. Fight back fiercely\n");
    printf("2. Attempt to negotiate peace\n");

    int choice;
    scanf("%d", &choice);
    getchar(); // To consume the newline character
    if (choice == 1) {
        printf("They fought bravely, but the odds were against them.\n");
        character->fate = 0; // Tragedy
    } else {
        printf("They negotiated peace, finding common ground in love.\n");
        character->fate = 1; // Happy ending
    }
}

void conclusion(Character character) {
    if (character.fate == 0) {
        printf("In the end, love is but a fleeting shadow.\n");
        printf("Their story is one of great tragedy, eternal love lost among the stars.\n");
    } else {
        printf("Against all odds, they prevailed, fostering peace among the stars.\n");
        printf("Their love illuminated the cosmos, forever united.\n");
    }
}

int main() {
    Character character;
    printf("Enter the name of the courageous astronaut: ");
    fgets(character.name, sizeof(character.name), stdin);
    character.name[strcspn(character.name, "\n")] = '\0'; // Remove newline
    
    printf("Enter the name of their love interest: ");
    fgets(character.love_interest, sizeof(character.love_interest), stdin);
    character.love_interest[strcspn(character.love_interest, "\n")] = '\0'; // Remove newline

    character.fate = -1; // Initialize fate

    start_adventure(&character);
    choose_spaceship(&character);
    
    chapter_one(&character);
    chapter_two(&character);
    chapter_three(&character);
    conclusion(character);

    return 0;
}