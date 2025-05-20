//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_NAME 50

void displayIntro();
void enterCastle(char name[MAX_NAME]);
void exploreForest(char name[MAX_NAME]);
void encounterDragon(char name[MAX_NAME]);
void findTreasure(char name[MAX_NAME]);
void showExit();

int main() {
    char name[MAX_NAME];

    displayIntro();
    
    printf("What is your name, brave adventurer? ");
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    printf("Welcome, %s! Your adventure begins now...\n\n", name);

    while (1) {
        int choice;
        printf("1. Enter the Castle\n");
        printf("2. Explore the Enchanted Forest\n");
        printf("3. Exit Game\n");
        printf("Choose your fate (1-3): ");
        scanf("%d", &choice);
        getchar(); // To consume newline left by scanf

        switch (choice) {
            case 1:
                enterCastle(name);
                break;
            case 2:
                exploreForest(name);
                break;
            case 3:
                showExit();
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayIntro() {
    printf("**************************************************\n");
    printf("*               WELCOME TO THE                   *\n");
    printf("*             TEXT BASED ADVENTURE GAME         *\n");
    printf("**************************************************\n\n");
}

void enterCastle(char name[MAX_NAME]) {
    printf("%s steps into the dimly lit castle.\n", name);
    printf("You hear a whisper: 'Find the hidden treasure!'\n");
    printf("Do you want to:\n");
    printf("1. Search the Throne Room\n");
    printf("2. Investigate the Dungeon\n");
    printf("3. Leave the Castle\n");

    int choice;
    scanf("%d", &choice);
    getchar(); // Consume newline

    if (choice == 1) {
        printf("You entered the Throne Room.\n");
        findTreasure(name);
    } else if (choice == 2) {
        printf("You wandered into the Dungeon.\n");
        encounterDragon(name);
    } else {
        printf("%s leaves the castle in search of new adventures.\n", name);
    }
}

void exploreForest(char name[MAX_NAME]) {
    printf("%s is walking through the Enchanted Forest.\n", name);
    printf("You see glowing plants and hear mystical sounds.\n");
    printf("Do you want to:\n");
    printf("1. Follow the sound of a stream\n");
    printf("2. Climb a tall tree\n");
    printf("3. Return to the main path\n");

    int choice;
    scanf("%d", &choice);
    getchar(); // Consume newline

    if (choice == 1) {
        printf("You found a crystal-clear stream and drink some water.\n");
        printf("%s feels rejuvenated!\n", name);
    } else if (choice == 2) {
        printf("You climbed a tree and got a better view of the forest.\n");
        printf("You notice a secret glade nearby.\n");
    } else {
        printf("%s returns safely to the main path.\n", name);
    }
}

void encounterDragon(char name[MAX_NAME]) {
    printf("Suddenly, a fierce dragon appears!\n");
    printf("Will you:\n");
    printf("1. Fight the Dragon\n");
    printf("2. Run away from the Dragon\n");

    int choice;
    scanf("%d", &choice);
    getchar(); // Consume newline

    if (choice == 1) {
        printf("You draw your sword courageously and face the dragon.\n");
        int outcome = rand() % 2; // Random outcome
        
        if (outcome) {
            printf("Victorious, you slay the dragon!\n");
            printf("You find treasures in its lair.\n");
        } else {
            printf("Oh no! The dragon proved too powerful...\n");
            printf("%s barely escapes with your life!\n", name);
        }
    } else {
        printf("%s makes a hasty escape.\n", name);
        printf("You narrowly avoid becoming dragon dinner!\n");
    }
}

void findTreasure(char name[MAX_NAME]) {
    printf("You search carefully and find a golden chest!\n");
    printf("Inside are jewels, gold coins, and an ancient map.\n");
    printf("Congratulations, %s! You are now wealthy!\n", name);
}

void showExit() {
    printf("Thank you for playing! Farewell, brave adventurer!\n");
}