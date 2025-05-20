//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if user input is valid
bool isValidInput(char input[]) {
    if (strlen(input) == 1 && (input[0] == '1' || input[0] == '2' || input[0] == '3')) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char input[100]; // User input buffer

    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You are stranded on an unknown island after a plane crash.\n");
    printf("You have three options:\n");
    printf("1 - Look for food\n");
    printf("2 - Build a shelter\n");
    printf("3 - Explore the island\n\n");

    while(true) { // Game loop
        printf("Enter your choice: ");
        scanf("%s", input);

        // Check if input is valid
        if (isValidInput(input)) {
            // Handle user input
            switch(input[0]) {
                case '1':
                    printf("\nYou search the island for food...\n");
                    printf("You find some berries and coconuts which provide enough sustenance for one day.\n");
                    break;
                case '2':
                    printf("\nYou collect some sticks and leaves and build a makeshift shelter...\n");
                    printf("You now have a place to sleep and protect yourself from the elements.\n");
                    break;
                case '3':
                    printf("\nYou embark on an journey to explore the island...\n");
                    printf("You come across a beautiful waterfall and a herd of wild boars.\n");
                    printf("You explore further and find a hidden cave where you discover a treasure chest full of gold.\n");
                    printf("Congratulations! You have won the game.\n");
                    return 0; // End game
                    break;
            }
        } else {
            printf("\nInvalid input. Please enter 1, 2 or 3.\n");
        }
    }

    return 0;
}