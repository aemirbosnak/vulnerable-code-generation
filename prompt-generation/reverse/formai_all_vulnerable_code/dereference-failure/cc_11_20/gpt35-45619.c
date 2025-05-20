//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code conversion function
char* convertToMorse(char* text);

int main() {
    // Welcome message
    printf("Welcome to the Morse code converter program.\n");

    // Get user input
    char text[100];
    printf("Please enter the text you would like to convert to Morse code:\n");
    fgets(text, 100, stdin);
    
    // Remove newline character from input string
    text[strcspn(text, "\n")] = 0;

    // Convert input text to Morse code
    char* morseCode = convertToMorse(text);

    // Print out Morse code output
    printf("Morse code output:\n%s\n", morseCode);

    // Free allocated memory
    free(morseCode);

    // Exit the program
    return 0;
}

// Morse code conversion function
char* convertToMorse(char* text) {
    // Define Morse code table
    char* morseTable[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* digits = "0123456789";
    char* special = ".,?'!/()&:;=+-_\"$@";

    // Create empty string to add Morse code output
    char* morseOutput = malloc(strlen(text) * 5 + 1);

    // Loop through each character in input string
    for (int i = 0; i < strlen(text); i++) {
        char c = toupper(text[i]);
        char* code = "";

        // Determine Morse code for character
        if (strchr(letters, c) != NULL) {
            code = morseTable[c - 'A'];
        }
        else if (strchr(digits, c) != NULL) {
            code = morseTable[c - '0' + 26];
        }
        else if (strchr(special, c) != NULL) {
            switch(c) {
                case '.':  code = ".-.-.-"; break;
                case ',':  code = "--..--"; break;
                case '?':  code = "..--.."; break;
                case '\'': code = ".----."; break;
                case '!':  code = "-.-.--"; break;
                case '/':  code = "-..-."; break;
                case '(':  code = "-.--."; break;
                case ')':  code = "-.--.-"; break;
                case '&':  code = ".-..."; break;
                case ':':  code = "---..."; break;
                case ';':  code = "-.-.-."; break;
                case '=':  code = "-...-"; break;
                case '+':  code = ".-.-."; break;
                case '-':  code = "-....-"; break;
                case '_':  code = "..--.-"; break;
                case '\"': code = ".-..-."; break;
                case '$':  code = "...-..-"; break;
                case '@':  code = ".--.-."; break;
            }
        }

        // Add Morse code to output string
        strcat(morseOutput, code);
        strcat(morseOutput, " ");
    }

    // Return Morse code output string
    return morseOutput;
}