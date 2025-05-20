//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 100 // Maximum length of input string

// Morse code lookup table
const char *morseCodeTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A to I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", // J to R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S to Z
};

// Function to convert a character to morse code
void charToMorseCode(char ch, char *morseCodeStr) {
    int index;
    // Check if character is a letter
    if (ch >= 'A' && ch <= 'Z') {
        // Get morse code pattern for the letter
        index = ch - 'A';
        strcpy(morseCodeStr, morseCodeTable[index]);
    }
    // Check if character is a number
    else if (ch >= '0' && ch <= '9') {
        // Get morse code pattern for the number (add 26 to index)
        index = ch - '0' + 26;
        strcpy(morseCodeStr, morseCodeTable[index]);
    }
    // For any other character, return a space
    else {
        strcpy(morseCodeStr, " ");
    }
}

// Function to convert a string to morse code
void stringToMorseCode(char *str, char *morseCodeStr) {
    int len = strlen(str);
    char morseChar[MAX_STR_LENGTH];
    morseCodeStr[0] = '\0';
    // Convert each character in the string to morse code
    for (int i = 0; i < len; i++) {
        charToMorseCode(str[i], morseChar);
        strcat(morseCodeStr, morseChar);
        // Add a space between morse code characters
        if (i != len - 1) {
            strcat(morseCodeStr, " ");
        }
    }
}

int main() {
    char str[MAX_STR_LENGTH];
    printf("Enter a string to convert to Morse code: ");
    fgets(str, MAX_STR_LENGTH, stdin);
    // Remove newline character from input string
    str[strcspn(str, "\n")] = 0;
    char morseCodeStr[MAX_STR_LENGTH * 4]; // Maximum length of morse code string is 4 times input string length
    stringToMorseCode(str, morseCodeStr);
    printf("\nMorse code: %s\n", morseCodeStr);
    return 0;
}