//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function declarations
void startGame();
void firstRoom();
void secondRoom();
void treasureRoom();
void displayIntro();

int main() {
    startGame();
    return 0;
}

void startGame() {
    displayIntro();
    firstRoom();
}

void displayIntro() {
    printf("=======================================\n");
    printf("     Welcome to the Adventure Game!   \n");
    printf("=======================================\n");
    printf("You're an adventurer on a quest to find the hidden treasure.\n");
    printf("Explore rooms, solve puzzles, and find the treasure!\n");
    printf("=======================================\n");
}

void firstRoom() {
    int choice;
    printf("\nYou are in a dimly lit room. There are two doors:\n");
    printf("1. Enter the left door\n");
    printf("2. Enter the right door\n");
    printf("What do you choose? (1 or 2): ");
    
    scanf("%d", &choice);
    
    if (choice == 1) {
        secondRoom();
    } else if (choice == 2) {
        printf("You have been transported to a dark void. Game Over!\n");
    } else {
        printf("Invalid choice! Please try again.\n");
        firstRoom();
    }
}

void secondRoom() {
    int choice;
    printf("\nYou have entered a room filled with ancient artifacts.\n");
    printf("In the center of the room, there is a pedestal with a mysterious book.\n");
    printf("On the wall, there are inscriptions.\n");
    printf("What will you do?\n");
    printf("1. Read the book\n");
    printf("2. Inspect the wall inscriptions\n");
    
    printf("What do you choose? (1 or 2): ");
    
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("The book contains a riddle: 'I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?'\n");
        printf("Solve the riddle (type your answer): ");
        char answer[50];
        scanf("%s", answer);
        
        if (strcmp(answer, "echo") == 0) {
            printf("Correct! A secret passage is revealed.\n");
            treasureRoom();
        } else {
            printf("Incorrect! The floor opens beneath you. Game Over!\n");
        }
    } else if (choice == 2) {
        printf("The inscriptions warn you of a curse. You decide to leave the room, but you are lost forever. Game Over!\n");
    } else {
        printf("Invalid choice! Please try again.\n");
        secondRoom();
    }
}

void treasureRoom() {
    int choice;
    printf("\nCongratulations! You've entered the treasure room.\n");
    printf("You see a large chest filled with gold.\n");
    printf("However, there is a guardian monster! You can:\n");
    printf("1. Fight the monster\n");
    printf("2. Try to sneak past the monster to grab the treasure\n");
    
    printf("What will you do? (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You bravely fight the monster and emerge victorious! You claim the treasure.\n");
        printf("You win! The treasure is yours!\n");
    } else if (choice == 2) {
        printf("You attempt to sneak past the monster, but it spots you and attacks! Game Over!\n");
    } else {
        printf("Invalid choice! Please try again.\n");
        treasureRoom();
    }
}