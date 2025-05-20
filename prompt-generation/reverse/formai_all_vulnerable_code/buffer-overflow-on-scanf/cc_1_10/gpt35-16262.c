//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function for getting user input
void getUserInput(int *input) {
    scanf("%d", input);
}

// Function for displaying game over message
void gameOver() {
    printf("Game Over. You have been trapped in the haunted house forever.\n");
}

// Function for displaying win message
void win() {
    printf("Congratulations! You found your way out of the haunted house.\n");
}

// Main function
int main() {
    int currentRoom = 1; // Starting room is room 1
    int userInput; // User input variable
    srand(time(NULL)); // Seed random number generator

    while (1) { // Infinite loop until game is over
        printf("You are in room %d of the haunted house.\n", currentRoom);

        // Randomly select the next room and prompt user for input
        switch (currentRoom) {
            case 1:
                printf("You see a dark hallway.\n");
                printf("1. Walk down the hallway.\n2. Turn back.\n");
                getUserInput(&userInput);
                if (userInput == 1) {
                    currentRoom = (rand() % 2) + 2; // Room 2 or 3
                } else {
                    gameOver();
                    return 0;
                }
                break;
            case 2:
                printf("You stumble upon an old library.\n");
                printf("1. Search for a secret passage.\n2. Leave the library.\n");
                getUserInput(&userInput);
                if (userInput == 1) {
                    currentRoom = (rand() % 3) + 4; // Room 4, 5, or 6
                } else {
                    currentRoom = 1;
                }
                break;
            case 3:
                printf("You find yourself in a creepy bedroom.\n");
                printf("1. Search for a window.\n2. Lie down on the bed.\n");
                getUserInput(&userInput);
                if (userInput == 1) {
                    win();
                    return 0;
                } else {
                    currentRoom = 1;
                }
                break;
            case 4:
                printf("You come across a dark and eerie laboratory.\n");
                printf("1. Examine the strange potions.\n2. Leave the lab.\n");
                getUserInput(&userInput);
                if (userInput == 1) {
                    currentRoom = 7;
                } else {
                    currentRoom = 6;
                }
                break;
            case 5:
                printf("You enter a dusty storage room.\n");
                printf("1. Search for a flashlight.\n2. Leave the room.\n");
                getUserInput(&userInput);
                if (userInput == 1) {
                    currentRoom = 8;
                } else {
                    currentRoom = 4;
                }
                break;
            case 6:
                printf("You accidentally enter a hidden room.\n");
                printf("1. Investigate the strange markings on the wall.\n2. Leave the hidden room.\n");
                getUserInput(&userInput);
                if (userInput == 1) {
                    currentRoom = 9;
                } else {
                    currentRoom = 5;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}