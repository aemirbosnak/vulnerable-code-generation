//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morseCodeTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert a character to Morse code
char *charToMorse(char character) {
    int index = character - 'A';
    if (index >= 0 && index < 26) {
        return morseCodeTable[index];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *stringToMorse(char *string) {
    int length = strlen(string);
    char *morseCode = malloc(length * 5 + 1); // Allocate enough space for the Morse code
    int index = 0;
    for (int i = 0; i < length; i++) {
        char *morseCharacter = charToMorse(string[i]);
        if (morseCharacter != NULL) {
            strcat(morseCode, morseCharacter);
            strcat(morseCode, " ");
            index += strlen(morseCharacter) + 1;
        }
    }
    morseCode[index] = '\0'; // Null-terminate the string
    return morseCode;
}

// Main function
int main() {
    // Get the input string
    printf("Enter a string to convert to Morse code: ");
    char string[100];
    scanf("%s", string);

    // Convert the string to Morse code
    char *morseCode = stringToMorse(string);

    // Print the Morse code
    printf("Morse code: %s\n", morseCode);

    // Free the allocated memory
    free(morseCode);

    return 0;
}