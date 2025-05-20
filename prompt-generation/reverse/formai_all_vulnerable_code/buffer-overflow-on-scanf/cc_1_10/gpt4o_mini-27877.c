//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Morse Code Definitions
const char *morseCode[] = {
    ".-",   "-...", "-.-.", "-..",   ".",    "..-.", "--.",   "....",
    "..",   ".---", "-.-",  ".-..",  "--",   "-.",   "---",   ".--.",
    "--.-", ".-.",  "...",  "-",     "..-",  "...-",  ".--",   "-..-",
    "-.--", "--..", " "
};

const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

// Function to convert a character to Morse code
const char* charToMorse(char c) {
    c = toupper(c);
    char *ptr = strchr(alphabet, c);
    if (ptr) {
        return morseCode[ptr - alphabet];
    }
    return "";
}

// Function to convert a string of text to Morse code
void textToMorse(const char *text) {
    printf("Morse Code: ");
    for (size_t i = 0; i < strlen(text); i++) {
        printf("%s ", charToMorse(text[i]));
    }
    printf("\n");
}

// Function to display the menu
void displayMenu() {
    printf("\n================================\n");
    printf("   Morse Code Converter         \n");
    printf("================================\n");
    printf("1. Convert Text to Morse Code \n");
    printf("2. Exit                       \n");
    printf("Select an option: ");
}

// Function to get user input
void getUserInput(char *input, size_t size) {
    printf("Enter the text to convert (up to %zu characters): ", size - 1);
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline
}

// Program Entry Point
int main() {
    char input[MAX_INPUT_LENGTH];
    int option;

    printf("Welcome to the Morse Code Converter!\n");
    do {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Clear the buffer

        switch (option) {
            case 1:
                getUserInput(input, MAX_INPUT_LENGTH);
                textToMorse(input);
                break;
            case 2:
                printf("Thank you for using the Morse Code Converter. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 2);

    return 0;
}