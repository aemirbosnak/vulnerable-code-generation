//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Morse code table
char *morseCodeTable[] = {
    ".-",  "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",   ".---", "-.-.-",
    "-..-", "-.--", "--..",  ".----", "..---", "...--", "....-", ".....", "-....", "--...",
    "---..", "----.", "-----", "|",    "|---|", "|..--|", "|..---|", "|..-.|", "|....|", "|..--.",
    "|--..|", "|---|",  "|----|"
};

// Character to Morse code conversion function
char *toMorseCode(char character) {
    int index = character - 'a';
    if (index >= 0 && index < 26) {
        return morseCodeTable[index];
    } else {
        return NULL;
    }
}

// Text to Morse code conversion function
char *textToMorseCode(char *text) {
    char *morseCode = malloc(strlen(text) * 5);
    int i = 0;
    int j = 0;
    while (text[i] != '\0') {
        char *morseCharacter = toMorseCode(text[i]);
        if (morseCharacter != NULL) {
            strcpy(morseCode + j, morseCharacter);
            j += strlen(morseCharacter);
            morseCode[j++] = ' ';
        }
        i++;
    }
    morseCode[j] = '\0';
    return morseCode;
}

// Main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter the text you want to convert to Morse code: ");
    gets(text);

    // Convert the text to Morse code
    char *morseCode = textToMorseCode(text);

    // Print the Morse code
    printf("The Morse code is: %s\n", morseCode);

    // Free the allocated memory
    free(morseCode);

    return 0;
}