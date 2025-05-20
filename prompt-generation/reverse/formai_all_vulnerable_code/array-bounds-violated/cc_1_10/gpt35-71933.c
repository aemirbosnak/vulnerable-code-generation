//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define the Morse code mapping array
char *morseMap[] = {
    ".-","-...","-.-.","-..",".","..-.","--.","....",
    "..",".---","-.-",".-..","--","-.","---",".--.",
    "--.-",".-.","...","-","..-","...-",".--","-..-",
    "-.--","--.."
};

// Function to convert a single character to Morse code
char* charToMorse(char c) {
    if (isalpha(c)) {
        // Convert uppercase letters to Morse code
        return morseMap[toupper(c) - 'A'];
    } else if (isdigit(c)) {
        // Convert digits to Morse code
        return morseMap[c - '0' + 26];
    } else {
        // Return null for unsupported characters
        return NULL;
    }
}

// Function to convert a string to Morse code
char* stringToMorse(char* str) {
    // Create a string buffer for the Morse code output
    char* morse = (char*)calloc(strlen(str) * 5 + 1,sizeof(char));
    char* morsePos = morse;
    // Iterate over the input string
    for (int i = 0; i < strlen(str); i++) {
        char* morseChar = charToMorse(str[i]);
        if (morseChar != NULL) {
            // Append the Morse code for this character to the output
            while (*morseChar != '\0') {
                *morsePos++ = *morseChar++;
            }
            *morsePos++ = ' ';
        }
    }
    // Add a null terminator to the end of the Morse code output
    *(morsePos - 1) = '\0';
    return morse;
}

int main() {
    char input[100];
    printf("Enter a string to convert to Morse code: ");
    fgets(input,100,stdin);
    // Remove the newline character from the input
    input[strlen(input) - 1] = '\0';
    char* morse = stringToMorse(input);
    if (morse != NULL) {
        printf("%s\n",morse);
        // Free the memory used for the Morse code output
        free(morse);
    } else {
        printf("Unsupported character found in input!\n");
    }
    return 0;
}