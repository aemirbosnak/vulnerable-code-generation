//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Morse code representation of each letter and digit
const char *morseCode[] = {
    ".-",   "-...","-.-.", "-..",  ".",   "..-.", "--.",  "....",
    "..",   ".---", "-.-",  ".-..", "--",  "-.",   "---",  ".--.",
    "--.-", ".-.",  "...",  "-",    "..-", ".--",  "-..-", "-.--", "--..",
    
    "-----", ".----","..---", "...--", "....-", ".....","-....", "--...", "---..", "----."
};

const char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Function to convert a character to Morse code
const char* charToMorse(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return morseCode[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morseCode[c - '0' + 26]; // Offset for digits
    } else {
        return " "; // Unknown character
    }
}

// This function converts a message to Morse code
void textToMorse(const char *message) {
    printf("Hey there! 🥳 Here comes your Morse code conversion!\n");
    for (int i = 0; message[i] != '\0'; i++) {
        const char *morseChar = charToMorse(message[i]);
        if (morseChar[0] != ' ') {
            printf("%s ", morseChar);
        } else {
            printf("/ "); // Represents a space between words
        }
    }
    printf("\nWow! Your message has been converted to Morse code! 🔥\n");
}

// Main function to drive the program
int main() {
    char message[256];

    printf("Welcome to the Morse Code Converter! 🤩\n");
    printf("Please enter the text you would like to convert (up to 255 characters):\n");
    
    if (fgets(message, sizeof(message), stdin) != NULL) {
        // Remove the newline character added by fgets
        message[strcspn(message, "\n")] = 0;

        // Convert and print the Morse code
        textToMorse(message);
    } else {
        printf("Oops! It seems there was a problem reading your input. Try again! 😬\n");
    }

    return 0;
}