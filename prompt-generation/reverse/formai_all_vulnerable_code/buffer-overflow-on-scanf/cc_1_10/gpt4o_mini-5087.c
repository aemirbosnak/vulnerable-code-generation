//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayIntroduction() {
    printf("Welcome to the Whispering Forest.\n");
    printf("In this peaceful land, you will embark on a journey of exploration.\n");
    printf("The forest is filled with ancient trees, soft rustling leaves, and melodic birdsong.\n");
    printf("As you walk, you will encounter various paths and choices.\n");
    printf("Choose wisely, and enjoy your adventure!\n\n");
}

int choosePath() {
    int choice;
    printf("You stand at a crossroads. Do you choose the path to the left or to the right?\n");
    printf("1. Left\n");
    printf("2. Right\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    while (choice != 1 && choice != 2) {
        printf("Invalid choice, please enter 1 for left or 2 for right: ");
        scanf("%d", &choice);
    }
    
    return choice;
}

void exploreLeftPath() {
    printf("\nYou walk down the left path, surrounded by tall trees and soft moss underfoot.\n");
    printf("The air is fresh and filled with the scent of pine. You find a small stream.\n");
    printf("You can:\n");
    printf("1. Sit by the stream and meditate.\n");
    printf("2. Follow the stream further into the forest.\n");
    int choice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou sit by the stream, listening to the sound of water flowing.\n");
        printf("As you meditate, you feel a deep sense of peace and connection with nature.\n");
    } else {
        printf("\nYou decide to follow the stream.\n");
        printf("As you walk alongside it, you come across a beautiful waterfall.\n");
        printf("You take a moment to marvel at the beauty of the scene.\n");
    }
}

void exploreRightPath() {
    printf("\nYou venture down the right path, where sunlight filters through the leaves.\n");
    printf("The sound of chirping birds surrounds you, creating a calm atmosphere.\n");
    printf("After a while, you find an inviting clearing filled with colorful flowers.\n");
    printf("You can:\n");
    printf("1. Pick some flowers to create a bouquet.\n");
    printf("2. Lie on the grass and relax.\n");
    
    int choice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou pick a handful of flowers, their vibrant colors making you smile.\n");
        printf("You feel grateful for the beauty of nature and the moment.\n");
    } else {
        printf("\nYou lie on the soft grass, watching clouds drift by in the sky.\n");
        printf("You drift into a peaceful nap, recharging your spirit.\n");
    }
}

int main() {
    displayIntroduction();
    
    int pathChoice = choosePath();
    
    if (pathChoice == 1) {
        exploreLeftPath();
    } else {
        exploreRightPath();
    }
    
    printf("\nYour adventure in the Whispering Forest has come to an end.\n");
    printf("Remember, nature welcomes you back anytime you seek its tranquility.\n");
    return 0;
}