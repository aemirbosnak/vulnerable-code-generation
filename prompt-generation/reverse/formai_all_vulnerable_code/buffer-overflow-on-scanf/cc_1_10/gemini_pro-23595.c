//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the Morse code table
char* morseTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Define the alphabet table
char* alphabetTable[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"
};

// Function to convert a character to Morse code
char* charToMorse(char character) {
    int index = character - 'A';
    if (index >= 0 && index < 26) {
        return morseTable[index];
    } else if (index >= 26 && index < 36) {
        return morseTable[index - 26];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char* stringToMorse(char* string) {
    int length = strlen(string);
    char* morseCode = malloc(length * 5); // Allocate enough space for the Morse code
    int index = 0;
    for (int i = 0; i < length; i++) {
        char* morseChar = charToMorse(string[i]);
        if (morseChar != NULL) {
            strcat(morseCode, morseChar);
            morseCode[index++] = ' '; // Add a space between characters
        }
    }
    morseCode[index] = '\0'; // Add the null terminator
    return morseCode;
}

// Function to print the Morse code
void printMorseCode(char* morseCode) {
    printf("Morse code: %s\n", morseCode);
}

int main() {
    // Get the input string from the user
    char* string = malloc(100);
    printf("Enter a string: ");
    scanf("%s", string);

    // Convert the string to Morse code
    char* morseCode = stringToMorse(string);

    // Print the Morse code
    printMorseCode(morseCode);

    // Free the allocated memory
    free(string);
    free(morseCode);

    return 0;
}