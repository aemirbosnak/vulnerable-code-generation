//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayWelcomeMessage() {
    printf("============================================\n");
    printf("     Welcome to the Medieval Dice Roller!   \n");
    printf("============================================\n");
    printf("Embark on a quest to test your luck and skill!\n");
    printf("May the dice roll in your favor, brave adventurer!\n");
    printf("============================================\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void adventureChoices() {
    printf("Choose your adventure:\n");
    printf("1. Enter the Dark Forest\n");
    printf("2. Climb the Mystic Mountain\n");
    printf("3. Duel with the Dragon\n");
    printf("4. Return to the Village\n");
}

void darkForestAdventure() {
    printf("You venture into the Dark Forest...\n");
    int roll = rollDice(6);
    printf("You rolled a %d...\n", roll);
    if (roll > 3) {
        printf("The forest spirits grant you a magical boon!\n");
    } else {
        printf("You trip over a root and lose your way!\n");
    }
}

void mysticMountainAdventure() {
    printf("You ascend the Mystic Mountain...\n");
    int roll = rollDice(10);
    printf("You rolled a %d...\n", roll);
    if (roll > 5) {
        printf("You find a hidden treasure chest!\n");
    } else {
        printf("An avalanche blocks your path, you must return!\n");
    }
}

void dragonDuelAdventure() {
    printf("You confront the fearsome Dragon...\n");
    int roll = rollDice(20);
    printf("You rolled a %d...\n", roll);
    if (roll >= 15) {
        printf("You strike a mighty blow, the dragon retreats!\n");
    } else {
        printf("The dragon roasts you with fiery breath!\n");
    }
}

int main() {
    srand(time(NULL));
    int choice;
    char continueAdventure;

    displayWelcomeMessage();
    
    do {
        adventureChoices();
        printf("Select an adventure (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                darkForestAdventure();
                break;
            case 2:
                mysticMountainAdventure();
                break;
            case 3:
                dragonDuelAdventure();
                break;
            case 4:
                printf("You return to the village, seeking rest and revelry.\n");
                break;
            default:
                printf("Alas! This adventure is not for thee!\n");
        }

        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &continueAdventure);
        
    } while (continueAdventure == 'y' || continueAdventure == 'Y');
    
    printf("Thank you for playing! May your future adventures be prosperous and thrilling!\n");
    return 0;
}