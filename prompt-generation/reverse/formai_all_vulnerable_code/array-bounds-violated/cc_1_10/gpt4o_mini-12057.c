//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse Code Dictionary
const char *morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

const char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Function to convert text to Morse code
void textToMorse(const char *input, char *output) {
    char temp[100];
    temp[0] = '\0';  // Initialize temporary output string as empty

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (ch >= 'A' && ch <= 'Z') {
            strcat(temp, morseCode[ch - 'A']);
        } else if (ch >= '0' && ch <= '9') {
            strcat(temp, morseCode[ch - '0' + 26]);
        }

        strcat(temp, " ");  // Add space between Morse code representations
    }

    // Copy temporary Morse code string to output
    strcpy(output, temp);
}

// Function to read input text from the user
void readInput(char *input, size_t size) {
    printf("Enter text (A-Z, 0-9) to convert to Morse code: ");
    fgets(input, size, stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}

// Function to print the Morse code output
void printMorseCode(const char *morse) {
    printf("Morse Code: %s\n", morse);
}

int main() {
    size_t inputSize = 256;
    char *input = (char *)malloc(inputSize);
    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    char output[512];  // Considerably larger to store the Morse Code

    readInput(input, inputSize);

    // Convert input text to uppercase
    for (int i = 0; input[i]; i++) {
        input[i] = toupper(input[i]);
    }

    // Convert the input text to Morse Code
    textToMorse(input, output); 

    // Print the output
    printMorseCode(output);

    // Free allocated memory
    free(input);

    return 0;
}