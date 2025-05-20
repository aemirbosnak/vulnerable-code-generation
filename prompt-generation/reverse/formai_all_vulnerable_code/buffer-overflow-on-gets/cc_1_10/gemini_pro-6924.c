//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the Morse code table
char *morseCodeTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-"
};

// Declare the text to Morse code conversion function
char *textToMorseCode(char *text) {
    // Allocate memory for the Morse code string
    char *morseCode = (char *)malloc(strlen(text) * 5);

    // Convert each character in the text to Morse code
    int i;
    for (i = 0; i < strlen(text); i++) {
        char character = text[i];

        // Convert the character to uppercase
        character = toupper(character);

        // Get the Morse code for the character
        char *morseCodeForCharacter = morseCodeTable[character - 'A'];

        // Append the Morse code for the character to the Morse code string
        strcat(morseCode, morseCodeForCharacter);

        // Append a space to the Morse code string
        strcat(morseCode, " ");
    }

    // Return the Morse code string
    return morseCode;
}

// Declare the main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter the text you want to convert to Morse code: ");
    gets(text);

    // Convert the text to Morse code
    char *morseCode = textToMorseCode(text);

    // Print the Morse code
    printf("The Morse code for the text is: %s", morseCode);

    // Free the memory allocated for the Morse code string
    free(morseCode);

    return 0;
}