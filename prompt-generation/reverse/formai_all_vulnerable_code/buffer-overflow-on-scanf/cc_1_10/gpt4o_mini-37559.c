//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void startAdventure();
void forestPath();
void encounterAnimal();
void treasureLocation();
void welcome();
void printGameRules();

int main() {
    welcome();
    startAdventure();
    return 0;
}

void welcome() {
    printf("*******************************\n");
    printf("** Welcome to Magical Forest! **\n");
    printf("*******************************\n");
    printf("In this cheerful adventure, you will explore a vibrant forest filled with surprises!\n");
    printGameRules();
}

void printGameRules() {
    printf("Game Rules:\n");
    printf("1. Choose paths to explore the forest.\n");
    printf("2. Encounter friendly animals who may help you.\n");
    printf("3. Find the hidden treasure!\n\n");
}

void startAdventure() {
    char choice[10];
    printf("Do you want to begin your adventure? (yes/no): ");
    scanf("%s", choice);
    
    if (strcmp(choice, "yes") == 0) {
        printf("Great! You step into the magical forest...\n");
        forestPath();
    } else {
        printf("Oh no! The adventure will wait for you. Come back when you're ready!\n");
    }
}

void forestPath() {
    char choice[10];
    printf("\nYou can go left or right in the forest. Which path do you choose? (left/right): ");
    scanf("%s", choice);

    if (strcmp(choice, "left") == 0) {
        encounterAnimal();
    } else if (strcmp(choice, "right") == 0) {
        treasureLocation();
    } else {
        printf("That's not a valid choice. Let's try again!\n");
        forestPath();
    }
}

void encounterAnimal() {
    char choice[10];
    printf("\nYou encounter a friendly squirrel!\n");
    printf("The squirrel offers you a nut. Do you take it? (yes/no): ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        printf("The squirrel thanks you with a cheerful dance! You've gained a nut!\n");
        printf("You can continue deeper into the forest or return to the path you came from.\n");
        printf("Where do you want to go next? (deeper/return): ");
        scanf("%s", choice);
        
        if (strcmp(choice, "deeper") == 0) {
            printf("You venture deeper into the forest, enjoying the sounds of nature...\n");
            treasureLocation();
        } else {
            printf("You return to the original path, safe and sound!\n");
            forestPath();
        }
    } else {
        printf("The squirrel looks sad, but you continue on your way.\n");
        treasureLocation();
    }
}

void treasureLocation() {
    char choice[10];
    printf("\nAs you walk, you stumble upon a sparkling clearing!\n");
    printf("Suddenly, you spot a treasure chest! Do you want to open it? (yes/no): ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        printf("\nYou open the chest and find it filled with shiny gold coins and gems!\n");
        printf("Congratulations, you found the treasure! You're now rich!\n");
        printf("Thank you for playing this cheerful adventure!\n");
    } else {
        printf("\nYou choose not to open the chest, wondering what could be inside...\n");
        printf("Maybe another adventurer will be braver than you!\n");
        printf("Thank you for playing this cheerful adventure!\n");
    }
}