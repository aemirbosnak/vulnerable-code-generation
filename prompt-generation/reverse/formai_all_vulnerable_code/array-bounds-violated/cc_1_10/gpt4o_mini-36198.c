//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Morse code representation for each letter and digit
const char* morseCode[36] = {
    "A", ".-",       "B", "-...",     "C", "-.-.",
    "D", "-..",     "E", ".",       "F", "..-.",
    "G", "--.",     "H", "....",    "I", "..",
    "J", ".---",    "K", "-.-",     "L", ".-..",
    "M", "--",      "N", "-.",      "O", "---",
    "P", ".--.",    "Q", "--.-",    "R", ".-.",
    "S", "...",     "T", "-",       "U", "..-",
    "V", "...-",    "W", ".--",     "X", "-..-",
    "Y", "-.--",    "Z", "--..",
    "0", "-----",   "1", ".----",   "2", "..---",
    "3", "...--",   "4", "....-",   "5", ".....",
    "6", "-....",   "7", "--...",    "8", "---..",
    "9", "----."
};

// Function to convert text to Morse code
void textToMorse(const char* text) {
    int length = strlen(text);
    printf("Morse Code: ");
    
    for (int i = 0; i < length; i++) {
        char ch = toupper(text[i]);

        if (ch >= 'A' && ch <= 'Z') {
            int index = ch - 'A';
            printf("%s ", morseCode[index * 2 + 1]);
        } else if (ch >= '0' && ch <= '9') {
            int index = ch - '0';
            printf("%s ", morseCode[26 * 2 + index * 2 + 1]);
        } else if (ch == ' ') {
            printf("/ "); // Use '/' to indicate a space
        } else {
            printf("? "); // Unknown character
        }
    }
    printf("\n");
}

// Main function to take user input
int main() {
    char input[256];

    printf("Welcome to the Text to Morse Code Converter!\n");
    printf("Enter text (max 255 characters): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    // Convert input text to Morse code
    textToMorse(input);
    
    printf("Conversion completed. Thank you for using the program!\n");
    return 0;
}