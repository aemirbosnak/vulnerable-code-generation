//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define game functions
void introduction();
void promptUser();
void startGame();
void adventureRoom();
void treasureRoom();
void endGame();

// Define global variables
char playerName[20];
char choice[20];

int main()
{
    // Start game
    introduction();
    promptUser();

    return 0;
}

// Function to introduce the game to the player
void introduction() {
    printf("Welcome to the Text-Based Adventure Game! \n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("Hello %s, let's begin the adventure! \n\n", playerName);
}

// Function to ask for the user's choice
void promptUser() {
    printf("What would you like to do? \n");
    printf("Enter '1' to start the game \n");
    printf("Enter '2' to quit the game \n");
    scanf("%s", choice);

    if(strcmp(choice, "1") == 0) {
        startGame();
    } else if(strcmp(choice, "2") == 0) {
        printf("Thank you for playing, %s! \n", playerName);
        exit(0);
    } else {
        printf("Invalid input! Please try again. \n\n");
        promptUser();
    }
}

// Function to start the game
void startGame() {
    printf("\nYou have entered a dark room. \n");
    printf("There are two doors in front of you, one on the left and one on the right. \n");
    printf("Which one would you like to choose? \n");
    printf("Enter '1' for the left door \n");
    printf("Enter '2' for the right door \n");
    scanf("%s", choice);

    if(strcmp(choice, "1") == 0) {
        adventureRoom();
    } else if(strcmp(choice, "2") == 0) {
        treasureRoom();
    } else {
        printf("Invalid input! Please try again. \n\n");
        startGame();
    }
}

// Function for the first room
void adventureRoom() {
    printf("\nYou have entered the adventure room. \n");
    printf("There are two chests in front of you, one on the left and one on the right. \n");
    printf("Which chest would you like to open? \n");
    printf("Enter '1' for the left chest \n");
    printf("Enter '2' for the right chest \n");
    scanf("%s", choice);

    if(strcmp(choice, "1") == 0) {
        printf("\nYou have found a sword! \n");
        printf("Would you like to:\n");
        printf("Enter '1' to attack the dragon in the next room\n");
        printf("Enter '2' to return to the previous room\n");
        scanf("%s", choice);

        if(strcmp(choice, "1") == 0) {
            printf("\nYou bravely attack the dragon with your sword. \n");
            printf("However, the dragon is too powerful for you alone. \n");
            printf("You have been defeated. \n\n");
            endGame();
        } else if(strcmp(choice, "2") == 0) {
            printf("\nYou return to the previous room. \n");
            startGame();
        } else {
            printf("\nInvalid input! Please try again. \n\n");
            adventureRoom();
        }
    } else if(strcmp(choice, "2") == 0) {
        printf("\nYou have found a shield! \n");
        printf("Would you like to:\n");
        printf("Enter '1' to attack the dragon in the next room\n");
        printf("Enter '2' to return to the previous room\n");
        scanf("%s", choice);

        if(strcmp(choice, "1") == 0) {
            printf("\nYou bravely attack the dragon with your shield. \n");
            printf("The shield protects you from the dragon's flames. \n");
            printf("You defeat the dragon and move on to the next room. \n\n");
            treasureRoom();
        } else if(strcmp(choice, "2") == 0) {
            printf("\nYou return to the previous room. \n");
            startGame();
        } else {
            printf("\nInvalid input! Please try again. \n\n");
            adventureRoom();
        }
    } else {
        printf("\nInvalid input! Please try again. \n\n");
        adventureRoom();
    }
}

// Function for the second room
void treasureRoom() {
    printf("\nYou have entered the treasure room. \n");
    printf("There is a treasure chest in front of you. \n");
    printf("Would you like to:\n");
    printf("Enter '1' to open the treasure chest\n");
    printf("Enter '2' to return to the previous room\n");
    scanf("%s", choice);

    if(strcmp(choice, "1") == 0) {
        printf("\nYou have found a valuable treasure and won the game! \n");
        endGame();
    } else if(strcmp(choice, "2") == 0) {
        printf("\nYou return to the previous room. \n");
        startGame();
    } else {
        printf("\nInvalid input! Please try again. \n\n");
        treasureRoom();
    }
}

// Function to end the game
void endGame() {
    printf("\nWould you like to play again?\n");
    printf("Enter '1' to play again\n");
    printf("Enter '2' to quit the game\n");
    scanf("%s", choice);

    if(strcmp(choice, "1") == 0) {
        startGame();
    } else if(strcmp(choice, "2") == 0) {
        printf("\nThank you for playing, %s! \n", playerName);
        exit(0);
    } else {
        printf("\nInvalid input! Please try again. \n\n");
        endGame();
    }
}