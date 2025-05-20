//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Morse code alphabet
char *morseAlphabet[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", " "
};

// Function to convert a character to Morse code
char *charToMorse(char c) {
    int index = c - 'A';
    if (index < 0 || index > 25) {
        return NULL;
    }
    return morseAlphabet[index];
}

// Function to convert a string to Morse code
char *stringToMorse(char *str) {
    int len = strlen(str);
    char *morseCode = malloc(len * 5 + 1);
    int i;
    for (i = 0; i < len; i++) {
        char *morse = charToMorse(str[i]);
        if (morse == NULL) {
            free(morseCode);
            return NULL;
        }
        strcat(morseCode, morse);
        strcat(morseCode, " ");
    }
    morseCode[len * 5] = '\0';
    return morseCode;
}

// Function to print the Morse code representation of a string
void printMorse(char *morseCode) {
    printf("%s\n", morseCode);
}

int main() {
    // Get the input string from the user
    char str[101];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morseCode = stringToMorse(str);
    if (morseCode == NULL) {
        printf("Invalid input string.\n");
        return 1;
    }

    // Print the Morse code representation of the string
    printf("Morse code: ");
    printMorse(morseCode);

    // Free the allocated memory
    free(morseCode);

    return 0;
}