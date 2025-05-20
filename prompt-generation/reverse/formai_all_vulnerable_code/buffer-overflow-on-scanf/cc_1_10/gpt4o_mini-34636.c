//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcome() {
    printf("==================================\n");
    printf("       Welcome to the Quest!     \n");
    printf("==================================\n");
    printf("In this game, you will explore a magical forest.\n");
    printf("Your goal is to find the lost artifact.\n");
    printf("Choose wisely, as your decisions will affect your fate!\n");
}

// Function to execute choice and encounter monster
int encounterMonster() {
    int outcome;
    printf("You encounter a wild monster!\n");
    printf("Do you want to (1) fight or (2) flee? ");
    scanf("%d", &outcome);
    return outcome;
}

void fight() {
    int result = rand() % 2; // Randomly determine fight outcome
    if (result == 0) {
        printf("You defeated the monster!\n");
    } else {
        printf("The monster defeated you. Game Over!\n");
        exit(0);
    }
}

void flee() {
    printf("You fled successfully!\n");
}

void exploreDarkCave() {
    printf("You enter a dark cave...\n");
    int choice;
    printf("Do you want to (1) light a torch or (2) leave the cave? ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You lit a torch and discovered a hidden treasure!\n");
        printf("You feel more confident now.\n");
    } else {
        printf("You left the cave safely.\n");
    }
}

void forestPath() {
    printf("You are on a forest path.\n");
    int choice;
    printf("Do you want to (1) go left into the forest or (2) go right to the river? ");
    scanf("%d", &choice);
    if (choice == 1) {
        int encounter = encounterMonster();
        if (encounter == 1) {
            fight();
        } else {
            flee();
        }
    } else {
        printf("You arrive at a beautiful river. You can rest here.\n");
    }
}

void findArtifact() {
    printf("You found the hidden cave of the artifact!\n");
    int choice;
    printf("Do you want to (1) take the artifact or (2) leave it? ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You claim the artifact. Congratulations, you completed the quest!\n");
    } else {
        printf("You decided to leave the artifact. Let's see what else you can find!\n");
        forestPath();
    }
}

int main() {
    srand(time(NULL)); // Seed for randomness
    welcome();

    int choice;
    while (1) {
        printf("You have two options: (1) Enter the forest or (2) Take the hidden path\n");
        printf("Which path will you take? ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            forestPath();
            break; // Break after exploring forest path
        } else if (choice == 2) {
            exploreDarkCave();
            findArtifact();
            break; // Break after exploring hidden path
        } else {
            printf("Invalid choice! Please choose (1) or (2).\n");
        }
    }

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}