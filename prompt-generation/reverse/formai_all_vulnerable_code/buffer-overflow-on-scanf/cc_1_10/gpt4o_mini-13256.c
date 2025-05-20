//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define ALIEN_CHAR_OFFSET 10

// Function to convert a character to an Alien language character
char toAlienChar(char inputChar) {
    if (inputChar >= 'a' && inputChar <= 'z') {
        return (inputChar - 'a' + ALIEN_CHAR_OFFSET) % 26 + 'a';
    } else if (inputChar >= 'A' && inputChar <= 'Z') {
        return (inputChar - 'A' + ALIEN_CHAR_OFFSET) % 26 + 'A';
    }
    return inputChar; // Return unchanged for non-alphabetic characters
}

// Function to translate a string to Alien language
void translateToAlien(char *inputString, char *outputString) {
    int i;
    for (i = 0; inputString[i] != '\0' && i < MAX_LENGTH; i++) {
        outputString[i] = toAlienChar(inputString[i]);
    }
    outputString[i] = '\0'; // Null terminate the string
}

// Function to display the menu and get the user's choice
int displayMenu() {
    int choice;
    printf("Alien Language Translator Menu:\n");
    printf("1. Translate String\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    return choice;
}

// Main function
int main() {
    char inputString[MAX_LENGTH];
    char outputString[MAX_LENGTH];
    int choice;

    do {
        choice = displayMenu();

        switch (choice) {
            case 1:
                printf("Enter a string to translate to Alien language: ");
                // Read user input, ensuring to ignore the newline
                getchar(); // Consume the newline character left by previous scanf
                fgets(inputString, MAX_LENGTH, stdin);

                // Remove newline character from inputString if present
                inputString[strcspn(inputString, "\n")] = 0; 

                // Translate inputString to Alien language
                translateToAlien(inputString, outputString);
                printf("Translated string: %s\n", outputString);
                break;

            case 2:
                printf("Exiting the translator. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 2);

    return 0;
}