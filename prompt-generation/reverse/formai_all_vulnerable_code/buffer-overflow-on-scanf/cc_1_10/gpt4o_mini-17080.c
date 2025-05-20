//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void introduction();
void firstChoice();
void forestPath();
void mountainPath();
void treasureRoom();
void fightDragon();
void treasureFound();

int main() {
    srand(time(0));
    introduction();
    firstChoice();
    return 0;
}

void introduction() {
    printf("Welcome to the Fantastical Adventure Game!\n");
    printf("Your adventure awaits in a realm filled with magic, treasure, and peril.\n");
    printf("Can you navigate the challenges that lie ahead?\n\n");
}

void firstChoice() {
    int choice;

    printf("You find yourself at a crossroads. Do you want to:\n");
    printf("1. Enter the Dark Forest\n");
    printf("2. Climb the Misty Mountains\n");
    printf("Please enter 1 or 2: ");

    scanf("%d", &choice);
    switch (choice) {
        case 1:
            forestPath();
            break;
        case 2:
            mountainPath();
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            firstChoice();
    }
}

void forestPath() {
    printf("\nYou venture into the Dark Forest. The trees are tall, and the atmosphere is tense.\n");
    printf("Suddenly, you stumble upon a mystical creature!\n");
    printf("Do you want to:\n");
    printf("1. Talk to the creature\n");
    printf("2. Run away\n");

    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("The creature shares a secret: There is a hidden treasure room nearby!\n");
        treasureRoom();
    } else if (choice == 2) {
        printf("You run away and find yourself back at the crossroads, safe for now.\n");
        firstChoice();
    } else {
        printf("Invalid choice! Please try again.\n");
        forestPath();
    }
}

void mountainPath() {
    printf("\nYou bravely ascend the Misty Mountains. The air is thin, and the winds howling!\n");
    printf("As you climb higher, you encounter a fearsome dragon!\n");
    printf("Do you want to:\n");
    printf("1. Fight the dragon\n");
    printf("2. Try to sneak past it\n");

    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        fightDragon();
    } else if (choice == 2) {
        printf("You successfully sneak past the dragon and find a hidden cave filled with jewels!\n");
        treasureFound();
    } else {
        printf("Invalid choice! Please try again.\n");
        mountainPath();
    }
}

void treasureRoom() {
    printf("\nYou follow the creature to a hidden treasure room, filled with gold and magical artifacts!\n");
    printf("Do you wish to:\n");
    printf("1. Take some gold\n");
    printf("2. Leave the treasure room\n");

    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("As you take the gold, the room starts to glow brightly!\n");
        printf("You've found the legendary treasure and become rich beyond imagination!\n");
    } else if (choice == 2) {
        printf("You choose to leave, and as you do, the treasure magically disappears.\n");
        printf("You return to the forest, wiser and more cautious.\n");
    } else {
        printf("Invalid choice! Please try again.\n");
        treasureRoom();
    }
}

void fightDragon() {
    printf("\nYou decide to fight the dragon! You draw your sword and prepare for battle!\n");
    int outcome = rand() % 2; // Random outcome: 0 = win, 1 = lose
    if (outcome == 0) {
        printf("You valiantly fight the dragon and emerge victorious!\n");
        printf("You can now claim its treasure!\n");
        treasureFound();
    } else {
        printf("The dragon proves too strong, and you are defeated...\n");
        printf("Don't worry! Every adventurer learns from their mistakes.\n");
        printf("You return to the crossroads to try again.\n");
        firstChoice();
    }
}

void treasureFound() {
    printf("\nCongratulations! You've discovered the hidden treasure!\n");
    printf("The wealth and glory belong to you!\n");
    printf("Thank you for playing the Fantastical Adventure Game!\n");
    exit(0);
}