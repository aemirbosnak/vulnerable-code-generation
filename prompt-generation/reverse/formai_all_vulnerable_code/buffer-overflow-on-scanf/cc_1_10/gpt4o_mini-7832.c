//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

void displayIntroduction();
void displayInstructions();
int getChoice();
void roomOne();
void roomTwo();
void roomThree();
void chooseAdventure(int);
void handleOutcome(int);

int main() {
    srand(time(0)); // Seed the random number generator
    displayIntroduction();
    displayInstructions();
    
    int choice = getChoice();
    chooseAdventure(choice);
    
    return 0;
}

void displayIntroduction() {
    printf("**************************************************\n");
    printf("*                Welcome to the Cave of         *\n");
    printf("*                   SHOCKING SECRETS!            *\n");
    printf("**************************************************\n");
    printf("You find yourself in a dark cave. The air is thick and misty, \n");
    printf("and you can hear the distant sound of water dripping.\n");
    printf("Rumors say that these caves hold secrets beyond imagination...\n");
    printf("\n");
}

void displayInstructions() {
    printf("Instructions:\n");
    printf("1. You can choose a direction to explore the cave.\n");
    printf("2. Each choice may lead you to unexpected outcomes...\n");
    printf("3. Make your choices wisely! Good luck!\n");
    printf("\n");
}

int getChoice() {
    int choice;
    printf("Where would you like to go?\n");
    printf("1. Enter Room One\n");
    printf("2. Enter Room Two\n");
    printf("3. Enter Room Three\n");
    printf("Choose your adventure (1-3): ");
    scanf("%d", &choice);
    
    while (choice < 1 || choice > 3) {
        printf("Invalid choice! Please choose 1, 2, or 3: ");
        scanf("%d", &choice);
    }
    
    return choice;
}

void chooseAdventure(int choice) {
    switch (choice) {
        case 1:
            roomOne();
            break;
        case 2:
            roomTwo();
            break;
        case 3:
            roomThree();
            break;
        default:
            printf("This shouldn't happen...\n");
    }
}

void roomOne() {
    printf("You enter Room One. The damp walls are covered in strange symbols.\n");
    printf("A chilling whisper fills the air, 'Find the truth...'\n");
    handleOutcome(rand() % 3);
}

void roomTwo() {
    printf("You step into Room Two. You see a treasure chest in the corner.\n");
    printf("But as you approach, it suddenly snaps shut!\n");
    handleOutcome(rand() % 3);
}

void roomThree() {
    printf("Entering Room Three, you feel an eerie presence.\n");
    printf("A ghostly figure appears before you, asking a riddle...\n");
    handleOutcome(rand() % 3);
}

void handleOutcome(int outcome) {
    switch (outcome) {
        case 0:
            printf("The air grows colder, and you feel time slowing...\n");
            printf("A braver adventurer emerges from the shadows!\n");
            printf("You've unleashed a powerful spirit. Game Over!\n");
            break;
        case 1:
            printf("You discover a hidden passage behind the symbols!\n");
            printf("You follow the path and find a magical artifact!\n");
            printf("Victory is yours! You are the Keeper of Secrets!\n");
            break;
        case 2:
            printf("You solve the riddle, and the ghost smiles.\n");
            printf("It grants you the ability to see the unseen for one hour!\n");
            printf("Success! You feel enlightened and empowered.\n");
            break;
    }
    printf("Would you like to play again? (1 for Yes, 0 for No): ");
    int playAgain;
    scanf("%d", &playAgain);
    
    if (playAgain) {
        printf("\nStarting a new adventure...\n");
        main();
    } else {
        printf("Thank you for playing!\n");
    }
}