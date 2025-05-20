//GPT-4o-mini DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_DESC_LENGTH 200

// Function prototypes
void welcomeMessage();
void getPlayerName(char *name);
void chooseAdventure();
void forestAdventure();
void oceanAdventure();
void mountainAdventure();
void displayEnding(const char *adventureName);

int main() {
    char playerName[MAX_NAME_LENGTH];

    welcomeMessage();
    getPlayerName(playerName);
    chooseAdventure();

    return 0;
}

void welcomeMessage() {
    printf("*****************************************\n");
    printf("*         Welcome to Happy Adventure!   *\n");
    printf("*****************************************\n");
    printf("In this game, you will embark on a joyful adventure!\n");
    printf("Choose your path wisely! Ready? Let's go!\n");
}

void getPlayerName(char *name) {
    printf("\nWhat's your name, brave adventurer? ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character
    printf("Welcome, %s! Let's start your adventure!\n", name);
}

void chooseAdventure() {
    int choice;
    
    printf("\nChoose your adventure:\n");
    printf("1. Enchanted Forest\n");
    printf("2. Sparkling Ocean\n");
    printf("3. Mysterious Mountains\n");
    printf("Enter the number of your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            forestAdventure();
            break;
        case 2:
            oceanAdventure();
            break;
        case 3:
            mountainAdventure();
            break;
        default:
            printf("That's not a valid choice. Let's try again!\n");
            chooseAdventure();
            break;
    }
}

void forestAdventure() {
    printf("\nYou've entered the Enchanted Forest filled with magic and wonder!\n");
    printf("You see friendly fairies dancing around you.\n");
    printf("Would you like to:\n");
    printf("1. Join the fairies in their dance\n");
    printf("2. Search for hidden treasures\n");

    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You dance with the fairies and feel the joy of the forest!\n");
        displayEnding("Enchanted Forest Dance");
    } else if (choice == 2) {
        printf("You discover a hidden treasure chest filled with glittering gems!\n");
        displayEnding("Hidden Treasures in the Forest");
    } else {
        printf("That's not a valid choice. The fairies giggle at you!\n");
        forestAdventure();
    }
}

void oceanAdventure() {
    printf("\nYou've arrived at the Sparkling Ocean with shimmering waves!\n");
    printf("You see friendly dolphins jumping in the water.\n");
    printf("Would you like to:\n");
    printf("1. Swim with the dolphins\n");
    printf("2. Collect seashells on the beach\n");

    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You swim with the dolphins and feel a wave of happiness!\n");
        displayEnding("Swim with Dolphins");
    } else if (choice == 2) {
        printf("You found beautiful seashells, each telling a story of the ocean!\n");
        displayEnding("Shores of Seashells");
    } else {
        printf("That's not a valid choice. The dolphins splash you playfully!\n");
        oceanAdventure();
    }
}

void mountainAdventure() {
    printf("\nYou've scaled the Mysterious Mountains filled with adventure!\n");
    printf("You encounter a wise old owl perched on a branch.\n");
    printf("Would you like to:\n");
    printf("1. Ask the owl for advice\n");
    printf("2. Climb higher to see the view\n");

    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("The owl shares wisdom and you feel enlightened!\n");
        displayEnding("Wisdom from the Owl");
    } else if (choice == 2) {
        printf("You reach a stunning viewpoint and the scenery takes your breath away!\n");
        displayEnding("Amazing Mountain View");
    } else {
        printf("That's not a valid choice. The owl hoots at you!\n");
        mountainAdventure();
    }
}

void displayEnding(const char *adventureName) {
    printf("***********************************\n");
    printf("*          Adventure Complete!    *\n");
    printf("* You had a wonderful time in the %s! *\n", adventureName);
    printf("***********************************\n");
}