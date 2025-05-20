//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introduction() {
    printf("Welcome to 'The Mysterious Forest'!\n");
    printf("You awaken in a dense, enchanted forest with towering trees and the sound of rustling leaves.\n");
    printf("In this adventure, you will decide your fate! What will you do?\n");
}

void clearing() {
    printf("You walk into a clearing where a majestic unicorn stands.\n");
    printf("Do you want to:\n");
    printf("1. Approach the unicorn.\n");
    printf("2. Ignore and continue walking.\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("The unicorn approaches you and grants you a wish! What do you wish for?\n");
        printf("1. Wealth\n");
        printf("2. Knowledge\n");
        printf("3. Adventure\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You are now the wealthiest person in the kingdom!\n");
        } else if (choice == 2) {
            printf("You attain wisdom beyond your years!\n");
        } else {
            printf("You become the hero of your own adventure, exploring lands far and wide!\n");
        }
    } else {
        printf("You ignore the unicorn and continue your journey.\n");
        printf("Suddenly you encounter a river. What do you do?\n");
        printf("1. Try to swim across.\n");
        printf("2. Look for a bridge.\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You swim across and find a treasure chest!\n");
        } else {
            printf("You find a bridge and safely cross.\n");
        }
    }
}

void darkForest() {
    printf("You venture deeper into the dark forest where shadows loom and eerie sounds echo.\n");
    printf("You see a fork in the path. Do you want to:\n");
    printf("1. Go left towards the howling sound.\n");
    printf("2. Go right towards the flickering light.\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You encounter a fierce wolf! What will you do?\n");
        printf("1. Fight the wolf.\n");
        printf("2. Try to befriend the wolf.\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You bravely fight the wolf and emerge victorious!\n");
        } else {
            printf("The wolf accepts you as a friend and guides you.\n");
        }
    } else {
        printf("You approach the flickering light and find a tiny fairy!\n");
        printf("She offers to grant you a special power. What do you choose?\n");
        printf("1. Flight\n");
        printf("2. Invisibility\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You can now fly! Soar through the forest!\n");
        } else {
            printf("You are now invisible! Sneak past any danger!\n");
        }
    }
}

void encounterDragon() {
    printf("You stumble upon a slumbering dragon!\n");
    printf("Do you want to:\n");
    printf("1. Steal the dragon's gold.\n");
    printf("2. Attempt to wake the dragon peacefully.\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("The dragon wakes up and you barely escape with your life!\n");
    } else {
        printf("The dragon wakes up peacefully and bestows you a portion of its gold!\n");
    }
}

int main() {
    introduction();
    while (1) {
        printf("Where do you want to go?\n");
        printf("1. Walk into the clearing.\n");
        printf("2. Venture into the dark forest.\n");
        printf("3. Encounter a dragon.\n");
        printf("4. Exit the adventure.\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                clearing();
                break;
            case 2:
                darkForest();
                break;
            case 3:
                encounterDragon();
                break;
            case 4:
                printf("Thank you for playing! Until next time, brave adventurer!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}