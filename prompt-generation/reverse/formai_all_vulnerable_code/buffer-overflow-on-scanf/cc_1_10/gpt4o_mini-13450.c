//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Struct to hold character to Morse code mapping
typedef struct {
    char letter;
    const char *morse;
} MorseDict;

// Morse code dictionary
const MorseDict morseDict[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}, {' ', " "}
};

// Function to convert a single character to Morse code
const char* charToMorse(char c) {
    c = toupper(c); // Convert to uppercase
    for (int i = 0; i < sizeof(morseDict) / sizeof(MorseDict); i++) {
        if (morseDict[i].letter == c) {
            return morseDict[i].morse;
        }
    }
    return ""; // Return an empty string if not found
}

// Function to convert text to Morse code
void textToMorse(const char *text) {
    printf("Morse code: ");
    for (int i = 0; i < strlen(text); i++) {
        const char *morse = charToMorse(text[i]);
        if (morse[0] != '\0') { // Only print if there's a valid Morse code
            printf("%s ", morse);
        } else {
            printf("? "); // Unknown character representation
        }
    }
    printf("\n");
}

// Function to read user input
void readInput() {
    char input[MAX_LENGTH];

    printf("Enter text to convert to Morse Code (max %d characters): ", MAX_LENGTH - 1);
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
        textToMorse(input);
    } else {
        printf("Error reading input.\n");
    }
}

// Main function
int main() {
    int choice;

    printf("Welcome to the Text to Morse Code Converter!\n");
    do {
        readInput();
        printf("Do you want to convert another text? (1 for Yes, 0 for No): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }
        while (getchar() != '\n'); // Clear the input buffer
    } while (choice == 1);

    printf("Thank you for using the Morse Code Converter! Goodbye!\n");
    return 0;
}