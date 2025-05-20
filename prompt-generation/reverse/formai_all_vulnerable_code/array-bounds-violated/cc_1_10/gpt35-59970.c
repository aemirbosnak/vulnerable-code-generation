//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert text to morse code
char* textToMorse(char* text) {
    const char* morseCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                                ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                                ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    // Array to hold the morse code for each character
    char* result = (char*)malloc(strlen(text) * 8 + 1);
    int resultIndex = 0;

    // Loop through each character in input string
    for (int i = 0; i < strlen(text); i++) {
        // Check if character is alphanumeric or a space
        if (isalnum(text[i])) {
            // If alphanumeric, convert to uppercase
            char uppercaseChar = toupper(text[i]);
            // Get the morse code for the character by subtracting char code of 'A'
            const char* morse = morseCode[uppercaseChar - 'A'];
            // Append morse code to result string
            strcat(result, morse);
            // Add a space between each morse code sequence
            strcat(result, " ");
            resultIndex += strlen(morse) + 1;
        }
        else if (isspace(text[i])) {
            // If space, add a space to result string
            strcat(result, "  ");
            resultIndex += 2;
        }
        else {
            // If character is not alphanumeric or a space, ignore it
            continue;
        }
    }
    if (resultIndex > 0) {
        // Remove trailing space from result string
        result[resultIndex - 1] = '\0';
    }
    return result;
}

int main() {
    char inputString[100];
    printf("Enter text to convert to Morse code: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove newline character from input string
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }

    // Convert input string to Morse code
    char* morseCodeString = textToMorse(inputString);
    printf("%s\n", morseCodeString);

    free(morseCodeString);
    return 0;
}