//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void introduction() {
    printf("=======================================\n");
    printf("          The Grateful Adventure       \n");
    printf("=======================================\n");
    printf("Welcome, brave traveler! Your journey begins here.\n");
    printf("Express gratitude for the wonders around you to unlock your path!\n");
}

void forestPath() {
    int choice;
    printf("\nYou find yourself in a mysterious forest. The trees seem to whisper softly.\n");
    printf("You can:\n");
    printf("1. Follow the sparkling river.\n");
    printf("2. Climb the ancient oak tree.\n");
    printf("3. Sit down and meditate.\n");
    printf("Choose an option (1-3): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("You have chosen to follow the sparkling river. As you walk, you express gratitude for its beauty.\n");
            printf("Suddenly, a water spirit appears and grants you a magical charm!\n");
            printf("APPROACHING: Magical Charm!\n");
            break;
        case 2:
            printf("You climb the ancient oak tree. From the top, you can see the whole forest! You thank the tree for its age and wisdom.\n");
            printf("It drops an acorn that glows with energy.\n");
            printf("It's a.... Enchanted Acorn!\n");
            break;
        case 3:
            printf("You sit down, close your eyes, and take a deep breath. You express your gratitude for this moment of peace.\n");
            printf("This attracts friendly forest animals that surround you, sharing their wisdom. Your heart feels lighter!\n");
            break;
        default:
            printf("That was not a valid choice. Please try again.\n");
            forestPath();
            break;
    }
}

void caveAdventure() {
    int choice;
    printf("\nYou enter a dark cave, the air filled with the scent of earth. Strange noises echo around you.\n");
    printf("You can:\n");
    printf("1. Venture deeper into the cave.\n");
    printf("2. Turn back and explore the forest further.\n");
    printf("Choose an option (1-2): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("You bravely venture into the cave, filled with awe. You thank the cave's spirit for its hidden secrets.\n");
            printf("You discover a hidden treasure chest filled with gold!\n");
            break;
        case 2:
            printf("You wisely choose to return to the forest. Sometimes, paths are best explored more carefully.\n");
            forestPath();
            break;
        default:
            printf("Invalid choice! Please enter 1 or 2.\n");
            caveAdventure();
            break;
    }
}

int main() {
    int startingChoice;
    
    introduction();
    printf("\nYour adventure awaits!\n");
    printf("Do you want to explore:\n");
    printf("1. The Enchanted Forest\n");
    printf("2. The Mysterious Cave\n");
    printf("Choose an option (1-2): ");
    scanf("%d", &startingChoice);
    
    if (startingChoice == 1) {
        forestPath();
    } else if (startingChoice == 2) {
        caveAdventure();
    } else {
        printf("That was not a valid selection. Please restart the game and choose a number between 1 and 2.\n");
    }
    
    printf("\nThank you for playing! May your heart always be filled with gratitude!\n");
    return 0;
}