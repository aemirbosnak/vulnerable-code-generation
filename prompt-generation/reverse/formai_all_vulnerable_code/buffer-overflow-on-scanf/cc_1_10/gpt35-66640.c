//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define game states
enum GameState {
    START,
    ROOM1,
    ROOM2,
    ROOM3,
    END
};

// Define function to print introduction
void printIntroduction() {
    printf("Welcome to the Grateful Adventure Game!\n");
    printf("In this game, you will navigate through three rooms to reach the end and win.\n");
    printf("Let's get started!\n\n");
}

int main() {
    // Initialize game state and user input
    enum GameState currentState = START;
    char userInput[50];

    // Print introduction
    printIntroduction();

    // Game loop
    while (currentState != END) {
        switch (currentState) {
            case START:
                printf("You wake up in a dark room with no memory of how you got here.\n");
                printf("There are three doors in front of you. Which one do you choose? (1, 2 or 3)\n");
                scanf("%s", userInput);

                // Move to next room based on user input
                if (strcmp(userInput, "1") == 0) {
                    currentState = ROOM1;
                } else if (strcmp(userInput, "2") == 0) {
                    currentState = ROOM2;
                } else if (strcmp(userInput, "3") == 0) {
                    currentState = ROOM3;
                } else {
                    printf("Invalid input. Please select door 1, 2 or 3.\n");
                }
                break;

            case ROOM1:
                printf("You enter the first room and find a chest full of gold.\n");
                printf("Do you want to take the gold or keep moving? (take or move)\n");
                scanf("%s", userInput);

                // Move to next room based on user input
                if (strcmp(userInput, "take") == 0) {
                    currentState = END;
                    printf("You take the gold and exit the room. Congratulations, you win!\n");
                } else if (strcmp(userInput, "move") == 0) {
                    currentState = ROOM2;
                } else {
                    printf("Invalid input. Please enter take or move.\n");
                }
                break;

            case ROOM2:
                printf("You enter the second room and find a sleeping dragon.\n");
                printf("Do you want to sneak around the dragon or attack it? (sneak or attack)\n");
                scanf("%s", userInput);

                // Move to next room or end game based on user input
                if (strcmp(userInput, "sneak") == 0) {
                    currentState = ROOM3;
                } else if (strcmp(userInput, "attack") == 0) {
                    currentState = END;
                    printf("The dragon wakes up and eats you. Game over!\n");
                } else {
                    printf("Invalid input. Please enter sneak or attack.\n");
                }
                break;

            case ROOM3:
                printf("You enter the third room and find a group of friendly travelers.\n");
                printf("They offer to help you. Do you want to join them or keep going alone? (join or keep)\n");
                scanf("%s", userInput);

                // Move to next room based on user input
                if (strcmp(userInput, "join") == 0) {
                    currentState = END;
                    printf("You join the travelers and exit the room. Congratulations, you win!\n");
                } else if (strcmp(userInput, "keep") == 0) {
                    currentState = ROOM1;
                } else {
                    printf("Invalid input. Please enter join or keep.\n");
                }
                break;

            default:
                printf("Invalid state. Exiting game.\n");
                currentState = END;
                break;
        }
    }

    return 0;
}