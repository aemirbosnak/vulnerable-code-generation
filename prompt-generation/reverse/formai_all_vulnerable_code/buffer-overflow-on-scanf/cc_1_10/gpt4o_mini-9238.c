//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function declarations
void displayWelcomeMessage();
void displayMenu();
void startAdventure();
void encounterGhost();
void encounterZombie();
void encounterVampire();
void ending();

int main() {
    displayWelcomeMessage();
    displayMenu();
    return 0;
}

void displayWelcomeMessage() {
    printf("===================================\n");
    printf("  WELCOME TO THE HAUNTED HOUSE!   \n");
    printf("===================================\n");
    printf("Brace yourself for a spine-chilling adventure!\n\n");
}

void displayMenu() {
    int choice;

    printf("Choose your destiny:\n");
    printf("1. Start Adventure\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            startAdventure();
            break;
        case 2:
            printf("Goodbye! We hope to see you again... if you dare!\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            displayMenu();
    }
}

void startAdventure() {
    printf("\nYou step into the dark hallway of the haunted house...\n");
    
    srand(time(NULL)); // Seed for random encounters
    int encounter = rand() % 3; // Random number between 0 and 2 for encounters
    
    switch(encounter) {
        case 0:
            encounterGhost();
            break;
        case 1:
            encounterZombie();
            break;
        case 2:
            encounterVampire();
            break;
    }
}

void encounterGhost() {
    printf("\nA ghostly figure appears before you!\n");
    printf("It moans and asks for your name...\n");
    
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("The ghost whispers, 'Hello %s, will you help me find my lost treasure?'\n", name);
    printf("You have two choices:\n");
    printf("1. Yes\n");
    printf("2. No\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("You helped the ghost and found the treasure! You win!\n");
    } else {
        printf("The ghost vanishes in disappointment...\n");
    }
    ending();
}

void encounterZombie() {
    printf("\nA zombie lurches toward you, groaning!\n");
    printf("It seems hungry...\n");
    
    printf("You have two options:\n");
    printf("1. Feed it a sandwich\n");
    printf("2. Run away\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("The zombie happily devours the sandwich and becomes your friend! You win!\n");
    } else {
        printf("You run away like a scaredy-cat, but the zombie follows you!\n");
        printf("You barely escape, but he's still hungry...\n");
    }
    ending();
}

void encounterVampire() {
    printf("\nA dark vampire appears, with piercing eyes!\n");
    printf("He greets you and offers a deal...\n");
    
    printf("You have two choices:\n");
    printf("1. Accept the deal for eternal life\n");
    printf("2. Fight the vampire\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("Welcome to the undead! You have chosen eternal life!\n");
    } else {
        printf("The vampire laughs as you try to fight him...\n");
        printf("You soon realize that escaping is your only option!\n");
    }
    ending();
}

void ending() {
    printf("\nThank you for playing the Haunted House Simulator!\n");
    printf("Will you dare to enter again? (Y/N): ");
    
    char choice;
    scanf(" %c", &choice);
    
    if(choice == 'Y' || choice == 'y') {
        startAdventure();
    } else {
        printf("Goodbye! Until next time...\n");
        exit(0);
    }
}