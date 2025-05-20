//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include <stdio.h>

// Function declarations
void startAdventure();
void forestPath(int choice);
void encounterBear();
void findTreasure();
void runFromBear();
void backToSafety();

int main() {
    printf("Welcome to the Mysterious Forest Adventure!\n");
    startAdventure();
    return 0;
}

// Function to start the adventure
void startAdventure() {
    int choice;
    printf("\nYou are standing at the edge of a dark forest.\n");
    printf("Do you wish to enter the forest? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You bravely enter the forest...\n");
        forestPath(0);
    } else {
        printf("You decide to stay safe at home. The adventure ends here.\n");
    }
}

// Recursive function to navigate through the forest
void forestPath(int choice) {
    printf("\nYou have reached a fork in the path.\n");
    printf("There are two paths:\n");
    printf("1. Take the left path.\n");
    printf("2. Take the right path.\n");
    printf("Choose a path (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        encounterBear();
    } else if (choice == 2) {
        findTreasure();
    } else {
        printf("Invalid choice. Try again.\n");
        forestPath(choice);
    }
}

// Function to encounter a bear
void encounterBear() {
    printf("\nYou've encountered a bear!\n");
    printf("What do you want to do?\n");
    printf("1. Try to scare the bear away.\n");
    printf("2. Run away.\n");
    
    int choice;
    printf("Choose an action (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("The bear is scared and flees into the forest. You are safe!\n");
        forestPath(0);
    } else if (choice == 2) {
        runFromBear();
    } else {
        printf("Invalid choice. Try again.\n");
        encounterBear();
    }
}

// Function to run away from the bear
void runFromBear() {
    printf("\nYou run deeper into the forest to escape the bear...\n");
    // Chance of escaping (could be more complex)
    if (rand() % 2 == 0) {
        printf("You managed to escape the bear!\n");
        forestPath(0);
    } else {
        printf("Oh no! The bear caught up with you. You have to start over...\n");
        startAdventure();
    }
}

// Function to find treasure
void findTreasure() {
    printf("\nCongratulations! You've stumbled upon a hidden treasure chest!\n");
    printf("What do you want to do?\n");
    printf("1. Open the chest.\n");
    printf("2. Leave it alone and continue the adventure.\n");

    int choice;
    printf("Choose an action (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You opened the chest and found gold coins! You're now rich!\n");
        backToSafety();
    } else if (choice == 2) {
        printf("You leave the treasure chest alone and continue exploring the forest.\n");
        forestPath(0);
    } else {
        printf("Invalid choice. Try again.\n");
        findTreasure();
    }
}

// Function to go back to safety
void backToSafety() {
    printf("\nYou've decided to go back home with your newfound treasure.\n");
    printf("The adventure ends here. Thank you for playing!\n");
}