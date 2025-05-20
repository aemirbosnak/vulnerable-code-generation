//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showIntro();
int choosePath();
void encounterCreature();
void exploreCave();
void findTreasure();
void meetWiseOldMan();
void unknownPath();

int main() {
    int choice;

    showIntro();
    
    while(1) {
        choice = choosePath();
        
        switch(choice) {
            case 1:
                encounterCreature();
                break;
            case 2:
                exploreCave();
                break;
            case 3:
                findTreasure();
                break;
            case 4:
                meetWiseOldMan();
                break;
            case 5:
                unknownPath();
                break;
            case 6:
                printf("Thank you for playing! Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }
    }

    return 0;
}

void showIntro() {
    printf("=====================================\n");
    printf("     Welcome to the Mysterious     \n");
    printf("          Forest Adventure!         \n");
    printf("=====================================\n");
    printf("You find yourself at the edge of an ancient forest. \n");
    printf("A sense of adventure fills the air as you decide which path to take.\n");
    printf("What will you choose?\n");
}

int choosePath() {
    int choice;
    printf("\nChoose a path:\n");
    printf("1. Venture deeper into the forest.\n");
    printf("2. Explore the dark cave.\n");
    printf("3. Search for hidden treasures.\n");
    printf("4. Seek knowledge from the wise old man.\n");
    printf("5. Take an unknown path.\n");
    printf("6. Exit the game.\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    return choice;
}

void encounterCreature() {
    printf("\nAs you venture deeper into the forest, you encounter a strange creature!\n");
    printf("It looks friendly but seems lost. Do you:\n");
    printf("1. Help the creature find its way home.\n");
    printf("2. Run away in fear.\n");

    int choice;
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("You help the creature and it rewards you with a magical gem!\n");
    } else {
        printf("You ran away, but the creature was harmless.\n");
    }
}

void exploreCave() {
    printf("\nThe cave is dark and eerie. You hear strange noises echoing.\n");
    printf("Do you:\n");
    printf("1. Light a torch and enter.\n");
    printf("2. Leave immediately.\n");

    int choice;
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("Inside, you discover ancient carvings and treasure chests!\n");
    } else {
        printf("You decide it’s not worth the risk. Better to stay outside.\n");
    }
}

void findTreasure() {
    printf("\nYou carefully search the forest for hidden treasures.\n");
    printf("You stumble upon a chest buried under some leaves!\n");
    printf("Do you:\n");
    printf("1. Open the chest.\n");
    printf("2. Leave it closed, too risky.\n");

    int choice;
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("Inside the chest, you find gold coins and jewels!\n");
    } else {
        printf("You walk away, leaving the treasure undiscovered.\n");
    }
}

void meetWiseOldMan() {
    printf("\nYou find a wise old man sitting by a tree.\n");
    printf("He offers you wisdom. Do you:\n");
    printf("1. Ask him for advice.\n");
    printf("2. Ignore him and move on.\n");

    int choice;
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("He shares invaluable knowledge that will guide your future decisions.\n");
    } else {
        printf("You miss an opportunity to gain wisdom.\n");
    }
}

void unknownPath() {
    printf("\nYou take the unknown path, feeling a hint of danger.\n");
    printf("Suddenly, you find yourself face to face with a fierce wolf!\n");
    printf("Do you:\n");
    printf("1. Stand your ground.\n");
    printf("2. Try to escape.\n");

    int choice;
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("The wolf respects your bravery and decides to let you pass.\n");
    } else {
        printf("You flee, but the experience lingers in your mind.\n");
    }
}