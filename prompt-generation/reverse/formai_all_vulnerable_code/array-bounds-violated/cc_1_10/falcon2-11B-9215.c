//Falcon2-11B DATASET v1.0 Category: Text to Morse code conversion ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert text to Morse code
void textToMorse(char* text, char* morseCode) {
    // Define Morse code for each letter
    const char morseCodeTable[] = {'.-', '-...', '-.-.', '-..', '.'};

    // Iterate through each character in the text
    int i = 0;
    while (text[i]!= '\0') {
        // Convert character to uppercase
        text[i] = toupper(text[i]);

        // Find the Morse code for the current character
        int index = (int) text[i] - 'A';
        morseCode[i] = morseCodeTable[index];

        // Move to the next character
        i++;
    }

    // Convert the last character to uppercase
    text[i] = toupper(text[i]);
    morseCode[i] = morseCodeTable[text[i] - 'A'];
}

// Function to print Morse code
void printMorse(char* morseCode) {
    // Iterate through each character in the Morse code
    int i = 0;
    while (morseCode[i]!= '\0') {
        // Print the Morse code character
        printf("%c", morseCode[i]);

        // Move to the next character
        i++;
    }
}

int main() {
    // Input text
    char text[] = "HELLO WORLD";

    // Output Morse code
    char morseCode[strlen(text) + 1];

    // Convert text to Morse code
    textToMorse(text, morseCode);

    // Print Morse code
    printf("Morse code: ");
    printMorse(morseCode);

    return 0;
}