//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printWelcome() {
    printf("================================\n");
    printf("    WELCOME TO THE FOREST     \n");
    printf("     ADVENTURE GAME!           \n");
    printf("================================\n");
    printf("You are an adventurer seeking a hidden treasure.\n");
    printf("Make wise choices to navigate through the mystical forest!\n");
    printf("================================\n\n");
}

void printChoices() {
    printf("Where would you like to go?\n");
    printf("1. Enter the Dark Cave\n");
    printf("2. Cross the Enchanted River\n");
    printf("3. Climb the Ancient Mountain\n");
    printf("4. Visit the Mysterious Village\n");
    printf("5. Exit the game\n");
}

void enterCave() {
    printf("You cautiously enter the Dark Cave.\n");
    printf("Suddenly, a giant bat swoops down!\n");
    printf("Do you want to (1) Fight the bat or (2) Run away?\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You bravely fight the bat and win!\n");
    } else {
        printf("You decide to run away. Luck favors you!\n");
    }
}

void crossRiver() {
    printf("You step towards the Enchanted River.\n");
    printf("The water sparkles with magical energy.\n");
    printf("Do you want to (1) Swim across or (2) Build a raft?\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You swim across the river and reach the other side safely!\n");
    } else {
        printf("You build a raft and float across. Good job!\n");
    }
}

void climbMountain() {
    printf("You start climbing the Ancient Mountain.\n");
    printf("Suddenly, a rockslide occurs!\n");
    printf("Do you want to (1) Try to climb faster or (2) Find a safe spot?\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You manage to climb faster and avoid the rockslide!\n");
    } else {
        printf("You find a safe spot. The rockslide misses you!\n");
    }
}

void visitVillage() {
    printf("You arrive at the Mysterious Village.\n");
    printf("The villagers seem friendly but they have enigmatic looks.\n");
    printf("Do you want to (1) Ask about treasure or (2) Trade with villagers?\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("The villagers share legends of a hidden treasure!\n");
    } else {
        printf("You trade items and gain their trust.\n");
    }
}

int main() {
    int choice;
    printWelcome();

    while (1) {
        printChoices();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterCave();
                break;
            case 2:
                crossRiver();
                break;
            case 3:
                climbMountain();
                break;
            case 4:
                visitVillage();
                break;
            case 5:
                printf("Thank you for playing! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}