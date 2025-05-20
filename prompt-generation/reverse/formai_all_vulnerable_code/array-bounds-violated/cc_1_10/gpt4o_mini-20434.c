//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_MORSE_LENGTH 500

// Define the Morse code for each character
const char *morseCode[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
};

// Function to get Morse code for a given character
const char *getMorse(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return morseCode[ch - 'A'];
    } else if (ch >= '0' && ch <= '9') {
        return morseCode[ch - '0' + 26]; // Adjust this if you add digits
    }
    return ""; // Return empty for unsupported characters
}

// Function to convert text to Morse code
void textToMorse(const char *text, char *morse) {
    morse[0] = '\0'; // Initialize morse string
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = toupper(text[i]); // Convert to uppercase
        const char *morseChar = getMorse(ch);
        if (strlen(morseChar) > 0) {
            strcat(morse, morseChar);
            strcat(morse, " "); // Add space between Morse code characters
        }
    }
    strtok(morse, " "); // Remove trailing space
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char morse[MAX_MORSE_LENGTH];

    // Introduction to the user
    printf("Welcome to the Text to Morse Code Converter!\n");
    printf("Please enter text (maximum %d characters): ", MAX_INPUT_LENGTH - 1);
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0; 

    if (strlen(input) == 0) {
        printf("No input provided. Please enter valid text next time.\n");
        return 1;
    }

    // Convert input text to Morse code
    textToMorse(input, morse);

    // Print the Morse code output
    printf("Your input in Morse Code is:\n%s\n", morse);

    return 0;
}