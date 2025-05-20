//FormAI DATASET v1.0 Category: Text processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    char inputString[MAX_LINE_LENGTH], outputString[MAX_LINE_LENGTH];
    int i, j, inputLength, wordLength;

    printf("Enter a sentence: ");

    // Get user input
    fgets(inputString, MAX_LINE_LENGTH, stdin);

    // Remove newline character from input
    inputLength = strlen(inputString);
    if (inputString[inputLength - 1] == '\n') {
        inputString[inputLength - 1] = '\0';
    }

    // Process the input string
    i = 0;
    j = 0;
    wordLength = 0;
    while (inputString[i] != '\0') {
        // Check if current character is a space
        if (inputString[i] == ' ') {
            // Check if previous character was part of a word
            if (wordLength > 0) {
                // Reverse the word and copy it to the output string
                for (int k = 0; k < wordLength; k++) {
                    outputString[j++] = inputString[i - 1 - k];
                }
                wordLength = 0;
            }
            // Copy the space to the output string
            outputString[j++] = inputString[i];
        } else {
            wordLength++;
        }
        i++;
    }

    // Check if last character was part of a word
    if (wordLength > 0) {
        // Reverse the word and copy it to the output string
        for (int k = 0; k < wordLength; k++) {
            outputString[j++] = inputString[i - 1 - k];
        }
    }

    // Add null terminator to output string
    outputString[j] = '\0';

    printf("Output string: %s\n", outputString);

    return 0;
}