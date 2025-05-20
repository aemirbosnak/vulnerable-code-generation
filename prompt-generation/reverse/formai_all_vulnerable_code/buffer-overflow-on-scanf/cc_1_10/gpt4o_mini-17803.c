//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void choosePath();
void darkForest();
void brightForest();
void encounterMonster();
void findTreasure();
void endGame(const char* story);

int main() {
    srand(time(NULL)); // Seed the random number generator
    intro();
    choosePath();
    return 0;
}

void intro() {
    printf("Welcome to the 'Mysterious Forest' Adventure Game!\n");
    printf("You find yourself at the edge of a dark, dense forest.\n");
    printf("Legends say that many have entered but few have returned.\n");
    printf("What will you choose to do?\n");
}

void choosePath() {
    int choice;
    printf("1. Enter the Dark Forest.\n");
    printf("2. Take the Bright Path.\n");
    printf("Choose your path (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            darkForest();
            break;
        case 2:
            brightForest();
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            choosePath();
            break;
    }
}

void darkForest() {
    printf("\nYou venture into the Dark Forest.\n");
    printf("It's eerily quiet and the trees block out most of the sunlight.\n");
    printf("Suddenly, you hear growling nearby...\n");
    encounterMonster();
}

void brightForest() {
    printf("\nYou take the Bright Path.\n");
    printf("Here, the sun shines brightly, and colorful flowers bloom all around.\n");
    printf("After walking some distance, you stumble upon a hidden treasure!\n");
    findTreasure();
}

void encounterMonster() {
    int choice;
    printf("You see a fierce wolf in front of you!\n");
    printf("What will you do?\n");
    printf("1. Try to fight the wolf.\n");
    printf("2. Climb the nearest tree to escape.\n");
    printf("Choose your action (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou bravely confront the wolf but it attacks you!\n");
        endGame("You have fallen prey to the wild beast.");
    } else {
        printf("\nYou quickly climb the tree and the wolf can't reach you.\n");
        printf("After a while, you manage to escape the forest safely.\n");
        endGame("You survived, but the forest's secrets remain unsolved.");
    }
}

void findTreasure() {
    printf("\nYou carefully approach the treasure chest.\n");
    printf("It's locked but looks old and worn out. You have two options:\n");
    printf("1. Try to open it.\n");
    printf("2. Leave it and continue exploring.\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou try to open the chest...\n");
        if (rand() % 2) {
            printf("Success! It opens to reveal gold coins and jewels!\n");
            endGame("Congratulations, you're now rich!");
        } else {
            printf("It was trapped! You triggered a mechanism and got injured!\n");
            endGame("You lost, but at least you found some treasure.");
        }
    } else {
        printf("\nYou decide to leave the chest untouched and move on.\n");
        endGame("While you didn't become rich, you lived to tell the tale.");
    }
}

void endGame(const char* story) {
    printf("\nGame Over: %s\n", story);
    printf("Thank you for playing!\n");
    exit(0);
}