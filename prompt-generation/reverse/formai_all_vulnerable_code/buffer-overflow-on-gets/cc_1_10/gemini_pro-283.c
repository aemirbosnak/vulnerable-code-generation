//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a Morse code character
typedef struct MorseCharacter {
    char character;
    char *code;
} MorseCharacter;

// An array of Morse code characters
const MorseCharacter morseCharacters[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {' ', " "}
};

// A function to convert a character to Morse code
char *characterToMorse(char character) {
    // Loop through the array of Morse code characters
    for (int i = 0; i < sizeof(morseCharacters) / sizeof(MorseCharacter); i++) {
        // If the character matches the current Morse code character, return the code
        if (character == morseCharacters[i].character) {
            return morseCharacters[i].code;
        }
    }

    // If the character is not found in the array, return an empty string
    return "";
}

// A function to convert a string to Morse code
char *stringToMorse(char *string) {
    // Allocate memory for the Morse code string
    char *morseString = malloc(strlen(string) * 5);

    // Loop through the string
    for (int i = 0; i < strlen(string); i++) {
        // Convert the character to Morse code
        char *morseCode = characterToMorse(string[i]);

        // Append the Morse code to the Morse code string
        strcat(morseString, morseCode);
    }

    // Return the Morse code string
    return morseString;
}

// A function to print a string in Morse code
void printMorseCode(char *string) {
    // Loop through the string
    for (int i = 0; i < strlen(string); i++) {
        // Print the Morse code character
        printf("%s ", string[i]);
    }

    // Print a newline
    printf("\n");
}

int main() {
    // Get the input string from the user
    char string[100];
    printf("Enter a string to convert to Morse code: ");
    gets(string);

    // Convert the string to Morse code
    char *morseCode = stringToMorse(string);

    // Print the Morse code
    printf("The Morse code for \"%s\" is: ", string);
    printMorseCode(morseCode);

    // Free the memory allocated for the Morse code string
    free(morseCode);

    return 0;
}