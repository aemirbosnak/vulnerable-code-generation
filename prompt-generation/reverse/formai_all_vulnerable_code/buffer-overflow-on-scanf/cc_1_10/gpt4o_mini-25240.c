//GPT-4o-mini DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void startGame();
void forestPath();
void riverSide();
void mysteriousCave();
void decision(char *option1, char *option2, void (*next1)(), void (*next2)());
void treasureFound();
void creatureEncounter();
void deadEnd();
void intro();

int main() {
    startGame();
    return 0;
}

void startGame() {
    intro();
    forestPath();
}

void intro() {
    printf("Welcome to the Forest Adventure Game!\n");
    printf("You will explore the forest paths to find treasure.\n");
    printf("Beware of creatures along the way!\n");
    printf("Let's begin your adventure...\n\n");
}

void forestPath() {
    printf("You find yourself at a fork in the path.\n");
    printf("To the left, the path leads deeper into the forest,\n");
    printf("To the right, you see a river sparkling in the sunlight.\n");
    printf("Which path do you want to take? (L/R): ");
    
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'L' || choice == 'l') {
        mysteriousCave();
    } else if (choice == 'R' || choice == 'r') {
        riverSide();
    } else {
        printf("That's not a valid choice. Let's try again.\n\n");
        forestPath();
    }
}

void riverSide() {
    printf("You walk along the riverside, enjoying the view.\n");
    printf("Suddenly, you see a strange figure by the water.\n");
    printf("Do you want to approach it or keep walking? (A/K): ");
    
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'A' || choice == 'a') {
        creatureEncounter();
    } else if (choice == 'K' || choice == 'k') {
        printf("You chose to keep walking. Safe and sound!\n\n");
        printf("But you missed an opportunity...\n\n");
        forestPath();
    } else {
        printf("That's not a valid choice. Let's try again.\n\n");
        riverSide();
    }
}

void mysteriousCave() {
    printf("You enter a dark cave. The air is damp and cool.\n");
    printf("You see two paths inside the cave.\n");
    printf("One path has eerie sounds coming from it,\n");
    printf("The other looks like it leads deeper into the darkness.\n");
    
    decision("Explore the eerie path", "Go deeper into the darkness", mysteriousCave, deadEnd);
}

void decision(char *option1, char *option2, void (*next1)(), void (*next2)()) {
    printf("What do you want to do?\n");
    printf("1. %s\n", option1);
    printf("2. %s\n", option2);
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        next1(); 
    } else if (choice == 2) {
        next2(); 
    } else {
        printf("That's not a valid choice. Let's try again.\n\n");
        decision(option1, option2, next1, next2);
    }
}

void treasureFound() {
    printf("Congratulations! You found the treasure!\n");
    printf("You can retire as a wealthy adventurer!\n");
    exit(0);
}

void creatureEncounter() {
    int encounter = rand() % 2; // Randomly determine the creature's outcome
    
    if (encounter == 0) {
        printf("It's a friendly elf! He grants you a wish.\n");
        treasureFound();
    } else {
        printf("Oh no! It's a fierce dragon! You cannot escape!\n");
        deadEnd();
    }
}

void deadEnd() {
    printf("You have reached a dead end. Game over!\n");
    exit(0);
}