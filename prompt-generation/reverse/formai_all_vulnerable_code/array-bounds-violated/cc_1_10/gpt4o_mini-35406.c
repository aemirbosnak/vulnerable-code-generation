//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MORSE_TABLE_SIZE 36

typedef struct {
    char character;
    char *morse;
} MorseCode;

MorseCode morseTable[MORSE_TABLE_SIZE] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"},
    {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {' ', "/"} // Space represented with /
};

char *textToMorse(const char *text) {
    char *morseResult = (char *)malloc(MAX_LENGTH * sizeof(char));
    if (!morseResult) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    morseResult[0] = '\0'; // Initialize the string
    
    for (size_t i = 0; i < strlen(text); i++) {
        char upperChar = toupper(text[i]);
        for (size_t j = 0; j < MORSE_TABLE_SIZE; j++) {
            if (morseTable[j].character == upperChar) {
                strcat(morseResult, morseTable[j].morse);
                strcat(morseResult, " "); // Add space as separator
                break;
            }
        }
    }
    
    return morseResult;
}

void cleanup(char *morseCode) {
    if (morseCode) {
        free(morseCode);
    }
}

int main() {
    char input[MAX_LENGTH];

    printf("Welcome to the Text to Morse Code Converter!\n");
    printf("Please enter text to convert (max length %d characters):\n", MAX_LENGTH - 1);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input!\n");
        return EXIT_FAILURE;
    }

    // Remove newline character from input
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    char *morseCode = textToMorse(input);

    printf("\nText: %s\n", input);
    printf("Morse Code: %s\n", morseCode);

    cleanup(morseCode);
    return EXIT_SUCCESS;
}