//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code dictionary
struct MorseCode {
    char character;
    char *code;
};

struct MorseCode morseCodeDictionary[] = {
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

// Function to convert a character to Morse code
char *characterToMorse(char character) {
    for (int i = 0; i < sizeof(morseCodeDictionary) / sizeof(struct MorseCode); i++) {
        if (morseCodeDictionary[i].character == character) {
            return morseCodeDictionary[i].code;
        }
    }

    return NULL;
}

// Function to convert a string to Morse code
char *stringToMorse(char *string) {
    char *morseCode = malloc(strlen(string) * 5); // Allocate enough memory for the Morse code
    int index = 0;

    for (int i = 0; i < strlen(string); i++) {
        char *characterMorseCode = characterToMorse(string[i]);
        if (characterMorseCode != NULL) {
            strcpy(morseCode + index, characterMorseCode);
            index += strlen(characterMorseCode);
            morseCode[index++] = ' '; // Add a space between each character's Morse code
        }
    }

    morseCode[index] = '\0'; // Add a null terminator to the end of the Morse code

    return morseCode;
}

// Main function
int main() {
    // Get the input string from the user
    printf("Enter a string to convert to Morse code: ");
    char string[100];
    scanf("%s", string);

    // Convert the string to Morse code
    char *morseCode = stringToMorse(string);

    // Print the Morse code
    printf("Morse code: %s\n", morseCode);

    // Free the memory allocated for the Morse code
    free(morseCode);

    return 0;
}