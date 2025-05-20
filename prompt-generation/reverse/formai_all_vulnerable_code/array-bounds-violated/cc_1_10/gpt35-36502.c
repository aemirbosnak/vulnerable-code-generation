//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: decentralized
#include <stdio.h>
#include <string.h>

// This function converts a single character to a Morse code string
char *charToMorse(char c) {
    // Define the Morse code alphabet as an array of strings
    char *morseAlphabet[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};

    // Get the index of the character in the ASCII table
    int index = c - 'A';

    // If the character is a space, return a slash
    if (c == ' ') {
        return morseAlphabet[26];
    }

    // If the character is not in the ASCII table (such as a symbol), return NULL
    if (index < 0 || index > 25) {
        return NULL;
    }

    // Return the Morse code string for the character
    return morseAlphabet[index];
}

int main() {
    char input[100]; // the input C string
    char output[1000]; // the output Morse code string
    int outputIndex = 0; // the current index of the output string
    int inputLength; // the length of the input string
    int i, j; // loop variables

    // Ask the user for the input string
    printf("Enter a string to convert to Morse code: ");
    fgets(input, 100, stdin);

    // Remove the newline character from the input string
    inputLength = strlen(input);
    if (input[inputLength-1] == '\n') {
        input[inputLength-1] = '\0';
        inputLength--;
    }

    // Loop through each character in the input string
    for (i = 0; i < inputLength; i++) {
        char *morseChar = charToMorse(input[i]); // the Morse code string for the current input character

        // If the character is not in the ASCII table, print an error message and exit the program
        if (morseChar == NULL) {
            printf("Error: character not in Morse code alphabet.\n");
            return 1;
        }

        // Add the Morse code string for the current input character to the output string
        for (j = 0; j < strlen(morseChar); j++) {
            output[outputIndex++] = morseChar[j];
            output[outputIndex++] = ' '; // Add a space between each Morse code character
        }
    }

    // Print the output Morse code string
    printf("%s\n", output);

    return 0;
}