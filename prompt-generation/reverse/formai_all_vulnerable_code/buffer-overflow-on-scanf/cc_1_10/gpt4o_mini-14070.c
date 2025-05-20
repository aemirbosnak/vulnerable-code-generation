//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showInstructions() {
    printf("\nWelcome to the Enchanted Forest Adventure!\n");
    printf("You find yourself at the entrance of a mystical forest.\n");
    printf("Your goal is to find the hidden treasure while avoiding dangers.\n");
    printf("You can move by typing 'north', 'south', 'east', or 'west'.\n");
    printf("Type 'quit' to exit the game at any time.\n\n");
}

void forestEntry() {
    printf("You are at the forest entrance. The trees loom high above.\n");
    printf("Paths lead deeper into the forest to the north and south.\n");
}

void northPath() {
    printf("You head north and enter a clearing filled with shimmering flowers.\n");
    printf("A gentle breeze carries a sweet scent.\n");
    printf("You can go back south or explore further to the east.\n");
}

void southPath() {
    printf("You venture south and encounter a dark cave.\n");
    printf("You can hear ominous sounds coming from inside.\n");
    printf("You can return north or risk entering the cave.\n");
}

void eastPath() {
    printf("You walk east and find a wise old man sitting by a tree.\n");
    printf("He offers you a riddle to solve in exchange for a clue about the treasure.\n");
}

void cave() {
    printf("You enter the cave and find glowing crystals lining the walls.\n");
    printf("Suddenly, a giant bat swoops down! What will you do?\n");
}

void riddle() {
    char answer[30];
    printf("The old man asks: 'I speak without a mouth and hear without ears. What am I?'\n");
    printf("Type your answer: ");
    scanf("%s", answer);
    
    if (strcmp(answer, "echo") == 0) {
        printf("Correct! The old man gives you a magical map.\n");
    } else {
        printf("Incorrect! The old man fades away with a disappointed look.\n");
    }
}

void playGame() {
    char choice[20];
    int gameOver = 0;

    while (!gameOver) {
        forestEntry();
        printf("What would you like to do? ");
        scanf("%s", choice);

        if (strcmp(choice, "north") == 0) {
            northPath();
        } else if (strcmp(choice, "south") == 0) {
            southPath();
        } else if (strcmp(choice, "east") == 0) {
            eastPath();
            riddle();
        } else if (strcmp(choice, "west") == 0) {
            printf("You wander off into the unknown and get lost. Game Over!\n");
            gameOver = 1;
        } else if (strcmp(choice, "quit") == 0) {
            gameOver = 1;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    printf("Thank you for playing! Goodbye!\n");
}

int main() {
    showInstructions();
    playGame();
    return 0;
}