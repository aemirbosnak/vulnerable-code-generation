//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to validate user input for yes/no questions
bool validateInput(char *input) {
    if (strlen(input) != 1) {
        printf("Invalid input. Please try again.\n");
        return false;
    }
    char *validInputs = "yYnN";
    if (strchr(validInputs, input[0]) == NULL) {
        printf("Invalid input. Please try again.\n");
        return false;
    }
    return true;
}

int main() {
    char playerName[100];
    char input[10];
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name? ");
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strlen(playerName) - 1] = '\0';
    printf("Hello, %s! Are you ready to begin your adventure? (y/n) ", playerName);
    fgets(input, sizeof(input), stdin);
    while (!validateInput(input)) {
        fgets(input, sizeof(input), stdin);
    }
    if (input[0] == 'n' || input[0] == 'N') {
        printf("Okay, maybe next time then. Goodbye!\n");
        return 0;
    }
    printf("Great! You find yourself standing in front of a mysterious cave. ");
    printf("Do you want to go inside? (y/n) ");
    fgets(input, sizeof(input), stdin);
    while (!validateInput(input)) {
        fgets(input, sizeof(input), stdin);
    }
    if (input[0] == 'n' || input[0] == 'N') {
        printf("You turn around and leave without ever knowing what was inside. The end.\n");
        return 0;
    }
    printf("As you step inside, you hear the sound of rocks tumbling behind you. ");
    printf("You turn around and see that the entrance has been blocked by a cave-in! ");
    printf("You are trapped inside. What will you do?\n");

    // The game continues with various choices and consequences for the player
    // ...

    printf("Thanks for playing Text-Based Adventure Game!\n");
    return 0;
}