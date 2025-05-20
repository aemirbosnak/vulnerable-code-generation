//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcome() {
    printf("Welcome to 'The Lost Treasure'!\n");
    printf("In this game, you will embark on an adventurous journey to find the lost treasure.\n");
    printf("Make wise decisions to succeed!\n");
    printf("Press enter to begin...\n");
    getchar();
}

void encounterCreature() {
    int choice;
    printf("You encounter a wild creature! What will you do?\n");
    printf("1. Fight the creature\n");
    printf("2. Run away\n");
    printf("Choose (1/2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You bravely fought the creature and emerged victorious!\n");
    } else {
        printf("You ran away safely, but lost some time.\n");
    }
}

void findTreasure() {
    srand(time(0));
    int treasure = rand() % 3; // Randomly choose treasure type
    
    printf("You found a treasure chest! What do you want to do?\n");
    printf("1. Open the chest\n");
    printf("2. Leave it\n");
    int choice;
    printf("Choose (1/2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        if (treasure == 0) {
            printf("Inside the chest, you found gold coins!\n");
        } else if (treasure == 1) {
            printf("Inside the chest, you found a magical artifact!\n");
        } else {
            printf("The chest was empty. Just your luck!\n");
        }
    } else {
        printf("You decided to leave the chest, who knows what could have been inside?\n");
    }
}

void questDecision() {
    int choice;
    printf("\nAs you progress, you arrive at a crossroad.\n");
    printf("1. Go left towards the mountains\n");
    printf("2. Go right towards the forest\n");
    printf("Which path will you take? (1/2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You walked up the mountains, and it was rocky but rewarding.\n");
        encounterCreature();
        findTreasure();
    } else {
        printf("The forest was lush and beautiful, but watch out for hazards!\n");
        encounterCreature();
        findTreasure();
    }
}

int main() {
    welcome();
    
    char playAgain;
    do {
        questDecision();
        printf("\nWould you like to play again? (y/n): ");
        getchar();  // Clear newline from buffer
        playAgain = getchar();
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing 'The Lost Treasure'! Goodbye!\n");
    return 0;
}