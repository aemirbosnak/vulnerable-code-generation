//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
void printIntro();
int choosePath();
void frontGate();
void secretDoor();
void leftPath();
void rightPath();
void endGame();

/* Global variables */
int hasKey = 0;
char playerName[20];

int main() {
    printIntro();
    choosePath();
    return 0;
}

/* Print the game introduction */
void printIntro() {
    printf("Welcome to the Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("\nHello, %s! You find yourself standing at the entrance of a mysterious castle. ", playerName);
    printf("You have heard rumors of great treasures hidden within its walls. ");
    printf("Do you dare to enter the castle and search for the treasure? Let's see if you can make it out alive!\n\n");
}

/* Prompt the player to choose a path */
int choosePath() {
    int pathChoice;
    printf("Which path will you take?\n");
    printf("1. Front gate\n");
    printf("2. Secret door\n");
    printf("Enter 1 or 2: ");
    scanf("%d", &pathChoice);
    printf("\n");

    switch (pathChoice) {
        case 1:
            frontGate();
            break;
        case 2:
            secretDoor();
            break;
        default:
            printf("Invalid choice! Please enter 1 or 2.\n\n");
            choosePath();
            break;
    }
    return 0;
}

/* Handle the front gate path */
void frontGate() {
    char gateChoice[10];
    printf("You approach the front gate of the castle. The gate is guarded by a fierce-looking dragon.\n");
    printf("Do you \"fight\" or \"flee\"? ");
    scanf("%s", gateChoice);
    printf("\n");

    if (strcmp(gateChoice, "fight") == 0) {
        printf("You draw your sword and prepare to battle the dragon...\n");
        if (hasKey) {
            printf("But wait! You have the key to the castle's treasure room.");
            printf("The dragon can sense your bravery, and steps aside to let you pass.\n\n");
            rightPath();
        } else {
            printf("You fought valiantly, but the dragon was too strong for you.\n");
            endGame();
        }
    } else if (strcmp(gateChoice, "flee") == 0) {
        printf("You turn and run as fast as you can, but the dragon catches up to you and breathes fire.\n");
        endGame();
    } else {
        printf("Invalid choice! Please enter \"fight\" or \"flee\".\n\n");
        frontGate();
    }
}

/* Handle the secret door path */
void secretDoor() {
    char doorChoice[10];
    printf("You search around the castle until you find a secret door hidden in the wall.\n");
    printf("Do you try to \"open\" it or \"leave\" it alone? ");
    scanf("%s", doorChoice);
    printf("\n");

    if (strcmp(doorChoice, "open") == 0) {
        printf("You discover a hidden passage inside the castle walls.\n");
        leftPath();
    } else if (strcmp(doorChoice, "leave") == 0) {
        printf("You decide to leave the secret door alone and search for another way in.\n");
        choosePath();
    } else {
        printf("Invalid choice! Please enter \"open\" or \"leave\".\n\n");
        secretDoor();
    }
}

/* Handle the left path */
void leftPath() {
    char leftChoice[10];
    printf("You follow the hidden passage as it winds its way through the castle walls.\n");
    printf("Eventually, you come across a room with a large chest in the corner.\n");
    printf("Do you \"open\" the chest or \"leave\" it alone? ");
    scanf("%s", leftChoice);
    printf("\n");

    if (strcmp(leftChoice, "open") == 0) {
        printf("You open the chest and find a map that leads to the treasure room!\n");
        hasKey = 1;
        rightPath();
    } else if (strcmp(leftChoice, "leave") == 0) {
        printf("You decide to leave the chest alone and continue on your search for the treasure.\n");
        rightPath();
    } else {
        printf("Invalid choice! Please enter \"open\" or \"leave\".\n\n");
        leftPath();
    }
}

/* Handle the right path */
void rightPath() {
    printf("You continue your search for the treasure room...\n");
    printf("As you round a corner, you see a door with a lock on it.\n");
    if (hasKey) {
        printf("You use the key you found to unlock the door and enter the treasure room!\n");
        printf("Congratulations, %s, you have found the treasure and won the game!\n", playerName);
        endGame();
    } else {
        printf("Unfortunately, you do not have the key to the treasure room.\n");
        printf("You will need to explore further in order to find it.\n\n");
        choosePath();
    }
}

/* Handle the end of the game */
void endGame() {
    char playAgain[10];
    printf("\nDo you want to play again? (yes or no) ");
    scanf("%s", playAgain);

    if (strcmp(playAgain, "yes") == 0) {
        printf("\n\n\n");
        main();
    } else if (strcmp(playAgain, "no") == 0) {
        printf("\nThank you for playing the Adventure Game, %s!\n", playerName);
        exit(0);
    } else {
        printf("Invalid choice! Please enter \"yes\" or \"no\".\n\n");
        endGame();
    }
}