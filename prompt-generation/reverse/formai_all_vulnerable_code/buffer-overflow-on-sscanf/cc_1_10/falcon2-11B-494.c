//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define variables
    char playerName[50];
    char input[100];
    char* currentLocation;
    char* nextLocation;
    char* verb;
    char* noun;

    // Prompt player for name
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name:\n");
    scanf("%s", playerName);

    // Initialize player's location
    currentLocation = "You are in a dark forest";

    // Loop until the player wins or loses
    while (1) {
        // Print the current location
        printf("%s\n", currentLocation);

        // Prompt player for input
        printf("What do you want to do?\n");
        scanf("%s", input);

        // Parse the input into verb and noun
        sscanf(input, "%s %s", verb, noun);

        // Check if the verb and noun are valid
        if (strcmp(verb, "look") == 0 && strcmp(noun, "around") == 0) {
            currentLocation = "You look around and see a path leading to the north.";
        } else if (strcmp(verb, "go") == 0 && strcmp(noun, "north") == 0) {
            currentLocation = "You walk north and enter a dark cave.";
        } else {
            printf("Invalid input.\n");
        }

        // Check if the player has won
        if (strcmp(currentLocation, "You have won the game!") == 0) {
            printf("Congratulations! You have won the game!\n");
            break;
        }

        // Check if the player has lost
        if (strcmp(currentLocation, "You have lost the game!") == 0) {
            printf("Sorry, you have lost the game.\n");
            break;
        }
    }

    return 0;
}