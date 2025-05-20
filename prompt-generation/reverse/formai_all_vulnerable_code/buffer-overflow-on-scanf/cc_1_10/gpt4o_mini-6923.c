//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void intro();
void firstChoice();
void secondChoice();
void finalChoice();
void gameOver();
void victory();

int main() {
    intro();
    firstChoice();
    return 0;
}

void intro() {
    printf("Welcome to the Mysterious Cave Adventure!\n");
    printf("You find yourself at the entrance of a dark cave.\n");
    printf("Will you step inside? (yes/no): ");

    char response[4];
    scanf("%3s", response);
    
    if (strcmp(response, "yes") == 0) {
        printf("You bravely step into the cave...\n");
    } else {
        printf("You decide to turn back and go home. Game over.\n");
        exit(0);
    }
}

void firstChoice() {
    printf("Inside the cave, you see two paths:\n");
    printf("1. The left path, which is filled with strange sounds.\n");
    printf("2. The right path, which seems eerily silent.\n");
    printf("Which path do you take? (1/2): ");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You walk down the left path and suddenly encounter a ghost!\n");
        secondChoice();
    } else {
        printf("You walk down the right path and find a treasure chest!\n");
        finalChoice();
    }
}

void secondChoice() {
    printf("The ghost asks you a riddle:\n");
    printf("'I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?'\n");
    printf("1. An echo\n");
    printf("2. A cloud\n");
    printf("3. A tree\n");
    printf("Your answer (1/2/3): ");
    
    int answer;
    scanf("%d", &answer);

    if (answer == 1) {
        printf("Correct! The ghost thanks you and disappears.\n");
        finalChoice();
    } else {
        printf("Wrong answer! The ghost is angry and you are trapped in the cave forever. Game over.\n");
        exit(0);
    }
}

void finalChoice() {
    printf("You carefully open the treasure chest and find two items:\n");
    printf("1. A magical wand\n");
    printf("2. A chest full of gold coins\n");
    printf("What do you choose? (1/2): ");

    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("The wand grants you the power to teleport home!\n");
        victory();
    } else {
        printf("You take the gold, but as you leave, the cave collapses! You're trapped.\n");
        gameOver();
    }
}

void gameOver() {
    printf("Game Over! You have lost the adventure.\n");
    printf("Thank you for playing!\n");
    exit(0);
}

void victory() {
    printf("Congratulations! You have successfully escaped the cave with your treasure!\n");
    printf("Thank you for playing!\n");
    exit(0);
}