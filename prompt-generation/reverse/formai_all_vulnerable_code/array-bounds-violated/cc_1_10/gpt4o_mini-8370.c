//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 128 // Define maximum characters for lookup

// Morse code representation for each character
const char* morseCode[MAX_CHAR] = {
    /* A-Z */
    ['A'] = ".-", ['B'] = "-...", ['C'] = "-.-.", ['D'] = "-..", 
    ['E'] = ".", ['F'] = "..-.", ['G'] = "--.", ['H'] = "....", 
    ['I'] = "..", ['J'] = ".---", ['K'] = "-.-", ['L'] = ".-..", 
    ['M'] = "--", ['N'] = "-.", ['O'] = "---", ['P'] = ".--.", 
    ['Q'] = "--.-", ['R'] = ".-.", ['S'] = "...", ['T'] = "-", 
    ['U'] = "..-", ['V'] = "...-", ['W'] = ".--", ['X'] = "-..-", 
    ['Y'] = "-.--", ['Z'] = "--..",

    /* 0-9 */
    ['0'] = "-----", ['1'] = ".----", ['2'] = "..---", ['3'] = "...--", 
    ['4'] = "....-", ['5'] = ".....", ['6'] = "-....", ['7'] = "--...", 
    ['8'] = "---..", ['9'] = "----.",

    /* Special Characters */
    [' '] = "/"
};

// Function prototypes
void initMorseCode();
void convertToMorse(const char *input, char *output);
void printMorse(const char *morse);

// Main function
int main() {
    char input[256];  // Input string
    char morse[768];  // Output morse code string

    // Initializing morse code reference table
    initMorseCode();

    printf("Enter the text to convert to Morse code (Press CTRL+D to end input): \n");
    while (fgets(input, sizeof(input), stdin)) {
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        convertToMorse(input, morse);
        printMorse(morse);
    }

    return 0;
}

// Function to initialize morse code reference
void initMorseCode() {
    // The morse code is already initialized statically above
}

// Function to convert given text to Morse code
void convertToMorse(const char *input, char *output) {
    output[0] = '\0'; // Initialize output string
    for (size_t i = 0; i < strlen(input); i++) {
        char ch = toupper(input[i]); // Convert input to uppercase
        if (ch < MAX_CHAR && morseCode[ch]) {
            strcat(output, morseCode[ch]); // Concatenate Morse code
            strcat(output, " ");           // Space between letters
        }
    }
}

// Function to print Morse code
void printMorse(const char *morse) {
    printf("Morse Code: %s\n", morse);
}